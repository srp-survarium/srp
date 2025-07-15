void __userpurge vostok::animation::mixing::n_ary_tree::update_synchronization_group_using_integration(
        vostok::animation::mixing::n_ary_tree_time_scale_calculator *animation_node@<esi>,
        vostok::animation::mixing::n_ary_tree *this,
        char *start_time_in_ms,
        const unsigned int target_time_in_ms)
{
  bool v5; // zf
  float m_time_scale; // edi
  vostok::animation::mixing::n_ary_tree_base_node *m_result; // ecx
  int v9; // eax
  unsigned int m_current_time_in_ms; // ecx
  float v11; // xmm0_4
  char *v12; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *m_animation; // edi
  vostok::animation::mixing::n_ary_tree_base_node *v14; // eax
  unsigned int v15; // edi
  float v16; // xmm0_4
  double v17; // st7
  char *v18; // edx
  float v19; // xmm0_4
  float v20; // xmm0_4
  const vostok::animation::base_interpolator *m_interpolator; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *i; // edi
  vostok::animation::mixing::animation_state *m_animation_state; // eax
  float v24; // [esp+10h] [ebp-5Ch]
  unsigned int v25; // [esp+14h] [ebp-58h]
  float v26; // [esp+14h] [ebp-58h]
  struct vostok::animation::mixing::n_ary_tree_animation_node *v27; // [esp+18h] [ebp-54h]
  char v28[8]; // [esp+1Ch] [ebp-50h] BYREF
  vostok::animation::mixing::n_ary_tree_base_node *v29; // [esp+24h] [ebp-48h]
  float v30; // [esp+38h] [ebp-34h]
  float v31; // [esp+44h] [ebp-28h]
  float v32; // [esp+48h] [ebp-24h]
  float v33; // [esp+4Ch] [ebp-20h]
  vostok::animation::mixing::n_ary_tree *v34; // [esp+50h] [ebp-1Ch]
  float v35; // [esp+54h] [ebp-18h]
  char *v36; // [esp+58h] [ebp-14h]
  unsigned int v37; // [esp+5Ch] [ebp-10h]
  unsigned int v38; // [esp+60h] [ebp-Ch]
  vostok::animation::mixing::n_ary_tree_base_node *v39; // [esp+64h] [ebp-8h]
  float v40; // [esp+68h] [ebp-4h]
  char v41; // [esp+77h] [ebp+Bh]

  v5 = animation_node->m_animation == 0;
  m_time_scale = animation_node->m_time_scale;
  v31 = m_time_scale;
  if ( v5 )
  {
    v39 = 0;
    m_result = 0;
  }
  else
  {
    m_result = animation_node[2].m_result;
    v39 = m_result;
  }
  if ( !m_result || (v41 = 1, !m_result->is_time_scale(m_result)) )
    v41 = 0;
  v9 = 20 * *(_DWORD *)(LODWORD(m_time_scale) + 92);
  m_current_time_in_ms = animation_node->m_current_time_in_ms;
  v40 = *(float *)(LODWORD(m_time_scale) + 100);
  v11 = *(float *)(v9 + m_current_time_in_ms + 16);
  v38 = 0;
  v35 = v11;
  v34 = this;
  v37 = (start_time_in_ms - (char *)this) / 0xAu;
  while ( 1 )
  {
    v12 = (char *)&this->m_time_root + 2;
    if ( v38 >= v37 )
      v12 = start_time_in_ms;
    vostok::animation::mixing::n_ary_tree_time_scale_calculator::n_ary_tree_time_scale_calculator(
      animation_node,
      (int)v28,
      SLODWORD(v40),
      (unsigned int)v12,
      *(float *)&this,
      v25,
      v27);
    if ( v41 )
    {
      m_animation = animation_node->m_animation;
      v39->accept(v39, (vostok::animation::mixing::n_ary_tree_visitor *)v28);
      v14 = v29;
      if ( !v29 )
        v14 = v39;
      v39 = v14;
      if ( m_animation != animation_node->m_animation )
      {
        v39 = 0;
        v41 = 0;
      }
    }
    v15 = v38;
    if ( v38 >= v37 )
    {
      if ( v41 )
        v19 = v30;
      else
        v19 = s_bm_current_air_resistance;
      v18 = start_time_in_ms;
      v32 = v19;
      v17 = v19;
    }
    else
    {
      if ( v41 )
        v16 = v30;
      else
        v16 = s_bm_current_air_resistance;
      v33 = v16;
      v17 = v16;
      v18 = (char *)&this->m_time_root + 2;
    }
    v24 = v17;
    v40 = vostok::animation::mixing::n_ary_tree::computed_animation_time(
            (vostok::animation::mixing::n_ary_tree_animation_node *)animation_node,
            (unsigned int)v18,
            (vostok::animation::mixing::n_ary_tree *)LODWORD(v40),
            (unsigned int)this,
            (unsigned int)this,
            v24,
            v26);
    if ( v40 <= 0.0 )
      v20 = 0.0;
    else
      v20 = v40;
    if ( v35 <= v20 )
      v20 = v35;
    v40 = v20;
    if ( v15 >= v37 )
      v36 = start_time_in_ms;
    else
      v36 = (char *)&this->m_time_root + 2;
    if ( *(_BYTE *)(LODWORD(v31) + 116) )
      vostok::animation::mixing::n_ary_tree::accumulate_object_movement(
        (vostok::animation::mixing::n_ary_tree_animation_node *)animation_node,
        (vostok::animation::mixing::n_ary_tree *)LODWORD(v40),
        (unsigned int)v36,
        v25);
    m_interpolator = animation_node[1].m_interpolator;
    if ( m_interpolator != (const vostok::animation::base_interpolator *)-1 )
    {
      for ( i = animation_node[1].m_animation;
            i && (const vostok::animation::base_interpolator *)i->m_time_synchronization_group_id == m_interpolator;
            i = i->m_next_time_animation )
      {
        m_animation_state = i->m_animation_state;
        if ( m_animation_state->are_there_any_weight_transitions )
          vostok::animation::mixing::n_ary_tree::accumulate_object_movement(
            i,
            COERCE_VOSTOK_ANIMATION_MIXING_N_ARY_TREE_((float)(i->m_animation_intervals[m_animation_state->animation_interval_id].m_length
                                                             / v35) * v40),
            (unsigned int)v36,
            v25);
      }
    }
    ++v38;
    v34 = (vostok::animation::mixing::n_ary_tree *)((char *)v34 + 10);
    if ( v38 > v37 )
      break;
    this = v34;
  }
}
