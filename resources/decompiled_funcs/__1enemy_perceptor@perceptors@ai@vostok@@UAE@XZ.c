void __thiscall vostok::ai::perceptors::enemy_perceptor::~enemy_perceptor(
        vostok::ai::perceptors::enemy_perceptor *this)
{
  this->__vftable = (vostok::ai::perceptors::enemy_perceptor_vtbl *)&vostok::ai::perceptors::enemy_perceptor::`vftable';
  vostok::ai::brain_unit::unsubscribe_from_sensors_events(this->m_brain_unit, &this->m_subscription);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&this->m_subscription);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_subscription);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_next);
}
