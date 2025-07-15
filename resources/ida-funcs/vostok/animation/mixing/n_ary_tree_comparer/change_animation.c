void __userpurge vostok::animation::mixing::n_ary_tree_comparer::change_animation(
        vostok::animation::mixing::n_ary_tree_comparer *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_animation_node *to@<eax>,
        vostok::animation::mixing::n_ary_tree_animation_node *from,
        unsigned int is_new_driving_animation)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v4; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *v7; // eax
  unsigned int m_operands_count; // eax
  unsigned int v9; // edx
  vostok::animation::mixing::n_ary_tree_comparer **v10; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *v11; // ecx
  vostok::animation::mixing::n_ary_tree_subtraction_node **v12; // edi
  vostok::animation::mixing::n_ary_tree_comparer *v13; // ecx
  int v14; // ecx
  int v15; // edi
  BOOL v16; // eax
  vostok::animation::mixing::n_ary_tree_comparer **i; // ebx
  float v18; // edi
  unsigned int v19; // xmm0_4
  vostok::animation::mixing::n_ary_tree_comparer **v20; // ebx
  unsigned int v21; // edi
  BOOL v22; // eax
  vostok::animation::mixing::n_ary_tree_comparer **j; // ebx
  float v24; // xmm0_4
  bool v25; // al
  vostok::animation::mixing::animation_state *m_animation_state; // eax
  vostok::animation::mixing::animation_state *v27; // ecx
  bool v28; // al
  int v29; // [esp+10h] [ebp-20h] BYREF
  unsigned int v30; // [esp+14h] [ebp-1Ch] BYREF
  stlp_std::pair<unsigned int,unsigned int> v31; // [esp+18h] [ebp-18h] BYREF
  vostok::animation::mixing::n_ary_tree_comparer **v32; // [esp+20h] [ebp-10h]
  unsigned int v33; // [esp+24h] [ebp-Ch] BYREF
  float v34; // [esp+28h] [ebp-8h]
  vostok::animation::mixing::n_ary_tree_comparer **v35; // [esp+2Ch] [ebp-4h]

  v4 = from;
  if ( from->m_is_transitting_to_zero && !to->m_is_transitting_to_zero
    || (_BYTE)is_new_driving_animation && from->m_animation_state->are_there_any_weight_transitions )
  {
    v7 = from;
    this->m_equal = 0;
    m_operands_count = v7->m_operands_count;
    v9 = to->m_operands_count;
    v10 = (vostok::animation::mixing::n_ary_tree_comparer **)&v4[1];
    LODWORD(v34) = &v10[m_operands_count];
    v11 = to + 1;
    v35 = (vostok::animation::mixing::n_ary_tree_comparer **)&to[1];
    v32 = (vostok::animation::mixing::n_ary_tree_comparer **)(&to[1].__vftable + v9);
    if ( m_operands_count )
    {
      if ( ((unsigned __int8 (__thiscall *)(vostok::animation::mixing::n_ary_tree_comparer *))LODWORD((*v10)->m_animated_objects->transform.i.w))(*v10) )
        goto LABEL_10;
      v11 = (vostok::animation::mixing::n_ary_tree_animation_node *)v35;
    }
    if ( !to->m_operands_count
      || !(*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v11->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
           + 3))(v11->__vftable) )
    {
      is_new_driving_animation = 0;
LABEL_12:
      vostok::animation::mixing::n_ary_tree_comparer::new_animation(
        &v33,
        this,
        to,
        &is_new_driving_animation,
        &v30,
        (const void *)1);
      this->m_needed_buffer_size += 4 * is_new_driving_animation + 4;
      if ( !v33 )
      {
        if ( from->m_operands_count
          && ((unsigned __int8 (__thiscall *)(vostok::animation::mixing::n_ary_tree_comparer *))LODWORD((*v10)->m_animated_objects->transform.i.w))(*v10) )
        {
          if ( to->m_operands_count )
          {
            v12 = (vostok::animation::mixing::n_ary_tree_subtraction_node **)v35;
            if ( ((unsigned __int8 (__thiscall *)(vostok::animation::mixing::n_ary_tree_comparer *))LODWORD((*v35)->m_animated_objects->transform.i.w))(*v35) )
            {
              vostok::animation::mixing::n_ary_tree_comparer::new_time_scale_transition(v13, (int)this, *v10++, *v12);
LABEL_22:
              ++v35;
              goto LABEL_23;
            }
          }
          vostok::animation::mixing::n_ary_tree_comparer::new_time_scale_transition(this, *v10++);
        }
        else if ( to->m_operands_count
               && ((unsigned __int8 (__thiscall *)(vostok::animation::mixing::n_ary_tree_comparer *))LODWORD((*v35)->m_animated_objects->transform.i.w))(*v35) )
        {
          vostok::animation::mixing::n_ary_tree_comparer::new_time_scale_transition(this, *v35, v14);
          goto LABEL_22;
        }
      }
LABEL_23:
      v15 = (LODWORD(v34) - (int)v10) >> 2;
      v30 = v15;
      if ( v15
        && ((unsigned __int8 (__thiscall *)(vostok::animation::mixing::n_ary_tree_comparer *))LODWORD((*v10)->m_animated_objects->transform.i.w))(*v10) )
      {
        v30 = --v15;
      }
      *(float *)&v31.second = float_max_28;
      HIBYTE(is_new_driving_animation) = 0;
      if ( v15 )
      {
        if ( v15 != 1 )
        {
          this->m_needed_buffer_size += 4 * v15 + 8;
          v16 = v33
             && ((unsigned __int8 (__thiscall *)(vostok::animation::mixing::n_ary_tree_comparer *))LODWORD((*v10)->m_animated_objects->transform.i.w))(*v10);
          for ( i = &v10[v16]; i != (vostok::animation::mixing::n_ary_tree_comparer **)LODWORD(v34); ++i )
            vostok::animation::mixing::n_ary_tree_comparer::increase_buffer_size(*i, (int)this);
LABEL_42:
          v20 = v32;
          v21 = v32 - v35;
          if ( v21
            && ((unsigned __int8 (__thiscall *)(vostok::animation::mixing::n_ary_tree_comparer *))LODWORD((*v35)->m_animated_objects->transform.i.w))(*v35) )
          {
            --v21;
          }
          v34 = float_max_28;
          HIBYTE(from) = 0;
          if ( v21 )
          {
            if ( v21 != 1 )
            {
              this->m_needed_buffer_size += 4 * v21 + 8;
              v22 = v33
                 && ((unsigned __int8 (__thiscall *)(vostok::animation::mixing::n_ary_tree_comparer *))LODWORD((*v35)->m_animated_objects->transform.i.w))(*v35);
              for ( j = &v35[v22]; j != v32; ++j )
                vostok::animation::mixing::n_ary_tree_comparer::increase_buffer_size(*j, (int)this);
              goto LABEL_61;
            }
            vostok::animation::mixing::n_ary_tree_comparer::increase_buffer_size(*(v20 - 1), (int)this);
            if ( !((unsigned __int8 (__thiscall *)(_DWORD))LODWORD((*(v20 - 1))->m_animated_objects->transform.j.x))(*(v20 - 1))
              || ((unsigned __int8 (__thiscall *)(_DWORD))LODWORD((*(v20 - 1))->m_animated_objects->transform.j.y))(*(v20 - 1)) )
            {
              HIBYTE(from) = 0;
LABEL_61:
              if ( v30 < 2
                && v21 < 2
                && HIBYTE(is_new_driving_animation)
                && HIBYTE(from)
                && *(float *)&v31.second == v34 )
              {
                this->m_needed_buffer_size += 12;
              }
              else
              {
                this->m_needed_buffer_size += 20;
              }
              return;
            }
            v24 = *(float *)&(*(v20 - 1))->m_from;
            HIBYTE(from) = 1;
          }
          else
          {
            this->m_needed_buffer_size += 12;
            v24 = s_bm_current_air_resistance;
            HIBYTE(from) = 1;
          }
          v34 = v24;
          goto LABEL_61;
        }
        vostok::animation::mixing::n_ary_tree_comparer::increase_buffer_size(
          *(vostok::animation::mixing::n_ary_tree_comparer **)(LODWORD(v34) - 4),
          (int)this);
        v18 = v34;
        if ( !(*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(LODWORD(v34) - 4) + 16))(*(_DWORD *)(LODWORD(v34) - 4))
          || (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(LODWORD(v18) - 4) + 20))(*(_DWORD *)(LODWORD(v18) - 4)) )
        {
          HIBYTE(is_new_driving_animation) = 0;
          goto LABEL_42;
        }
        v19 = *(_DWORD *)(*(_DWORD *)(LODWORD(v18) - 4) + 8);
        HIBYTE(is_new_driving_animation) = 1;
      }
      else
      {
        this->m_needed_buffer_size += 12;
        v19 = LODWORD(s_bm_current_air_resistance);
        HIBYTE(is_new_driving_animation) = 1;
      }
      v31.second = v19;
      goto LABEL_42;
    }
LABEL_10:
    is_new_driving_animation = 1;
    goto LABEL_12;
  }
  from->m_weight_interpolator->accept(
    from->m_weight_interpolator,
    (vostok::animation::interpolator_comparer *)&v29,
    to->m_weight_interpolator);
  v25 = this->m_equal && !v29;
  this->m_equal = v25;
  if ( to->m_override_existing_animation )
  {
    v28 = 0;
    if ( v25 )
    {
      m_animation_state = v4->m_animation_state;
      v27 = to->m_animation_state;
      if ( m_animation_state->animation_interval_id == v27->animation_interval_id
        && m_animation_state->animation_interval_time == v27->animation_interval_time )
      {
        v28 = 1;
      }
    }
    this->m_equal = v28;
  }
  vostok::animation::mixing::computed_operands_count(v4, &v31, (int)to);
  is_new_driving_animation = v31.second;
  vostok::animation::mixing::n_ary_tree_comparer::new_animation(
    (unsigned int *)&from,
    this,
    to,
    &is_new_driving_animation,
    &v30,
    (const void *)1);
  this->m_needed_buffer_size += 4 * (is_new_driving_animation + v31.first);
  vostok::animation::mixing::n_ary_tree_comparer::add_operands(v4, this, to, from != 0);
}
