void __thiscall survarium::game_material_manager_cook::game_material_manager_cook(
        survarium::game_material_manager_cook *this,
        bool server_usage)
{
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v2; // [esp-4h] [ebp-Ch] BYREF
  survarium::game_material_manager_cook *thisa; // [esp+0h] [ebp-8h]

  thisa = this;
  v2.m_flags = (unsigned int)this;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    0,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&v2);
  vostok::resources::translate_query_cook::translate_query_cook(
    thisa,
    game_material_manager_class,
    reuse_true,
    0xFFFFFFFD,
    v2);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&thisa->m_server_usage);
  thisa->__vftable = (survarium::game_material_manager_cook_vtbl *)&survarium::game_material_manager_cook::`vftable';
  thisa->m_server_usage = server_usage;
  vostok::resources::register_cook(thisa);
}
