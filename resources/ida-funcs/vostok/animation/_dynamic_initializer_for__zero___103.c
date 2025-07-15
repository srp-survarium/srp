void vostok::animation::_dynamic_initializer_for__zero___103()
{
  float v0; // xmm0_4
  __int64 v1; // [esp+4h] [ebp-8h]

  zero_103.translation.x = 0.0;
  zero_103.translation.y = 0.0;
  zero_103.translation.z = 0.0;
  v0 = s_bm_current_air_resistance;
  zero_103.rotation.x = 0.0;
  *(_QWORD *)&zero_103.channels[4] = 0;
  *(float *)&v1 = v0;
  *((float *)&v1 + 1) = v0;
  zero_103.scale.x = v0;
  *(_QWORD *)&zero_103.channels[7] = v1;
}
