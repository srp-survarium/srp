void __thiscall survarium::weapon_user_animations_container_cook::weapon_user_animations_container_cook(
        survarium::weapon_user_animations_container_cook *this)
{
  survarium::game_camera *v1; // ecx
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v2; // [esp-4h] [ebp-Ch] BYREF
  survarium::weapon_user_animations_container_cook *thisa; // [esp+0h] [ebp-8h]

  thisa = this;
  v2.m_flags = (unsigned int)this;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    0,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&v2);
  vostok::resources::translate_query_cook::translate_query_cook(
    thisa,
    animation_container_class,
    reuse_true,
    0xFFFFFFFD,
    v2);
  survarium::weapon_user_dead_state::finalize(v1);
  thisa->__vftable = (survarium::weapon_user_animations_container_cook_vtbl *)&survarium::weapon_user_animations_container_cook::`vftable';
}
