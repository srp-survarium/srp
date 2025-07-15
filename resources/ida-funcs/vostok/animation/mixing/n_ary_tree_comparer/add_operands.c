void __userpurge vostok::animation::mixing::n_ary_tree_comparer::add_operands(
        vostok::animation::mixing::n_ary_tree_animation_node *from@<eax>,
        vostok::animation::mixing::n_ary_tree_comparer *this,
        vostok::animation::mixing::n_ary_tree_animation_node *to,
        const bool skip_time_scale_node)
{
  vostok::animation::mixing::n_ary_tree_comparer **v4; // esi
  unsigned int m_operands_count; // eax
  vostok::animation::mixing::n_ary_tree_subtraction_node **p_m_operands_count; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl **v7; // ecx
  vostok::animation::mixing::n_ary_tree_comparer *v8; // ecx
  int v9; // ecx
  vostok::animation::mixing::n_ary_tree_comparer *v10; // ecx
  vostok::animation::mixing::n_ary_tree_comparer *v11; // eax
  const vostok::animation::base_interpolator *m_weight_interpolator; // edi
  const vostok::animation::base_interpolator *v13; // esi
  const vostok::animation::base_interpolator *v14; // eax
  vostok::animation::mixing::n_ary_tree_subtraction_node *v15; // esi
  vostok::animation::mixing::n_ary_tree_comparer *v16; // eax
  double v17; // st6
  vostok::animation::mixing::n_ary_tree_subtraction_node *v18; // ecx
  vostok::animation::mixing::n_ary_tree_base_node *v19; // [esp+0h] [ebp-3Ch]
  _DWORD v20[3]; // [esp+10h] [ebp-2Ch] BYREF
  char v21; // [esp+1Ch] [ebp-20h]
  void **v22; // [esp+20h] [ebp-1Ch] BYREF
  const vostok::animation::base_interpolator *right; // [esp+24h] [ebp-18h]
  vostok::animation::mixing::n_ary_tree_subtraction_node **v24; // [esp+28h] [ebp-14h]
  void **v25; // [esp+2Ch] [ebp-10h] BYREF
  vostok::animation::mixing::n_ary_tree_comparer **v26; // [esp+30h] [ebp-Ch]
  vostok::animation::mixing::n_ary_tree_comparer **v27; // [esp+34h] [ebp-8h]
  vostok::animation::mixing::n_ary_tree_comparer *v28; // [esp+4Ch] [ebp+10h]

  v20[2] = 0;
  v4 = (vostok::animation::mixing::n_ary_tree_comparer **)&from[1];
  m_operands_count = from->m_operands_count;
  v20[1] = this->m_animated_object_resolver;
  v26 = &v4[m_operands_count];
  p_m_operands_count = (vostok::animation::mixing::n_ary_tree_subtraction_node **)&to[1];
  v7 = &to[1].__vftable + to->m_operands_count;
  v20[0] = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  v21 = 0;
  v27 = v4;
  v24 = (vostok::animation::mixing::n_ary_tree_subtraction_node **)v7;
  if ( m_operands_count
    && ((unsigned __int8 (__thiscall *)(vostok::animation::mixing::n_ary_tree_comparer *))LODWORD((*v4)->m_animated_objects->transform.i.w))(*v4) )
  {
    if ( to->m_operands_count && (*p_m_operands_count)->is_time_scale(*p_m_operands_count) )
    {
      if ( !skip_time_scale_node )
        vostok::animation::mixing::n_ary_tree_comparer::new_time_scale_transition(
          v8,
          (int)this,
          *v4,
          *p_m_operands_count);
      v27 = ++v4;
LABEL_15:
      p_m_operands_count = (vostok::animation::mixing::n_ary_tree_subtraction_node **)&to[1].m_operands_count;
      goto LABEL_16;
    }
    if ( !skip_time_scale_node )
    {
      vostok::animation::mixing::n_ary_tree_comparer::new_time_scale_transition(this, *v4);
      v4 = v27;
    }
    v27 = ++v4;
  }
  else if ( to->m_operands_count && (*p_m_operands_count)->is_time_scale(*p_m_operands_count) )
  {
    if ( !skip_time_scale_node )
    {
      vostok::animation::mixing::n_ary_tree_comparer::new_time_scale_transition(
        this,
        (vostok::animation::mixing::n_ary_tree_comparer *)*p_m_operands_count,
        v9);
      v4 = v27;
    }
    goto LABEL_15;
  }
LABEL_16:
  right = 0;
  v22 = &vostok::animation::mixing::n_ary_tree_interpolator_selector::`vftable';
  if ( v4 == v26 )
    goto LABEL_37;
  while ( p_m_operands_count != v24 )
  {
    if ( vostok::animation::mixing::n_ary_tree_node_comparer::compare(
           (vostok::animation::mixing::n_ary_tree_node_comparer *)*v4,
           (int)v20,
           *p_m_operands_count,
           v19) == equal )
    {
      v10 = *v27;
      v11 = this;
      goto LABEL_26;
    }
    m_weight_interpolator = to->m_weight_interpolator;
    (*p_m_operands_count)->accept(*p_m_operands_count, (vostok::animation::mixing::n_ary_tree_visitor *)&v22);
    v13 = right;
    v14 = vostok::animation::compare(right);
    if ( !v14 )
    {
      v15 = *p_m_operands_count;
      v16 = *v27;
      this->m_equal = 0;
      v28 = v16;
      v17 = ((double (__thiscall *)(unsigned int))*(_DWORD *)(*(_DWORD *)v15->m_operands_count + 16))(v15->m_operands_count);
      v11 = this;
      if ( v17 == 0.0 )
      {
        v10 = (vostok::animation::mixing::n_ary_tree_comparer *)v15;
LABEL_26:
        vostok::animation::mixing::n_ary_tree_comparer::increase_buffer_size(v10, (int)v11);
      }
      else
      {
        vostok::animation::mixing::n_ary_tree_comparer::increase_buffer_size(v28, (int)this);
        vostok::animation::mixing::n_ary_tree_comparer::increase_buffer_size(
          (vostok::animation::mixing::n_ary_tree_comparer *)v15,
          (int)this);
        this->m_needed_buffer_size += 20;
      }
      ++v27;
      goto LABEL_29;
    }
    if ( v14 != (const vostok::animation::base_interpolator *)1 )
    {
      vostok::animation::mixing::n_ary_tree_comparer::new_weight_transition(
        this,
        (vostok::animation::mixing::n_ary_tree_comparer *)*p_m_operands_count,
        v13,
        *(float *)&v19);
LABEL_29:
      ++p_m_operands_count;
      goto LABEL_30;
    }
    vostok::animation::mixing::n_ary_tree_comparer::new_weight_transition(
      this,
      m_weight_interpolator,
      *v27++,
      *(float *)&v19);
LABEL_30:
    v4 = v27;
    if ( v27 == v26 )
      break;
  }
  if ( v4 != v26 )
  {
    while ( 1 )
    {
      vostok::animation::mixing::n_ary_tree_comparer::new_weight_transition(
        this,
        to->m_weight_interpolator,
        *v4,
        *(float *)&v19);
      if ( ++v27 == v26 )
        break;
      v4 = v27;
    }
  }
LABEL_37:
  while ( p_m_operands_count != v24 )
  {
    v18 = *p_m_operands_count;
    v26 = 0;
    v25 = &vostok::animation::mixing::n_ary_tree_interpolator_selector::`vftable';
    v18->accept(v18, (vostok::animation::mixing::n_ary_tree_visitor *)&v25);
    vostok::animation::mixing::n_ary_tree_comparer::new_weight_transition(
      this,
      (vostok::animation::mixing::n_ary_tree_comparer *)*p_m_operands_count++,
      (const vostok::animation::base_interpolator *)v26,
      *(float *)&v19);
  }
}
