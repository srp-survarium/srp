double __cdecl survarium::fire_animation_time_scale_calculator(
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *reload_animation,
        const survarium::weapon_state_creation_params *params)
{
  return COERCE_FLOAT(survarium::computed_shooting_animation_time_scale(reload_animation, params->rounds_per_second));
}
