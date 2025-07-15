void __thiscall vostok::ai::blackboard::~blackboard(vostok::ai::blackboard *this)
{
  vostok::threading::mutex *v1; // ecx
  vostok::threading::mutex *v2; // ecx

  vostok::ai::blackboard::clear(this);
  vostok::threading::mutex::~mutex(v1, (_RTL_CRITICAL_SECTION *)&this->m_played_sounds.vostok::threading::mutex);
  vostok::threading::mutex::~mutex(v2, (_RTL_CRITICAL_SECTION *)&this->m_played_animations.vostok::threading::mutex);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
