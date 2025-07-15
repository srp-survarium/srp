void vostok::animation::_dynamic_initializer_for__zero___91()
{
  float v0; // xmm0_4
  __int64 v1; // [esp+4h] [ebp-8h]

  zero_91.translation.x = 0.0;
  zero_91.translation.y = 0.0;
  zero_91.translation.z = 0.0;
  v0 = s_bm_current_air_resistance;
  zero_91.rotation.x = 0.0;
  *(_QWORD *)&zero_91.channels[4] = 0;
  *(float *)&v1 = v0;
  *((float *)&v1 + 1) = v0;
  zero_91.scale.x = v0;
  *(_QWORD *)&zero_91.channels[7] = v1;
}
