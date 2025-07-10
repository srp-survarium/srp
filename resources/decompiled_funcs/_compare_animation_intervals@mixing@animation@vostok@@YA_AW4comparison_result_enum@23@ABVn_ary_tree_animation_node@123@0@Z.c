int __fastcall vostok::animation::mixing::compare_animation_intervals(
        const vostok::animation::mixing::n_ary_tree_animation_node *right,
        const vostok::animation::mixing::n_ary_tree_animation_node *left)
{
  unsigned int m_animation_intervals_count; // eax
  unsigned int v3; // esi
  unsigned int m_start_cycle_interval_id; // esi
  unsigned int v6; // edi
  const vostok::animation::mixing::animation_interval *m_animation_intervals; // edi
  const vostok::animation::mixing::animation_interval *v8; // esi
  const vostok::animation::mixing::animation_interval *v9; // ebx

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
  while ( 1 )
  {
    if ( vostok::animation::mixing::operator<(m_animation_intervals, v8) )
      return 1;
    if ( vostok::animation::mixing::operator>(m_animation_intervals, v8) )
      break;
    ++m_animation_intervals;
    ++v8;
    if ( m_animation_intervals == v9 )
      return 0;
  }
  return 2;
}
