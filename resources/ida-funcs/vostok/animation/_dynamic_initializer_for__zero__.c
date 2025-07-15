void vostok::animation::_dynamic_initializer_for__zero__()
{
  float v0; // xmm0_4
  __int64 v1; // [esp+4h] [ebp-8h]

  zero.translation.x = 0.0;
  zero.translation.y = 0.0;
  zero.translation.z = 0.0;
  v0 = s_bm_current_air_resistance;
  zero.rotation.x = 0.0;
  *(_QWORD *)&zero.channels[4] = 0;
  *(float *)&v1 = v0;
  *((float *)&v1 + 1) = v0;
  zero.scale.x = v0;
  *(_QWORD *)&zero.channels[7] = v1;
}
