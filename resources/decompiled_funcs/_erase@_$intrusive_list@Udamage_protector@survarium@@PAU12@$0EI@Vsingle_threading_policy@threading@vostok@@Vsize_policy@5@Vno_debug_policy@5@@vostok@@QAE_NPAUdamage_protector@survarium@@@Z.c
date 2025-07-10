char __thiscall vostok::intrusive_list<survarium::damage_protector,survarium::damage_protector *,72,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
        vostok::intrusive_list<survarium::damage_protector,survarium::damage_protector *,72,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this,
        survarium::damage_protector *object)
{
  BOOL v2; // ecx
  survarium::game_camera *v4; // ecx
  survarium::damage_protector *m_first; // [esp+0h] [ebp-24h]
  survarium::damage_protector *i; // [esp+1Ch] [ebp-8h]
  survarium::damage_protector *previous_i; // [esp+20h] [ebp-4h]

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
