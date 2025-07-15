void __cdecl vostok::sound::sound_debug_stats::set_detail_view_proxy_id(unsigned int proxy_id)
{
  vostok::sound::sound_debug_stats::set_debug_draw_mode(move_backward);
  _InterlockedExchange(&vostok::sound::sound_debug_stats::m_s_proxy_id, proxy_id);
}
