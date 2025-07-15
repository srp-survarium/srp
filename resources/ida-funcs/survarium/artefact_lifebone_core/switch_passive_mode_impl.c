void __thiscall survarium::artefact_lifebone_core::switch_passive_mode_impl(
        survarium::artefact_lifebone_core *this,
        bool switch_on)
{
  survarium::inventory_holder *v2; // eax
  const vostok::variant<32> **v3; // eax
  const vostok::variant<32> **v4; // eax
  const vostok::variant<32> **v5; // eax
  const char *v6; // [esp-8h] [ebp-24h]
  const char *v7; // [esp-8h] [ebp-24h]
  const char *v8; // [esp-8h] [ebp-24h]
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v9; // [esp-4h] [ebp-20h]
  vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v11; // [esp+Ch] [ebp-10h]
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *j; // [esp+10h] [ebp-Ch]
  unsigned int i; // [esp+14h] [ebp-8h]
  vostok::resources::resource_ptr<survarium::damage_model,vostok::resources::unmanaged_intrusive_base> dm; // [esp+18h] [ebp-4h] BYREF

  v2 = survarium::inventory::holder((survarium::inventory *)this, (int)this->m_inventory);
  v11 = (vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((int (__thiscall *)(survarium::inventory_holder *, survarium::inventory_holder *))v2->damage_model)(v2, v2);
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
    v11,
    (survarium::inventory **)&dm);
  if ( switch_on )
  {
    for ( i = 0; i < 4; ++i )
    {
      v9 = (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)protected_affects[i];
      v6 = protected_body_patrs[i];
      v3 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v9, (int)&dm);
      survarium::damage_model::cancel_affect(
        (survarium::damage_model *)v3,
        v6,
        (const survarium::hit_affects_type_enum)v9);
      v7 = protected_body_patrs[i];
      v4 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
             (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)i,
             (int)&dm);
      survarium::damage_model::register_body_part_damage_protector(
        (survarium::damage_model *)v4,
        v7,
        &this->m_damage_protectors[i]);
    }
  }
  else
  {
    for ( j = 0;
          (unsigned int)j < 4;
          j = (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)((char *)j + 1) )
    {
      v8 = protected_body_patrs[(_DWORD)j];
      v5 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(j, (int)&dm);
      survarium::damage_model::unregister_body_part_damage_protector(
        (survarium::damage_model *)v5,
        v8,
        &this->m_damage_protectors[(_DWORD)j]);
    }
  }
  this->m_passive_mode = switch_on;
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&dm);
}
