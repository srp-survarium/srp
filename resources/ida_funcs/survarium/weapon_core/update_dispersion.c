void __thiscall survarium::weapon_core::update_dispersion(
        survarium::weapon_core *this,
        bool is_moving,
        unsigned int current_time_in_ms)
{
  const vostok::resources::resource_ptr<survarium::damage_model,vostok::resources::unmanaged_intrusive_base> *v3; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  survarium::weapon_user_state_enum current_state_id; // eax
  bool is_aimed; // [esp-10h] [ebp-20h]
  unsigned __int8 v7; // [esp-Ch] [ebp-1Ch]
  bool m_is_double_handed; // [esp-8h] [ebp-18h]
  const vostok::variant<32> **v10; // [esp+8h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = this->m_user->damage_model(this->m_user);
  v10 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v4, (int)v3);
  m_is_double_handed = this->m_is_double_handed;
  v7 = *((_BYTE *)v10 + 827) + *((_BYTE *)v10 + 826);
  is_aimed = survarium::weapon_core::is_aimed((survarium::weapon_core *)m_is_double_handed, (int)this);
  current_state_id = survarium::weapon_user_animations_selector::get_current_state_id(&this->m_user_animations_selector);
  survarium::dispersion_calculator::tick(
    &this->m_dispersion_calculator,
    current_state_id,
    is_moving,
    is_aimed,
    v7,
    m_is_double_handed,
    current_time_in_ms);
}
