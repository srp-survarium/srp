char __thiscall survarium::artefact_container_core::use_finalize(
        survarium::artefact_container_core *this,
        survarium::usable_object_user_data *user)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v2);
  survarium::weapon_user_dead_state::finalize(v3);
  user->current_object = 0;
  user->current_progress = -1;
  vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
    (vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&this->m_usable_object_users,
    (vostok::ai::sensed_visual_object *)user);
  return 1;
}
