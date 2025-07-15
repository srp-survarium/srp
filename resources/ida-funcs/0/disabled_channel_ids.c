unsigned __int8 __usercall disabled_channel_ids@<al>(
        float target_animation_time@<xmm0>,
        const boost::function<unsigned char __cdecl(void const *)> *animated_object_resolver,
        vostok::animation::mixing::n_ary_tree_animation_node *node,
        const unsigned int animation_interval_id,
        const vostok::animation::mixing::animation_interval *animation_interval_time,
        unsigned int time_in_ms,
        const vostok::animation::mixing::n_ary_tree *tree)
{
  vostok::animation::mixing::n_ary_tree_animation_node *m_time_root; // edi
  unsigned int m_time_synchronization_group_id; // eax
  unsigned int v10; // ecx
  const vostok::animation::mixing::animation_interval *animation_interval_time_low; // xmm0_4
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *p_m_first_view_animation; // eax
  vostok::resources::managed_resource *start_animation_time; // [esp+10h] [ebp-70h]
  char v14; // [esp+2Ah] [ebp-56h]
  unsigned __int8 channel_ids; // [esp+2Bh] [ebp-55h] BYREF
  float target_time; // [esp+2Ch] [ebp-54h] BYREF
  const vostok::animation::mixing::animation_interval *interval; // [esp+30h] [ebp-50h]
  unsigned __int16 event_type[2]; // [esp+34h] [ebp-4Ch] BYREF
  float v19; // [esp+38h] [ebp-48h]
  unsigned int m_time_in_ms; // [esp+3Ch] [ebp-44h]
  vostok::animation::mixing::animation_comparer_predicate v21; // [esp+40h] [ebp-40h] BYREF
  vostok::animation::mixing::n_ary_tree_time_in_ms_calculator v22; // [esp+48h] [ebp-38h] BYREF
  vostok::animation::mixing::n_ary_tree_time_in_ms_calculator v23; // [esp+64h] [ebp-1Ch] BYREF

  vostok::animation::mixing::n_ary_tree_animation_event_iterator::get_nearest_animation_interval_event_time(
    &node->m_animation_intervals[animation_interval_id].m_first_view_animation,
    animation_interval_time,
    float_max_29,
    &target_time,
    event_type,
    &channel_ids,
    0);
  v19 = target_animation_time;
  vostok::animation::mixing::n_ary_tree_time_in_ms_calculator::n_ary_tree_time_in_ms_calculator(
    &v22,
    node,
    LOWORD(target_time),
    time_in_ms,
    *(float *)&animation_interval_time,
    target_animation_time);
  m_time_in_ms = v22.m_time_in_ms;
  if ( v22.m_time_in_ms != time_in_ms )
    return 0;
  v14 = 0;
  if ( (LOBYTE(target_time) & 0x20) == 0 )
    return 0;
  v21.m_animated_object_resolver = animated_object_resolver;
  m_time_root = tree->m_time_root;
  v21.m_use_synchronized_animations = 0;
  v21.m_use_overriding_animations = 0;
  while ( 1 )
  {
    if ( !m_time_root )
      return v14;
    m_time_synchronization_group_id = m_time_root->m_time_synchronization_group_id;
    v10 = node->m_time_synchronization_group_id;
    if ( m_time_synchronization_group_id >= v10 )
    {
      if ( m_time_synchronization_group_id > v10 )
        return v14;
      if ( !m_time_root->m_is_transitting_to_zero )
        break;
    }
LABEL_14:
    m_time_root = m_time_root->m_next_time_animation;
  }
  if ( vostok::animation::mixing::animation_comparer_predicate::operator()(&v21, node, m_time_root) )
  {
    if ( node->m_time_synchronization_group_id != -1 )
    {
      animation_interval_time_low = (const vostok::animation::mixing::animation_interval *)LODWORD(m_time_root->m_animation_state->animation_interval_time);
      interval = animation_interval_time_low;
      LOBYTE(event_type[0]) = 0;
      while ( 1 )
      {
        vostok::animation::mixing::n_ary_tree_animation_event_iterator::get_nearest_animation_interval_event_time(
          &m_time_root->m_animation_intervals[m_time_root->m_animation_state->animation_interval_id].m_first_view_animation,
          interval,
          float_max_29,
          &target_time,
          event_type,
          &channel_ids,
          *(unsigned __int8 **)event_type);
        v19 = *(float *)&animation_interval_time_low;
        vostok::animation::mixing::n_ary_tree_time_in_ms_calculator::n_ary_tree_time_in_ms_calculator(
          &v23,
          m_time_root,
          LOWORD(target_time),
          time_in_ms,
          *(float *)&interval,
          *(float *)&animation_interval_time_low);
        if ( v23.m_time_in_ms != m_time_in_ms )
          break;
        animation_interval_time_low = (const vostok::animation::mixing::animation_interval *)LODWORD(v19);
        if ( *(float *)&interval == v19 )
          break;
        p_m_first_view_animation = &m_time_root->m_animation_intervals[m_time_root->m_animation_state->animation_interval_id].m_first_view_animation;
        start_animation_time = (vostok::resources::managed_resource *)&node->m_animation_intervals[animation_interval_id];
        *(float *)&interval = v19;
        v14 |= convert_channels_ids(
                 p_m_first_view_animation,
                 start_animation_time,
                 (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)start_animation_time,
                 event_type[0]);
      }
    }
    goto LABEL_14;
  }
  return -1;
}
