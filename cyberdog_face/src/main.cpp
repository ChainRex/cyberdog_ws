#include <memory>
#include "cyberdog_face/cyberdog_face_entry.hpp"

int main(int argc, char ** argv)
{
  LOGGER_MAIN_INSTANCE("cyberdog_face");
  INFO("cyberdog_face node started");
  rclcpp::init(argc, argv);
  auto face_ptr = std::make_shared<cyberdog::interaction::face>("cyberdog_face");
  std::thread run_thread(&cyberdog::interaction::face::Run, std::ref(*face_ptr));
  face_ptr->Init();
  if (run_thread.joinable()) {
    run_thread.join();
  }
  return 0;
}
