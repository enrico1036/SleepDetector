
#define ENABLE_BLUEFOX	// Comment this line to disable bluefox

#if !defined BLUEFOXCAM_H && defined ENABLE_BLUEFOX
#define BLUEFOXCAM_H

#include "mvIMPACT_CPP/mvIMPACT_acquire.h"

using namespace mvIMPACT::acquire;

class BlueFoxCam
{
	public:
		BlueFoxCam();
		~BlueFoxCam();
		void getImage(unsigned char* data);
		
	private:
		DeviceManager devMgr;
		Device *pDev;
		FunctionInterface *fi;
};



#endif // BLUEFOXCAM_H
