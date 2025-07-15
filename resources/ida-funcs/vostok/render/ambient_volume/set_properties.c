void __usercall vostok::render::ambient_volume::set_properties(
        vostok::render::ambient_volume *this@<eax>,
        vostok::math::aabb *in_properties@<edx>)
{
  const vostok::math::float4x4 *v2; // xmm0_4
  vostok::math::aabb *p_m_aabb; // eax
  __int64 v4; // [esp+4h] [ebp-28h]
  __int128 v5; // [esp+18h] [ebp-14h]

  v2 = clear_value;
  qmemcpy(&this->m_properties, in_properties, sizeof(this->m_properties));
  LODWORD(v4) = v2;
  HIDWORD(v4) = v2;
  LODWORD(v5) = -1082130432;
  p_m_aabb = &this->m_aabb;
  *(_QWORD *)((char *)&v5 + 4) = v4;
  *(_QWORD *)&p_m_aabb->min.x = 0xBF800000BF800000uLL;
  HIDWORD(v5) = v2;
  *(_OWORD *)&p_m_aabb->min.elements[2] = v5;
  vostok::math::aabb::modify(in_properties, p_m_aabb);
}
