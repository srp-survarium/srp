void __cdecl vostok::sound::sound_debug_stats::set_debug_draw_mode(
        vostok::sound::sound_debug_stats::mode debug_draw_mode)
{
  _InterlockedExchange(&vostok::sound::sound_debug_stats::m_s_debug_draw_mode, debug_draw_mode);
}
