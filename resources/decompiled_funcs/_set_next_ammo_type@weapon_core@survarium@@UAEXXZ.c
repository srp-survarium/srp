void __thiscall survarium::weapon_core::set_next_ammo_type(survarium::weapon_core *this)
{
  survarium::inventory_item *v1; // ecx
  survarium::inventory *inventory; // eax
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *v3; // eax
  survarium::inventory *v4; // eax
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v5; // eax
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *object; // [esp+8h] [ebp-2Ch]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base> result; // [esp+2Ch] [ebp-8h] BYREF
  survarium::profile_slot_enum next_slot; // [esp+30h] [ebp-4h]

  next_slot = max_slots_count;
  if ( this->m_ammo_slot == survarium::weapon_core::get_ammo_slot(this, first_ammo) )
  {
    next_slot = survarium::weapon_core::get_ammo_slot(this, second_ammo);
  }
  else
  {
    if ( this->m_ammo_slot != survarium::weapon_core::get_ammo_slot(this, second_ammo) )
      return;
    next_slot = survarium::weapon_core::get_ammo_slot(this, first_ammo);
  }
  inventory = survarium::inventory_item::get_inventory(v1, (int)this);
  v3 = survarium::inventory::item_in_slot((survarium::inventory *)next_slot, (int)inventory);
  if ( !vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator==(
          &v3->vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>,
          0) )
  {
    survarium::weapon_core::unload_ammo(this);
    this->m_ammo_slot = next_slot;
    v4 = survarium::inventory_item::get_inventory(&this->survarium::inventory_item, (int)this);
    v5 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)survarium::inventory::item_in_slot((survarium::inventory *)this->m_ammo_slot, (int)v4);
    object = (vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base> *)&result, v5);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
      (vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_ammunition,
      object);
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result);
    this->m_target = weapon_target_reload;
  }
}
