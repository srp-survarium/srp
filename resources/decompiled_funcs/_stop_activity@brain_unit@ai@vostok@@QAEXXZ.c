void __thiscall vostok::ai::brain_unit::stop_activity(vostok::ai::brain_unit *this)
{
  vostok::ai::clear_targets_predicate pred; // [esp+17h] [ebp-1h] BYREF

  this->m_is_activity_suspended = 1;
  if ( this->m_current_sound )
    vostok::ai::brain_unit::on_finish_sound_playing(this);
  vostok::ai::blackboard::clear(&this->m_blackboard);
  vostok::ai::planning::goal_selector::finalize(this->m_goal_selector);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&pred);
  vostok::intrusive_list<vostok::ai::selectors::target_selector_base,vostok::ai::selectors::target_selector_base *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::ai::clear_targets_predicate>(
    &this->m_target_selectors,
    &pred);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&pred);
}
