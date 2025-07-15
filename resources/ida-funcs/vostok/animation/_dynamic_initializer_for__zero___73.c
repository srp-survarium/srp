void vostok::animation::_dynamic_initializer_for__zero___73()
{
  float v0; // xmm0_4
  __int64 v1; // [esp+4h] [ebp-8h]

  zero_73.translation.x = 0.0;
  zero_73.translation.y = 0.0;
  zero_73.translation.z = 0.0;
  v0 = s_bm_current_air_resistance;
  zero_73.rotation.x = 0.0;
  *(_QWORD *)&zero_73.channels[4] = 0;
  *(float *)&v1 = v0;
  *((float *)&v1 + 1) = v0;
  zero_73.scale.x = v0;
  *(_QWORD *)&zero_73.channels[7] = v1;
}
