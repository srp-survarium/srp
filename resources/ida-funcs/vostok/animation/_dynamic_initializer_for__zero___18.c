void vostok::animation::_dynamic_initializer_for__zero___18()
{
  float v0; // xmm0_4
  __int64 v1; // [esp+4h] [ebp-8h]

  zero_18.translation.x = 0.0;
  zero_18.translation.y = 0.0;
  zero_18.translation.z = 0.0;
  v0 = s_bm_current_air_resistance;
  zero_18.rotation.x = 0.0;
  *(_QWORD *)&zero_18.channels[4] = 0;
  *(float *)&v1 = v0;
  *((float *)&v1 + 1) = v0;
  zero_18.scale.x = v0;
  *(_QWORD *)&zero_18.channels[7] = v1;
}
