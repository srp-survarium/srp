char __thiscall survarium::artefact_container_core::use_initialize(
        survarium::artefact_container_core *this,
        survarium::game_camera *user)
{
  BOOL v2; // ecx

  v2 = this->m_usable_object_users.m_first == 0;
  if ( !v2 )
    return 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v2);
  vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
    (vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&this->m_usable_object_users,
    user,
    0);
  LODWORD(user->m_inverted_view_matrix.i.x) = this;
  user->m_inverted_view_matrix.i.y = user->m_inverted_view_matrix.i.z;
  return 1;
}
