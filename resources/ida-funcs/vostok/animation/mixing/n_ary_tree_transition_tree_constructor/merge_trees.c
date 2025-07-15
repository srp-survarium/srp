void __userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::merge_trees(
        const vostok::animation::mixing::n_ary_tree *from@<eax>,
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this,
        vostok::animation::mixing::n_ary_tree_animation_node **to)
{
  float v3; // edx
  unsigned int v4; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v5; // edi
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v6; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v7; // esi
  vostok::animation::mixing::n_ary_tree_animation_node *v8; // ebx
  unsigned int m_weight_synchronization_group_id; // eax
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v10; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v11; // eax
  unsigned int v12; // edi
  vostok::animation::mixing::n_ary_tree_animation_node *v13; // eax
  unsigned int v14; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *v15; // eax
  unsigned int v16; // edi
  unsigned int v17; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *v18; // eax
  unsigned int v19; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *v20; // eax
  unsigned int v21; // edi
  vostok::animation::mixing::n_ary_tree_animation_node *i; // ecx
  unsigned int m_time_synchronization_group_id; // edx
  vostok::animation::mixing::n_ary_tree_animation_node **m_time_driving_animations_begin; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v25; // edi
  void *v26; // esp
  vostok::animation::mixing::n_ary_tree_animation_node *m_weight_root; // eax
  vostok::animation::mixing::n_ary_tree_animation_node **j; // edi
  int v29; // eax
  int k; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node **v31; // eax
  int v32; // ecx
  int v33; // edx
  vostok::animation::mixing::n_ary_tree_animation_node *m_time_root; // ebx
  const vostok::animation::mixing::animation_state_params *m_animation_state; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *m_time_driving_animation; // ecx
  vostok::animation::mixing::animation_state *v37; // esi
  unsigned int animation_interval_id; // edi
  double v39; // st7
  float v40; // xmm0_4
  double v41; // st7
  const vostok::animation::mixing::animation_state *previous; // esi
  vostok::animation::mixing::animation_state *v43; // eax
  BOOL v44; // ecx
  float v45; // [esp+0h] [ebp-3Ch]
  vostok::animation::mixing::n_ary_tree_animation_node *v46; // [esp+14h] [ebp-28h] BYREF
  _BYTE v47[8]; // [esp+18h] [ebp-24h] BYREF
  int initial_event_types; // [esp+20h] [ebp-1Ch]
  float weight; // [esp+24h] [ebp-18h]
  float animation_interval_time; // [esp+28h] [ebp-14h]
  const vostok::animation::mixing::animation_state_params *params; // [esp+2Ch] [ebp-10h]
  float v52; // [esp+30h] [ebp-Ch]
  const vostok::animation::mixing::animation_interval *time_driving_animation_interval; // [esp+34h] [ebp-8h]
  float animation_time_threshold; // [esp+38h] [ebp-4h]
  bool is_freezed; // [esp+48h] [ebp+Ch]

  v3 = *(float *)&from->m_weight_root;
  v4 = *(_DWORD *)(LODWORD(v3) + 56);
  animation_time_threshold = v3;
  *(float *)&v5 = v3;
  do
  {
    if ( v5->m_weight_synchronization_group_id != v4 )
      break;
    v5 = v5->m_next_weight_animation;
  }
  while ( *(float *)&v5 != 0.0 );
  v6 = (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)to;
  v7 = to[1];
  v8 = v7;
  do
  {
    if ( v8->m_weight_synchronization_group_id != v7->m_weight_synchronization_group_id )
      break;
    v8 = v8->m_next_weight_animation;
  }
  while ( v8 );
  while ( v7 )
  {
    m_weight_synchronization_group_id = v7->m_weight_synchronization_group_id;
    v10 = *(vostok::animation::mixing::n_ary_tree_transition_tree_constructor **)(LODWORD(v3) + 56);
    if ( (unsigned int)v10 < m_weight_synchronization_group_id )
    {
      vostok::animation::mixing::n_ary_tree_transition_tree_constructor::remove_weight_synchronization_group(
        v10,
        this,
        (vostok::animation::mixing::n_ary_tree_animation_node *)LODWORD(v3),
        v5);
      animation_time_threshold = *(float *)&v5;
      if ( *(float *)&v5 == 0.0 )
        goto LABEL_33;
      v11 = v5;
      v12 = v5->m_weight_synchronization_group_id;
      do
      {
        if ( v11->m_weight_synchronization_group_id != v12 )
          break;
        v11 = v11->m_next_weight_animation;
      }
      while ( v11 );
      v5 = v11;
      goto LABEL_32;
    }
    if ( (unsigned int)v10 > m_weight_synchronization_group_id )
    {
      vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_weight_synchronization_group(
        v7,
        v10,
        this,
        v8);
      v7 = v8;
      if ( !v8 )
        goto LABEL_32;
      v13 = v8;
      v14 = v8->m_weight_synchronization_group_id;
      do
      {
        if ( v13->m_weight_synchronization_group_id != v14 )
          break;
        v13 = v13->m_next_weight_animation;
      }
      while ( v13 );
      goto LABEL_31;
    }
    vostok::animation::mixing::n_ary_tree_transition_tree_constructor::change_weight_synchronization_group(
      v5,
      (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)v7,
      this,
      (vostok::animation::mixing::n_ary_tree_animation_node *)LODWORD(v3),
      v8);
    animation_time_threshold = *(float *)&v5;
    if ( *(float *)&v5 != 0.0 )
    {
      v15 = v5;
      v16 = v5->m_weight_synchronization_group_id;
      do
      {
        if ( v15->m_weight_synchronization_group_id != v16 )
          break;
        v15 = v15->m_next_weight_animation;
      }
      while ( v15 );
      v5 = v15;
    }
    v7 = v8;
    if ( v8 )
    {
      v13 = v8;
      v17 = v8->m_weight_synchronization_group_id;
      do
      {
        if ( v13->m_weight_synchronization_group_id != v17 )
          break;
        v13 = v13->m_next_weight_animation;
      }
      while ( v13 );
LABEL_31:
      v8 = v13;
    }
LABEL_32:
    if ( animation_time_threshold == 0.0 )
    {
LABEL_33:
      if ( v7 )
      {
        while ( 1 )
        {
          vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_weight_synchronization_group(
            v7,
            v6,
            this,
            v8);
          v7 = v8;
          if ( !v8 )
            break;
          v18 = v8;
          v19 = v8->m_weight_synchronization_group_id;
          do
          {
            if ( v18->m_weight_synchronization_group_id != v19 )
              break;
            v18 = v18->m_next_weight_animation;
          }
          while ( v18 );
          v8 = v18;
        }
      }
      goto LABEL_45;
    }
    v3 = animation_time_threshold;
  }
  if ( v3 != 0.0 )
  {
    while ( 1 )
    {
      vostok::animation::mixing::n_ary_tree_transition_tree_constructor::remove_weight_synchronization_group(
        v6,
        this,
        (vostok::animation::mixing::n_ary_tree_animation_node *)LODWORD(v3),
        v5);
      animation_time_threshold = *(float *)&v5;
      if ( *(float *)&v5 == 0.0 )
        break;
      v20 = v5;
      v21 = v5->m_weight_synchronization_group_id;
      do
      {
        if ( v20->m_weight_synchronization_group_id != v21 )
          break;
        v20 = v20->m_next_weight_animation;
      }
      while ( v20 );
      v3 = animation_time_threshold;
      v5 = v20;
    }
  }
LABEL_45:
  for ( i = this->m_weight_root; i; i = i->m_next_weight_animation )
  {
    m_time_synchronization_group_id = i->m_time_synchronization_group_id;
    if ( m_time_synchronization_group_id != -1 )
    {
      m_time_driving_animations_begin = this->m_time_driving_animations_begin;
      if ( m_time_driving_animations_begin != this->m_time_driving_animations_end )
      {
        while ( 1 )
        {
          v25 = *m_time_driving_animations_begin;
          if ( (*m_time_driving_animations_begin)->m_time_synchronization_group_id == m_time_synchronization_group_id )
            break;
          if ( ++m_time_driving_animations_begin == this->m_time_driving_animations_end )
            goto LABEL_54;
        }
        if ( v25 && v25 != i )
          i->m_time_driving_animation = v25;
      }
    }
LABEL_54:
    ;
  }
  v26 = alloca(4 * this->m_animations_count);
  m_weight_root = this->m_weight_root;
  for ( j = &v46; m_weight_root; ++j )
  {
    *j = m_weight_root;
    m_weight_root = m_weight_root->m_next_weight_animation;
  }
  LOBYTE(to) = 0;
  if ( &v46 != j )
  {
    v29 = j - &v46;
    for ( k = 0; v29 != 1; ++k )
      v29 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::animation::mixing::n_ary_tree_animation_node * *,vostok::animation::mixing::n_ary_tree_animation_node *,int,vostok::animation::mixing::time_animations_predicate>(
      (vostok::animation::mixing::time_animations_predicate)this,
      &v46,
      j,
      0,
      2 * k,
      to);
    stlp_std::priv::__final_insertion_sort<vostok::animation::mixing::n_ary_tree_animation_node * *,vostok::animation::mixing::time_animations_predicate>(
      &v46,
      j,
      0);
  }
  v31 = (vostok::animation::mixing::n_ary_tree_animation_node **)v47;
  this->m_time_root = v46;
  if ( v47 != (_BYTE *)j )
  {
    do
    {
      v32 = (int)*(v31 - 1);
      v33 = (int)*v31++;
      *(_DWORD *)(v32 + 44) = v33;
    }
    while ( v31 != j );
  }
  m_time_root = this->m_time_root;
  if ( m_time_root )
  {
    do
    {
      m_animation_state = (const vostok::animation::mixing::animation_state_params *)m_time_root->m_animation_state;
      initial_event_types = m_animation_state->initial_event_types;
      m_time_driving_animation = m_time_root->m_time_driving_animation;
      params = m_animation_state;
      if ( m_time_driving_animation )
      {
        v37 = m_time_driving_animation->m_animation_state;
        animation_interval_id = v37->animation_interval_id;
        time_driving_animation_interval = &m_time_driving_animation->m_animation_intervals[animation_interval_id];
        v52 = vostok::animation::mixing::animation_interval::length(&m_time_root->m_animation_intervals[animation_interval_id]);
        v39 = vostok::animation::mixing::animation_interval::length(time_driving_animation_interval);
        v40 = 0.0;
        m_animation_state = params;
        v41 = v52 / v39 * v37->animation_interval_time;
      }
      else
      {
        animation_interval_id = m_animation_state->animation_interval_id;
        animation_interval_time = m_animation_state->animation_interval_time;
        v40 = m_animation_state->animation_time_threshold;
        v41 = animation_interval_time;
      }
      previous = m_animation_state->previous;
      animation_time_threshold = v40;
      weight = m_animation_state->weight;
      if ( previous )
        is_freezed = previous->is_freezed;
      else
        is_freezed = 0;
      if ( m_time_root->m_animation_state )
      {
        v45 = v41;
        vostok::animation::mixing::animation_state::animation_state(
          (vostok::animation::mixing::animation_state *)this->m_current_time_in_ms,
          m_time_root,
          this->m_current_time_in_ms,
          initial_event_types,
          animation_interval_id,
          animation_interval_id,
          v45,
          animation_time_threshold,
          weight,
          this->m_channels_head,
          is_freezed);
      }
      v43 = m_time_root->m_animation_state;
      v44 = !v43->event_iterator.m_weight_event_iterator.m_animation
         && v43->event_iterator.m_weight_event_iterator.m_time_in_ms == -1
         && !v43->event_iterator.m_weight_event_iterator.m_event_type;
      v43->are_there_any_weight_transitions = !v44;
      if ( previous )
        vostok::animation::mixing::bone_matrices_computer_data::operator=(
          &m_time_root->m_animation_state->bone_matrices_computer,
          &previous->bone_matrices_computer,
          (vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > *)v44);
      m_time_root = m_time_root->m_next_time_animation;
    }
    while ( m_time_root );
    this->m_time_driving_animations_begin = 0;
    this->m_time_driving_animations_end = 0;
  }
  else
  {
    this->m_time_driving_animations_begin = 0;
    this->m_time_driving_animations_end = 0;
  }
}
