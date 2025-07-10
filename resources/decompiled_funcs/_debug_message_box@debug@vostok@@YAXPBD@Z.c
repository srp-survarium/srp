void __cdecl vostok::debug::debug_message_box(const char *message)
{
  MessageBoxA(0, message, "Debug Break", 0);
}
