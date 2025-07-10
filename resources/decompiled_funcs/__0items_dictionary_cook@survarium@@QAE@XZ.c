void __thiscall survarium::items_dictionary_cook::items_dictionary_cook(survarium::items_dictionary_cook *this)
{
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v1; // [esp-4h] [ebp-Ch] BYREF
  survarium::items_dictionary_cook *thisa; // [esp+0h] [ebp-8h]

  thisa = this;
  v1.m_flags = (unsigned int)this;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    0,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&v1);
  vostok::resources::translate_query_cook::translate_query_cook(
    thisa,
    items_dictionary_class,
    reuse_true,
    0xFFFFFFFB,
    v1);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&thisa[1]);
  thisa->__vftable = (survarium::items_dictionary_cook_vtbl *)&survarium::items_dictionary_cook::`vftable';
  vostok::resources::register_cook(thisa);
}
