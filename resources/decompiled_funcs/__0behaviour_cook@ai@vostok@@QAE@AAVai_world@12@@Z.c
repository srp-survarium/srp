void __thiscall vostok::ai::behaviour_cook::behaviour_cook(
        vostok::ai::behaviour_cook *this,
        vostok::ai::ai_world *world)
{
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v2; // [esp-4h] [ebp-Ch] BYREF
  vostok::ai::behaviour_cook *thisa; // [esp+0h] [ebp-8h]

  thisa = this;
  v2.m_flags = (unsigned int)this;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    0,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&v2);
  vostok::resources::translate_query_cook::translate_query_cook(thisa, behaviour_class, reuse_true, 0xFFFFFFFD, v2);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&thisa->m_ai_world);
  thisa->__vftable = (vostok::ai::behaviour_cook_vtbl *)&vostok::ai::behaviour_cook::`vftable';
  thisa->m_ai_world = world;
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>((vostok::render::stage_lights::lights_instance *)&thisa->m_loaded_binary_config);
}
