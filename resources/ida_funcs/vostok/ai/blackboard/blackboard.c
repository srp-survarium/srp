void __thiscall vostok::ai::blackboard::blackboard(vostok::ai::blackboard *this)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v1; // ecx

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v1, this);
  vostok::threading::mutex::mutex(&this->m_played_animations.vostok::threading::mutex);
  this->m_played_animations.m_first = 0;
  this->m_played_animations.m_last = 0;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this,
    &this->m_played_sounds.m_size);
  vostok::threading::mutex::mutex(&this->m_played_sounds.vostok::threading::mutex);
  this->m_played_sounds.m_first = 0;
  this->m_played_sounds.m_last = 0;
  this->m_current_enemy = 0;
  this->m_current_threat = 0;
  this->m_current_pickup_item = 0;
  this->m_current_disturbance = 0;
  this->m_current_weapon = 0;
  this->m_current_goal = 0;
}
