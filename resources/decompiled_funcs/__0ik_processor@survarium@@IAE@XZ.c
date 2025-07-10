void __thiscall survarium::ik_processor::ik_processor(survarium::ik_processor *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_skeleton = 0;
  this->m_last_time_in_ms = 0;
}
