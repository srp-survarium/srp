void __cdecl vostok::debug::bugtrap::setup_unhandled_exception_handler()
{
  s_previous_handler = SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)unhandled_exception_handler_on_top_of_bugtrap);
}
