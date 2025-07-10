void __thiscall survarium::weapon_core::get_ammo_info(survarium::weapon_core *this, survarium::weapon_core *info)
{
  survarium::profile_slot_enum v2; // esi
  survarium::weapon_core *v3; // ecx
  survarium::inventory *ammo_slot; // eax
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *v5; // eax
  survarium::inventory *v6; // eax
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *v7; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v8; // ecx
  const vostok::variant<32> **v9; // eax
  survarium::inventory_item *v10; // ecx
  const vostok::variant<32> **v11; // eax
  survarium::inventory_item *v12; // ecx
  unsigned int v13; // [esp+4h] [ebp-20h]
  unsigned int v14; // [esp+8h] [ebp-1Ch]
  survarium::inventory *inv; // [esp+18h] [ebp-Ch]
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> slot2_itm; // [esp+1Ch] [ebp-8h] BYREF
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> slot1_itm; // [esp+20h] [ebp-4h] BYREF

  v2 = survarium::weapon_core::ammo_slot(this, (int)this);
  v3 = (survarium::weapon_core *)((v2 != survarium::weapon_core::get_ammo_slot(this, first_ammo)) + 1);
  *((_BYTE *)&info->vostok::resources::resource_flags + 14) = (_BYTE)v3;
  *((_WORD *)&info->vostok::resources::resource_flags + 6) = survarium::weapon_core::fire_queue_length(v3, (int)this);
  info->survarium::inventory_item::survarium::interactive_object::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.survarium::inventory_item::survarium::interactive_object::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags = survarium::weapon_core::ammo_in_magazine(info, (int)this);
  inv = this->m_inventory;
  ammo_slot = (survarium::inventory *)survarium::weapon_core::get_ammo_slot(this, first_ammo);
  v5 = survarium::inventory::item_in_slot(ammo_slot, (int)inv);
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
    (vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v5,
    (survarium::inventory **)&slot1_itm);
  v6 = (survarium::inventory *)survarium::weapon_core::get_ammo_slot(this, second_ammo);
  v7 = survarium::inventory::item_in_slot(v6, (int)inv);
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
    (vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v7,
    (survarium::inventory **)&slot2_itm);
  if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator==(
         &slot1_itm.vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>,
         0) )
  {
    v14 = 0;
  }
  else
  {
    v9 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v8, (int)&slot1_itm);
    v14 = survarium::inventory_item::amount(v10, (int)v9);
  }
  info->__vftable = (survarium::weapon_core_vtbl *)v14;
  if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator==(
         &slot2_itm.vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>,
         0) )
  {
    v13 = 0;
  }
  else
  {
    v11 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(0, (int)&slot2_itm);
    v13 = survarium::inventory_item::amount(v12, (int)v11);
  }
  info->type = v13;
  *((_BYTE *)&info->vostok::resources::resource_flags + 15) = this->m_is_round_chambered;
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&slot2_itm);
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&slot1_itm);
}
