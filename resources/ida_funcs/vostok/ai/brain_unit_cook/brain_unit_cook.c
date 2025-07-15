void __thiscall vostok::ai::brain_unit_cook::brain_unit_cook(
        vostok::ai::brain_unit_cook *this,
        vostok::ai::ai_world *world)
{
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v2; // [esp-4h] [ebp-Ch] BYREF
  vostok::ai::brain_unit_cook *thisa; // [esp+0h] [ebp-8h]

  thisa = this;
  v2.m_flags = (unsigned int)this;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    0,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&v2);
  vostok::resources::translate_query_cook::translate_query_cook(thisa, brain_unit_class, reuse_false, 0xFFFFFFFD, v2);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&thisa->m_ai_world);
  thisa->__vftable = (vostok::ai::brain_unit_cook_vtbl *)&vostok::ai::brain_unit_cook::`vftable';
  thisa->m_ai_world = world;
}
