vostok::animation::mixing::n_ary_tree_animation_node *__userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::remove_animation@<eax>(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_animation_node *animation@<eax>,
        vostok::animation::mixing::n_ary_tree_animation_node *const weight_driving_animation,
        int is_new_driving_animation)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v4; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *m_weight_interpolator; // ecx
  BOOL v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // ebp
  vostok::animation::mixing::n_ary_tree_animation_node *v12; // eax
  vostok::mutable_buffer *v13; // eax
  int v14; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v15; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v16; // ecx
  const vostok::math::float4x4 *v17; // xmm0_4
  int *v18; // edx
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v19; // ecx
  vostok::animation::mixing::n_ary_tree_base_node *v20; // eax
  char v21; // al
  unsigned int m_time_synchronization_group_id; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *m_time_root; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v24; // eax
  unsigned int v25; // edx
  unsigned int v26; // ebp
  vostok::mutable_buffer *m_buffer; // eax
  vostok::animation::mixing::n_ary_tree_base_node **v28; // ebx
  int v29; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v30; // ecx
  const vostok::math::float4x4 *v31; // xmm0_4
  vostok::animation::mixing::n_ary_tree_base_node *m_result; // ecx
  vostok::mutable_buffer *v33; // eax
  vostok::animation::mixing::n_ary_tree_weight_transition_node *m_data; // ebx
  bool v35; // zf
  BOOL v36; // eax
  int v37; // ecx
  vostok::mutable_buffer *v38; // eax
  char *v39; // edx
  vostok::mutable_buffer *v40; // eax
  vostok::animation::mixing::n_ary_tree_base_node **v41; // edx
  int v42; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v43; // ecx
  void (__thiscall *v44)(struct vostok::animation::mixing::n_ary_tree_n_ary_operation_node *); // eax
  int v45; // ecx
  vostok::animation::mixing::n_ary_tree_base_node **v46; // ebp
  vostok::animation::mixing::n_ary_tree_base_node *v47; // ecx
  vostok::animation::mixing::n_ary_tree_base_node **v48; // eax
  vostok::mutable_buffer *v49; // eax
  char *v50; // ebp
  const vostok::animation::base_interpolator *v51; // eax
  const vostok::animation::base_interpolator *v52; // eax
  int v53; // ecx
  vostok::animation::mixing::n_ary_tree_base_node **v54; // edx
  vostok::animation::mixing::n_ary_tree_animation_node *v55; // edx
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v56; // ecx
  int v57; // ecx
  vostok::mutable_buffer *v58; // eax
  int v59; // eax
  const vostok::math::float4x4 *v60; // xmm0_4
  float v61; // [esp+8h] [ebp-34h]
  bool v62; // [esp+10h] [ebp-2Ch]
  vostok::animation::mixing::n_ary_tree_base_node **multiplicands; // [esp+20h] [ebp-1Ch] BYREF
  vostok::animation::mixing::n_ary_tree_weight_transition_node *transition; // [esp+24h] [ebp-18h]
  unsigned int operands_offset; // [esp+28h] [ebp-14h] BYREF
  vostok::animation::mixing::n_ary_tree_animation_node *result; // [esp+2Ch] [ebp-10h] BYREF
  vostok::animation::mixing::n_ary_tree_base_node **e; // [esp+30h] [ebp-Ch]
  float animation_interval_time; // [esp+34h] [ebp-8h] BYREF
  unsigned int animation_interval_id; // [esp+38h] [ebp-4h] BYREF

  v4 = weight_driving_animation;
  if ( weight_driving_animation )
  {
    m_weight_interpolator = (vostok::animation::mixing::n_ary_tree_animation_node *)weight_driving_animation->m_weight_interpolator;
    weight_driving_animation = m_weight_interpolator;
  }
  else
  {
    weight_driving_animation = (vostok::animation::mixing::n_ary_tree_animation_node *const)animation->m_weight_interpolator;
    m_weight_interpolator = weight_driving_animation;
  }
  if ( ((double (__thiscall *)(vostok::animation::mixing::n_ary_tree_animation_node *))m_weight_interpolator->is_time_scale)(m_weight_interpolator) == 0.0 )
    return 0;
  if ( !animation->m_is_transitting_to_zero || (_BYTE)is_new_driving_animation )
  {
    if ( animation->m_time_driving_animation
      || !animation->m_operands_count
      || (v21 = (*((int (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
                 + 3))(animation[1].__vftable),
          is_new_driving_animation = 1,
          !v21) )
    {
      is_new_driving_animation = 0;
    }
    m_time_synchronization_group_id = animation->m_time_synchronization_group_id;
    LOBYTE(multiplicands) = 1;
    if ( m_time_synchronization_group_id != -1 )
    {
      m_time_root = this->m_to->m_time_root;
      if ( m_time_root )
      {
        while ( m_time_root->m_time_synchronization_group_id != m_time_synchronization_group_id )
        {
          m_time_root = m_time_root->m_next_time_animation;
          if ( !m_time_root )
            goto LABEL_38;
        }
        if ( m_time_root != animation )
        {
          LOBYTE(multiplicands) = 0;
          is_new_driving_animation = 0;
        }
      }
    }
LABEL_38:
    v24 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_animation(
            animation,
            &operands_offset,
            this,
            (const vostok::animation::mixing::animation_state *)animation,
            v4,
            1u,
            (unsigned int *)&is_new_driving_animation,
            &animation_interval_id,
            &animation_interval_time,
            1,
            *(float *)&multiplicands);
    v25 = operands_offset;
    v26 = is_new_driving_animation;
    result = v24;
    m_buffer = this->m_buffer;
    v28 = (vostok::animation::mixing::n_ary_tree_base_node **)&m_buffer->m_data[4 * operands_offset];
    v29 = 4 * is_new_driving_animation + 4;
    m_buffer->m_data += v29;
    m_buffer->m_size -= v29;
    operands_offset = (unsigned int)v28;
    if ( v25 < v26 )
    {
      v30 = animation[1].__vftable;
      v31 = clear_value;
      this->m_cloner.m_result = 0;
      this->m_cloner.m_animation_interval_time = 0;
      LODWORD(this->m_cloner.m_time_scale_factor) = v31;
      (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, vostok::animation::mixing::n_ary_tree_cloner *))v30->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
       + 2))(
        v30,
        &this->m_cloner);
      m_result = this->m_cloner.m_result;
      LODWORD(this->m_cloner.m_time_scale_factor) = clear_value;
      *v28 = m_result;
      operands_offset = (unsigned int)(v28 + 1);
    }
    v33 = this->m_buffer;
    m_data = (vostok::animation::mixing::n_ary_tree_weight_transition_node *)v33->m_data;
    v33->m_data += 20;
    v33->m_size -= 20;
    v35 = animation->m_operands_count == 0;
    transition = m_data;
    v36 = !v35
       && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
           + 3))(animation[1].__vftable);
    v37 = animation->m_operands_count - v36;
    if ( v37 )
    {
      if ( v37 == 1 )
      {
        v57 = *((_DWORD *)&animation[1].__vftable
              + ((*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
                  + 3))(animation[1].__vftable) != 0));
        this->m_cloner.m_result = 0;
        this->m_cloner.m_animation_interpolator = 0;
        (*(void (__thiscall **)(int, vostok::animation::mixing::n_ary_tree_cloner *))(*(_DWORD *)v57 + 8))(
          v57,
          &this->m_cloner);
        v45 = (int)this->m_cloner.m_result;
        this->m_cloner.m_animation_interpolator = 0;
        is_new_driving_animation = v45;
      }
      else
      {
        v38 = this->m_buffer;
        v39 = v38->m_data;
        v38->m_data += 8;
        v38->m_size -= 8;
        is_new_driving_animation = (int)v39;
        if ( v39 )
        {
          *((_DWORD *)v39 + 1) = v37;
          *(_DWORD *)v39 = &vostok::animation::mixing::n_ary_tree_multiplication_node::`vftable';
        }
        v40 = this->m_buffer;
        v41 = (vostok::animation::mixing::n_ary_tree_base_node **)v40->m_data;
        v42 = v37;
        v40->m_data += 4 * v37;
        v40->m_size -= 4 * v37;
        v43 = animation[1].__vftable;
        v44 = v43->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node;
        multiplicands = v41;
        v45 = (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v44 + 3))(v43) != 0;
        v46 = (vostok::animation::mixing::n_ary_tree_base_node **)(&animation[1].__vftable + v45);
        for ( e = &v46[v42]; v46 != e; multiplicands = v48 + 1 )
        {
          v47 = *v46;
          this->m_cloner.m_result = 0;
          this->m_cloner.m_animation_interpolator = 0;
          v47->accept(v47, &this->m_cloner);
          v48 = multiplicands;
          v45 = (int)this->m_cloner.m_result;
          this->m_cloner.m_animation_interpolator = 0;
          *v48 = (vostok::animation::mixing::n_ary_tree_base_node *)v45;
          ++v46;
        }
        m_data = transition;
      }
    }
    else
    {
      v58 = this->m_buffer;
      v45 = (int)v58->m_data;
      v58->m_data += 12;
      v58->m_size -= 12;
      is_new_driving_animation = v45;
      if ( v45 )
      {
        v45 = (int)result->m_weight_interpolator;
        v59 = is_new_driving_animation;
        v60 = clear_value;
        *(_DWORD *)is_new_driving_animation = &vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
        *(_DWORD *)(v59 + 4) = v45;
        *(_DWORD *)(v59 + 8) = v60;
      }
    }
    v49 = this->m_buffer;
    v50 = v49->m_data;
    v49->m_data += 12;
    v49->m_size -= 12;
    if ( v50 )
    {
      v51 = vostok::animation::mixing::n_ary_tree_cloner::clone(
              (vostok::animation::mixing::n_ary_tree_cloner *)v45,
              (int)&this->m_cloner,
              (const vostok::animation::base_interpolator *)weight_driving_animation,
              v62);
      *(_DWORD *)v50 = &vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
      *((_DWORD *)v50 + 1) = v51;
      *((_DWORD *)v50 + 2) = 0;
    }
    if ( m_data )
    {
      e = (vostok::animation::mixing::n_ary_tree_base_node **)this->m_current_time_in_ms;
      v52 = vostok::animation::mixing::n_ary_tree_cloner::clone(
              (vostok::animation::mixing::n_ary_tree_cloner *)e,
              (int)&this->m_cloner,
              (const vostok::animation::base_interpolator *)weight_driving_animation,
              v62);
      v53 = is_new_driving_animation;
      v54 = e;
      m_data->__vftable = (vostok::animation::mixing::n_ary_tree_weight_transition_node_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_transition_node::`vftable';
      m_data->m_from = (vostok::animation::mixing::n_ary_tree_base_node *)v53;
      m_data->m_to = (vostok::animation::mixing::n_ary_tree_base_node *)v50;
      m_data->m_interpolator = v52;
      m_data->m_start_time_in_ms = (unsigned int)v54;
    }
    v55 = result;
    v56 = (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)animation_interval_id;
    v61 = animation_interval_time;
    *(_DWORD *)operands_offset = m_data;
    return vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation_node(
             v56,
             (int)this,
             v55,
             animation->m_animation_state,
             (unsigned int)v56,
             v61,
             0);
  }
  else
  {
    v9 = animation->m_operands_count
      && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
          + 3))(animation[1].__vftable);
    v10 = animation->m_time_synchronization_group_id;
    v11 = animation->m_operands_count - v9;
    weight_driving_animation = (vostok::animation::mixing::n_ary_tree_animation_node *const)v9;
    LOBYTE(is_new_driving_animation) = 1;
    if ( v10 != -1 )
    {
      v12 = this->m_to->m_time_root;
      if ( v12 )
      {
        while ( v12->m_time_synchronization_group_id != v10 )
        {
          v12 = v12->m_next_time_animation;
          if ( !v12 )
            goto LABEL_19;
        }
        if ( v12 != animation )
        {
          LOBYTE(is_new_driving_animation) = 0;
          weight_driving_animation = 0;
        }
      }
    }
LABEL_19:
    transition = (vostok::animation::mixing::n_ary_tree_weight_transition_node *)vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_animation(
                                                                                   animation,
                                                                                   (unsigned int *)&multiplicands,
                                                                                   this,
                                                                                   (const vostok::animation::mixing::animation_state *)animation,
                                                                                   v4,
                                                                                   v11,
                                                                                   (unsigned int *)&weight_driving_animation,
                                                                                   &operands_offset,
                                                                                   (float *)&result,
                                                                                   1,
                                                                                   *(float *)&is_new_driving_animation);
    v13 = this->m_buffer;
    is_new_driving_animation = (int)&v13->m_data[4 * (_DWORD)multiplicands];
    v14 = 4 * ((_DWORD)weight_driving_animation + v11);
    v13->m_data += v14;
    v13->m_size -= v14;
    v15 = animation + 1;
    weight_driving_animation = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)animation
                                                                                      + 4 * animation->m_operands_count
                                                                                      + 88);
    if ( &animation[1] != weight_driving_animation )
    {
      do
      {
        if ( (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v15->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
              + 3))(v15->__vftable) )
        {
          if ( multiplicands )
          {
            is_new_driving_animation -= 4;
          }
          else
          {
            v16 = v15->__vftable;
            v17 = clear_value;
            this->m_cloner.m_result = 0;
            this->m_cloner.m_animation_interval_time = 0;
            LODWORD(this->m_cloner.m_time_scale_factor) = v17;
            (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, vostok::animation::mixing::n_ary_tree_cloner *))v16->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
             + 2))(
              v16,
              &this->m_cloner);
            v14 = (int)this->m_cloner.m_result;
            v18 = (int *)is_new_driving_animation;
            LODWORD(this->m_cloner.m_time_scale_factor) = clear_value;
            *v18 = v14;
          }
        }
        else
        {
          v19 = v15->__vftable;
          this->m_cloner.m_result = 0;
          this->m_cloner.m_animation_interpolator = 0;
          (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, vostok::animation::mixing::n_ary_tree_cloner *))v19->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
           + 2))(
            v19,
            &this->m_cloner);
          v20 = this->m_cloner.m_result;
          v14 = is_new_driving_animation;
          this->m_cloner.m_animation_interpolator = 0;
          *(_DWORD *)v14 = v20;
        }
        is_new_driving_animation += 4;
        v15 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)v15 + 4);
      }
      while ( v15 != weight_driving_animation );
    }
    return vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation_node(
             (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)v14,
             (int)this,
             (vostok::animation::mixing::n_ary_tree_animation_node *)transition,
             animation->m_animation_state,
             operands_offset,
             *(float *)&result,
             0);
  }
}
