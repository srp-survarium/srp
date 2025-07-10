vostok::ai::planning::action_parameter *__thiscall vostok::ai::planning::goal::get_parameter(
        vostok::ai::planning::goal *this,
        unsigned int index)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return this->m_parameters.m_begin[index];
}
