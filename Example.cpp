#include <gflags/gflags.h>
#include <glog/logging.h>

DEFINE_bool(dummy, false, "A dummy variable");

int main(int argc, char** argv) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  google::InitGoogleLogging(argv[0]);
  LOG(INFO) << "Flag dummy is: " << std::boolalpha << FLAGS_dummy;
  return FLAGS_dummy ? 0 : 1;
}
