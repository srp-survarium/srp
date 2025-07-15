void __thiscall survarium::bullet_manager::bullet_functor::bullet_functor(
        survarium::bullet_manager::bullet_functor *this)
{
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this,
    this);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->position);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->direction);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->normal);
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>((vostok::render::stage_lights::lights_instance *)&this->resource);
}
