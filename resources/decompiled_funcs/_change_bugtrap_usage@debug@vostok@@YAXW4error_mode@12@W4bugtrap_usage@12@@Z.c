void __cdecl vostok::debug::change_bugtrap_usage(
        vostok::debug::error_mode error_mode,
        vostok::debug::bugtrap_usage bugtrap_usage)
{
  vostok::debug::bugtrap::change_usage(error_mode, bugtrap_usage);
  vostok::debug::platform::change_storage_access_handler(error_mode);
  vostok::debug::postinitialize();
}
