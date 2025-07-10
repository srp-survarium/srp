char __thiscall vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
        vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::ai::sensed_visual_object *object)
{
  BOOL v2; // ecx
  survarium::game_camera *v4; // ecx
  vostok::ai::sensed_visual_object *m_first; // [esp+0h] [ebp-24h]
  vostok::ai::sensed_visual_object *i; // [esp+1Ch] [ebp-8h]
  vostok::ai::sensed_visual_object *previous_i; // [esp+20h] [ebp-4h]

  v2 = this->m_first == 0;
  if ( v2 )
    return 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v2);
  previous_i = 0;
  for ( i = this->m_first; i && i != object; i = i->next )
    previous_i = i;
  if ( i == object )
  {
    vostok::size_policy::decrement_size((vostok::size_policy *)i, this);
    if ( previous_i )
      previous_i->next = i->next;
    else
      this->m_first = i->next;
    v4 = (survarium::game_camera *)i;
    if ( !i->next )
    {
      if ( previous_i )
        m_first = previous_i;
      else
        m_first = this->m_first;
      v4 = (survarium::game_camera *)m_first;
      this->m_last = m_first;
    }
    survarium::weapon_user_dead_state::finalize(v4);
    return 1;
  }
  else
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)i);
    return 0;
  }
}
