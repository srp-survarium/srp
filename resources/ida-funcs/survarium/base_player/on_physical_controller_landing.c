void __thiscall survarium::base_player::on_physical_controller_landing(
        survarium::base_player *this,
        float vertical_speed)
{
  float fatal_vertical_speed; // xmm0_4
  char *v4; // edx
  float harmless_vertical_speed; // xmm2_4
  char *v6; // edx
  _BYTE v7[76]; // [esp+18h] [ebp-70h] BYREF
  vostok::buffer_string v8[2]; // [esp+64h] [ebp-24h] BYREF
  float v9; // [esp+84h] [ebp-4h]
  char *v10; // [esp+90h] [ebp+8h]
  char *v11; // [esp+90h] [ebp+8h]

  fatal_vertical_speed = this->m_fall_params.fatal_vertical_speed;
  if ( vertical_speed <= fatal_vertical_speed )
  {
    harmless_vertical_speed = this->m_fall_params.harmless_vertical_speed;
    if ( vertical_speed > harmless_vertical_speed )
    {
      v9 = (float)(s_bm_current_air_resistance
                 - (float)((float)(fatal_vertical_speed - COERCE_FLOAT(LODWORD(vertical_speed) & 0x7FFFFFFF))
                         / (float)(fatal_vertical_speed - harmless_vertical_speed)))
         * this->m_fall_params.fatal_damage;
      vostok::collision::bone_collision_data::bone_collision_data(
        (vostok::collision::bone_collision_data *)this,
        (int)v7,
        (char *)uri,
        (char *)uri);
      v11 = (char *)damage_parts;
      do
      {
        v6 = *(char **)v11;
        if ( v8[0].m_begin != *(char **)v11 )
        {
          v8[0].m_end = v8[0].m_begin;
          *v8[0].m_begin = 0;
          vostok::buffer_string::operator+=(v8, v6);
        }
        ((void (__thiscall *)(survarium::hit_receiver *, unsigned int, survarium::hit_initiator *, _BYTE *, int, _DWORD, _DWORD, _DWORD, _DWORD))this->hit)(
          &this->survarium::hit_receiver,
          this->m_current_time_in_ms,
          &this->survarium::hit_initiator,
          v7,
          1,
          LODWORD(v9),
          0.0,
          0,
          0);
        v11 += 4;
      }
      while ( v11 != "usable_objects_detection_distance" );
    }
  }
  else
  {
    vostok::collision::bone_collision_data::bone_collision_data(
      (vostok::collision::bone_collision_data *)this,
      (int)v7,
      (char *)uri,
      (char *)uri);
    v10 = (char *)damage_parts;
    do
    {
      v4 = *(char **)v10;
      if ( v8[0].m_begin != *(char **)v10 )
      {
        v8[0].m_end = v8[0].m_begin;
        *v8[0].m_begin = 0;
        vostok::buffer_string::operator+=(v8, v4);
      }
      ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->hit)(
        &this->survarium::hit_receiver,
        this->m_current_time_in_ms,
        &this->survarium::hit_initiator,
        v7,
        1,
        this->m_fall_params.fatal_damage,
        0.0,
        0,
        0);
      v10 += 4;
    }
    while ( v10 != "usable_objects_detection_distance" );
  }
}
