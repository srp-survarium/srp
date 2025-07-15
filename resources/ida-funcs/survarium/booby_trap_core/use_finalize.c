void __thiscall survarium::booby_trap_core::use_finalize(
        survarium::booby_trap_core *this,
        survarium::usable_object_user_data *user)
{
  bool v3; // bl
  survarium::booby_trap_core *v4; // ecx

  v3 = user->current_progress == -1;
  user->current_object = 0;
  user->current_progress = -1;
  vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,20,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
    (vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,20,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&this->survarium::collision_sensor::m_collision_geometries_count,
    user);
  if ( v3 )
    survarium::booby_trap_core::switch_to_state(
      (survarium::booby_trap_core *)((char *)this - 52),
      booby_trap_state_disarmed,
      v4);
}
