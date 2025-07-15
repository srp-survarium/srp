void __thiscall survarium::weapon_recoil_calculator::weapon_recoil_calculator(
        survarium::weapon_recoil_calculator *this)
{
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    0,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)this);
  this->m_pseudo_random.m_time = *(float *)&FLOAT_0_0;
  vostok::animation::linear_interpolator::linear_interpolator(
    (vostok::animation::linear_interpolator *)&this->m_pseudo_random,
    &this->m_interpolator.__vftable,
    SLODWORD(FLOAT_0_1));
  this->m_weapon = 0;
  LODWORD(this->m_player_recoil_multiplier) = clear_value;
  LODWORD(this->m_player_compensation_multiplier) = clear_value;
  this->m_time_since_shoot = *(float *)&FLOAT_0_0;
  this->m_additive_recoil_timer = *(float *)&FLOAT_0_0;
  this->m_time_since_last_dispersion_change = *(float *)&FLOAT_0_0;
  this->m_vertical_koef = *(float *)&FLOAT_0_0;
  this->m_horizontal_koef = *(float *)&FLOAT_0_0;
  this->m_back_koef = *(float *)&FLOAT_0_0;
  this->m_target_vertical_koef = *(float *)&FLOAT_0_0;
  this->m_target_horizontal_koef = *(float *)&FLOAT_0_0;
  this->m_target_recoil_koef = *(float *)&FLOAT_0_0;
  this->m_last_time_in_ms = 0;
}
