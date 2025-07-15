BOOL __thiscall vostok::core::core_debug_engine::terminate_on_error(vostok::core::core_debug_engine *this)
{
  return vostok::build::print_build_id_command_line()
      || vostok::testing::run_tests_command_line()
      || vostok::core::suppress_debug_window_on_crash();
}
