void __thiscall survarium::weapon_core_throw_grenade_state::attach_grenade(
        survarium::weapon_core_throw_grenade_state *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> a2)
{
  vostok::particle::particle_system_instance_impl *m_object; // ebx
  int v3; // eax
  vostok::particle::particle_system_instance_impl *v4; // esi
  vostok::particle::particle_system_instance_impl *v5; // edi
  vostok::resources::unmanaged_resource *v6; // eax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v7; // [esp+Ch] [ebp-4h] BYREF

  m_object = a2.m_object;
  v3 = *(_DWORD *)(*(_DWORD *)(LODWORD(a2.m_object->m_lods[0].m_time_fade_in) + 8) + 268);
  v4 = *(vostok::particle::particle_system_instance_impl **)(v3 + 4 * *(_DWORD *)(v3 + 384) + 272);
  v5 = 0;
  v7.m_object = 0;
  if ( v4 )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v7);
    v5 = v4;
    v7.m_object = v4;
    _InterlockedExchangeAdd(&v4->m_reference_count, 1u);
  }
  v6 = 0;
  a2.m_object = 0;
  if ( v5 )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&a2);
    v6 = v5;
    _InterlockedExchangeAdd(&v5->m_reference_count, 1u);
  }
  a2.m_object = (vostok::particle::particle_system_instance_impl *)m_object->m_lods[3].m_template.m_object;
  m_object->m_lods[3].m_template.m_object = v6;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&a2);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v7);
}
