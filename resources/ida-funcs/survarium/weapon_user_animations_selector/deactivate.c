void __thiscall survarium::weapon_user_animations_selector::deactivate(
        survarium::weapon_user_animations_selector *this)
{
  int v1; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  const vostok::variant<32> **v3; // eax

  vostok::ai::fsm::set_initial_state(&this->m_logic, 0);
  ((void (__thiscall *)(survarium::base_player *))this->m_user->unsubscribe_animation_player)(this->m_user);
  v1 = ((int (__thiscall *)(survarium::base_player *, int, survarium::affect_subscriber *))this->m_user->damage_model)(
         this->m_user,
         4,
         &this->m_leg_damaged_subscriber);
  v3 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v2, v1);
  survarium::damage_model::unsubscribe_from_affect(
    (survarium::damage_model *)v3,
    affects_type_concussion,
    (survarium::affect_subscriber *const)this);
}
