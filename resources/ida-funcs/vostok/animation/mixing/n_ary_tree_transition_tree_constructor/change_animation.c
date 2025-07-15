void __thiscall vostok::animation::mixing::n_ary_tree_transition_tree_constructor::change_animation(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this,
        const vostok::animation::mixing::animation_interval from)
{
  vostok::resources::managed_resource *m_object; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *m_animation_id; // esi
  vostok::animation::mixing::n_ary_tree_animation_node *v4; // edi
  unsigned int type; // eax
  int v6; // edx
  float m_length; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v8; // eax
  unsigned int v9; // edx
  _DWORD *v10; // eax
  int v11; // ecx
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v12; // ecx
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node *v13; // eax
  vostok::resources::managed_resource *v14; // ecx
  float v15; // esi
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v16; // ecx
  vostok::animation::mixing::n_ary_tree_node_cloner **v17; // edi
  int v18; // esi
  volatile int v19; // eax
  vostok::animation::mixing::n_ary_tree_node_cloner **v20; // ecx
  volatile int v21; // eax
  BOOL v22; // eax
  vostok::animation::mixing::n_ary_tree_node_cloner **i; // edi
  vostok::animation::mixing::n_ary_tree_base_node *v24; // eax
  fastdelegate::detail::GenericClass *m_pthis; // ecx
  vostok::animation::mixing::n_ary_tree_node_cloner ***v26; // eax
  vostok::animation::mixing::n_ary_tree_node_cloner **v27; // ecx
  vostok::animation::mixing::n_ary_tree_node_cloner *v28; // ecx
  vostok::animation::mixing::n_ary_tree_node_cloner **v29; // eax
  float v30; // xmm0_4
  unsigned int v31; // esi
  volatile int v32; // eax
  vostok::animation::mixing::n_ary_tree_base_node *v33; // edi
  volatile int v34; // eax
  BOOL v35; // eax
  float v36; // eax
  vostok::animation::mixing::n_ary_tree_base_node *v37; // eax
  fastdelegate::detail::GenericClass *v38; // ecx
  volatile int v39; // eax
  vostok::animation::mixing::n_ary_tree_base_node_vtbl *v40; // eax
  float v41; // xmm0_4
  vostok::animation::mixing::n_ary_tree_node_cloner **v42; // esi
  vostok::animation::mixing::n_ary_tree_node_cloner *v43; // ecx
  volatile int v44; // eax
  vostok::resources::managed_resource_vtbl *v45; // esi
  float v46; // eax
  const vostok::animation::base_interpolator *v47; // eax
  const vostok::animation::base_interpolator *v48; // eax
  float v49; // xmm0_4
  volatile int v50; // eax
  float m_start_time; // eax
  const vostok::animation::base_interpolator *v52; // eax
  const vostok::animation::base_interpolator *v53; // eax
  vostok::animation::mixing::n_ary_tree_node_cloner **v54; // ecx
  float v55; // eax
  int *m_thread_id; // eax
  int v57; // esi
  int v58; // ecx
  vostok::resources::managed_resource *v59; // [esp-4h] [ebp-48h]
  float v60; // [esp+0h] [ebp-44h]
  vostok::animation::mixing::n_ary_tree_base_node *v61; // [esp+8h] [ebp-3Ch]
  vostok::animation::mixing::animation_interval v62; // [esp+18h] [ebp-2Ch] BYREF
  unsigned int v63; // [esp+2Ch] [ebp-18h] BYREF
  fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> v64; // [esp+30h] [ebp-14h] BYREF
  vostok::animation::mixing::n_ary_tree_node_cloner **v65; // [esp+38h] [ebp-Ch]
  vostok::animation::mixing::n_ary_tree_node_cloner **p_m_memory_usage_self; // [esp+3Ch] [ebp-8h]

  m_object = from.m_first_view_animation.m_object;
  m_animation_id = (vostok::animation::mixing::n_ary_tree_animation_node *)from.m_animation_id;
  v4 = (vostok::animation::mixing::n_ary_tree_animation_node *)from.m_third_view_animation.m_object;
  if ( (!HIBYTE(from.m_third_view_animation.m_object->m_parent_resources.m_last) || *(_BYTE *)(from.m_animation_id + 83))
    && (!LOBYTE(from.m_length) || !*(_BYTE *)(*(&from.m_third_view_animation.m_object->m_reconstruction_size + 1) + 116)) )
  {
    vostok::animation::mixing::computed_operands_count(
      (vostok::animation::mixing::n_ary_tree_animation_node *)from.m_third_view_animation.m_object,
      (int)from.m_first_view_animation.m_object->m_parent_resources.m_last,
      (stlp_std::pair<unsigned int,unsigned int> *)&v62.m_third_view_animation,
      from.m_animation_id);
    LODWORD(from.m_length) = v62.m_animation_id;
    LOBYTE(from.m_third_view_animation.m_object) = m_animation_id->m_is_transitting_to_zero;
    v62.m_first_view_animation.m_object = (vostok::resources::managed_resource *)vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_animation(
                                                                                   m_animation_id,
                                                                                   (unsigned int *)&from.m_start_time,
                                                                                   (const vostok::animation::base_interpolator *)m_object,
                                                                                   v4,
                                                                                   (vostok::animation::mixing::n_ary_tree_animation_node *)LODWORD(from.m_start_time),
                                                                                   (unsigned int)v62.m_third_view_animation.m_object,
                                                                                   (fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *)&from.m_length,
                                                                                   &v62,
                                                                                   (unsigned int *)&from,
                                                                                   (float *)&from.m_third_view_animation,
                                                                                   (bool)from.m_third_view_animation.m_object,
                                                                                   (vostok::animation::mixing::n_ary_tree_animation_node *)1);
    m_thread_id = (int *)m_object->m_parent_resources.m_thread_id;
    v57 = *m_thread_id;
    v58 = 4 * ((int)v62.m_third_view_animation.m_object + LODWORD(from.m_length));
    *m_thread_id += v58;
    m_thread_id[1] -= v58;
    vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_operands(
      (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)(v57 + v58),
      (vostok::animation::mixing::n_ary_tree_addition_node *)m_object,
      v4,
      (vostok::animation::mixing::n_ary_tree_base_node **)from.m_animation_id,
      (vostok::animation::mixing::n_ary_tree_base_node **)(v57 + 4 * LODWORD(from.m_start_time)),
      (vostok::animation::mixing::n_ary_tree_base_node **)(v57 + v58),
      LODWORD(from.m_start_time) != 0);
    vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation_node(
      (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)m_object,
      v4->m_animation_state,
      (vostok::animation::mixing::n_ary_tree_animation_node *)v62.m_first_view_animation.m_object,
      (unsigned int)from.m_first_view_animation.m_object,
      *(float *)&from.m_third_view_animation.m_object,
      0);
    return;
  }
  type = from.m_third_view_animation.m_object->type;
  v6 = *(_DWORD *)(from.m_animation_id + 4);
  p_m_memory_usage_self = (vostok::animation::mixing::n_ary_tree_node_cloner **)&from.m_third_view_animation.m_object->m_memory_usage_self;
  v65 = (vostok::animation::mixing::n_ary_tree_node_cloner **)(&from.m_third_view_animation.m_object->m_memory_usage_self.type
                                                             + type);
  LODWORD(m_length) = from.m_animation_id + 88;
  LODWORD(from.m_length) = from.m_animation_id + 88;
  v64.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))(from.m_animation_id
                                                                                        + 88
                                                                                        + 4 * v6);
  if ( type )
  {
    if ( ((unsigned __int8 (__thiscall *)(vostok::animation::mixing::n_ary_tree_node_cloner *))(*p_m_memory_usage_self)->visit)(*p_m_memory_usage_self) )
    {
LABEL_10:
      v64.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)1;
      goto LABEL_12;
    }
    m_length = from.m_length;
  }
  if ( m_animation_id->m_operands_count
    && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)LODWORD(m_length) + 12))(*(_DWORD *)LODWORD(m_length)) )
  {
    goto LABEL_10;
  }
  v64.m_Closure.m_pthis = 0;
LABEL_12:
  LOBYTE(from.m_first_view_animation.m_object) = m_animation_id->m_is_transitting_to_zero;
  v8 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_animation(
         m_animation_id,
         &v63,
         (const vostok::animation::base_interpolator *)m_object,
         v4,
         (vostok::animation::mixing::n_ary_tree_animation_node *)LODWORD(from.m_start_time),
         1u,
         &v64,
         &from,
         (unsigned int *)&v62,
         (float *)&v62.m_animation_id,
         (bool)from.m_first_view_animation.m_object,
         (vostok::animation::mixing::n_ary_tree_animation_node *)1);
  v9 = v63;
  LODWORD(v62.m_length) = v8;
  v10 = (_DWORD *)m_object->m_parent_resources.m_thread_id;
  from.m_first_view_animation.m_object = (vostok::resources::managed_resource *)(*v10 + 4 * v63);
  v11 = 4 * (int)v64.m_Closure.m_pthis + 4;
  *v10 += v11;
  v10[1] -= v11;
  if ( !v9 )
  {
    if ( v4->m_operands_count
      && ((unsigned __int8 (__thiscall *)(vostok::animation::mixing::n_ary_tree_node_cloner *))(*p_m_memory_usage_self)->visit)(*p_m_memory_usage_self) )
    {
      if ( !m_animation_id->m_operands_count
        || !(*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)LODWORD(from.m_length) + 12))(*(_DWORD *)LODWORD(from.m_length)) )
      {
        v13 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_time_scale_transition(
                v12,
                (vostok::animation::mixing::n_ary_tree_addition_node *)m_object,
                v4,
                *p_m_memory_usage_self,
                *(float *)&v61);
        v14 = from.m_first_view_animation.m_object;
        from.m_first_view_animation.m_object = (vostok::resources::managed_resource *)((char *)from.m_first_view_animation.m_object
                                                                                     + 4);
        ++p_m_memory_usage_self;
LABEL_23:
        v14->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::managed_resource_vtbl *)v13;
        goto LABEL_24;
      }
      v13 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_time_scale_transition(
              (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)*p_m_memory_usage_self,
              (vostok::animation::mixing::n_ary_tree_addition_node *)m_object,
              v4,
              m_animation_id,
              *p_m_memory_usage_self,
              *(vostok::animation::mixing::n_ary_tree_subtraction_node **)LODWORD(from.m_length));
      ++p_m_memory_usage_self;
LABEL_22:
      v14 = from.m_first_view_animation.m_object;
      from.m_first_view_animation.m_object = (vostok::resources::managed_resource *)((char *)from.m_first_view_animation.m_object
                                                                                   + 4);
      LODWORD(from.m_length) += 4;
      goto LABEL_23;
    }
    if ( m_animation_id->m_operands_count )
    {
      v15 = from.m_length;
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)LODWORD(from.m_length) + 12))(*(_DWORD *)LODWORD(from.m_length)) )
      {
        v13 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_time_scale_transition(
                v16,
                (vostok::animation::mixing::n_ary_tree_addition_node *)m_object,
                COERCE_VOSTOK_ANIMATION_MIXING_N_ARY_TREE_BASE_NODE_(v4->m_animation_state->animation_interval_time),
                *(vostok::animation::mixing::n_ary_tree_node_cloner **)LODWORD(v15),
                v61);
        goto LABEL_22;
      }
    }
  }
LABEL_24:
  v17 = p_m_memory_usage_self;
  v18 = v65 - p_m_memory_usage_self;
  LODWORD(v62.m_start_time) = v18;
  if ( v18
    && ((unsigned __int8 (__thiscall *)(vostok::animation::mixing::n_ary_tree_node_cloner *))(*p_m_memory_usage_self)->visit)(*p_m_memory_usage_self) )
  {
    LODWORD(v62.m_start_time) = --v18;
  }
  if ( v18 )
  {
    if ( v18 == 1 )
    {
      p_m_memory_usage_self = (vostok::animation::mixing::n_ary_tree_node_cloner **)vostok::animation::mixing::n_ary_tree_node_cloner::clone(
                                                                                      *(v65 - 1),
                                                                                      (vostok::animation::mixing::n_ary_tree_addition_node *)&m_object->vostok::uid_object<vostok::resources::resource_children>);
    }
    else
    {
      v19 = m_object->m_parent_resources.m_thread_id;
      v20 = *(vostok::animation::mixing::n_ary_tree_node_cloner ***)v19;
      *(_DWORD *)v19 += 8;
      *(_DWORD *)(v19 + 4) -= 8;
      p_m_memory_usage_self = v20;
      if ( v20 )
      {
        v20[1] = (vostok::animation::mixing::n_ary_tree_node_cloner *)v18;
        *v20 = (vostok::animation::mixing::n_ary_tree_node_cloner *)&vostok::animation::mixing::n_ary_tree_multiplication_node::`vftable';
      }
      v21 = m_object->m_parent_resources.m_thread_id;
      v64.m_Closure.m_pthis = *(fastdelegate::detail::GenericClass **)v21;
      *(_DWORD *)v21 += 4 * v18;
      *(_DWORD *)(v21 + 4) -= 4 * v18;
      v22 = v63
         && ((unsigned __int8 (__thiscall *)(vostok::animation::mixing::n_ary_tree_node_cloner *))(*v17)->visit)(*v17);
      for ( i = &v17[v22]; i != v65; *(_DWORD *)m_pthis = v24 )
      {
        v24 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(
                *i,
                (vostok::animation::mixing::n_ary_tree_addition_node *)&m_object->vostok::uid_object<vostok::resources::resource_children>);
        m_pthis = v64.m_Closure.m_pthis;
        v64.m_Closure.m_pthis += 4;
        ++i;
      }
    }
  }
  else
  {
    v26 = (vostok::animation::mixing::n_ary_tree_node_cloner ***)m_object->m_parent_resources.m_thread_id;
    v27 = *v26;
    *v26 += 3;
    v26[1] -= 3;
    p_m_memory_usage_self = v27;
    if ( v27 )
    {
      v28 = *(vostok::animation::mixing::n_ary_tree_node_cloner **)(LODWORD(v62.m_length) + 32);
      v29 = p_m_memory_usage_self;
      v30 = s_bm_current_air_resistance;
      *p_m_memory_usage_self = (vostok::animation::mixing::n_ary_tree_node_cloner *)&vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
      v29[1] = v28;
      *((float *)v29 + 2) = v30;
    }
  }
  v31 = ((int)v64.m_Closure.m_pFunction - LODWORD(from.m_length)) >> 2;
  v65 = (vostok::animation::mixing::n_ary_tree_node_cloner **)v31;
  if ( v31
    && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)LODWORD(from.m_length) + 12))(*(_DWORD *)LODWORD(from.m_length)) )
  {
    v65 = (vostok::animation::mixing::n_ary_tree_node_cloner **)--v31;
  }
  if ( !v31 )
  {
    v39 = m_object->m_parent_resources.m_thread_id;
    v33 = *(vostok::animation::mixing::n_ary_tree_base_node **)v39;
    *(_DWORD *)v39 += 12;
    *(_DWORD *)(v39 + 4) -= 12;
    if ( v33 )
    {
      v40 = *(vostok::animation::mixing::n_ary_tree_base_node_vtbl **)(LODWORD(v62.m_length) + 32);
      v41 = s_bm_current_air_resistance;
      v33->__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
      v33[1].__vftable = v40;
      *(float *)&v33[2].__vftable = v41;
    }
    goto LABEL_61;
  }
  if ( v31 == 1 )
  {
    v33 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(
            *((vostok::animation::mixing::n_ary_tree_node_cloner **)v64.m_Closure.m_pFunction - 1),
            (vostok::animation::mixing::n_ary_tree_addition_node *)&m_object->vostok::uid_object<vostok::resources::resource_children>);
  }
  else
  {
    v32 = m_object->m_parent_resources.m_thread_id;
    v33 = *(vostok::animation::mixing::n_ary_tree_base_node **)v32;
    *(_DWORD *)v32 += 8;
    *(_DWORD *)(v32 + 4) -= 8;
    if ( v33 )
    {
      v33[1].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)v31;
      v33->__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)&vostok::animation::mixing::n_ary_tree_multiplication_node::`vftable';
    }
    v34 = m_object->m_parent_resources.m_thread_id;
    v64.m_Closure.m_pthis = *(fastdelegate::detail::GenericClass **)v34;
    *(_DWORD *)v34 += 4 * v31;
    *(_DWORD *)(v34 + 4) -= 4 * v31;
    v35 = v63
       && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)LODWORD(from.m_length) + 12))(*(_DWORD *)LODWORD(from.m_length));
    LODWORD(v36) = LODWORD(from.m_length) + 4 * v35;
    from.m_length = v36;
    if ( (void (__thiscall *)(fastdelegate::detail::GenericClass *))LODWORD(v36) == v64.m_Closure.m_pFunction )
      goto LABEL_61;
    while ( 1 )
    {
      v37 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(
              *(vostok::animation::mixing::n_ary_tree_node_cloner **)LODWORD(v36),
              (vostok::animation::mixing::n_ary_tree_addition_node *)&m_object->vostok::uid_object<vostok::resources::resource_children>);
      v38 = v64.m_Closure.m_pthis;
      LODWORD(from.m_length) += 4;
      v64.m_Closure.m_pthis += 4;
      *(_DWORD *)v38 = v37;
      if ( (void (__thiscall *)(fastdelegate::detail::GenericClass *))LODWORD(from.m_length) == v64.m_Closure.m_pFunction )
        break;
      v36 = from.m_length;
    }
  }
  v31 = (unsigned int)v65;
LABEL_61:
  if ( LODWORD(v62.m_start_time) >= 2
    || v31 >= 2
    || (v42 = p_m_memory_usage_self,
        ((unsigned __int8 (__thiscall *)(vostok::animation::mixing::n_ary_tree_node_cloner **))(*p_m_memory_usage_self)->m_animation_interval_time)(p_m_memory_usage_self))
    || *((float *)v42 + 2) != *(float *)&v33[2].__vftable )
  {
    v50 = m_object->m_parent_resources.m_thread_id;
    v45 = *(vostok::resources::managed_resource_vtbl **)v50;
    *(_DWORD *)v50 += 20;
    *(_DWORD *)(v50 + 4) -= 20;
    m_start_time = from.m_start_time;
    if ( !LODWORD(from.m_start_time) )
      m_start_time = *(float *)&from.m_animation_id;
    v52 = *(const vostok::animation::base_interpolator **)(LODWORD(m_start_time) + 32);
    if ( v45 )
    {
      LODWORD(from.m_length) = m_object->m_class_id;
      v53 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(
              (vostok::animation::mixing::n_ary_tree_node_cloner *)LODWORD(from.m_length),
              (int)&m_object->vostok::uid_object<vostok::resources::resource_children>,
              v52,
              (bool)v61);
      v54 = p_m_memory_usage_self;
      v45->unlink_child_resource = (void (__thiscall *)(struct vostok::resources::resource_base *, vostok::resources::resource_base *))v53;
      v55 = from.m_length;
      v45->~vostok::resources::resource_base = (void (__thiscall *)(struct vostok::resources::resource_base *))&vostok::animation::mixing::n_ary_tree_weight_transition_node::`vftable';
      v45->log_string = (vostok::fixed_string<512> *(__thiscall *)(struct vostok::resources::resource_base *, vostok::fixed_string<512> *))v54;
      v45->link_child_resource = (void (__thiscall *)(struct vostok::resources::resource_base *, vostok::resources::resource_base *, unsigned int))v33;
      *(float *)&v45->decrease_quality = v55;
    }
  }
  else
  {
    v44 = m_object->m_parent_resources.m_thread_id;
    v45 = *(vostok::resources::managed_resource_vtbl **)v44;
    *(_DWORD *)v44 += 12;
    *(_DWORD *)(v44 + 4) -= 12;
    v46 = from.m_start_time;
    if ( !LODWORD(from.m_start_time) )
      v46 = *(float *)&from.m_animation_id;
    v47 = *(const vostok::animation::base_interpolator **)(LODWORD(v46) + 32);
    if ( v45 )
    {
      LODWORD(from.m_length) = (vostok::animation::mixing::n_ary_tree_base_node)v33[2].__vftable;
      v48 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(
              v43,
              (int)&m_object->vostok::uid_object<vostok::resources::resource_children>,
              v47,
              (bool)v61);
      v49 = from.m_length;
      v45->~vostok::resources::resource_base = (void (__thiscall *)(struct vostok::resources::resource_base *))&vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
      v45->log_string = (vostok::fixed_string<512> *(__thiscall *)(struct vostok::resources::resource_base *, vostok::fixed_string<512> *))v48;
      *(float *)&v45->link_child_resource = v49;
    }
  }
  v60 = *(float *)&v62.m_animation_id;
  v59 = v62.m_first_view_animation.m_object;
  from.m_first_view_animation.m_object->__vftable = v45;
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation_node(
    (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)m_object,
    *((const vostok::animation::mixing::animation_state **)&from.m_third_view_animation.m_object->m_reconstruction_size
    + 1),
    (vostok::animation::mixing::n_ary_tree_animation_node *)LODWORD(v62.m_length),
    (unsigned int)v59,
    v60,
    0);
}
