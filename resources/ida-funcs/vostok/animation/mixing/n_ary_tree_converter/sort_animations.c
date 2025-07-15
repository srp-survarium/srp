void __thiscall vostok::animation::mixing::n_ary_tree_converter::sort_animations(
        vostok::animation::mixing::n_ary_tree_converter *this,
        vostok::mutable_buffer *buffer,
        int a3)
{
  const boost::function<unsigned char __cdecl(void const *)> *m_size; // eax
  const boost::function<unsigned char __cdecl(void const *)> *m_animated_object_resolver; // ecx
  int v5; // edi
  bool v6; // zf
  void *v7; // esp
  vostok::mutable_buffer *v8; // esi
  vostok::animation::mixing::binary_tree_weight_node *v9; // eax
  vostok::animation::mixing::binary_tree_weight_node *v10; // ebx
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v11; // edi
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v12; // esi
  const vostok::animation::base_interpolator *m_interpolator; // eax
  const vostok::animation::base_interpolator *v14; // ecx
  vostok::particle::particle_system_instance_impl *(__thiscall *v15)(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // eax
  const vostok::animation::base_interpolator *v16; // esi
  vostok::animation::base_interpolator_vtbl *v17; // eax
  vostok::animation::base_interpolator_vtbl *v18; // ecx
  vostok::particle::particle_system_instance_impl *(__thiscall *v19)(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // eax
  vostok::animation::base_interpolator_vtbl *v20; // eax
  const vostok::animation::base_interpolator *v21; // ecx
  unsigned int m_reference_count; // eax
  unsigned int v23; // ecx
  vostok::particle::particle_system_instance_impl *(__thiscall *v24)(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // eax
  vostok::animation::mixing::binary_tree_weight_node *v25; // esi
  unsigned int v26; // eax
  unsigned int v27; // ecx
  vostok::particle::particle_system_instance_impl *(__thiscall *v28)(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // eax
  unsigned int v29; // eax
  vostok::animation::mixing::binary_tree_weight_node *v30; // ecx
  const boost::function<unsigned char __cdecl(void const *)> *v31; // eax
  const boost::function<unsigned char __cdecl(void const *)> *m_data; // ebx
  vostok::animation::mixing::binary_tree_animation_node **v33; // edi
  int v34; // esi
  int v35; // ecx
  int v36; // eax
  vostok::animation::mixing::binary_tree_animation_node **v37; // esi
  vostok::animation::mixing::binary_tree_animation_node **v38; // eax
  const vostok::animation::mixing::binary_tree_animation_node **v39; // ebx
  vostok::animation::mixing::binary_tree_animation_node **i; // esi
  vostok::animation::mixing::binary_tree_animation_node *v41; // eax
  unsigned int m_weight_synchronization_group_id; // ecx
  vostok::animation::mixing::binary_tree_animation_node *m_weight_driving_animation; // ecx
  vostok::animation::mixing::binary_tree_weight_node *binary_multipliers; // eax
  vostok::animation::mixing::binary_tree_base_node *v45; // eax
  vostok::animation::mixing::binary_tree_binary_operation_node *v46; // edi
  vostok::animation::mixing::binary_tree_base_node *v47; // ecx
  vostok::animation::mixing::binary_tree_weight_node *v48; // edi
  vostok::animation::mixing::binary_tree_expression_simplifier *v49; // ecx
  vostok::animation::mixing::binary_tree_animation_node **j; // eax
  vostok::animation::mixing::binary_tree_animation_node **v51; // edi
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **p_m_next_weight_animation; // esi
  vostok::mutable_buffer *v53[4]; // [esp+0h] [ebp-40h] BYREF
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_animation_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> v54[2]; // [esp+10h] [ebp-30h] BYREF
  vostok::animation::mixing::binary_tree_expression_simplifier *v55; // [esp+18h] [ebp-28h]
  int v56; // [esp+1Ch] [ebp-24h]
  vostok::animation::mixing::binary_tree_animation_node *v57; // [esp+20h] [ebp-20h] BYREF
  const vostok::animation::mixing::binary_tree_animation_node **v58; // [esp+24h] [ebp-1Ch]
  animation_less_predicate __comp; // [esp+28h] [ebp-18h] BYREF
  vostok::animation::mixing::binary_tree_weight_node *v60; // [esp+2Ch] [ebp-14h] BYREF
  vostok::animation::mixing::binary_tree_base_node *v61; // [esp+30h] [ebp-10h]
  vostok::animation::mixing::binary_tree_animation_node **v62; // [esp+34h] [ebp-Ch]
  vostok::animation::mixing::binary_tree_animation_node **__first; // [esp+38h] [ebp-8h]
  bool v64; // [esp+3Fh] [ebp-1h]

  m_size = (const boost::function<unsigned char __cdecl(void const *)> *)buffer[9].m_size;
  m_animated_object_resolver = 0;
  v5 = 0;
  __comp.m_animated_object_resolver = 0;
  if ( m_size )
  {
    ++m_size->functor.vostok_pointer_size_alignment[2];
    m_animated_object_resolver = m_size;
    __comp.m_animated_object_resolver = m_size;
  }
  while ( m_animated_object_resolver )
  {
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v6 = m_animated_object_resolver->functor.vostok_pointer_size_alignment[2]-- == (void *)1;
      if ( v6 )
        ((void (__thiscall *)(const boost::function<unsigned char __cdecl(void const *)> *, _DWORD))m_animated_object_resolver->vtable->manager)(
          m_animated_object_resolver,
          0);
      break;
    }
    ++v5;
    vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&m_animated_object_resolver[1].functor.data
    + 5,
      (vostok::animation::mixing::binary_tree_weight_node **)&__comp);
    m_animated_object_resolver = __comp.m_animated_object_resolver;
  }
  v57 = (vostok::animation::mixing::binary_tree_animation_node *)(4 * v5);
  v7 = alloca(4 * v5);
  v8 = buffer;
  __first = (vostok::animation::mixing::binary_tree_animation_node **)v53;
  __comp.m_animated_object_resolver = (const boost::function<unsigned char __cdecl(void const *)> *)v53;
  v9 = (vostok::animation::mixing::binary_tree_weight_node *)buffer[9].m_size;
  v10 = 0;
  v60 = 0;
  if ( v9 )
  {
    ++v9->m_reference_count;
    v10 = v9;
    v60 = v9;
  }
  while ( v10 )
  {
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v6 = v10->m_reference_count-- == 1;
      if ( v6 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_weight_node *, _DWORD))v10->~vostok::animation::mixing::binary_tree_base_node)(
          v10,
          0);
      break;
    }
    if ( (v8->m_data != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    {
      v11 = (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)v10[1].__vftable;
      v12 = &v11[5 * (int)v10[2].m_same_weight];
      while ( v11 != v12 )
      {
        v11[2].m_object = (vostok::resources::managed_resource *)(unsigned __int16)boost::function2<void,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>::operator()(
                                                                                     (boost::function2<unsigned short,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &> *)m_animated_object_resolver,
                                                                                     buffer,
                                                                                     v11,
                                                                                     v11 + 1);
        v11 += 5;
      }
    }
    m_interpolator = v10[1].m_interpolator;
    v14 = 0;
    if ( m_interpolator )
    {
      ++m_interpolator[4].__vftable;
      v14 = m_interpolator;
      v15 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
    }
    else
    {
      v15 = 0;
    }
    v64 = v15 != 0;
    if ( v14 )
    {
      v6 = v14[4].__vftable-- == (vostok::animation::base_interpolator_vtbl *)1;
      if ( v6 )
        ((void (__thiscall *)(const vostok::animation::base_interpolator *, _DWORD))v14->interpolated_value)(v14, 0);
    }
    if ( v64 )
    {
      v16 = (const vostok::animation::base_interpolator *)v10;
      while ( 1 )
      {
        v17 = v16[13].__vftable;
        v18 = 0;
        if ( v17 )
        {
          ++v17->transition_time;
          v18 = v17;
          v19 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
        }
        else
        {
          v19 = 0;
        }
        v64 = v19 != 0;
        if ( v18 )
        {
          v6 = v18->transition_time-- == (float (__thiscall *)(vostok::animation::base_interpolator *))1;
          if ( v6 )
            (*(void (__thiscall **)(vostok::animation::base_interpolator_vtbl *, _DWORD))v18->interpolated_value)(
              v18,
              0);
        }
        if ( !v64 )
          break;
        v20 = v16[13].__vftable;
        v21 = 0;
        if ( v20 )
        {
          ++v20->transition_time;
          v21 = (const vostok::animation::base_interpolator *)v20;
        }
        v16 = v21;
        if ( v21 )
        {
          v6 = v21[4].__vftable-- == (vostok::animation::base_interpolator_vtbl *)1;
          if ( v6 )
            ((void (__thiscall *)(const vostok::animation::base_interpolator *, _DWORD))v21->interpolated_value)(v21, 0);
        }
      }
      v10[1].m_interpolator = v16;
    }
    m_reference_count = v10[1].m_reference_count;
    v23 = 0;
    if ( m_reference_count )
    {
      ++*(_DWORD *)(m_reference_count + 16);
      v23 = m_reference_count;
      v24 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
    }
    else
    {
      v24 = 0;
    }
    v64 = v24 != 0;
    if ( v23 )
    {
      v6 = (*(_DWORD *)(v23 + 16))-- == 1;
      if ( v6 )
        (**(void (__thiscall ***)(unsigned int, _DWORD))v23)(v23, 0);
    }
    if ( v64 )
    {
      v25 = v10;
      while ( 1 )
      {
        v26 = v25[1].m_reference_count;
        v27 = 0;
        if ( v26 )
        {
          ++*(_DWORD *)(v26 + 16);
          v27 = v26;
          v28 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
        }
        else
        {
          v28 = 0;
        }
        v64 = v28 != 0;
        if ( v27 )
        {
          v6 = (*(_DWORD *)(v27 + 16))-- == 1;
          if ( v6 )
            (**(void (__thiscall ***)(unsigned int, _DWORD))v27)(v27, 0);
        }
        if ( !v64 )
          break;
        v29 = v25[1].m_reference_count;
        v30 = 0;
        if ( v29 )
        {
          ++*(_DWORD *)(v29 + 16);
          v30 = (vostok::animation::mixing::binary_tree_weight_node *)v29;
        }
        v25 = v30;
        if ( v30 )
        {
          v6 = v30->m_reference_count-- == 1;
          if ( v6 )
            ((void (__thiscall *)(vostok::animation::mixing::binary_tree_weight_node *, _DWORD))v30->~vostok::animation::mixing::binary_tree_base_node)(
              v30,
              0);
        }
      }
      v10[1].m_reference_count = (unsigned int)v25;
    }
    v31 = __comp.m_animated_object_resolver;
    __comp.m_animated_object_resolver = (const boost::function<unsigned char __cdecl(void const *)> *)((char *)__comp.m_animated_object_resolver + 4);
    v31->vtable = (boost::detail::function::vtable_base *)v10;
    vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&v10[1].m_simplified_weight,
      &v60);
    v10 = v60;
    v8 = buffer;
  }
  m_data = (const boost::function<unsigned char __cdecl(void const *)> *)v8[4].m_data;
  v33 = (vostok::animation::mixing::binary_tree_animation_node **)((char *)__first + (_DWORD)v57);
  v58 = (const vostok::animation::mixing::binary_tree_animation_node **)((char *)__first + (_DWORD)v57);
  if ( __first != (vostok::animation::mixing::binary_tree_animation_node **)((char *)__first + (_DWORD)v57) )
  {
    v34 = (int)v57 >> 2;
    v35 = (int)v57 >> 2;
    v36 = 0;
    while ( v35 != 1 )
    {
      ++v36;
      v35 >>= 1;
    }
    stlp_std::priv::__introsort_loop<vostok::animation::mixing::binary_tree_animation_node * *,vostok::animation::mixing::binary_tree_animation_node *,int,animation_less_predicate>(
      __first,
      (vostok::animation::mixing::binary_tree_animation_node **)((char *)__first + (_DWORD)v57),
      0,
      2 * v36,
      (animation_less_predicate)m_data);
    __comp.m_animated_object_resolver = m_data;
    if ( v34 <= 16 )
    {
      v57 = (vostok::animation::mixing::binary_tree_animation_node *)m_data;
      stlp_std::priv::__insertion_sort<vostok::animation::mixing::binary_tree_animation_node * *,vostok::animation::mixing::binary_tree_animation_node *,animation_less_predicate>(
        __first,
        v33,
        (const boost::function<unsigned char __cdecl(void const *)> **)&v57);
    }
    else
    {
      v37 = __first + 16;
      stlp_std::priv::__insertion_sort<vostok::animation::mixing::binary_tree_animation_node * *,vostok::animation::mixing::binary_tree_animation_node *,animation_less_predicate>(
        __first,
        __first + 16,
        &__comp.m_animated_object_resolver);
      while ( v37 != v33 )
      {
        stlp_std::priv::__unguarded_linear_insert<vostok::animation::mixing::binary_tree_animation_node * *,vostok::animation::mixing::binary_tree_animation_node *,animation_less_predicate>(
          *v37,
          v37,
          __comp);
        ++v37;
      }
    }
  }
  v38 = __first;
  v39 = (const vostok::animation::mixing::binary_tree_animation_node **)(__first + 1);
  for ( i = __first + 1; i != v33; ++i )
  {
    v41 = *v38;
    m_weight_synchronization_group_id = v41->m_weight_synchronization_group_id;
    if ( m_weight_synchronization_group_id != -1
      && m_weight_synchronization_group_id == (*i)->m_weight_synchronization_group_id )
    {
      m_weight_driving_animation = v41->m_weight_driving_animation;
      if ( m_weight_driving_animation )
      {
        v6 = ++m_weight_driving_animation->m_reference_count == 1;
        --m_weight_driving_animation->m_reference_count;
        if ( v6 )
          ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))m_weight_driving_animation->~vostok::animation::mixing::binary_tree_base_node)(
            m_weight_driving_animation,
            0);
      }
    }
    v38 = i;
  }
  v57 = (vostok::animation::mixing::binary_tree_animation_node *)buffer[4].m_data;
  v62 = __first;
  __comp.m_animated_object_resolver = (const boost::function<unsigned char __cdecl(void const *)> *)(v58 - 1);
  while ( v39 != v58 )
  {
    if ( animation_less_predicate::operator()(*v62, *v39, (animation_less_predicate *)&v57) )
    {
      ++v62;
      ++v39;
    }
    else
    {
      binary_multipliers = (vostok::animation::mixing::binary_tree_weight_node *)vostok::animation::mixing::n_ary_tree_converter::create_binary_multipliers(
                                                                                   (*v62)->m_next_weight,
                                                                                   (vostok::animation::mixing::n_ary_tree_converter *)a3,
                                                                                   v53[0]);
      v60 = 0;
      if ( binary_multipliers )
      {
        ++binary_multipliers->m_reference_count;
        v60 = binary_multipliers;
      }
      do
      {
        v45 = vostok::animation::mixing::n_ary_tree_converter::create_binary_multipliers(
                (*v39)->m_next_weight,
                (vostok::animation::mixing::n_ary_tree_converter *)a3,
                v53[0]);
        v61 = 0;
        if ( v45 )
        {
          ++v45->m_reference_count;
          v61 = v45;
        }
        v46 = *(vostok::animation::mixing::binary_tree_binary_operation_node **)a3;
        *(_DWORD *)(a3 + 4) -= 28;
        *(_DWORD *)a3 = v46 + 1;
        if ( v46 )
        {
          vostok::animation::mixing::binary_tree_binary_operation_node::binary_tree_binary_operation_node(v46, v60, v61);
          v46->__vftable = (vostok::animation::mixing::binary_tree_binary_operation_node_vtbl *)&vostok::animation::mixing::binary_tree_addition_node::`vftable';
        }
        vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
          (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)v46,
          (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **)&v60);
        __comp.m_animated_object_resolver = (const boost::function<unsigned char __cdecl(void const *)> *)((char *)__comp.m_animated_object_resolver - 4);
        ++v39;
        if ( v61 )
        {
          v47 = v61;
          v6 = v61->m_reference_count-- == 1;
          if ( v6 )
            ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v47->~vostok::animation::mixing::binary_tree_base_node)(
              v47,
              0);
        }
      }
      while ( v39 != v58 && !animation_less_predicate::operator()(*v62, *v39, (animation_less_predicate *)&v57) );
      v48 = v60;
      v55 = 0;
      v56 = 0;
      v54[0].m_object = (vostok::animation::mixing::binary_tree_animation_node *)&vostok::animation::mixing::binary_tree_expression_simplifier::`vftable';
      v54[1].m_object = (vostok::animation::mixing::binary_tree_animation_node *)a3;
      v60->accept(v60, (vostok::animation::mixing::binary_tree_visitor *)v54);
      v49 = v55;
      (*v62)->m_next_weight = (vostok::animation::mixing::binary_tree_base_node *)v55;
      vostok::animation::mixing::binary_tree_expression_simplifier::~binary_tree_expression_simplifier(v49, v54);
      ++v62;
      v6 = v48->m_reference_count-- == 1;
      if ( v6 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_weight_node *, _DWORD))v48->~vostok::animation::mixing::binary_tree_base_node)(
          v48,
          0);
    }
  }
  for ( j = __first; ; j = v51 )
  {
    p_m_next_weight_animation = (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **)&(*j)->m_next_weight_animation;
    if ( j == (vostok::animation::mixing::binary_tree_animation_node **)__comp.m_animated_object_resolver )
      break;
    v51 = j + 1;
    vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)j[1],
      p_m_next_weight_animation);
  }
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
    0,
    p_m_next_weight_animation);
  buffer[9].m_size = (unsigned int)*__first;
}
