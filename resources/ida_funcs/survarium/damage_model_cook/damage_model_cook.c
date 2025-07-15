void __thiscall survarium::damage_model_cook::damage_model_cook(survarium::damage_model_cook *this)
{
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v1; // [esp-4h] [ebp-Ch] BYREF
  survarium::damage_model_cook *thisa; // [esp+0h] [ebp-8h]

  thisa = this;
  v1.m_flags = (unsigned int)this;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    0,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&v1);
  vostok::resources::translate_query_cook::translate_query_cook(thisa, damage_model_class, reuse_false, 0xFFFFFFFD, v1);
  thisa->__vftable = (survarium::damage_model_cook_vtbl *)&survarium::damage_model_cook::`vftable';
  vostok::resources::register_cook(thisa);
}
