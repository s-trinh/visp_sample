#include <visp3/sensor/vpFlyCaptureGrabber.h>

int main()
{
#ifdef VISP_HAVE_FLYCAPTURE
  vpImage<vpRGBa> I;
  vpFlyCaptureGrabber g;
  g >> I;
#endif
}
