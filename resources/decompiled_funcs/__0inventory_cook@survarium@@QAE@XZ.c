void __thiscall survarium::inventory_cook::inventory_cook(survarium::inventory_cook *this)
{
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v1; // [esp-4h] [ebp-Ch] BYREF
  survarium::inventory_cook *thisa; // [esp+0h] [ebp-8h]

  thisa = this;
  v1.m_flags = (unsigned int)this;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    0,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&v1);
  vostok::resources::translate_query_cook::translate_query_cook(thisa, inventory_class, reuse_false, 0xFFFFFFFB, v1);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&thisa[1]);
  thisa->__vftable = (survarium::inventory_cook_vtbl *)&survarium::inventory_cook::`vftable';
  vostok::resources::register_cook(thisa);
  if ( ((int)_S3_4.__vftable & 1) == 0 )
  {
    _S3_4.__vftable = (survarium::game_camera_vtbl *)((int)_S3_4.__vftable | 1);
    survarium::items_cook::items_cook(&s_items_cook);
    atexit(survarium::inventory_cook::inventory_cook_::_2_::_dynamic_atexit_destructor_for__s_items_cook__);
  }
  if ( ((int)_S3_4.__vftable & 2) == 0 )
  {
    _S3_4.__vftable = (survarium::game_camera_vtbl *)((int)_S3_4.__vftable | 2);
    survarium::damage_model_cook::damage_model_cook(&s_damage_model_cook);
    atexit(survarium::inventory_cook::inventory_cook_::_2_::_dynamic_atexit_destructor_for__s_damage_model_cook__);
  }
  if ( ((int)_S3_4.__vftable & 4) == 0 )
  {
    _S3_4.__vftable = (survarium::game_camera_vtbl *)((int)_S3_4.__vftable | 4);
    survarium::weapon_ammunition_cook::weapon_ammunition_cook(&s_weapon_ammunition_cook);
    atexit(survarium::inventory_cook::inventory_cook_::_2_::_dynamic_atexit_destructor_for__s_weapon_ammunition_cook__);
  }
}
