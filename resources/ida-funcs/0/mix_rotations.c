vostok::math::quaternion *__usercall mix_rotations@<eax>(
        vostok::buffer_vector<stlp_std::pair<vostok::math::float3,float> > *transforms@<eax>,
        vostok::math::quaternion *do_normalization,
        char a3)
{
  stlp_std::pair<vostok::math::float3,float> *m_end; // ebx
  stlp_std::pair<vostok::math::float3,float> *m_begin; // edi
  vostok::math::quaternion *p_result; // esi
  vostok::math::quaternion *v6; // eax
  float *p_y; // esi
  void *v8; // esp
  vostok::math::float3 *p_first; // esi
  int *v10; // eax
  float v11; // xmm0_4
  vostok::buffer_vector<stlp_std::pair<vostok::math::quaternion,float> > *v12; // ecx
  int y_low; // ebx
  int v14; // eax
  long double v15; // rdi
  long double v16; // rdi
  BOOL v17; // ecx
  float v18; // xmm0_4
  float *v19; // eax
  float v20; // xmm0_4
  long double v21; // rdi
  stlp_std::pair<vostok::math::quaternion,float> *t; // [esp+0h] [ebp-84h]
  float *v23[3]; // [esp+4h] [ebp-80h] BYREF
  vostok::math::quaternion v24; // [esp+10h] [ebp-74h] BYREF
  _DWORD v25[2]; // [esp+28h] [ebp-5Ch] BYREF
  vostok::math::quaternion v26; // [esp+30h] [ebp-54h] BYREF
  int v27; // [esp+40h] [ebp-44h] BYREF
  vostok::math::quaternion result; // [esp+44h] [ebp-40h] BYREF
  vostok::math::quaternion v29; // [esp+54h] [ebp-30h] BYREF
  vostok::math::quaternion v30; // [esp+64h] [ebp-20h] BYREF
  vostok::math::float3 value_12; // [esp+74h] [ebp-10h] BYREF
  int v32; // [esp+80h] [ebp-4h]

  m_end = transforms->m_end;
  m_begin = transforms->m_begin;
  if ( transforms->m_begin == m_end )
    goto LABEL_2;
  v8 = alloca(20 * (m_end - m_begin));
  LODWORD(v30.w) = &v23[5 * (m_end - m_begin)];
  p_first = &m_begin->first;
  LODWORD(v30.y) = v23;
  LODWORD(v30.z) = v23;
  v32 = (int)m_begin;
  value_12.z = 0.0;
  do
  {
    if ( !vostok::math::is_similar<float>(&p_first[1].x, &value_12.z, 0.0000099999997) )
    {
      vostok::math::quaternion::quaternion(&t->first, &v26.x, *p_first);
      v27 = *v10;
      LODWORD(result.x) = v10[1];
      v11 = *(float *)(v32 + 12);
      LODWORD(result.y) = v10[2];
      t = (stlp_std::pair<vostok::math::quaternion,float> *)&v27;
      LODWORD(result.z) = v10[3];
      result.w = v11;
      vostok::buffer_vector<stlp_std::pair<vostok::math::quaternion,float>>::push_back(
        v12,
        (const stlp_std::pair<vostok::math::quaternion,float> *)&v30.vector.elements[1],
        (float *)&v27);
    }
    p_first = (vostok::math::float3 *)(v32 + 16);
    v32 = (int)p_first;
  }
  while ( p_first != (vostok::math::float3 *)m_end );
  y_low = LODWORD(v30.y);
  if ( LODWORD(v30.y) == LODWORD(v30.z) )
  {
LABEL_2:
    memset(&v29, 0, 12);
    v29.w = s_bm_current_air_resistance;
    p_result = &v29;
    goto LABEL_3;
  }
  v14 = (LODWORD(v30.z) - LODWORD(v30.y)) / 20;
  if ( v14 != 1 )
  {
    t = (stlp_std::pair<vostok::math::quaternion,float> *)LODWORD(v30.z);
    if ( v14 != 2 )
    {
      vostok::math::weighted_blend(
        do_normalization,
        (const stlp_std::pair<vostok::math::quaternion,float> *)LODWORD(v30.y),
        t);
      return do_normalization;
    }
    v20 = *(float *)(LODWORD(v30.z) - 4);
    value_12.y = *(float *)(LODWORD(v30.y) + 16) + v20;
    vostok::math::slerp(
      &result,
      (const vostok::math::quaternion *)LODWORD(v30.y),
      (const vostok::math::quaternion *)(LODWORD(v30.z) - 20),
      v20 / value_12.y);
    p_result = &result;
    if ( !a3 )
    {
      v29 = result;
      HIDWORD(v21) = &v29;
      LODWORD(v21) = &v30;
      vostok::math::quaternion::get_axis_and_angle(
        &v24,
        &v29.x,
        y_low,
        v21,
        (vostok::math::float3 *)&v30.vector.elements[2],
        v23[0]);
      LODWORD(v29.x) ^= _mask__NegFloat_;
      LODWORD(v29.y) ^= _mask__NegFloat_;
      LODWORD(v29.z) ^= _mask__NegFloat_;
      LODWORD(v29.w) ^= _mask__NegFloat_;
      v26 = v29;
      HIDWORD(v16) = &v30;
      LODWORD(v16) = &v27;
      vostok::math::quaternion::get_axis_and_angle(
        (vostok::math::quaternion *)&v24.vector.elements[3],
        &v26.x,
        y_low,
        v16,
        (vostok::math::float3 *)&v30.vector.elements[3],
        v23[0]);
      v32 = LODWORD(v30.z) & 0x7FFFFFFF;
      LODWORD(value_12.z) = LODWORD(v30.w) & 0x7FFFFFFF;
      v17 = COERCE_FLOAT(LODWORD(v30.w) & 0x7FFFFFFF) <= COERCE_FLOAT(LODWORD(v30.z) & 0x7FFFFFFF);
      v18 = *(&v30.z + v17) * value_12.y;
      v19 = &v24.x + 3 * v17;
      goto LABEL_12;
    }
LABEL_3:
    v6 = do_normalization;
    do_normalization->x = p_result->x;
    p_y = &p_result->y;
    do_normalization->y = *p_y;
    *(_QWORD *)&do_normalization->vector.elements[2] = *(_QWORD *)(p_y + 1);
    return v6;
  }
  p_result = (vostok::math::quaternion *)LODWORD(v30.y);
  if ( a3 )
    goto LABEL_3;
  v30.x = *(float *)LODWORD(v30.y);
  *(_QWORD *)&v30.vector.elements[1] = *(_QWORD *)(LODWORD(v30.y) + 4);
  t = (stlp_std::pair<vostok::math::quaternion,float> *)&value_12;
  v30.w = *(float *)(y_low + 12);
  HIDWORD(v15) = y_low + 16;
  LODWORD(v15) = &value_12;
  vostok::math::quaternion::get_axis_and_angle((vostok::math::quaternion *)v25, &v30.x, y_low, v15, &value_12, v23[0]);
  LODWORD(v30.x) ^= _mask__NegFloat_;
  LODWORD(v30.y) ^= _mask__NegFloat_;
  LODWORD(v30.z) ^= _mask__NegFloat_;
  LODWORD(v30.w) ^= _mask__NegFloat_;
  result = v30;
  HIDWORD(v16) = &value_12;
  LODWORD(v16) = &v29;
  vostok::math::quaternion::get_axis_and_angle(
    (vostok::math::quaternion *)&v26.vector.elements[1],
    &result.x,
    y_low,
    v16,
    (vostok::math::float3 *)&value_12.elements[1],
    v23[0]);
  v32 = LODWORD(value_12.x) & 0x7FFFFFFF;
  LODWORD(value_12.z) = LODWORD(value_12.y) & 0x7FFFFFFF;
  v17 = COERCE_FLOAT(LODWORD(value_12.y) & 0x7FFFFFFF) <= COERCE_FLOAT(LODWORD(value_12.x) & 0x7FFFFFFF);
  v18 = *(&value_12.x + v17) * *(float *)(y_low + 16);
  v19 = (float *)&v25[3 * v17];
LABEL_12:
  vostok::math::quaternion::quaternion(
    (vostok::math::quaternion *)v17,
    v19,
    v16,
    v18,
    (const struct vostok::math::float3 *)do_normalization,
    *(float *)v23);
  return do_normalization;
}
