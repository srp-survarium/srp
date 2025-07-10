void __thiscall survarium::booby_trap_core::tick(
        survarium::booby_trap_core *this,
        boost::intrusive::rbtree_node<void *> *time_delta_ms,
        survarium::game_camera *current_time_ms)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( this->grm_satisfaction_tree_hook.right_ )
  {
    if ( this->grm_satisfaction_tree_hook.right_ > time_delta_ms )
      this->grm_satisfaction_tree_hook.right_ = (boost::intrusive::rbtree_node<void *> *)((char *)this->grm_satisfaction_tree_hook.right_
                                                                                        - (unsigned int)time_delta_ms);
    else
      survarium::booby_trap_core::on_state_timer_finished((survarium::booby_trap_core *)((char *)this - 292));
  }
  if ( this->m_parent_resources.m_first == (vostok::resources::resource_link *)1 )
    survarium::collision_sensor::tick((survarium::collision_sensor *)this, (unsigned int)time_delta_ms, current_time_ms);
}
