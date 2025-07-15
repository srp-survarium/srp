void __thiscall survarium::weapon_core_inactive_state::on_animation_end(
        survarium::weapon_core_inactive_state *this,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *animation,
        survarium::game_camera *callback_time_in_ms)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(callback_time_in_ms);
}
