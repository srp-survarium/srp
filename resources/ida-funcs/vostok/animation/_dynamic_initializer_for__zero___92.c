void vostok::animation::_dynamic_initializer_for__zero___92()
{
  float v0; // xmm0_4
  __int64 v1; // [esp+4h] [ebp-8h]

  zero_92.translation.x = 0.0;
  zero_92.translation.y = 0.0;
  zero_92.translation.z = 0.0;
  v0 = s_bm_current_air_resistance;
  zero_92.rotation.x = 0.0;
  *(_QWORD *)&zero_92.channels[4] = 0;
  *(float *)&v1 = v0;
  *((float *)&v1 + 1) = v0;
  zero_92.scale.x = v0;
  *(_QWORD *)&zero_92.channels[7] = v1;
}
