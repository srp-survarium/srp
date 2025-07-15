void __usercall survarium::weapon_core::load_ammo(survarium::weapon_core *this@<ecx>, survarium::weapon_core *a2@<eax>)
{
  vostok::particle::particle_system_instance_impl *m_object; // eax
  __int16 m_last; // di
  int m_last_low; // edi
  int *v7; // eax
  unsigned __int16 m_ammo_in_magazine; // ax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp+8h] [ebp-Ch] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v10; // [esp+Ch] [ebp-8h] BYREF
  char v11; // [esp+13h] [ebp-1h]

  v10.m_object = 0;
  if ( !a2->m_ammunition.m_object
    || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    || (v10.m_object = (vostok::particle::particle_system_instance_impl *)1,
        m_object = survarium::weapon_core::ammunition(a2, &v9)->m_object,
        v11 = 1,
        !LOWORD(m_object->m_lods[0].m_emitter_instance_list.m_last)) )
  {
    v11 = 0;
  }
  if ( ((int)v10.m_object & 1) != 0 )
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v9);
  if ( v11 )
  {
    if ( !a2->m_ammo_in_magazine )
      survarium::weapon_core::load_magazine(this, a2);
    if ( a2->m_is_there_chamber_a_round_state && !a2->m_chamber_a_round_on_reload )
    {
      m_last = (__int16)survarium::weapon_core::ammunition(a2, &v9)->m_object->m_lods[0].m_emitter_instance_list.m_last;
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v9);
      if ( m_last )
      {
        a2->m_is_round_chambered = 1;
        m_last_low = LOWORD(survarium::weapon_core::ammunition(a2, &v10)->m_object->m_lods[0].m_emitter_instance_list.m_last);
        v7 = (int *)survarium::weapon_core::ammunition(a2, &v9);
        survarium::inventory_item::set_amount((survarium::inventory_item *)(m_last_low - 1), *v7);
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v9);
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v10);
      }
      else
      {
        m_ammo_in_magazine = a2->m_ammo_in_magazine;
        if ( m_ammo_in_magazine )
        {
          a2->m_is_round_chambered = 1;
          a2->m_ammo_in_magazine = m_ammo_in_magazine - 1;
        }
      }
    }
  }
}
