#include "BlueFoxCam.h"
#include <exception>
#include <iostream>
using namespace std;

BlueFoxCam::BlueFoxCam()
{
	if (this->devMgr.deviceCount() == 0){
		throw runtime_error("ERROR: No device found.");
	}

	this->pDev = devMgr[0];
	try{
		this->pDev->open();
	}
	catch (mvIMPACT::acquire::ImpactAcquireException& e){
		throw runtime_error("ERROR: Cannot open the device.");
	}
	
	SettingsBlueFOX setting(this->pDev);
	setting.cameraSetting.imageRequestTimeout_ms.write(800);
	setting.cameraSetting.autoExposeControl.write(aecOn);
	//setting.cameraSetting.getAutoControlParameters().exposeLowerLimit_us.write(50);
	//setting.cameraSetting.getAutoControlParameters().exposeUpperLimit_us.write(50000);
	setting.cameraSetting.autoGainControl.write(agcOn);
	setting.cameraSetting.getAutoControlParameters().gainLowerLimit_dB.write(0);
	setting.cameraSetting.getAutoControlParameters().gainUpperLimit_dB.write(12);
	setting.cameraSetting.pixelFormat.write(ibpfAuto);
	setting.imageDestination.pixelFormat.write(idpfRGB888Packed);
	setting.cameraSetting.triggerMode.write(ctmOnDemand);
	//setting.cameraSetting.exposeMode.write(cemOverlapped);
	//setting.cameraSetting.expose_us.write(40000);
	setting.cameraSetting.pixelClock_KHz.write(cpc40000KHz);
	//setting.cameraSetting.gain_dB.write(0);

	SystemSettings ss(this->pDev);
	ss.requestCount.write(1);
	ss.workerPriority.write(tpTimeCritical);
	
	this->fi = new FunctionInterface(this->pDev);

	for (int i=0;i<ss.requestCount.read();i++){
		if(this->fi->imageRequestSingle() != DMR_NO_ERROR)
			throw runtime_error("Errore");
	}
}

BlueFoxCam::~BlueFoxCam()
{
	this->pDev->close();
	delete this->pDev;
	delete this->fi;
}

void BlueFoxCam::getImage(unsigned char* data)
{
	
	int requestNr = this->fi->imageRequestWaitFor(800);

	if (this->fi->isRequestNrValid(requestNr)){

		const Request* pRequest = this->fi->getRequest(requestNr);
		if (pRequest->isOK()){
			int dataSize = pRequest->imageSize.read();
			memcpy(data, pRequest->imageData.read(), dataSize); 
		}
		else{
			throw runtime_error("ERROR: Request failed");
		}

		this->fi->imageRequestUnlock(requestNr);
	}
	else{
		throw runtime_error("ERROR: imageRequestWaitFor() failed.");
	}

	this->fi->imageRequestSingle();
}



