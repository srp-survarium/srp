void __thiscall survarium::items_cook::items_cook(survarium::items_cook *this)
{
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v1; // [esp-4h] [ebp-Ch] BYREF
  survarium::items_cook *thisa; // [esp+0h] [ebp-8h]

  thisa = this;
  v1.m_flags = (unsigned int)this;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    0,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&v1);
  vostok::resources::translate_query_cook::translate_query_cook(thisa, item_class, reuse_false, 0xFFFFFFFD, v1);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&thisa[1]);
  thisa->__vftable = (survarium::items_cook_vtbl *)&survarium::items_cook::`vftable';
  vostok::resources::register_cook(thisa);
}
