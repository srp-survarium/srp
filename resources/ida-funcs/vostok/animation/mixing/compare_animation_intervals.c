int __fastcall vostok::animation::mixing::compare_animation_intervals(
        const vostok::animation::mixing::n_ary_tree_animation_node *left,
        const vostok::animation::mixing::n_ary_tree_animation_node *right)
{
  unsigned int m_animation_intervals_count; // eax
  unsigned int v3; // esi
  unsigned int m_start_cycle_interval_id; // esi
  unsigned int v6; // edi
  const vostok::animation::mixing::animation_interval *m_animation_intervals; // ecx
  const vostok::animation::mixing::animation_interval *v8; // edx
  const vostok::animation::mixing::animation_interval *v9; // eax
  float *i; // esi
  unsigned int v11; // edi
  unsigned int m_animation_id; // ebx
  float m_start_time; // xmm0_4
  float v14; // xmm0_4

  m_animation_intervals_count = left->m_animation_intervals_count;
  v3 = right->m_animation_intervals_count;
  if ( v3 > m_animation_intervals_count )
    return 1;
  if ( v3 < m_animation_intervals_count )
    return 2;
  m_start_cycle_interval_id = left->m_start_cycle_interval_id;
  v6 = right->m_start_cycle_interval_id;
  if ( v6 > m_start_cycle_interval_id )
    return 1;
  if ( v6 < m_start_cycle_interval_id )
    return 2;
  m_animation_intervals = left->m_animation_intervals;
  v8 = right->m_animation_intervals;
  v9 = &m_animation_intervals[m_animation_intervals_count];
  if ( m_animation_intervals == v9 )
    return 0;
  for ( i = &v8->m_start_time; ; i += 5 )
  {
    v11 = *((_DWORD *)i - 1);
    m_animation_id = m_animation_intervals->m_animation_id;
    if ( v11 > m_animation_id )
      return 1;
    if ( v11 >= m_animation_id )
    {
      m_start_time = m_animation_intervals->m_start_time;
      if ( *i > m_start_time || m_start_time <= *i && i[1] > m_animation_intervals->m_length )
        return 1;
    }
    if ( v11 < m_animation_id )
      break;
    v14 = m_animation_intervals->m_start_time;
    if ( v14 > *i || *i <= v14 && m_animation_intervals->m_length > i[1] )
      break;
    if ( ++m_animation_intervals == v9 )
      return 0;
  }
  return 2;
}
