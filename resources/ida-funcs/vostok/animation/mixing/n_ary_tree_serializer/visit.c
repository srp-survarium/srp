void __thiscall vostok::animation::mixing::n_ary_tree_serializer::visit(
        vostok::animation::mixing::n_ary_tree_serializer *this,
        vostok::animation::mixing::n_ary_tree_serializer *state,
        int a3)
{
  vostok::animation::mixing::n_ary_tree_serializer *v3; // ecx
  vostok::animation::mixing::n_ary_tree_serializer *v4; // ecx
  vostok::animation::mixing::n_ary_tree_serializer *v5; // ecx
  const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v6; // edi
  vostok::resources::pinned_ptr_mutable<unsigned char> *v7; // ecx
  vostok::animation::mixing::n_ary_tree_serializer *v8; // ecx
  vostok::resources::pinned_ptr_const<unsigned char> *v9; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> value; // [esp+0h] [ebp-1Ch] BYREF
  _BYTE v11[12]; // [esp+10h] [ebp-Ch] BYREF

  vostok::animation::mixing::n_ary_tree_serializer::append(this, (int)state, *(_DWORD *)(a3 + 92), 1u);
  vostok::animation::mixing::n_ary_tree_serializer::append(v3, (int)state, *(_DWORD *)(a3 + 96), 1u);
  vostok::animation::mixing::n_ary_tree_serializer::append(state, *(float *)(a3 + 100));
  if ( *(float *)(a3 + 112) == 0.0 )
  {
    vostok::animation::mixing::n_ary_tree_serializer::append(v4, (int)state, 0, 1u);
  }
  else
  {
    v6 = (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)(*(_DWORD *)(a3 + 168) + 16) + 20 * *(_DWORD *)(a3 + 92));
    value.m_object = (vostok::resources::managed_resource *)v4;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
      &value,
      v6);
    vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
      v7,
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)v11,
      value);
    vostok::animation::mixing::n_ary_tree_serializer::append(v8, (int)state, 1u, 1u);
    vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
      v9,
      (int)v11);
  }
  vostok::animation::mixing::n_ary_tree_serializer::append(v5, (int)state, *(_BYTE *)(a3 + 117) != 0, 1u);
}


void __usercall vostok::animation::mixing::n_ary_tree_serializer::visit(
        vostok::animation::mixing::n_ary_tree_serializer *this@<edi>,
        const vostok::animation::mixing::animated_object_holder *object_holder@<esi>)
{
  vostok::animation::mixing::n_ary_tree_serializer::append(this, object_holder->transform.i.x);
  vostok::animation::mixing::n_ary_tree_serializer::append(this, object_holder->transform.i.y);
  vostok::animation::mixing::n_ary_tree_serializer::append(this, object_holder->transform.i.z);
  vostok::animation::mixing::n_ary_tree_serializer::append(this, object_holder->transform.j.x);
  vostok::animation::mixing::n_ary_tree_serializer::append(this, object_holder->transform.j.y);
  vostok::animation::mixing::n_ary_tree_serializer::append(this, object_holder->transform.j.z);
  vostok::animation::mixing::n_ary_tree_serializer::append(this, object_holder->transform.k.x);
  vostok::animation::mixing::n_ary_tree_serializer::append(this, object_holder->transform.k.y);
  vostok::animation::mixing::n_ary_tree_serializer::append(this, object_holder->transform.k.z);
  vostok::animation::mixing::n_ary_tree_serializer::append(this, object_holder->transform.c.x);
  vostok::animation::mixing::n_ary_tree_serializer::append(this, object_holder->transform.c.y);
  vostok::animation::mixing::n_ary_tree_serializer::append(this, object_holder->transform.c.z);
}


void __userpurge vostok::animation::mixing::n_ary_tree_serializer::visit(
        vostok::animation::mixing::n_ary_tree_serializer *this@<eax>,
        const vostok::animation::mixing::n_ary_tree_animation_node *node@<esi>,
        vostok::animation::mixing::n_ary_tree_serializer *a3@<ecx>,
        const vostok::animation::mixing::n_ary_tree *tree)
{
  vostok::animation::mixing::n_ary_tree_serializer *v5; // ecx
  vostok::animation::mixing::n_ary_tree_serializer *v6; // ecx
  const vostok::animation::mixing::animation_interval *m_animation_intervals; // eax
  vostok::animation::mixing::n_ary_tree_serializer *v8; // ebx
  unsigned int m_animation_intervals_count; // eax
  vostok::animation::interpolator_visitor *v10; // eax
  vostok::animation::mixing::n_ary_tree_serializer *v11; // ecx
  vostok::animation::mixing::n_ary_tree_serializer *v12; // ecx
  unsigned int m_time_synchronization_group_id; // eax
  vostok::animation::mixing::n_ary_tree_serializer *v14; // ecx
  unsigned int m_weight_synchronization_group_id; // eax
  vostok::animation::mixing::n_ary_tree_serializer *v16; // ecx
  vostok::animation::mixing::n_ary_tree_serializer *v17; // ecx
  vostok::animation::mixing::n_ary_tree_serializer *v18; // ecx
  unsigned int m_bones_mask; // eax
  vostok::animation::mixing::n_ary_tree_serializer *v20; // ecx
  unsigned int v21; // eax
  vostok::animation::mixing::n_ary_tree_serializer *v22; // ecx
  vostok::animation::mixing::n_ary_tree_serializer *v23; // ecx
  unsigned int v24; // [esp-8h] [ebp-34h]
  vostok::animation::mixing::animation_interval v25; // [esp+Ch] [ebp-20h] BYREF
  unsigned int v26; // [esp+20h] [ebp-Ch]
  unsigned int v27; // [esp+24h] [ebp-8h]
  vostok::animation::mixing::n_ary_tree_serializer *v28; // [esp+28h] [ebp-4h]

  vostok::animation::mixing::n_ary_tree_serializer::append(a3, (int)this, node->m_time_calculator_id, 4u);
  vostok::animation::mixing::n_ary_tree_serializer::append(v5, (int)this, node->m_animation_intervals_count - 1, 1u);
  m_animation_intervals = node->m_animation_intervals;
  v8 = (vostok::animation::mixing::n_ary_tree_serializer *)&m_animation_intervals[node->m_animation_intervals_count];
  v28 = (vostok::animation::mixing::n_ary_tree_serializer *)m_animation_intervals;
  if ( m_animation_intervals != (const vostok::animation::mixing::animation_interval *)v8 )
  {
    while ( 1 )
    {
      vostok::animation::mixing::n_ary_tree_serializer::append(
        v6,
        (int)this,
        m_animation_intervals->m_animation_id,
        0xAu);
      m_animation_intervals_count = node->m_animation_intervals_count;
      v27 = 0;
      v26 = m_animation_intervals_count;
      if ( m_animation_intervals_count )
      {
        while ( 1 )
        {
          vostok::animation::mixing::animation_lexeme_parameters::create_animation_interval(
            (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)v28,
            (vostok::resources::managed_resource *)v6,
            &v25,
            v27,
            0xFFFF);
          if ( v25.m_start_time == *(float *)&v28->m_times_in_ms_stream.m_end
            && v25.m_length == *(float *)&v28->m_times_in_ms_stream.m_max_end )
          {
            break;
          }
          vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v25.m_third_view_animation);
          vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v25.m_first_view_animation);
          if ( ++v27 >= v26 )
            goto LABEL_10;
        }
        vostok::animation::mixing::n_ary_tree_serializer::append(v28, (int)this, v27, 1u);
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v25.m_third_view_animation);
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v25.m_first_view_animation);
      }
LABEL_10:
      v28 = (vostok::animation::mixing::n_ary_tree_serializer *)((char *)v28 + 20);
      if ( v28 == v8 )
        break;
      m_animation_intervals = (const vostok::animation::mixing::animation_interval *)v28;
    }
  }
  vostok::animation::mixing::n_ary_tree_serializer::append(v6, (int)this, node->m_is_time_driving_animation, 1u);
  if ( this )
    v10 = &this->vostok::animation::interpolator_visitor;
  else
    v10 = 0;
  node->m_weight_interpolator->accept(node->m_weight_interpolator, v10);
  v24 = tree->m_animated_objects->animated_object != node->m_animated_object;
  vostok::animation::mixing::n_ary_tree_serializer::append(
    (vostok::animation::mixing::n_ary_tree_serializer *)v24,
    (int)this,
    v24,
    1u);
  if ( node->user_data == 1 )
    vostok::animation::mixing::n_ary_tree_serializer::append(v11, (int)this, 0, 1u);
  else
    vostok::animation::mixing::n_ary_tree_serializer::append(v11, (int)this, 1u, 1u);
  m_time_synchronization_group_id = node->m_time_synchronization_group_id;
  if ( m_time_synchronization_group_id == -1 )
    vostok::animation::mixing::n_ary_tree_serializer::append(v12, (int)this, 0xFu, 4u);
  else
    vostok::animation::mixing::n_ary_tree_serializer::append(v12, (int)this, m_time_synchronization_group_id, 4u);
  m_weight_synchronization_group_id = node->m_weight_synchronization_group_id;
  if ( m_weight_synchronization_group_id == -1 )
    vostok::animation::mixing::n_ary_tree_serializer::append(v14, (int)this, 3u, 2u);
  else
    vostok::animation::mixing::n_ary_tree_serializer::append(v14, (int)this, m_weight_synchronization_group_id, 2u);
  vostok::animation::mixing::n_ary_tree_serializer::append(v16, (int)this, node->m_playback_type, 1u);
  vostok::animation::mixing::n_ary_tree_serializer::append(v17, (int)this, node->m_additivity_priority, 3u);
  m_bones_mask = node->m_bones_mask;
  if ( m_bones_mask == 2 )
  {
    vostok::animation::mixing::n_ary_tree_serializer::append(v18, (int)this, 1u, 2u);
  }
  else if ( m_bones_mask == -3 )
  {
    vostok::animation::mixing::n_ary_tree_serializer::append(v18, (int)this, 2u, 2u);
  }
  else
  {
    vostok::animation::mixing::n_ary_tree_serializer::append(v18, (int)this, 0, 2u);
  }
  LOBYTE(v21) = node->m_unique_animation_id;
  if ( (_BYTE)v21 == 0xFF )
    v21 = 3;
  else
    v21 = (unsigned __int8)v21;
  vostok::animation::mixing::n_ary_tree_serializer::append(v20, (int)this, v21, 2u);
  vostok::animation::mixing::n_ary_tree_serializer::append(v22, (int)this, node->m_can_generate_events, 1u);
  vostok::animation::mixing::n_ary_tree_serializer::append(v23, (int)this, node->m_operands_count, 2u);
}


void __thiscall vostok::animation::mixing::n_ary_tree_serializer::visit(
        vostok::animation::mixing::n_ary_tree_serializer *this,
        vostok::animation::mixing::n_ary_tree_serializer *event_iterator,
        int a3)
{
  vostok::animation::mixing::n_ary_tree_serializer *v3; // ebx
  vostok::buffer_vector<unsigned int> *v4; // ecx
  vostok::animation::mixing::n_ary_tree_serializer *v5; // ecx
  vostok::animation::mixing::n_ary_tree_serializer *v6; // ecx
  vostok::animation::mixing::n_ary_tree_serializer *v7; // ecx

  v3 = event_iterator;
  vostok::animation::mixing::n_ary_tree_serializer::append(
    this,
    (int)event_iterator,
    (unsigned __int16)*(_DWORD *)(a3 + 12) >> 1,
    6u);
  if ( (unsigned __int16)*(_DWORD *)(a3 + 12) )
  {
    event_iterator = *(vostok::animation::mixing::n_ary_tree_serializer **)(a3 + 8);
    vostok::buffer_vector<unsigned int>::push_back(
      v4,
      (int)&v3->m_times_in_ms_stream,
      (const unsigned int *)&event_iterator);
    vostok::animation::mixing::n_ary_tree_serializer::append(v5, (int)v3, *(_DWORD *)a3, 1u);
    vostok::animation::mixing::n_ary_tree_serializer::append(v3, *(const float *)(a3 + 4));
    vostok::animation::mixing::n_ary_tree_serializer::append(
      v6,
      (int)v3,
      (unsigned __int8)BYTE2(*(_DWORD *)(a3 + 12)),
      8u);
    if ( HIBYTE(*(_DWORD *)(a3 + 12)) == 0xFF )
      vostok::animation::mixing::n_ary_tree_serializer::append(v7, (int)v3, 0xFu, 4u);
    else
      vostok::animation::mixing::n_ary_tree_serializer::append(v7, (int)v3, HIBYTE(*(_DWORD *)(a3 + 12)), 4u);
  }
}


void __userpurge vostok::animation::mixing::n_ary_tree_serializer::visit(
        vostok::animation::mixing::n_ary_tree_serializer *this@<ecx>,
        int a2@<eax>,
        const vostok::animation::mixing::n_ary_tree_weight_event_iterator *event_iterator)
{
  vostok::animation::mixing::animation_event *v4; // eax
  vostok::animation::mixing::n_ary_tree_serializer *v5; // ecx
  vostok::animation::mixing::n_ary_tree_weight_event_iterator *v6; // ecx
  vostok::animation::mixing::animation_event *v7; // eax
  vostok::animation::mixing::n_ary_tree_serializer *v8; // ecx
  vostok::animation::mixing::n_ary_tree_weight_event_iterator *v9; // ecx
  vostok::animation::mixing::n_ary_tree_weight_event_iterator *v10; // ecx
  vostok::buffer_vector<unsigned int> *v11; // ecx
  vostok::animation::mixing::animation_event result; // [esp+10h] [ebp-14h] BYREF

  v4 = vostok::animation::mixing::n_ary_tree_weight_event_iterator::operator*(
         (vostok::animation::mixing::n_ary_tree_weight_event_iterator *)this,
         &result);
  vostok::animation::mixing::n_ary_tree_serializer::append(v5, a2, HIBYTE(v4->event_type) & 1, 1u);
  v7 = vostok::animation::mixing::n_ary_tree_weight_event_iterator::operator*(v6, &result);
  vostok::animation::mixing::n_ary_tree_serializer::append(v8, a2, (v7->event_type >> 1) & 1, 1u);
  if ( vostok::animation::mixing::n_ary_tree_weight_event_iterator::operator*(v9, &result)->event_type )
  {
    event_iterator = (const vostok::animation::mixing::n_ary_tree_weight_event_iterator *)vostok::animation::mixing::n_ary_tree_weight_event_iterator::operator*(
                                                                                            v10,
                                                                                            &result)->event_time_in_ms;
    vostok::buffer_vector<unsigned int>::push_back(v11, a2 + 8, (const unsigned int *)&event_iterator);
  }
}


void __thiscall vostok::animation::mixing::n_ary_tree_serializer::visit(
        vostok::animation::mixing::n_ary_tree_serializer *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *node)
{
  vostok::animation::interpolator_visitor *v3; // eax
  vostok::animation::mixing::n_ary_tree_time_scale_node *v4; // esi
  vostok::buffer_vector<unsigned int> *v5; // ecx

  vostok::animation::mixing::n_ary_tree_serializer::append(this, (int)this, 0, 2u);
  if ( this )
    v3 = &this->vostok::animation::interpolator_visitor;
  else
    v3 = 0;
  v4 = node;
  node->m_interpolator->accept(node->m_interpolator, v3);
  vostok::animation::mixing::n_ary_tree_serializer::append(this, v4->m_time_scale);
  vostok::animation::mixing::n_ary_tree_serializer::append(this, v4->m_animation_time_before_scale_starts);
  node = (vostok::animation::mixing::n_ary_tree_time_scale_node *)v4->m_time_scale_start_time_in_ms;
  vostok::buffer_vector<unsigned int>::push_back(v5, (int)&this->m_times_in_ms_stream, (const unsigned int *)&node);
}


void __thiscall vostok::animation::mixing::n_ary_tree_serializer::visit(
        vostok::animation::mixing::n_ary_tree_serializer *this,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *node)
{
  vostok::animation::interpolator_visitor *v3; // eax
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node *v4; // ebx
  vostok::buffer_vector<unsigned int> *v5; // ecx

  vostok::animation::mixing::n_ary_tree_serializer::append(this, (int)this, 3u, 2u);
  if ( this )
    v3 = &this->vostok::animation::interpolator_visitor;
  else
    v3 = 0;
  v4 = node;
  node->m_interpolator->accept(node->m_interpolator, v3);
  node = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)v4->m_start_time_in_ms;
  vostok::buffer_vector<unsigned int>::push_back(v5, (int)&this->m_times_in_ms_stream, (const unsigned int *)&node);
  v4->m_from->accept(v4->m_from, this);
  v4->m_to->accept(v4->m_to, this);
}


void __thiscall vostok::animation::mixing::n_ary_tree_serializer::visit(
        vostok::animation::mixing::n_ary_tree_serializer *this,
        vostok::animation::mixing::n_ary_tree_weight_node *node)
{
  vostok::animation::interpolator_visitor *v3; // eax

  vostok::animation::mixing::n_ary_tree_serializer::append(this, (int)this, 1u, 2u);
  if ( this )
    v3 = &this->vostok::animation::interpolator_visitor;
  else
    v3 = 0;
  node->m_interpolator->accept(node->m_interpolator, v3);
  vostok::animation::mixing::n_ary_tree_serializer::append(this, node->m_weight);
}


void __thiscall vostok::animation::mixing::n_ary_tree_serializer::visit(
        vostok::animation::mixing::n_ary_tree_serializer *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *node)
{
  vostok::animation::interpolator_visitor *v3; // eax
  vostok::animation::mixing::n_ary_tree_weight_transition_node *v4; // ebx
  vostok::buffer_vector<unsigned int> *v5; // ecx

  vostok::animation::mixing::n_ary_tree_serializer::append(this, (int)this, 2u, 2u);
  if ( this )
    v3 = &this->vostok::animation::interpolator_visitor;
  else
    v3 = 0;
  v4 = node;
  node->m_interpolator->accept(node->m_interpolator, v3);
  node = (vostok::animation::mixing::n_ary_tree_weight_transition_node *)v4->m_start_time_in_ms;
  vostok::buffer_vector<unsigned int>::push_back(v5, (int)&this->m_times_in_ms_stream, (const unsigned int *)&node);
  v4->m_from->accept(v4->m_from, this);
  v4->m_to->accept(v4->m_to, this);
}


void __thiscall vostok::animation::mixing::n_ary_tree_serializer::visit(
        vostok::animation::mixing::n_ary_tree_serializer *this,
        const vostok::animation::instant_interpolator *interpolator)
{
  int v2; // eax
  unsigned int *p_m_write_operation_id; // edi

  v2 = *(_DWORD *)(*(_DWORD *)&this->m_floats_stream.m_buffer[1023] + 40);
  if ( v2 != 1 )
  {
    p_m_write_operation_id = &this[-1].m_write_operation_id;
    if ( v2 == 2 )
      vostok::animation::mixing::n_ary_tree_serializer::append(this, (int)p_m_write_operation_id, 0, 1u);
    else
      vostok::animation::mixing::n_ary_tree_serializer::append(this, (int)p_m_write_operation_id, 0, 2u);
  }
}


void __thiscall vostok::animation::mixing::n_ary_tree_serializer::visit(
        vostok::animation::mixing::n_ary_tree_serializer *this,
        const vostok::animation::linear_interpolator *interpolator)
{
  vostok::fixed_vector<float,1024>::allign_helper v2; // edx
  const vostok::animation::linear_interpolator **v3; // eax
  const vostok::animation::linear_interpolator **v4; // edi
  int i; // edx
  vostok::fixed_vector<float,1024>::allign_helper v6; // edx
  int v7; // eax
  int v8; // edx
  unsigned int v9; // eax
  unsigned int *p_m_write_operation_id; // edi

  v2 = this->m_floats_stream.m_buffer[1023];
  v3 = *(const vostok::animation::linear_interpolator ***)(*(_DWORD *)&v2 + 12);
  v4 = &v3[*(_DWORD *)(*(_DWORD *)&v2 + 40)];
  for ( i = (4 * *(_DWORD *)(*(_DWORD *)&v2 + 40)) >> 4; i > 0; --i )
  {
    if ( *v3 == interpolator )
      goto LABEL_17;
    if ( *++v3 == interpolator )
      goto LABEL_17;
    if ( *++v3 == interpolator )
      goto LABEL_17;
    if ( *++v3 == interpolator )
      goto LABEL_17;
    ++v3;
  }
  switch ( v4 - v3 )
  {
    case 1:
      goto LABEL_15;
    case 2:
LABEL_13:
      if ( *v3 == interpolator )
        goto LABEL_17;
      ++v3;
LABEL_15:
      if ( *v3 == interpolator )
        goto LABEL_17;
      break;
    case 3:
      if ( *v3 == interpolator )
        goto LABEL_17;
      ++v3;
      goto LABEL_13;
  }
  v3 = v4;
LABEL_17:
  v6 = this->m_floats_stream.m_buffer[1023];
  v7 = (int)v3 - *(_DWORD *)(*(_DWORD *)&v6 + 12);
  v8 = *(_DWORD *)(*(_DWORD *)&v6 + 40);
  v9 = v7 >> 2;
  if ( v8 != 1 )
  {
    p_m_write_operation_id = &this[-1].m_write_operation_id;
    if ( v8 == 2 )
      vostok::animation::mixing::n_ary_tree_serializer::append(this, (int)p_m_write_operation_id, v9, 1u);
    else
      vostok::animation::mixing::n_ary_tree_serializer::append(this, (int)p_m_write_operation_id, v9, 2u);
  }
}
