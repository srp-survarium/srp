unsigned int __thiscall vostok::math::on_thread_spawn(vostok::command_line::key *ecx0)
{
  unsigned int result; // eax
  unsigned int _CurrentState; // [esp+4h] [ebp-4h] BYREF

  result = vostok::command_line::key::is_set(ecx0, (int)&s_floating_point_control_disabled);
  if ( !(_BYTE)result )
  {
    _controlfp_s(&_CurrentState, (unsigned int)&loc_20000, (unsigned int)&loc_30000);
    _controlfp_s(&_CurrentState, 0, 0x300u);
    _mm_setcsr(_mm_getcsr() & 0xFFFF9FFF);
    _controlfp_s(&_CurrentState, 0, (unsigned int)&loc_3FFFF + 1);
    _controlfp_s(
      &_CurrentState,
      (unsigned int)&s_ui_commands_allocator.m_buffer[2035360],
      (unsigned int)&s_ui_commands_allocator.m_buffer[35589792]);
    result = _mm_getcsr() | 0x8000;
    _mm_setcsr(result);
  }
  return result;
}
