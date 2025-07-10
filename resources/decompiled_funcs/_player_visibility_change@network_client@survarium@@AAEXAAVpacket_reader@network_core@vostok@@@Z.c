void __usercall survarium::network_client::player_visibility_change(
        survarium::network_client *this@<ecx>,
        _DWORD *a2@<esi>)
{
  char *v2; // eax
  char v3; // dl
  char v4; // bl
  survarium::player *v5; // ecx
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> player; // [esp+8h] [ebp-4h] BYREF

  v2 = *(char **)&this->m_use_physics_controller_for_current;
  v3 = *v2++;
  *(_DWORD *)&this->m_use_physics_controller_for_current = v2;
  LOBYTE(player.m_object) = v3;
  v4 = *v2;
  *(_DWORD *)&this->m_use_physics_controller_for_current = v2 + 1;
  (*(void (__thiscall **)(_DWORD *, vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *, survarium::player *))(*a2 + 72))(
    a2,
    &player,
    player.m_object);
  if ( a2[3886] )
  {
    if ( !player.m_object )
      return;
    if ( player.m_object->m_has_been_inserted && v4 != byte_10F34[(unsigned int)player.m_object] )
    {
      if ( v4 )
      {
        survarium::player::show(v5);
        vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>(&player);
        return;
      }
      survarium::player::hide(v5);
    }
    vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>(&player);
  }
  else if ( player.m_object && !_InterlockedExchangeAdd(&player.m_object->m_reference_count, 0xFFFFFFFF) )
  {
    if ( player.m_object )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &player.m_object->vostok::resources::unmanaged_intrusive_base,
        &player.m_object->vostok::resources::unmanaged_resource);
    else
      vostok::resources::unmanaged_intrusive_base::destroy((vostok::resources::unmanaged_intrusive_base *)0x1F0, 0);
  }
}
