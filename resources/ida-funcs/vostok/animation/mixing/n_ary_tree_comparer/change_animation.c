void __userpurge vostok::animation::mixing::n_ary_tree_comparer::change_animation(
        vostok::animation::mixing::n_ary_tree_animation_node *from@<ecx>,
        vostok::animation::mixing::n_ary_tree_animation_node *to@<eax>,
        vostok::animation::mixing::n_ary_tree_comparer *this,
        unsigned int is_new_driving_animation)
{
  vostok::animation::mixing::n_ary_tree_comparer *v4; // ebp
  unsigned int m_operands_count; // eax
  unsigned int v8; // edx
  vostok::animation::mixing::n_ary_tree_base_node **v9; // ebx
  vostok::animation::mixing::n_ary_tree_comparer *v10; // ecx
  vostok::animation::mixing::n_ary_tree_comparer *v11; // edi
  unsigned int v12; // esi
  BOOL v13; // eax
  vostok::animation::mixing::n_ary_tree_comparer *i; // esi
  vostok::animation::mixing::animated_object_holder *m_animated_objects; // ecx
  void (__thiscall *v16)(vostok::animation::mixing::animated_object_holder *, void ***); // edx
  vostok::animation::mixing::n_ary_tree_base_node **v17; // ebx
  unsigned int v18; // edi
  BOOL v19; // eax
  float v20; // xmm0_4
  const vostok::math::float4x4 *v21; // xmm0_4
  vostok::animation::mixing::n_ary_tree_base_node **j; // esi
  vostok::animation::mixing::n_ary_tree_base_node *v23; // ecx
  void (__thiscall *accept)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_visitor *); // edx
  int v25; // ecx
  void (__thiscall *v26)(int, void ***); // eax
  vostok::animation::mixing::n_ary_tree_base_node **v27; // xmm0_4
  vostok::animation::mixing::n_ary_tree_base_node **v28; // xmm0_4
  bool v29; // al
  vostok::animation::mixing::animation_state *m_animation_state; // eax
  vostok::animation::mixing::animation_state *v31; // ecx
  bool v32; // al
  vostok::animation::mixing::n_ary_tree_comparer *v33; // ecx
  vostok::animation::mixing::n_ary_tree_base_node **to_begin; // [esp+14h] [ebp-30h]
  unsigned int left_multiplicands_count; // [esp+18h] [ebp-2Ch]
  unsigned int operands_offset; // [esp+1Ch] [ebp-28h] BYREF
  float left_weight; // [esp+20h] [ebp-24h]
  vostok::animation::mixing::n_ary_tree_base_node **to_end; // [esp+24h] [ebp-20h] BYREF
  vostok::animation::mixing::n_ary_tree_comparer *v39; // [esp+28h] [ebp-1Ch]
  vostok::animation::interpolator_comparer interpolator_comparer; // [esp+2Ch] [ebp-18h] BYREF
  void **v41; // [esp+30h] [ebp-14h]
  void **v42; // [esp+34h] [ebp-10h] BYREF
  vostok::animation::mixing::n_ary_tree_comparer *v43; // [esp+38h] [ebp-Ch]
  int v44; // [esp+3Ch] [ebp-8h]

  v4 = this;
  if ( from->m_is_transitting_to_zero && !to->m_is_transitting_to_zero
    || (_BYTE)is_new_driving_animation && from->m_animation_state->are_there_any_weight_transitions )
  {
    this->m_equal = 0;
    m_operands_count = from->m_operands_count;
    v8 = to->m_operands_count;
    v9 = (vostok::animation::mixing::n_ary_tree_base_node **)&from[1];
    this = (vostok::animation::mixing::n_ary_tree_comparer *)(&from[1].__vftable + m_operands_count);
    v10 = (vostok::animation::mixing::n_ary_tree_comparer *)&to[1];
    to_begin = (vostok::animation::mixing::n_ary_tree_base_node **)&to[1];
    to_end = (vostok::animation::mixing::n_ary_tree_base_node **)(&to[1].__vftable + v8);
    if ( m_operands_count )
    {
      if ( (*v9)->is_time_scale(*v9) )
        goto LABEL_10;
      v10 = (vostok::animation::mixing::n_ary_tree_comparer *)&to[1];
    }
    if ( !to->m_operands_count
      || !(*(unsigned __int8 (__thiscall **)(vostok::animation::mixing::animated_object_holder *))(LODWORD(v10->m_animated_objects->transform.i.x)
                                                                                                 + 12))(v10->m_animated_objects) )
    {
      is_new_driving_animation = 0;
LABEL_12:
      vostok::animation::mixing::n_ary_tree_comparer::new_animation(
        &operands_offset,
        v10,
        v4,
        to,
        &is_new_driving_animation);
      v4->m_needed_buffer_size += 4 * is_new_driving_animation + 4;
      if ( operands_offset )
        goto LABEL_23;
      if ( from->m_operands_count && (*v9)->is_time_scale(*v9) )
      {
        if ( !to->m_operands_count || !(*to_begin)->is_time_scale(*to_begin) )
        {
          vostok::animation::mixing::n_ary_tree_comparer::new_time_scale_transition(v4, *v9++);
          goto LABEL_23;
        }
        vostok::animation::mixing::n_ary_tree_comparer::new_time_scale_transition(v4, *to_begin, *v9++);
      }
      else
      {
        if ( !to->m_operands_count || !(*to_begin)->is_time_scale(*to_begin) )
          goto LABEL_23;
        vostok::animation::mixing::n_ary_tree_comparer::new_time_scale_transition(v4, *to_begin);
      }
      to_begin = (vostok::animation::mixing::n_ary_tree_base_node **)&to[1].m_operands_count;
LABEL_23:
      v11 = this;
      v12 = ((char *)this - (char *)v9) >> 2;
      left_multiplicands_count = v12;
      if ( v12 && (*v9)->is_time_scale(*v9) )
        left_multiplicands_count = --v12;
      left_weight = float_max_15;
      LOBYTE(is_new_driving_animation) = 0;
      if ( v12 )
      {
        if ( v12 == 1 )
        {
          vostok::animation::mixing::n_ary_tree_comparer::increase_buffer_size(
            *(vostok::animation::mixing::n_ary_tree_comparer **)&v11[-1].m_equal,
            v4);
          if ( !(*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&v11[-1].m_equal + 16))(*(_DWORD *)&v11[-1].m_equal)
            || (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&v11[-1].m_equal + 20))(*(_DWORD *)&v11[-1].m_equal) )
          {
            LOBYTE(is_new_driving_animation) = 0;
          }
          else
          {
            v20 = *(float *)(*(_DWORD *)&v11[-1].m_equal + 8);
            LOBYTE(is_new_driving_animation) = 1;
            left_weight = v20;
          }
        }
        else
        {
          v4->m_needed_buffer_size += 4 * v12 + 8;
          v13 = operands_offset && (*v9)->is_time_scale(*v9);
          for ( i = (vostok::animation::mixing::n_ary_tree_comparer *)&v9[v13];
                i != v11;
                i = (vostok::animation::mixing::n_ary_tree_comparer *)((char *)i + 4) )
          {
            m_animated_objects = i->m_animated_objects;
            v16 = *(void (__thiscall **)(vostok::animation::mixing::animated_object_holder *, void ***))(LODWORD(i->m_animated_objects->transform.i.x) + 8);
            v41 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::binary_tree_visitor'};
            v42 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::n_ary_tree_visitor'};
            v43 = v4;
            v44 = 0;
            v16(m_animated_objects, &v42);
          }
          v12 = left_multiplicands_count;
        }
      }
      else
      {
        v21 = clear_value;
        v4->m_needed_buffer_size += 12;
        left_weight = *(float *)&v21;
        LOBYTE(is_new_driving_animation) = 1;
      }
      v17 = to_end;
      v18 = to_end - to_begin;
      if ( v18 && (*to_begin)->is_time_scale(*to_begin) )
        --v18;
      *(float *)&to_end = float_max_15;
      LOBYTE(this) = 0;
      if ( v18 )
      {
        if ( v18 == 1 )
        {
          v25 = (int)*(v17 - 1);
          v26 = *(void (__thiscall **)(int, void ***))(*(_DWORD *)v25 + 8);
          v41 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::binary_tree_visitor'};
          v42 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::n_ary_tree_visitor'};
          v43 = v4;
          v44 = 0;
          v26(v25, &v42);
          if ( !(*(v17 - 1))->is_weight(*(v17 - 1)) || (*(v17 - 1))->is_transition(*(v17 - 1)) )
          {
            LOBYTE(this) = 0;
          }
          else
          {
            v27 = (vostok::animation::mixing::n_ary_tree_base_node **)(*(v17 - 1))[2].__vftable;
            LOBYTE(this) = 1;
            to_end = v27;
          }
        }
        else
        {
          v4->m_needed_buffer_size += 4 * v18 + 8;
          v19 = operands_offset && (*to_begin)->is_time_scale(*to_begin);
          for ( j = &to_begin[v19]; j != v17; ++j )
          {
            v23 = *j;
            accept = (*j)->accept;
            v41 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::binary_tree_visitor'};
            v42 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::n_ary_tree_visitor'};
            v43 = v4;
            v44 = 0;
            accept(v23, (vostok::animation::mixing::n_ary_tree_visitor *)&v42);
          }
          v12 = left_multiplicands_count;
        }
      }
      else
      {
        v28 = (vostok::animation::mixing::n_ary_tree_base_node **)clear_value;
        v4->m_needed_buffer_size += 12;
        to_end = v28;
        LOBYTE(this) = 1;
      }
      if ( v12 < 2 && v18 < 2 && (_BYTE)is_new_driving_animation && (_BYTE)this && left_weight == *(float *)&to_end )
        v4->m_needed_buffer_size += 12;
      else
        v4->m_needed_buffer_size += 20;
      return;
    }
LABEL_10:
    is_new_driving_animation = 1;
    goto LABEL_12;
  }
  from->m_weight_interpolator->accept(from->m_weight_interpolator, &interpolator_comparer, to->m_weight_interpolator);
  v29 = v4->m_equal && interpolator_comparer.result == equal;
  v4->m_equal = v29;
  if ( to->m_override_existing_animation )
  {
    v32 = 0;
    if ( v29 )
    {
      m_animation_state = from->m_animation_state;
      v31 = to->m_animation_state;
      if ( m_animation_state->animation_interval_id == v31->animation_interval_id
        && m_animation_state->animation_interval_time == v31->animation_interval_time )
      {
        v32 = 1;
      }
    }
    v4->m_equal = v32;
  }
  vostok::animation::mixing::computed_operands_count(
    from,
    (vostok::animation::mixing::n_ary_tree_animation_node *)&to_end);
  is_new_driving_animation = (unsigned int)v39;
  vostok::animation::mixing::n_ary_tree_comparer::new_animation(
    (unsigned int *)&this,
    v39,
    v4,
    to,
    &is_new_driving_animation);
  v33 = (vostok::animation::mixing::n_ary_tree_comparer *)(4 * ((_DWORD)to_end + is_new_driving_animation));
  v4->m_needed_buffer_size += (unsigned int)v33;
  vostok::animation::mixing::n_ary_tree_comparer::add_operands(v33, v4, from, to, this != 0);
}
