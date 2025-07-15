void __thiscall survarium::base_player::clear(survarium::base_player *this)
{
  survarium::inventory *m_object; // eax
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *p_m_slots; // edi
  survarium::usable_object *current_object; // ecx
  survarium::usable_object_user_data *p_m_usable_object_user_data; // ebx
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> **p_m_artefact_slots; // [esp+Ch] [ebp-8h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v7; // [esp+10h] [ebp-4h] BYREF

  m_object = this->m_inventory.m_object;
  p_m_slots = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_object->m_slots;
  p_m_artefact_slots = &m_object->m_artefact_slots;
  if ( &m_object->m_slots != (boost::array<vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>,23> *)&m_object->m_artefact_slots )
  {
    do
    {
      vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v7,
        p_m_slots);
      if ( v7.m_object
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        ((void (*)(void))v7.m_object->__vftable[1].log_string)();
      }
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v7);
      ++p_m_slots;
    }
    while ( p_m_slots != (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_m_artefact_slots );
  }
  survarium::player_params_modifiers_container::remove_modifier(
    *(survarium::player_params_modifiers_container **)((char *)&loc_110E8 + (_DWORD)this),
    stamina_spending_speed_modifier,
    (survarium::player_params_modifier *)((char *)this + (_DWORD)&loc_110EA + 2));
  survarium::player_params_modifiers_container::remove_modifier(
    *(survarium::player_params_modifiers_container **)((char *)&loc_110E8 + (_DWORD)this),
    movement_speed_modifier,
    (survarium::player_params_modifier *)((char *)this + (_DWORD)&loc_110F2 + 2));
  current_object = this->m_usable_object_user_data.current_object;
  p_m_usable_object_user_data = &this->m_usable_object_user_data;
  if ( current_object )
    current_object->use_finalize(current_object, p_m_usable_object_user_data);
}
