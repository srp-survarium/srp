void __thiscall vostok::ai::blackboard::clear(vostok::ai::blackboard *this)
{
  vostok::ai::blackboard::delete_played_animations(this);
  vostok::ai::blackboard::delete_played_sounds(this);
  this->m_current_enemy = 0;
  this->m_current_threat = 0;
  this->m_current_pickup_item = 0;
  this->m_current_disturbance = 0;
  this->m_current_weapon = 0;
  this->m_current_goal = 0;
}
