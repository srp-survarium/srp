void __thiscall survarium::weapon_core::set_next_ammo_type(survarium::weapon_core *this)
{
  unsigned __int8 m_ammunition_slots_count; // dl
  unsigned __int8 *p_m_selected_ammo_id; // eax
  survarium::profile_slot_enum *m_ammunition_slots; // ecx
  int v5; // ebx
  vostok::particle::particle_system_instance_impl *v6; // ebx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v7; // [esp+4h] [ebp-4h] BYREF

  m_ammunition_slots_count = this->m_ammunition_slots_count;
  if ( m_ammunition_slots_count >= 2u )
  {
    p_m_selected_ammo_id = &this->m_selected_ammo_id;
    if ( ++this->m_selected_ammo_id == m_ammunition_slots_count )
      *p_m_selected_ammo_id = 0;
    m_ammunition_slots = this->m_ammunition_slots;
    v5 = 4 * m_ammunition_slots[*p_m_selected_ammo_id] + 272;
    if ( *(survarium::inventory_vtbl **)((char *)&this->m_inventory->survarium::inventory_item::__vftable + v5) )
    {
      survarium::weapon_core::unload_ammo((survarium::weapon_core *)m_ammunition_slots, this);
      v6 = *(vostok::particle::particle_system_instance_impl **)((char *)&this->m_inventory->survarium::inventory_item::__vftable
                                                               + v5);
      v7.m_object = 0;
      if ( v6 )
      {
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v7);
        v7.m_object = v6;
        _InterlockedExchangeAdd(&v6->m_reference_count, 1u);
      }
      vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
        (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v7,
        (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_ammunition);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v7);
      this->m_need_to_auto_reload = 1;
    }
  }
}
