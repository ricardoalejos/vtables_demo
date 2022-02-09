add_library(switchable INTERFACE)
target_include_directories(switchable INTERFACE
  $<BUILD_INTERFACE:$ENV{VTABLES_SOURCE}>
  $<INSTALL_INTERFACE:include>
)
install(
    FILES switchable.h
    DESTINATION include/switchable
)
