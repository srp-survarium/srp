bool __usercall survarium::player::is_first_view@<al>(survarium::player *this@<ecx>, int a2@<eax>)
{
  survarium::base_network_client *v2; // ecx
  bool v3; // bl
  int m_game; // eax
  survarium::base_network_client *v5; // edx
  unsigned __int8 v7; // [esp-4h] [ebp-14h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v8; // [esp+8h] [ebp-8h] BYREF
  int v9; // [esp+Ch] [ebp-4h]

  v2 = *(survarium::base_network_client **)(*(int *)((char *)&dword_11410 + a2) + 160);
  v7 = *(_BYTE *)(a2 + 304);
  v3 = 0;
  m_game = (int)v2[496].m_game;
  v9 = 0;
  if ( survarium::base_network_client::is_player_current(v2, m_game, v7) )
  {
    v9 = 1;
    v3 = *(_DWORD *)(*(_DWORD *)((char *)&loc_11403
                               + (unsigned int)survarium::base_network_client::get_current_player(v5, &v8)->m_object
                               + 5)
                   + 864) == 0;
  }
  if ( (v9 & 1) != 0 )
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v8);
  return v3;
}
