set(EXTERNAL_LIB_HEADERS libraries/jsoncpp)

target_include_directories(
  executable_name PRIVATE
  ${EXTERNAL_LIB_HEADERS}
)