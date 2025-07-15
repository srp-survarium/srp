void __usercall survarium::weapon_core::load_magazine(
        survarium::weapon_core *this@<ecx>,
        survarium::weapon_core *a2@<esi>)
{
  int m_last_low; // ebx
  int v3; // edi
  unsigned __int16 v4; // ax
  int *v5; // eax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v6; // [esp+8h] [ebp-4h] BYREF

  m_last_low = LOWORD(survarium::weapon_core::ammunition(a2, &v6)->m_object->m_lods[0].m_emitter_instance_list.m_last);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v6);
  v3 = (unsigned __int16)m_last_low;
  v4 = a2->m_magazine_capacity - a2->m_ammo_in_magazine;
  if ( (unsigned __int16)m_last_low >= v4 )
    v3 = v4;
  v5 = (int *)survarium::weapon_core::ammunition(a2, &v6);
  survarium::inventory_item::set_amount((survarium::inventory_item *)(m_last_low - v3), *v5);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v6);
  a2->m_ammo_in_magazine += v3;
  if ( a2->m_chamber_a_round_on_reload )
  {
    --a2->m_ammo_in_magazine;
    a2->m_is_round_chambered = 1;
  }
}
