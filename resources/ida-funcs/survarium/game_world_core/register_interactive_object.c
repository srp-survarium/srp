unsigned __int8 __userpurge survarium::game_world_core::register_interactive_object@<al>(
        survarium::game_world_core *this@<ecx>,
        _DWORD *a2@<esi>,
        survarium::interactive_object *const object)
{
  _DWORD *v3; // eax
  survarium::game_world_core *v5; // [esp-2h] [ebp-4h] BYREF

  v5 = this;
  if ( a2[12532] >= a2[12533]
    && !`vostok::buffer_vector<survarium::interactive_object *>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v5) = 0;
    vostok::debug::on_error(
      (bool *)&v5 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class survarium::interactive_object *>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v5);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v5) )
      __debugbreak();
  }
  v3 = (_DWORD *)a2[12532];
  if ( v3 )
    *v3 = object;
  a2[12532] += 4;
  return ((a2[12532] - a2[12531]) >> 2) - 1;
}
