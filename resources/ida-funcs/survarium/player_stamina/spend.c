void __usercall survarium::player_stamina::spend(survarium::player_stamina *this@<eax>, float a2@<xmm2>)
{
  float max_value; // xmm0_4
  bool v3; // zf

  if ( a2 >= 0.0 && COERCE_FLOAT(LODWORD(a2) & 0x7FFFFFFF) >= 0.000001 )
  {
    max_value = this->m_value - a2;
    if ( max_value > 0.0 )
    {
      if ( this->m_params.max_value < max_value )
        max_value = this->m_params.max_value;
    }
    else
    {
      max_value = 0.0;
    }
    v3 = !this->m_is_low_stamina;
    this->m_value = max_value;
    if ( v3 && this->m_params.start_low_stamina_value > max_value )
      this->m_is_low_stamina = 1;
    this->m_last_spending_time_in_ms = this->m_current_time_in_ms;
  }
}
