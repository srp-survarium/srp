void __usercall vostok::physics::round_up(float *value@<esi>)
{
  float v1; // [esp+0h] [ebp-8h]
  float v2; // [esp+4h] [ebp-4h]
  float v3; // [esp+4h] [ebp-4h]
  float v4; // [esp+4h] [ebp-4h]

  v2 = *value * 1000.0;
  v1 = v2 + 0.5;
  v3 = (float)(int)vostok::math::floor(v1);
  v4 = v3 * 0.001;
  *value = v4;
}
