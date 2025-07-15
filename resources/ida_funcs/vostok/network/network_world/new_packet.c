vostok::network_core::tcp_packet *__thiscall vostok::network::network_world::new_packet(
        vostok::network::network_world *this)
{
  vostok::memory::doug_lea_allocator *v1; // eax
  vostok::memory::doug_lea_allocator *v4; // [esp+8h] [ebp-10h]
  void *_Where; // [esp+Ch] [ebp-Ch]
  char *v6; // [esp+14h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v1, 0x10u);
  v6 = (char *)operator new(0x10u, _Where);
  if ( !v6 )
    return 0;
  v4 = vostok::network::g_allocator;
  *(_DWORD *)v6 = 0;
  *((_DWORD *)v6 + 1) = 0;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)(v6 + 8));
  *((_DWORD *)v6 + 2) = v4;
  *((_DWORD *)v6 + 3) = 0;
  return (vostok::network_core::tcp_packet *)v6;
}
