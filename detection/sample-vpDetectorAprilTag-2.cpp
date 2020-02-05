#include <visp3/detection/vpDetectorAprilTag.h>
#include <visp3/io/vpImageIo.h>

int main()
{
#ifdef VISP_HAVE_APRILTAG
  vpImage<unsigned char> I;
  vpImageIo::read(I, "image-tag36h11.pgm");

  vpDetectorAprilTag detector(vpDetectorAprilTag::TAG_36h11);
  std::vector<vpHomogeneousMatrix> cMo;
  vpCameraParameters cam;
  cam.initPersProjWithoutDistortion(615.1674805, 615.1675415, 312.1889954, 243.4373779);
  double tagSize = 0.053;

  bool status = detector.detect(I, tagSize, cam, cMo);
  if (status) {
    for(size_t i=0; i < detector.getNbObjects(); i++) {
      std::cout << "Tag code " << i << ":" << std::endl;
      std::cout << "  Message: \"" << detector.getMessage(i) << "\"" << std::endl;
      std::cout << "  Pose: " << vpPoseVector(cMo[i]).t() << std::endl;
    }
  }
#endif
}
