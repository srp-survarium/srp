vostok::math::float4x4 *__userpurge survarium::weapon::calculate_locator@<eax>(
        survarium::weapon *this@<ecx>,
        int a2@<eax>,
        vostok::math::float4x4 *result,
        const vostok::render::model_locator_item *locator,
        const vostok::math::float4x4 *matrices,
        unsigned int matrices_count)
{
  unsigned __int16 m_bone; // ax
  const vostok::math::float4x4 *p_m_offset; // [esp+0h] [ebp-DCh]
  unsigned __int16 v10; // [esp+18h] [ebp-C4h]
  vostok::math::float4x4 right; // [esp+1Ch] [ebp-C0h] BYREF
  vostok::math::float4x4 left; // [esp+5Ch] [ebp-80h] BYREF
  vostok::math::float4x4 v13; // [esp+9Ch] [ebp-40h] BYREF

  if ( (_S6_0 & 1) == 0 )
  {
    _S6_0 |= 1u;
    vostok::math::create_rotation_y(
      &_S3_4.m_inverted_view_matrix.lines[3].elements[1],
      COERCE_VOSTOK_MATH_FLOAT4X4_(3.1415927));
  }
  m_bone = locator->m_bone;
  p_m_offset = &locator->m_offset;
  v10 = m_bone;
  qmemcpy((void *)&right, (const void *)(a2 + 344), sizeof(right));
  if ( m_bone == 0xFFFF )
  {
    vostok::math::mul4x3(
      &left,
      (const vostok::math::float4x4 *)&_S3_4.m_inverted_view_matrix.lines[3].elements[1],
      p_m_offset);
    vostok::math::mul4x3(result, &left, &right);
  }
  else
  {
    vostok::math::mul4x3(
      &left,
      (const vostok::math::float4x4 *)&_S3_4.m_inverted_view_matrix.lines[3].elements[1],
      p_m_offset);
    vostok::math::mul4x3(&v13, &left, &matrices[v10]);
    vostok::math::mul4x3(result, &v13, &right);
  }
  return result;
}
