void __userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_time_scale(
        vostok::animation::mixing::n_ary_tree_animation_node *new_time_driving_animation@<eax>,
        const vostok::animation::base_interpolator *this,
        unsigned int *animation_interval_id,
        float *animation_interval_time)
{
  unsigned int m_time_synchronization_group_id; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *i; // esi
  vostok::animation::mixing::n_ary_tree_animation_node *j; // eax
  vostok::animation::mixing::animation_state *m_animation_state; // eax
  unsigned int v10; // eax
  const vostok::animation::mixing::animation_interval *m_animation_intervals; // edx
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v15; // edi
  float v16; // xmm0_4
  void ***v17; // eax
  int v18; // eax
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *accept; // edi
  bool v20; // zf
  vostok::animation::mixing::n_ary_tree_node_cloner *v21; // ecx
  vostok::animation::mixing::n_ary_tree_base_node *v22; // edi
  vostok::animation::mixing::n_ary_tree_node_cloner *v23; // ecx
  const vostok::animation::base_interpolator *v24; // eax
  char *v25; // ecx
  unsigned int v26; // edx
  vostok::mutable_buffer *v27; // ecx
  char *v28; // ecx
  unsigned int v29; // edx
  vostok::mutable_buffer *v30; // edx
  char *v31; // esi
  const vostok::animation::base_interpolator *v32; // eax
  char *interpolated_value; // ecx
  unsigned int v34; // edx
  vostok::mutable_buffer *v35; // ebx
  unsigned int v36; // [esp+0h] [ebp-4Ch]
  bool v37; // [esp+0h] [ebp-4Ch]
  struct vostok::animation::mixing::n_ary_tree_animation_node *v38; // [esp+4h] [ebp-48h]
  _BYTE v39[12]; // [esp+Ch] [ebp-40h] BYREF
  void ***v40; // [esp+18h] [ebp-34h]
  float v41; // [esp+28h] [ebp-24h]
  vostok::animation::mixing::n_ary_tree_target_time_scale_calculator v42; // [esp+34h] [ebp-18h] BYREF
  void **v43; // [esp+3Ch] [ebp-10h] BYREF
  float v44; // [esp+40h] [ebp-Ch]
  float v45; // [esp+44h] [ebp-8h]
  const vostok::animation::base_interpolator *interpolator; // [esp+54h] [ebp+8h]
  char interpolator_3; // [esp+57h] [ebp+Bh]
  float v48; // [esp+58h] [ebp+Ch]
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v49; // [esp+5Ch] [ebp+10h]

  m_time_synchronization_group_id = new_time_driving_animation->m_time_synchronization_group_id;
  for ( i = (vostok::animation::mixing::n_ary_tree_animation_node *)this[18].clone; i; i = i->m_next_weight_animation )
  {
    if ( !i->m_time_driving_animation && i->m_time_synchronization_group_id == m_time_synchronization_group_id )
    {
      if ( !i->m_animation_state->is_freezed )
      {
        for ( j = (vostok::animation::mixing::n_ary_tree_animation_node *)this[19].clone; j; j = j->m_next_time_animation )
        {
          if ( j->m_time_synchronization_group_id == m_time_synchronization_group_id )
          {
            if ( j != new_time_driving_animation )
              return;
            break;
          }
        }
        if ( new_time_driving_animation->m_override_existing_animation )
          m_animation_state = new_time_driving_animation->m_animation_state;
        else
          m_animation_state = i->m_animation_state;
        v10 = m_animation_state->animation_interval_id;
        m_animation_intervals = i->m_animation_intervals;
        *animation_interval_id = v10;
        v12 = new_time_driving_animation->m_animation_intervals[v10].m_length / m_animation_intervals[v10].m_length;
        if ( new_time_driving_animation->m_is_positive_event_direction == i->m_is_positive_event_direction )
          v13 = s_bm_current_air_resistance;
        else
          v13 = FLOAT_N1_0;
        v20 = !new_time_driving_animation->m_override_existing_animation;
        v44 = v13 * v12;
        if ( v20 )
          v14 = i->m_animation_state->animation_interval_time * v12;
        else
          v14 = new_time_driving_animation->m_animation_state->animation_interval_time;
        *animation_interval_time = v14;
        v48 = v14;
        vostok::animation::mixing::n_ary_tree_time_scale_calculator::n_ary_tree_time_scale_calculator(
          0,
          (int)v39,
          0,
          (unsigned int)this[33].__vftable,
          *(float *)&this[33].__vftable,
          v36,
          v38);
        if ( new_time_driving_animation->m_operands_count
          && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))new_time_driving_animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
              + 3))(new_time_driving_animation[1].__vftable) )
        {
          v15 = new_time_driving_animation[1].__vftable;
          v49 = v15;
        }
        else
        {
          v49 = 0;
          v15 = 0;
        }
        if ( v15
          && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v15->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
              + 3))(v15) )
        {
          interpolator_3 = 1;
          (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, _BYTE *))v15->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
           + 2))(
            v15,
            v39);
          v16 = v41;
        }
        else
        {
          v16 = s_bm_current_air_resistance;
          interpolator_3 = 0;
        }
        v45 = v16;
        if ( interpolator_3 )
        {
          v17 = v40;
        }
        else
        {
          v43 = &vostok::animation::instant_interpolator::`vftable';
          v17 = &v43;
        }
        interpolator = (const vostok::animation::base_interpolator *)v17;
        vostok::animation::mixing::n_ary_tree_target_time_scale_calculator::n_ary_tree_target_time_scale_calculator(
          &v42,
          i);
        accept = v49;
        if ( v45 != (float)(*(float *)(v18 + 4) * v44)
          && (!v49
           || !(*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v49->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
                + 5))(v49)) )
        {
          goto LABEL_42;
        }
        if ( v49 )
        {
          if ( (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v49->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
                + 5))(v49) )
            accept = (vostok::animation::mixing::n_ary_tree_animation_node_vtbl *)v49->accept;
          v20 = v48 == *(float *)&accept->is_time_scale;
        }
        else
        {
          v20 = v48 == 0.0;
        }
        if ( !v20 )
        {
LABEL_42:
          if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))interpolator->transition_time)(interpolator) <= 0.0 )
          {
            v32 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(v21, (int)&this[8], interpolator, v37);
            interpolated_value = (char *)this[17].interpolated_value;
            if ( interpolated_value )
            {
              v34 = (unsigned int)this[33].__vftable;
              *((float *)interpolated_value + 2) = v45;
              *((_DWORD *)interpolated_value + 1) = v32;
              *(_DWORD *)interpolated_value = &vostok::animation::mixing::n_ary_tree_time_scale_node::`vftable';
              *((float *)interpolated_value + 3) = v48;
              *((_DWORD *)interpolated_value + 4) = v34;
            }
          }
          else
          {
            v22 = 0;
            if ( i->m_operands_count
              && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))i[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
                  + 3))(i[1].__vftable) )
            {
              v23 = (vostok::animation::mixing::n_ary_tree_node_cloner *)i[1].__vftable;
            }
            else
            {
              v23 = 0;
            }
            if ( v23 )
              v22 = (vostok::animation::mixing::n_ary_tree_base_node *)vostok::animation::mixing::n_ary_tree_node_cloner::clone(
                                                                         v23,
                                                                         (vostok::animation::mixing::n_ary_tree_addition_node *)&this[8],
                                                                         (vostok::animation::mixing::n_ary_tree_addition_node_vtbl *)LODWORD(v44));
            v24 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(v23, (int)&this[8], interpolator, v37);
            if ( !v22 )
            {
              v25 = (char *)this[17].interpolated_value;
              if ( v25 )
              {
                v26 = (unsigned int)this[33].__vftable;
                *((float *)v25 + 2) = s_bm_current_air_resistance;
                *(_DWORD *)v25 = &vostok::animation::mixing::n_ary_tree_time_scale_node::`vftable';
                *((_DWORD *)v25 + 1) = v24;
                *((float *)v25 + 3) = v48;
                *((_DWORD *)v25 + 4) = v26;
                v22 = (vostok::animation::mixing::n_ary_tree_base_node *)v25;
              }
              else
              {
                v22 = 0;
              }
              v27 = (vostok::mutable_buffer *)this[17].__vftable;
              v27->m_data += 20;
              v27->m_size -= 20;
            }
            v28 = (char *)this[17].interpolated_value;
            if ( v28 )
            {
              v29 = (unsigned int)this[33].__vftable;
              *((float *)v28 + 2) = v45;
              *(_DWORD *)v28 = &vostok::animation::mixing::n_ary_tree_time_scale_node::`vftable';
              *((_DWORD *)v28 + 1) = v24;
              *((float *)v28 + 3) = v48;
              *((_DWORD *)v28 + 4) = v29;
            }
            else
            {
              v28 = 0;
            }
            v30 = (vostok::mutable_buffer *)this[17].__vftable;
            v30->m_data += 20;
            v30->m_size -= 20;
            v31 = (char *)this[17].interpolated_value;
            if ( v31 )
              vostok::animation::mixing::n_ary_tree_time_scale_transition_node::n_ary_tree_time_scale_transition_node(
                (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)v31,
                v22,
                (vostok::animation::mixing::n_ary_tree_base_node *)v28,
                v24,
                (unsigned int)this[33].__vftable);
          }
          v35 = (vostok::mutable_buffer *)this[17].__vftable;
          v35->m_data += 20;
          v35->m_size -= 20;
        }
      }
      return;
    }
  }
}
