double __cdecl survarium::reload_animation_time_scale_calculator(
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *reload_animation,
        const survarium::weapon_state_creation_params *params)
{
  return survarium::computed_reload_animation_time_scale(reload_animation, params->reload_time);
}
