float __userpurge vostok::particle::base_particle::get_linear_lifetime_impl@<st0>(
        vostok::particle::base_particle *this@<ecx>,
        int a2@<eax>,
        float curr_lifetime)
{
  float v3; // xmm1_4
  double v4; // st7
  float v6; // [esp+Ch] [ebp+8h]

  if ( *(float *)(a2 + 252) <= 0.001 )
  {
    v3 = *(float *)(a2 + 204);
    if ( v3 > 0.001 )
    {
      v6 = curr_lifetime / v3;
      v4 = v6;
      vostok::math::floor(v6);
    }
  }
  return v4;
}
