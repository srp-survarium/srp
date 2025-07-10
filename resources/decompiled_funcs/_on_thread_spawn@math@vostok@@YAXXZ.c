void __cdecl vostok::math::on_thread_spawn()
{
  if ( s_floating_point_control_disabled.m_type == type_unset )
  {
    s_floating_point_control_disabled.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  if ( s_floating_point_control_disabled.m_type == type_recursive )
  {
    _controlfp_s(0, (unsigned int)&loc_20000, 0x30000u);
    _controlfp_s(0, 0, 0x300u);
    _mm_setcsr(_mm_getcsr() & 0xFFFF9FFF);
    _controlfp_s(0, 0, 0x40000u);
    _controlfp_s(
      0,
      (unsigned int)&vostok::memory::s_CRT_arena[5574200],
      (unsigned int)&vostok::memory::s_CRT_arena[39128632]);
    _mm_setcsr(_mm_getcsr() | 0x8000);
  }
}
