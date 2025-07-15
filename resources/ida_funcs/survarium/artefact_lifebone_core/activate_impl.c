void __thiscall survarium::artefact_lifebone_core::activate_impl(survarium::artefact_lifebone_core *this)
{
  survarium::inventory_holder *v1; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  const vostok::variant<32> **v3; // eax
  const char *v4; // [esp-4h] [ebp-24h]
  vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v6; // [esp+Ch] [ebp-14h]
  survarium::body_part_parameters *body_part; // [esp+14h] [ebp-Ch]
  unsigned int i; // [esp+18h] [ebp-8h]
  vostok::resources::resource_ptr<survarium::damage_model,vostok::resources::unmanaged_intrusive_base> dm; // [esp+1Ch] [ebp-4h] BYREF

  v1 = survarium::inventory::holder((survarium::inventory *)this, (int)this->m_inventory);
  v6 = (vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((int (__thiscall *)(survarium::inventory_holder *, survarium::inventory_holder *, survarium::artefact_lifebone_core *))v1->damage_model)(v1, v1, this);
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
    v6,
    (survarium::inventory **)&dm);
  for ( i = 0; i < 4; ++i )
  {
    v4 = protected_body_patrs[i];
    v3 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v2, (int)&dm);
    body_part = survarium::damage_model::get_body_part((survarium::damage_model *)v3, v4);
    survarium::body_part_parameters::reset(body_part);
    v2 = (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)(i + 1);
  }
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&dm);
}
