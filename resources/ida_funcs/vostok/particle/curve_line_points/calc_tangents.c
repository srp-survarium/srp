void __thiscall vostok::particle::curve_line_points<vostok::math::float3_pod,0>::calc_tangents(
        vostok::particle::curve_line_points<vostok::math::float3_pod,0> *this)
{
  vostok::math::float3 *v1; // esi
  vostok::math::float3 *v2; // eax
  vostok::math::float3 *v3; // eax
  vostok::math::float3 *v4; // eax
  vostok::particle::curve_point<vostok::math::float3_pod> *left; // [esp+8h] [ebp-4Ch]
  vostok::particle::curve_point<vostok::math::float3_pod> *right; // [esp+Ch] [ebp-48h]
  vostok::particle::curve_point<vostok::math::float3_pod> *v8; // [esp+10h] [ebp-44h]
  vostok::math::float3 v9; // [esp+14h] [ebp-40h] BYREF
  float value; // [esp+20h] [ebp-34h] BYREF
  vostok::math::float3 v11; // [esp+24h] [ebp-30h] BYREF
  vostok::math::float3 v12; // [esp+30h] [ebp-24h] BYREF
  vostok::math::float3 v13; // [esp+3Ch] [ebp-18h] BYREF
  vostok::math::float3_pod *tangent_out; // [esp+48h] [ebp-Ch]
  vostok::math::float3_pod *tangent_in; // [esp+4Ch] [ebp-8h]
  unsigned int i; // [esp+50h] [ebp-4h]

  for ( i = 0; i < this->num_points; ++i )
  {
    tangent_in = &this->points.pointer[i].tangent_in;
    tangent_out = &this->points.pointer[i].tangent_out;
    if ( i )
    {
      if ( i >= this->num_points - 1 )
      {
        vostok::memory::zero(tangent_in, 0xCu);
      }
      else
      {
        left = &this->points.pointer[i + 1];
        right = &this->points.pointer[i];
        v8 = &this->points.pointer[i - 1];
        value = FLOAT_0_5;
        v1 = vostok::math::operator-(&right->upper_value, &left->upper_value, &v13);
        v2 = vostok::math::operator-(&v8->upper_value, &right->upper_value, &v12);
        v3 = vostok::math::operator+(v1, v2, &v11);
        v4 = vostok::math::operator*(v3, &v9, &value);
        *tangent_in = v4->vostok::math::float3_pod;
        *tangent_out = *tangent_in;
      }
    }
    else
    {
      vostok::memory::zero(tangent_out, 0xCu);
    }
  }
}
