void __thiscall vostok::buffer_vector<vostok::ai::planning::action_parameter *>::erase(
        vostok::buffer_vector<vostok::ai::planning::action_parameter *> *this,
        vostok::ai::planning::action_parameter ***begin,
        vostok::ai::planning::action_parameter ***end)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  survarium::game_camera *v6; // ecx
  vostok::ai::planning::action_parameter **k; // [esp+8h] [ebp-24h]
  vostok::ai::planning::action_parameter **v9; // [esp+Ch] [ebp-20h]
  vostok::ai::planning::action_parameter **j; // [esp+18h] [ebp-14h]
  vostok::ai::planning::action_parameter **i; // [esp+1Ch] [ebp-10h]
  unsigned int size; // [esp+20h] [ebp-Ch]
  unsigned int count; // [esp+28h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v3);
  survarium::weapon_user_dead_state::finalize(v4);
  survarium::weapon_user_dead_state::finalize(v5);
  survarium::weapon_user_dead_state::finalize(v6);
  if ( *begin != *end )
  {
    i = *begin;
    for ( j = *end; j != this->m_end; ++j )
    {
      v9 = (vostok::ai::planning::action_parameter **)operator new(4u, i);
      if ( v9 )
        *v9 = *j;
      ++i;
    }
    count = *end - *begin;
    size = this->m_end - this->m_begin;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    for ( k = &this->m_begin[size - count]; k != this->m_end; ++k )
      ;
    this->m_end = &this->m_begin[size - count];
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  }
}
