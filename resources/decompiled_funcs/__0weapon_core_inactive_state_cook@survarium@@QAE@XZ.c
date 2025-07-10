void __thiscall survarium::weapon_core_inactive_state_cook::weapon_core_inactive_state_cook(
        survarium::weapon_core_inactive_state_cook *this)
{
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v1; // [esp-4h] [ebp-14h] BYREF
  survarium::weapon_core_inactive_state_cook *thisa; // [esp+8h] [ebp-8h]

  thisa = this;
  v1.m_flags = (unsigned int)this;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    0,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&v1);
  vostok::resources::unmanaged_cook::unmanaged_cook(
    thisa,
    weapon_inactive_state_class,
    reuse_false,
    0xFFFFFFFD,
    0xFFFFFFFD,
    v1);
  thisa->__vftable = (survarium::weapon_core_inactive_state_cook_vtbl *)&survarium::weapon_core_inactive_state_cook::`vftable';
  vostok::resources::register_cook(thisa);
}
