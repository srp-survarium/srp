void __thiscall survarium::player_logic_sprint_state::initialize(survarium::player_logic_sprint_state *this)
{
  survarium::player_stamina *v1; // eax
  survarium::player_stamina_subscriber *p_m_stamina_subscriber; // [esp-4h] [ebp-134h]

  p_m_stamina_subscriber = &this->m_stamina_subscriber;
  v1 = this->m_user->stamina(this->m_user);
  survarium::player_stamina::subscribe_on_depletion(
    v1,
    (vostok::ai::perceptors::sensors_subscriber *)p_m_stamina_subscriber);
  boost::function0<void>::operator()(&this->m_initialize_callback);
}
