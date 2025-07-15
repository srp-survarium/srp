void __usercall survarium::weapon_core::unload_ammo(
        survarium::weapon_core *this@<ecx>,
        survarium::weapon_core *a2@<esi>)
{
  int m_ammo_in_magazine; // edi
  int m_last_low; // ebx
  int *v4; // eax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v5; // [esp+Ch] [ebp-Ch] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v6; // [esp+10h] [ebp-8h] BYREF
  bool v7; // [esp+17h] [ebp-1h]

  v7 = survarium::weapon_core::ammunition(a2, &v6)->m_object == 0;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v6);
  if ( !v7 )
  {
    m_ammo_in_magazine = a2->m_ammo_in_magazine;
    a2->m_ammo_in_magazine = 0;
    if ( a2->m_is_round_chambered )
    {
      ++m_ammo_in_magazine;
      a2->m_is_round_chambered = 0;
    }
    m_last_low = LOWORD(survarium::weapon_core::ammunition(a2, &v5)->m_object->m_lods[0].m_emitter_instance_list.m_last);
    v4 = (int *)survarium::weapon_core::ammunition(a2, &v6);
    survarium::inventory_item::set_amount((survarium::inventory_item *)(m_last_low + m_ammo_in_magazine), *v4);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v6);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v5);
  }
}
