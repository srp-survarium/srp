int __userpurge survarium::player_speed_parameters::get_speed_multiplier@<xmm0>(
        const unsigned int animation_index@<ecx>,
        const survarium::weapon_user_state_enum user_state@<edx>,
        survarium::player_speed_parameters *this,
        const bool aimed)
{
  int result; // xmm0_4
  int *m_begin; // eax
  float *v6; // eax
  float *v7; // eax

  if ( user_state == type_sprint )
    return *((_DWORD *)this->m_multipliers.m_begin + 12);
  switch ( byte_1C08FD[animation_index] )
  {
    case 0:
      result = LODWORD(s_bm_current_air_resistance);
      break;
    case 1:
      m_begin = (int *)this->m_multipliers.m_begin;
      if ( user_state )
      {
        if ( aimed )
          result = m_begin[9];
        else
          result = m_begin[6];
      }
      else if ( aimed )
      {
        result = m_begin[3];
      }
      else
      {
        result = *m_begin;
      }
      break;
    case 2:
      v6 = this->m_multipliers.m_begin;
      if ( user_state )
      {
        if ( aimed )
          result = *((_DWORD *)v6 + 10);
        else
          result = *((_DWORD *)v6 + 7);
      }
      else if ( aimed )
      {
        result = *((_DWORD *)v6 + 4);
      }
      else
      {
        result = *((_DWORD *)v6 + 1);
      }
      break;
    case 3:
      v7 = this->m_multipliers.m_begin;
      if ( user_state )
      {
        if ( aimed )
          result = *((_DWORD *)v7 + 11);
        else
          result = *((_DWORD *)v7 + 8);
      }
      else if ( aimed )
      {
        result = *((_DWORD *)v7 + 5);
      }
      else
      {
        result = *((_DWORD *)v7 + 2);
      }
      break;
  }
  return result;
}
