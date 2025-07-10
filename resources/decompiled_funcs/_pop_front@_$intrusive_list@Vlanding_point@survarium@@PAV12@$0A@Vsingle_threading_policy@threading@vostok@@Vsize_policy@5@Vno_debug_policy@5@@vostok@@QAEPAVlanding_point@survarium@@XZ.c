vostok::ai::planning::generalized_action *__thiscall vostok::intrusive_list<survarium::landing_point,survarium::landing_point *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front(
        vostok::intrusive_list<vostok::ai::planning::generalized_action,vostok::ai::planning::generalized_action *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this)
{
  BOOL v1; // ecx
  vostok::ai::planning::generalized_action *result; // [esp+18h] [ebp-8h]

  v1 = this->m_first == 0;
  if ( v1 )
    return 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v1);
  if ( this->m_first )
  {
    vostok::size_policy::decrement_size(this, this);
    result = this->m_first;
    this->m_first = result->next;
    if ( !this->m_first )
      this->m_last = 0;
    result->next = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)result);
    return result;
  }
  else
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    return 0;
  }
}
