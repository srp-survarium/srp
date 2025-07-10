void vostok::threading::_dynamic_initializer_for__g_debug_single_thread__()
{
  vostok::debug::protected_call(
    (void (__cdecl *)(void *))vostok::command_line::protected_key_construct,
    &vostok::threading::g_debug_single_thread);
}
