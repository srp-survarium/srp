char __thiscall vostok::ai::planning::specified_action::specify(
        vostok::ai::planning::specified_action *this,
        const vostok::ai::planning::generalized_action *prototype,
        const vostok::fixed_vector<unsigned int,4> *parameters)
{
  unsigned int *end; // [esp+30h] [ebp-10h] BYREF
  char v6; // [esp+37h] [ebp-9h]
  unsigned int j; // [esp+38h] [ebp-8h]
  unsigned int i; // [esp+3Ch] [ebp-4h]

  v6 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_prototype = prototype;
  end = parameters->m_end;
  vostok::buffer_vector<unsigned int>::assign<unsigned int const *>(
    &this->m_parameters_instances,
    parameters->m_begin,
    (const unsigned int *const *)&end);
  for ( i = 0; i < prototype->m_preconditions._M_impl._M_finish - prototype->m_preconditions._M_impl._M_start; ++i )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&prototype->m_preconditions);
    if ( !vostok::ai::planning::specified_action::specify_property(
            this,
            (survarium::game_camera *)&prototype->m_preconditions._M_impl._M_start[i],
            &this->m_preconditions) )
      return 0;
  }
  for ( j = 0; j < prototype->m_effects._M_impl._M_finish - prototype->m_effects._M_impl._M_start; ++j )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&prototype->m_effects);
    if ( !vostok::ai::planning::specified_action::specify_property(
            this,
            (survarium::game_camera *)&prototype->m_effects._M_impl._M_start[j],
            &this->m_effects) )
      return 0;
  }
  return 1;
}
