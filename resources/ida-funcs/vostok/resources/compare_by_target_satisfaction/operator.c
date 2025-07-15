bool __fastcall vostok::resources::compare_by_target_satisfaction::operator()(
        const vostok::resources::resource_base *right,
        const vostok::resources::resource_base *left,
        vostok::resources::compare_by_target_satisfaction *this)
{
  float m_target_satisfaction; // xmm0_4
  float v4; // xmm1_4

  m_target_satisfaction = left->m_target_satisfaction;
  v4 = right->m_target_satisfaction;
  if ( v4 > m_target_satisfaction )
    return 1;
  if ( m_target_satisfaction == v4 )
    return left < right;
  return 0;
}
