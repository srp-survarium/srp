vostok::math::quaternion *__usercall mix_rotations@<eax>(
        vostok::buffer_vector<stlp_std::pair<vostok::math::float3,float> > *transforms@<eax>,
        vostok::math::quaternion *do_normalization,
        bool do_normalizationa)
{
  float v3; // esi
  stlp_std::pair<vostok::math::float3,float> *m_begin; // edi
  vostok::math::quaternion *result; // eax
  void *v6; // esp
  vostok::math::quaternion *v7; // ecx
  vostok::math::quaternion *v8; // ebx
  vostok::math::quaternion *z_low; // ecx
  _QWORD *v10; // eax
  __int64 v11; // xmm1_8
  float v12; // xmm2_4
  int v13; // eax
  float v14; // xmm0_4
  float w; // xmm0_4
  vostok::math::float3 v16; // [esp-8h] [ebp-4Ch]
  _BYTE v17[12]; // [esp+4h] [ebp-40h] BYREF
  vostok::math::quaternion mix; // [esp+10h] [ebp-34h] BYREF
  int v19; // [esp+20h] [ebp-24h]
  vostok::math::float3 direction; // [esp+24h] [ebp-20h] BYREF
  float angle; // [esp+30h] [ebp-14h] BYREF
  float total_weight; // [esp+34h] [ebp-10h]
  int v23; // [esp+38h] [ebp-Ch]
  float second; // [esp+3Ch] [ebp-8h]
  vostok::math::quaternion *q0; // [esp+40h] [ebp-4h]

  v3 = *(float *)&transforms->m_end;
  m_begin = transforms->m_begin;
  angle = v3;
  if ( m_begin == (stlp_std::pair<vostok::math::float3,float> *)LODWORD(v3) )
    goto LABEL_2;
  v6 = alloca(20 * ((LODWORD(v3) - (int)m_begin) >> 4));
  v7 = (vostok::math::quaternion *)v17;
  q0 = (vostok::math::quaternion *)v17;
  v8 = (vostok::math::quaternion *)v17;
  do
  {
    second = m_begin->second;
    total_weight = second;
    v23 = LODWORD(second) & 0x7FFFFFFF;
    if ( COERCE_FLOAT(LODWORD(second) & 0x7FFFFFFF) >= 0.0000099999997 )
    {
      z_low = (vostok::math::quaternion *)LODWORD(m_begin->first.z);
      *(_QWORD *)&v16.x = *(_QWORD *)&m_begin->first.x;
      LODWORD(v16.z) = z_low;
      vostok::math::quaternion::quaternion(z_low, &mix.x, v16);
      v11 = v10[1];
      v12 = total_weight;
      if ( v8 )
      {
        *(_QWORD *)&v8->x = *v10;
        *(_QWORD *)&v8->vector.elements[2] = v11;
        v8[1].x = v12;
      }
      v3 = angle;
      v7 = q0;
      v8 = (vostok::math::quaternion *)((char *)v8 + 20);
    }
    ++m_begin;
  }
  while ( m_begin != (stlp_std::pair<vostok::math::float3,float> *)LODWORD(v3) );
  if ( v7 == v8 )
  {
LABEL_2:
    result = do_normalization;
    v19 = 0;
    *(_QWORD *)&direction.x = 0;
    LODWORD(direction.z) = clear_value;
    *(_QWORD *)&do_normalization->x = 0;
    *(_QWORD *)&do_normalization->vector.elements[2] = *(_QWORD *)&direction.elements[1];
    return result;
  }
  v13 = ((char *)v8 - (char *)v7) / 20;
  if ( v13 == 1 )
  {
    if ( do_normalizationa )
    {
      result = do_normalization;
      *(_QWORD *)&do_normalization->x = *(_QWORD *)&v7->x;
      *(_QWORD *)&do_normalization->vector.elements[2] = *(_QWORD *)&v7->vector.elements[2];
      return result;
    }
    mix = *v7;
    vostok::math::quaternion::get_axis_and_angle(&mix, &direction, &angle);
    v14 = q0[1].x * angle;
    goto LABEL_14;
  }
  if ( v13 == 2 )
  {
    w = v8[-1].w;
    total_weight = v7[1].x + w;
    slerp_optimized(v7, (vostok::math::quaternion *)((char *)v8 - 20), w / total_weight);
    if ( !do_normalizationa )
    {
      vostok::math::quaternion::get_axis_and_angle(&mix, &direction, &angle);
      v14 = angle * total_weight;
LABEL_14:
      vostok::math::quaternion::quaternion(do_normalization, &direction, v14);
      return do_normalization;
    }
    result = do_normalization;
    *do_normalization = mix;
  }
  else
  {
    extrapolated_slerp(
      (const stlp_std::pair<vostok::math::quaternion,float> *const)v7,
      (const stlp_std::pair<vostok::math::quaternion,float> *const)do_normalization);
    return do_normalization;
  }
  return result;
}
