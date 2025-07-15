void __thiscall survarium::damage_zone::draw(survarium::damage_zone *this)
{
  int v2; // ebx
  int m_reconstruction_info_actuality_tick; // eax
  survarium::damage_zone *v4; // esi
  survarium::damage_zone *v5; // ecx
  survarium::damage_zone *v6; // ecx

  if ( LOBYTE(this[-1].m_distance_curve.curve_value_max) )
    v2 = (BYTE1(this[-1].m_effects.elems[18].m_object) != 0) + 1;
  else
    v2 = 0;
  m_reconstruction_info_actuality_tick = this->m_reconstruction_info_actuality_tick;
  if ( m_reconstruction_info_actuality_tick != v2 )
  {
    if ( m_reconstruction_info_actuality_tick )
    {
      if ( m_reconstruction_info_actuality_tick == 2 )
        survarium::damage_zone::stop_hitting_fx(this, (int)&this[-1].m_parent_resources.m_last);
    }
    else
    {
      v4 = (survarium::damage_zone *)((char *)this - 552);
      survarium::damage_zone::activated_fx(this, (survarium::damage_zone *)((char *)this - 552));
      survarium::damage_zone::start_idle_fx(v5, v4);
    }
    if ( v2 )
    {
      if ( v2 == 2 )
        survarium::damage_zone::start_hitting_fx(this, (survarium::damage_zone *)((char *)this - 552));
    }
    else
    {
      survarium::damage_zone::stop_idle_fx(this, &this[-1].m_parent_resources.m_last);
      survarium::damage_zone::deactivated_fx(v6, (survarium::damage_zone *)((char *)this - 552));
    }
    LODWORD(this->m_reconstruction_info_actuality_tick) = v2;
  }
}
