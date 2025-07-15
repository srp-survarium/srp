void __usercall vostok::physics::bt_character_controller::set_air_control_vector(
        vostok::physics::bt_character_controller *this@<ecx>,
        const vostok::math::float3 *air_control_vector@<eax>)
{
  char *m_old_controller; // edi
  char *v3; // edi
  float y; // [esp+Ch] [ebp-Ch]
  int v5; // [esp+10h] [ebp-8h]

  y = air_control_vector->y;
  v5 = LODWORD(air_control_vector->z) ^ _mask__NegFloat_;
  if ( s_cc_use_old_controller_value )
    m_old_controller = (char *)this->m_old_controller;
  else
    m_old_controller = (char *)this->m_bt_controller;
  v3 = m_old_controller + 48;
  *(float *)v3 = air_control_vector->x;
  v3 += 4;
  *(float *)v3 = y;
  v3 += 4;
  *(_DWORD *)v3 = v5;
  *((_DWORD *)v3 + 1) = 0;
}
