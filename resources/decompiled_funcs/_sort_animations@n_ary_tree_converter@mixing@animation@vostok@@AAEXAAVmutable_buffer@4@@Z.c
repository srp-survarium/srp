void __thiscall vostok::animation::mixing::n_ary_tree_converter::sort_animations(
        vostok::animation::mixing::n_ary_tree_converter *this,
        vostok::animation::mixing::n_ary_tree_converter *buffer,
        vostok::mutable_buffer *buffera)
{
  unsigned int m_animations_root; // eax
  int v4; // ebx
  unsigned int v5; // esi
  int v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // ecx
  bool v9; // zf
  void *v10; // esp
  vostok::animation::mixing::binary_tree_animation_node *v11; // eax
  vostok::animation::mixing::binary_tree_animation_node *m_object; // edi
  vostok::animation::mixing::binary_tree_animation_node *m_weight_driving_animation; // eax
  vostok::animation::mixing::binary_tree_animation_node *v14; // ecx
  vostok::render::skeleton_model_instance *(__thiscall *v15)(vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // eax
  bool v16; // bl
  vostok::animation::mixing::binary_tree_animation_node *v17; // esi
  vostok::animation::mixing::binary_tree_animation_node *v18; // eax
  vostok::animation::mixing::binary_tree_animation_node *v19; // ecx
  vostok::render::skeleton_model_instance *(__thiscall *v20)(vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // eax
  bool v21; // bl
  vostok::animation::mixing::binary_tree_animation_node *v22; // eax
  vostok::animation::mixing::binary_tree_animation_node *v23; // ecx
  vostok::animation::mixing::binary_tree_animation_node *m_time_driving_animation; // eax
  vostok::animation::mixing::binary_tree_animation_node *v25; // ecx
  vostok::render::skeleton_model_instance *(__thiscall *v26)(vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // eax
  bool v27; // bl
  vostok::animation::mixing::binary_tree_animation_node *v28; // esi
  vostok::animation::mixing::binary_tree_animation_node *v29; // eax
  vostok::animation::mixing::binary_tree_animation_node *v30; // ecx
  vostok::render::skeleton_model_instance *(__thiscall *v31)(vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // eax
  bool v32; // bl
  vostok::animation::mixing::binary_tree_animation_node *v33; // eax
  vostok::animation::mixing::binary_tree_animation_node *v34; // ecx
  vostok::animation::mixing::binary_tree_animation_node *v35; // ecx
  vostok::animation::mixing::binary_tree_animation_node **v36; // eax
  vostok::animation::mixing::binary_tree_animation_node *v37; // ecx
  vostok::animation::mixing::binary_tree_animation_node *v38; // eax
  vostok::animation::mixing::binary_tree_animation_node *v39; // ecx
  vostok::animation::mixing::binary_tree_animation_node **v40; // ebx
  vostok::animation::mixing::binary_tree_animation_node **v41; // edi
  int v42; // esi
  int v43; // eax
  int k; // ecx
  vostok::animation::mixing::binary_tree_animation_node **v45; // esi
  vostok::animation::mixing::binary_tree_animation_node **v46; // eax
  vostok::animation::mixing::binary_tree_animation_node *v47; // eax
  unsigned int m_weight_synchronization_group_id; // ecx
  vostok::animation::mixing::binary_tree_animation_node *v49; // ecx
  vostok::animation::mixing::binary_tree_animation_node **v50; // ebx
  vostok::animation::mixing::binary_tree_base_node *binary_multipliers; // eax
  vostok::animation::mixing::binary_tree_base_node *v52; // ebx
  vostok::animation::mixing::binary_tree_base_node *v53; // eax
  vostok::animation::mixing::binary_tree_base_node *v54; // esi
  char *m_data; // eax
  char *v56; // edi
  vostok::animation::mixing::binary_tree_base_node *v57; // ecx
  void (__thiscall **v58)(_DWORD *, _DWORD); // eax
  void (__thiscall *v59)(char *, _DWORD *); // edx
  unsigned int *v60; // edi
  vostok::animation::mixing::binary_tree_animation_node **m; // esi
  vostok::animation::mixing::binary_tree_animation_node *v62; // ecx
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_animation_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *p_m_next_weight_animation; // eax
  vostok::animation::mixing::binary_tree_animation_node *v64; // edx
  vostok::animation::mixing::binary_tree_animation_node *v65; // ecx
  vostok::animation::mixing::binary_tree_animation_node *v66; // esi
  vostok::animation::mixing::binary_tree_animation_node *v67; // ecx
  vostok::animation::mixing::n_ary_tree_converter *v68[4]; // [esp+0h] [ebp-38h] BYREF
  _DWORD v69[2]; // [esp+10h] [ebp-28h] BYREF
  int v70; // [esp+18h] [ebp-20h]
  int v71; // [esp+1Ch] [ebp-1Ch]
  vostok::animation::mixing::binary_tree_animation_node **v72; // [esp+20h] [ebp-18h]
  vostok::animation::mixing::binary_tree_animation_node **__first; // [esp+24h] [ebp-14h]
  vostok::animation::mixing::binary_tree_animation_node **new_e_minus_1; // [esp+28h] [ebp-10h] BYREF
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_animation_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> i; // [esp+2Ch] [ebp-Ch]
  vostok::animation::mixing::binary_tree_animation_node **j; // [esp+30h] [ebp-8h]
  vostok::animation::mixing::binary_tree_animation_node *v77; // [esp+34h] [ebp-4h] BYREF

  m_animations_root = (unsigned int)buffer->m_animations_root;
  v4 = 0;
  v5 = 0;
  if ( m_animations_root )
  {
    ++*(_DWORD *)(m_animations_root + 16);
    v5 = m_animations_root;
  }
  while ( v5 )
  {
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v9 = (*(_DWORD *)(v5 + 16))-- == 1;
      if ( v9 )
        (**(void (__thiscall ***)(unsigned int, _DWORD))v5)(v5, 0);
      break;
    }
    v6 = *(_DWORD *)(v5 + 60);
    ++v4;
    v7 = 0;
    if ( v6 )
    {
      v7 = *(_DWORD *)(v5 + 60);
      ++*(_DWORD *)(v6 + 16);
    }
    v8 = v5;
    v5 = v7;
    v9 = (*(_DWORD *)(v8 + 16))-- == 1;
    if ( v9 )
      (**(void (__thiscall ***)(unsigned int, _DWORD))v8)(v8, 0);
  }
  v72 = (vostok::animation::mixing::binary_tree_animation_node **)(4 * v4);
  v10 = alloca(4 * v4);
  __first = (vostok::animation::mixing::binary_tree_animation_node **)v68;
  j = (vostok::animation::mixing::binary_tree_animation_node **)v68;
  v11 = buffer->m_animations_root;
  i.m_object = 0;
  if ( v11 )
  {
    ++v11->m_reference_count;
    i.m_object = v11;
  }
  m_object = i.m_object;
  while ( m_object )
  {
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v9 = m_object->m_reference_count-- == 1;
      if ( v9 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))m_object->~vostok::animation::mixing::binary_tree_base_node)(
          m_object,
          0);
      break;
    }
    m_weight_driving_animation = m_object->m_weight_driving_animation;
    v14 = 0;
    if ( m_weight_driving_animation )
    {
      ++m_weight_driving_animation->m_reference_count;
      v14 = m_weight_driving_animation;
      v15 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
    }
    else
    {
      v15 = 0;
    }
    v16 = v15 != 0;
    if ( v14 )
    {
      v9 = v14->m_reference_count-- == 1;
      if ( v9 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v14->~vostok::animation::mixing::binary_tree_base_node)(
          v14,
          0);
    }
    if ( v16 )
    {
      v17 = m_object;
      while ( 1 )
      {
        v18 = v17->m_weight_driving_animation;
        v19 = 0;
        if ( v18 )
        {
          ++v18->m_reference_count;
          v19 = v18;
          v20 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
        }
        else
        {
          v20 = 0;
        }
        v21 = v20 != 0;
        if ( v19 )
        {
          v9 = v19->m_reference_count-- == 1;
          if ( v9 )
            ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v19->~vostok::animation::mixing::binary_tree_base_node)(
              v19,
              0);
        }
        if ( !v21 )
          break;
        v22 = v17->m_weight_driving_animation;
        v23 = 0;
        if ( v22 )
        {
          ++v22->m_reference_count;
          v23 = v22;
        }
        v17 = v23;
        if ( v23 )
        {
          v9 = v23->m_reference_count-- == 1;
          if ( v9 )
            ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v23->~vostok::animation::mixing::binary_tree_base_node)(
              v23,
              0);
        }
      }
      m_object->m_weight_driving_animation = v17;
    }
    m_time_driving_animation = m_object->m_time_driving_animation;
    v25 = 0;
    if ( m_time_driving_animation )
    {
      ++m_time_driving_animation->m_reference_count;
      v25 = m_time_driving_animation;
      v26 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
    }
    else
    {
      v26 = 0;
    }
    v27 = v26 != 0;
    if ( v25 )
    {
      v9 = v25->m_reference_count-- == 1;
      if ( v9 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v25->~vostok::animation::mixing::binary_tree_base_node)(
          v25,
          0);
    }
    if ( v27 )
    {
      v28 = m_object;
      while ( 1 )
      {
        v29 = v28->m_time_driving_animation;
        v30 = 0;
        if ( v29 )
        {
          ++v29->m_reference_count;
          v30 = v29;
          v31 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
        }
        else
        {
          v31 = 0;
        }
        v32 = v31 != 0;
        if ( v30 )
        {
          v9 = v30->m_reference_count-- == 1;
          if ( v9 )
            ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v30->~vostok::animation::mixing::binary_tree_base_node)(
              v30,
              0);
        }
        if ( !v32 )
          break;
        v33 = v28->m_time_driving_animation;
        v34 = 0;
        if ( v33 )
        {
          ++v33->m_reference_count;
          v34 = v33;
        }
        v28 = v34;
        if ( v34 )
        {
          v9 = v34->m_reference_count-- == 1;
          if ( v9 )
            ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v34->~vostok::animation::mixing::binary_tree_base_node)(
              v34,
              0);
        }
      }
      v35 = i.m_object;
      i.m_object->m_time_driving_animation = v28;
      m_object = v35;
    }
    v36 = j;
    *j = m_object;
    v37 = m_object->m_next_weight_animation.m_object;
    j = v36 + 1;
    v38 = 0;
    if ( v37 )
    {
      v38 = v37;
      ++v37->m_reference_count;
    }
    v39 = m_object;
    m_object = v38;
    i.m_object = v38;
    if ( v39 )
    {
      v9 = v39->m_reference_count-- == 1;
      if ( v9 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v39->~vostok::animation::mixing::binary_tree_base_node)(
          v39,
          0);
    }
  }
  v40 = __first;
  v41 = (vostok::animation::mixing::binary_tree_animation_node **)((char *)__first + (_DWORD)v72);
  LOBYTE(new_e_minus_1) = 0;
  v72 = v41;
  if ( __first != v41 )
  {
    v42 = v41 - __first;
    v43 = v42;
    for ( k = 0; v43 != 1; ++k )
      v43 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::animation::mixing::binary_tree_animation_node * *,vostok::animation::mixing::binary_tree_animation_node *,int,animation_less_predicate>(
      (animation_less_predicate)v42,
      __first,
      v41,
      0,
      2 * k,
      new_e_minus_1);
    if ( v42 <= 16 )
    {
      LOBYTE(v77) = (_BYTE)new_e_minus_1;
      stlp_std::priv::__insertion_sort<vostok::animation::mixing::binary_tree_animation_node * *,vostok::animation::mixing::binary_tree_animation_node *,animation_less_predicate>(
        v40,
        v41,
        &v77);
    }
    else
    {
      stlp_std::priv::__insertion_sort<vostok::animation::mixing::binary_tree_animation_node * *,vostok::animation::mixing::binary_tree_animation_node *,animation_less_predicate>(
        v40,
        v40 + 16,
        (vostok::animation::mixing::binary_tree_animation_node **)&new_e_minus_1);
      stlp_std::priv::__unguarded_insertion_sort_aux<vostok::animation::mixing::binary_tree_animation_node * *,vostok::animation::mixing::binary_tree_animation_node *,animation_less_predicate>(
        v40 + 16,
        v41);
    }
  }
  v45 = v40 + 1;
  v46 = v40;
  new_e_minus_1 = v40 + 1;
  if ( v40 + 1 != v41 )
  {
    do
    {
      v47 = *v46;
      m_weight_synchronization_group_id = v47->m_weight_synchronization_group_id;
      if ( m_weight_synchronization_group_id != -1
        && m_weight_synchronization_group_id == (*v45)->m_weight_synchronization_group_id )
      {
        v49 = v47->m_weight_driving_animation;
        if ( v49 )
        {
          v9 = ++v49->m_reference_count == 1;
          --v49->m_reference_count;
          if ( v9 )
            ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v49->~vostok::animation::mixing::binary_tree_base_node)(
              v49,
              0);
        }
      }
      v46 = v45++;
    }
    while ( v45 != v41 );
    v45 = new_e_minus_1;
  }
  i.m_object = (vostok::animation::mixing::binary_tree_animation_node *)v40;
  v50 = v41 - 1;
  new_e_minus_1 = v41 - 1;
  j = v45;
  if ( v45 != v41 )
  {
    do
    {
      if ( animation_less_predicate::operator()(
             (animation_less_predicate *)*j,
             (const vostok::animation::mixing::binary_tree_animation_node *)i.m_object->__vftable,
             *j) )
      {
        i.m_object = (vostok::animation::mixing::binary_tree_animation_node *)((char *)i.m_object + 4);
        ++j;
      }
      else
      {
        binary_multipliers = vostok::animation::mixing::n_ary_tree_converter::create_binary_multipliers(
                               buffera,
                               (vostok::animation::mixing::binary_tree_base_node *)i.m_object->accept,
                               v68[0]);
        v52 = 0;
        if ( binary_multipliers )
        {
          ++binary_multipliers->m_reference_count;
          v52 = binary_multipliers;
        }
        do
        {
          v53 = vostok::animation::mixing::n_ary_tree_converter::create_binary_multipliers(
                  buffera,
                  (*j)->m_next_weight,
                  v68[0]);
          v54 = 0;
          if ( v53 )
          {
            ++v53->m_reference_count;
            v54 = v53;
          }
          m_data = buffera->m_data;
          buffera->m_size -= 28;
          buffera->m_data = m_data + 28;
          if ( m_data )
          {
            *((_DWORD *)m_data + 1) = 0;
            *((_DWORD *)m_data + 2) = 0;
            *((_DWORD *)m_data + 3) = 0;
            *((_DWORD *)m_data + 4) = 0;
            *(_DWORD *)m_data = &vostok::animation::mixing::binary_tree_binary_operation_node::`vftable';
            *((_DWORD *)m_data + 5) = 0;
            if ( v52 )
            {
              *((_DWORD *)m_data + 5) = v52;
              ++v52->m_reference_count;
            }
            *((_DWORD *)m_data + 6) = 0;
            if ( v54 )
            {
              *((_DWORD *)m_data + 6) = v54;
              ++v54->m_reference_count;
            }
            *(_DWORD *)m_data = &vostok::animation::mixing::binary_tree_addition_node::`vftable';
          }
          v56 = 0;
          if ( m_data )
          {
            ++*((_DWORD *)m_data + 4);
            v56 = m_data;
          }
          v57 = v52;
          v52 = (vostok::animation::mixing::binary_tree_base_node *)v56;
          if ( v57 )
          {
            v9 = v57->m_reference_count-- == 1;
            if ( v9 )
              ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v57->~vostok::animation::mixing::binary_tree_base_node)(
                v57,
                0);
          }
          ++j;
          --new_e_minus_1;
          if ( v54 )
          {
            v9 = v54->m_reference_count-- == 1;
            if ( v9 )
              ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v54->~vostok::animation::mixing::binary_tree_base_node)(
                v54,
                0);
          }
        }
        while ( j != v72
             && !animation_less_predicate::operator()(
                   (animation_less_predicate *)i.m_object->__vftable,
                   (const vostok::animation::mixing::binary_tree_animation_node *)i.m_object->__vftable,
                   *j) );
        v58 = *(void (__thiscall ***)(_DWORD *, _DWORD))v56;
        v69[1] = buffera;
        v59 = (void (__thiscall *)(char *, _DWORD *))v58[1];
        v69[0] = &vostok::animation::mixing::binary_tree_expression_simplifier::`vftable';
        v70 = 0;
        v71 = 0;
        v59(v56, v69);
        i.m_object->accept = (void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, vostok::animation::mixing::binary_tree_visitor *))v70;
        if ( v71 )
        {
          v9 = (*(_DWORD *)(v71 + 16))-- == 1;
          if ( v9 )
            (**(void (__thiscall ***)(int, _DWORD))v71)(v71, 0);
        }
        if ( v70 )
        {
          v9 = (*(_DWORD *)(v70 + 16))-- == 1;
          if ( v9 )
            (**(void (__thiscall ***)(int, _DWORD))v70)(v70, 0);
        }
        i.m_object = (vostok::animation::mixing::binary_tree_animation_node *)((char *)i.m_object + 4);
        v9 = (*((_DWORD *)v56 + 4))-- == 1;
        if ( v9 )
          (**(void (__thiscall ***)(char *, _DWORD))v56)(v56, 0);
      }
    }
    while ( j != v72 );
    v50 = new_e_minus_1;
  }
  v60 = (unsigned int *)__first;
  for ( m = __first; m != v50; ++m )
  {
    v62 = m[1];
    p_m_next_weight_animation = &(*m)->m_next_weight_animation;
    v64 = 0;
    if ( v62 )
    {
      ++v62->m_reference_count;
      v64 = v62;
    }
    v65 = p_m_next_weight_animation->m_object;
    p_m_next_weight_animation->m_object = v64;
    if ( v65 )
    {
      v9 = v65->m_reference_count-- == 1;
      if ( v9 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v65->~vostok::animation::mixing::binary_tree_base_node)(
          v65,
          0);
    }
  }
  v66 = *m;
  v67 = v66->m_next_weight_animation.m_object;
  v66->m_next_weight_animation.m_object = 0;
  if ( v67 )
  {
    v9 = v67->m_reference_count-- == 1;
    if ( v9 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v67->~vostok::animation::mixing::binary_tree_base_node)(
        v67,
        0);
    buffer->m_animations_root = (vostok::animation::mixing::binary_tree_animation_node *)*v60;
  }
  else
  {
    buffer->m_animations_root = (vostok::animation::mixing::binary_tree_animation_node *)*v60;
  }
}
