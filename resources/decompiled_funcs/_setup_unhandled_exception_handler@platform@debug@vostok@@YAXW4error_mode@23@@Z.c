void __cdecl vostok::debug::platform::setup_unhandled_exception_handler(vostok::debug::error_mode error_mode)
{
  s_error_mode = error_mode;
  s_previous_handler = SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)unhandled_exception_handler);
}
