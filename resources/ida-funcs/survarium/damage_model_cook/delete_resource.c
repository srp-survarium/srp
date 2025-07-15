void __thiscall survarium::damage_model_cook::delete_resource(
        survarium::damage_model_cook *this,
        vostok::resources::resource_base *resource)
{
  unsigned int m_lock; // esi
  unsigned int v3; // ecx
  _DWORD *v4; // edi
  _DWORD *v5; // eax
  int v6; // ecx
  _DWORD *v7; // edi
  _DWORD *v8; // eax
  int v9; // ecx
  vostok::memory::doug_lea_allocator *v10; // ecx
  const char *v11; // [esp+0h] [ebp-10h]
  const char *v12; // [esp+4h] [ebp-Ch]
  unsigned int v13; // [esp+8h] [ebp-8h]

  while ( resource[1].m_parent_resources.m_lock )
  {
    m_lock = resource[1].m_parent_resources.m_lock;
    --resource[1].m_children_resources.m_last;
    v3 = *(_DWORD *)m_lock;
    resource[1].m_parent_resources.m_lock = *(_DWORD *)m_lock;
    if ( !v3 )
      resource[1].m_parent_resources.m_thread_id = 0;
    *(_DWORD *)m_lock = 0;
    while ( 1 )
    {
      if ( *(_DWORD *)(m_lock + 12) )
      {
        v5 = *(_DWORD **)(m_lock + 12);
        --*(_DWORD *)(m_lock + 4);
        v6 = *v5;
        *(_DWORD *)(m_lock + 12) = *v5;
        if ( !v6 )
          *(_DWORD *)(m_lock + 16) = 0;
        *v5 = 0;
        v4 = v5;
      }
      else
      {
        v4 = 0;
      }
      if ( !v4 )
        break;
      survarium::loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::~loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>(
        (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)v4
      + 7);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v4
      + 6);
    }
    while ( 1 )
    {
      if ( *(_DWORD *)(m_lock + 28) )
      {
        v8 = *(_DWORD **)(m_lock + 28);
        --*(_DWORD *)(m_lock + 20);
        v9 = *v8;
        *(_DWORD *)(m_lock + 28) = *v8;
        if ( !v9 )
          *(_DWORD *)(m_lock + 32) = 0;
        *v8 = 0;
        v7 = v8;
      }
      else
      {
        v7 = 0;
      }
      if ( !v7 )
        break;
      survarium::loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::~loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>(
        (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)v7
      + 4);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v7
      + 3);
    }
    survarium::loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::~loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>((survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)(m_lock + 220));
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(m_lock + 216));
    *(_DWORD *)(m_lock + 40) = *(_DWORD *)(m_lock + 36);
  }
  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))resource->~vostok::resources::resource_base)(
    resource,
    0);
  vostok::memory::doug_lea_allocator::free_impl(v10, (int)survarium::g_allocator, (char *)resource, v11, v12, v13);
}
