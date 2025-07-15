void __userpurge vostok::animation::mixing::n_ary_tree_deserializer::resolve_animation_node(
        vostok::animation::mixing::n_ary_tree_deserializer::n_ary_tree_animation_node_helper *node@<eax>,
        vostok::animation::mixing::n_ary_tree_deserializer *this)
{
  vostok::animation::mixing::n_ary_tree_deserializer *v2; // edx
  unsigned int animation_intervals_count; // ecx
  vostok::mutable_buffer *m_buffer; // eax
  vostok::animation::mixing::animation_interval *m_data; // edi
  vostok::animation::mixing::animation_interval *v7; // ebx
  unsigned int animation; // ecx
  vostok::mutable_buffer *v9; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v10; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *m_previous_animation; // eax
  unsigned int v12; // ecx
  unsigned int bones_mask; // eax
  unsigned int time_synchronization_group_id; // edx
  int v15; // eax
  vostok::resources::managed_resource *weight_synchronization_group_id; // ecx
  unsigned int unique_animation_id; // ecx
  bool v18; // zf
  unsigned __int8 time_calculator; // al
  vostok::resources::managed_resource *m_weight_root; // ecx
  unsigned int v21; // ecx
  unsigned int v22; // edx
  int v23; // ecx
  unsigned int v24; // eax
  bool v25; // cl
  vostok::mutable_buffer *v26; // eax
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node **v27; // edi
  unsigned int v28; // ecx
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node **v29; // esi
  unsigned __int8 v30; // [esp-20h] [ebp-54h]
  bool v31; // [esp-10h] [ebp-44h]
  bool v32; // [esp-10h] [ebp-44h]
  unsigned int additivity_priority; // [esp-8h] [ebp-3Ch]
  unsigned int v34; // [esp-8h] [ebp-3Ch]
  unsigned int v35; // [esp-4h] [ebp-38h]
  unsigned int v36; // [esp-4h] [ebp-38h]
  unsigned int operands_count; // [esp+0h] [ebp-34h]
  unsigned int v38; // [esp+0h] [ebp-34h]
  fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> v39; // [esp+18h] [ebp-1Ch] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v40; // [esp+20h] [ebp-14h] BYREF
  vostok::animation::mixing::n_ary_tree_deserializer::n_ary_tree_animation_node_helper *v41; // [esp+24h] [ebp-10h]
  const vostok::animation::mixing::animation_interval *v42; // [esp+28h] [ebp-Ch]
  vostok::animation::mixing::animation_interval *i; // [esp+2Ch] [ebp-8h]

  v2 = this;
  animation_intervals_count = node->animation_intervals_count;
  m_buffer = this->m_buffer;
  animation_intervals_count *= 20;
  m_data = (vostok::animation::mixing::animation_interval *)m_buffer->m_data;
  m_buffer->m_data += animation_intervals_count;
  m_buffer->m_size -= animation_intervals_count;
  v7 = &m_data[node->animation_intervals_count];
  v42 = m_data;
  v41 = node;
  for ( i = m_data;
        i != v7;
        v41 = (vostok::animation::mixing::n_ary_tree_deserializer::n_ary_tree_animation_node_helper *)((char *)v41 + 8) )
  {
    if ( i )
    {
      animation = v41->intervals.elems[0].animation;
      v39.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))v41->intervals.elems[0].animation_interval;
      v40.m_object = 0;
      vostok::animation::mixing::animation_interval::animation_interval(
        i,
        (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v40,
        animation,
        *(float *)&v39.m_Closure.m_pFunction,
        float_max_27);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v40);
      v2 = this;
    }
    ++i;
  }
  v9 = v2->m_buffer;
  v10 = (vostok::animation::mixing::n_ary_tree_animation_node *)v9->m_data;
  v9->m_data += 88;
  v9->m_size -= 88;
  m_previous_animation = v2->m_previous_animation;
  if ( !m_previous_animation
    || (v12 = node->weight_synchronization_group_id, v12 == 3)
    || m_previous_animation->m_weight_synchronization_group_id < v12 )
  {
    if ( !v10 )
      goto LABEL_35;
    bones_mask = node->bones_mask;
    time_synchronization_group_id = -1;
    if ( bones_mask )
      v15 = bones_mask != 1 ? -3 : 2;
    else
      v15 = -1;
    weight_synchronization_group_id = (vostok::resources::managed_resource *)node->weight_synchronization_group_id;
    v40.m_object = (vostok::resources::managed_resource *)-1;
    if ( weight_synchronization_group_id != (vostok::resources::managed_resource *)3 )
      v40.m_object = weight_synchronization_group_id;
    if ( node->time_synchronization_group_id != 15 )
      time_synchronization_group_id = node->time_synchronization_group_id;
    unique_animation_id = node->unique_animation_id;
    if ( unique_animation_id == 3 )
      LOBYTE(unique_animation_id) = -1;
    v18 = node->is_time_driving_animation == 1;
    operands_count = node->operands_count;
    v39.m_Closure.m_pthis = 0;
    v35 = v15;
    additivity_priority = node->additivity_priority;
    v31 = node->can_generate_events == 1;
    time_calculator = node->time_calculator;
    v39.m_Closure.m_pFunction = 0;
    vostok::animation::mixing::n_ary_tree_animation_node::n_ary_tree_animation_node(
      v10,
      &v39,
      v42,
      &v42[node->animation_intervals_count],
      unique_animation_id,
      0,
      node->weight_interpolator,
      0,
      node->animated_object,
      (vostok::animation::mixing::playback_enum)(node->playback_type != 0),
      time_calculator,
      time_synchronization_group_id,
      (unsigned int)v40.m_object,
      0,
      1,
      v31,
      v18,
      additivity_priority,
      v35,
      operands_count,
      0);
    goto LABEL_34;
  }
  m_weight_root = (vostok::resources::managed_resource *)v2->m_weight_root;
  v40.m_object = 0;
  while ( m_weight_root )
  {
    if ( m_weight_root->m_children_resources.m_last == (vostok::resources::resource_link *)node->weight_synchronization_group_id )
    {
      v40.m_object = m_weight_root;
      break;
    }
    m_weight_root = (vostok::resources::managed_resource *)m_weight_root->m_children_resources.m_lock;
  }
  if ( v10 )
  {
    v21 = node->bones_mask;
    v22 = -1;
    if ( v21 )
      v23 = v21 != 1 ? -3 : 2;
    else
      v23 = -1;
    if ( node->time_synchronization_group_id != 15 )
      v22 = node->time_synchronization_group_id;
    v24 = node->unique_animation_id;
    if ( v24 == 3 )
      LOBYTE(v24) = -1;
    v18 = node->is_time_driving_animation == 1;
    v38 = node->operands_count;
    v39.m_Closure.m_pthis = 0;
    v36 = v23;
    v34 = node->additivity_priority;
    v25 = v18;
    v32 = node->can_generate_events == 1;
    v30 = node->time_calculator;
    v18 = node->playback_type == 0;
    v39.m_Closure.m_pFunction = 0;
    vostok::animation::mixing::n_ary_tree_animation_node::n_ary_tree_animation_node(
      (vostok::animation::mixing::n_ary_tree_animation_node *)v40.m_object,
      v42,
      &v39,
      v10,
      &v42[node->animation_intervals_count],
      v24,
      0,
      0,
      node->animated_object,
      (vostok::animation::mixing::playback_enum)!v18,
      v30,
      v22,
      0,
      1,
      v32,
      v25,
      v34,
      v36,
      v38,
      0);
LABEL_34:
    v2 = this;
  }
LABEL_35:
  v10->user_data = 2 * (node->user_data == 0) - 1;
  if ( !node->is_time_driving_animation )
    v10->m_time_driving_animation = v10;
  if ( v2->m_weight_root )
    v2->m_previous_animation->m_next_weight_animation = v10;
  else
    v2->m_weight_root = v10;
  v26 = v2->m_buffer;
  v2->m_previous_animation = v10;
  v27 = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node **)v26->m_data;
  v28 = 4 * node->operands_count;
  v26->m_data += v28;
  v26->m_size -= v28;
  v29 = &v27[node->operands_count];
  if ( v27 != v29 )
  {
    while ( 1 )
    {
      *v27++ = vostok::animation::mixing::n_ary_tree_deserializer::get_operand(v2);
      if ( v27 == v29 )
        break;
      v2 = this;
    }
  }
}
