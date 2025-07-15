void __thiscall vostok::animation::mixing::n_ary_tree::remove_animations(
        vostok::animation::mixing::n_ary_tree *this,
        _DWORD *target_time_in_ms,
        vostok::animation::mixing::animation_state **__comp)
{
  _DWORD *v3; // esi
  unsigned int v4; // edi
  void *v5; // esp
  vostok::animation::mixing::n_ary_tree_animation_node *v6; // ebx
  vostok::animation::mixing::animation_state *v7; // eax
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v8; // eax
  survarium::flash_movie_resource *m_animation_state; // ebx
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v10; // esi
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v11; // eax
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v12; // edx
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *k; // eax
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *m_end; // esi
  vostok::animation::mixing::animation_state *v15; // esi
  vostok::animation::mixing::animation_state *v16; // ebx
  int v17; // eax
  _DWORD *v18; // edx
  int m; // ecx
  vostok::animation::mixing::animation_state **v20; // esi
  int v21; // edx
  vostok::animation::mixing::animation_state **v22; // edi
  int v23; // eax
  int n; // ecx
  int v25; // eax
  int v26; // edi
  const vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v27; // ebx
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v28; // esi
  const void *v29; // [esp+0h] [ebp-30h] BYREF
  vostok::buffer_vector<void const *> v30; // [esp+10h] [ebp-20h] BYREF
  void *value; // [esp+18h] [ebp-18h] BYREF
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> __val; // [esp+1Ch] [ebp-14h] BYREF
  vostok::animation::mixing::n_ary_tree_animation_node *j; // [esp+20h] [ebp-10h] BYREF
  vostok::animation::mixing::animation_state *v34; // [esp+24h] [ebp-Ch]
  vostok::animation::mixing::n_ary_tree_animation_node *i; // [esp+28h] [ebp-8h] BYREF
  vostok::animation::mixing::animation_state *__that; // [esp+2Ch] [ebp-4h]
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *__compa; // [esp+3Ch] [ebp+Ch]

  v3 = target_time_in_ms;
  v4 = target_time_in_ms[8];
  v5 = alloca(4 * v4);
  vostok::buffer_vector<void const *>::buffer_vector<void const *>(&v30, &v29, v4, 0);
  v6 = (vostok::animation::mixing::n_ary_tree_animation_node *)target_time_in_ms[1];
  v7 = (vostok::animation::mixing::animation_state *)target_time_in_ms[4];
  __that = v7;
  v34 = v7;
  j = 0;
  i = v6;
  if ( v6 )
  {
    while ( 1 )
    {
      if ( (vostok::animation::mixing::animation_state **)v7->event_iterator.m_value.event_time_in_ms == __comp
        && (v7->event_iterator.m_value.event_type & 2) != 0 )
      {
        v8 = (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v3[5];
        m_animation_state = (survarium::flash_movie_resource *)v6->m_animation_state;
        v10 = &v8[v3[7]];
        __val.m_object = m_animation_state;
        v11 = stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
                v8,
                v10,
                &__val);
        if ( v11 != v10 )
        {
          v12 = v11;
          for ( k = v11 + 1; k != v10; ++k )
          {
            if ( k->m_object != m_animation_state )
            {
              v12->m_object = k->m_object;
              ++v12;
            }
          }
        }
        vostok::animation::mixing::n_ary_tree::remove_animation(
          (vostok::animation::mixing::n_ary_tree *)&i,
          target_time_in_ms,
          &i,
          j);
        v6 = i;
      }
      else
      {
        m_end = (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v30.m_end;
        j = (vostok::animation::mixing::n_ary_tree_animation_node *)v6->m_animated_object;
        if ( stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
               (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v30.m_begin,
               (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v30.m_end,
               (const vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)&j) == m_end )
        {
          value = (void *)v6->m_animated_object;
          vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(&v30, (const void **)&value);
        }
        v15 = v34;
        if ( __that != v34 )
        {
          vostok::animation::mixing::animation_state::operator=(__that, v34);
          v6->m_animation_state = v15;
        }
        j = v6;
        v6 = v6->m_next_weight_animation;
        v34 = v15 + 1;
        i = v6;
      }
      ++__that;
      if ( !v6 )
        break;
      v3 = target_time_in_ms;
      v7 = __that;
    }
    v16 = v34;
    if ( v34 != __that )
    {
      v17 = target_time_in_ms[4];
      v18 = (_DWORD *)target_time_in_ms[5];
      for ( m = v17 + 180 * target_time_in_ms[7]; v17 != m; ++v18 )
      {
        *v18 = v17;
        v17 += 180;
      }
      v20 = (vostok::animation::mixing::animation_state **)target_time_in_ms[5];
      v21 = target_time_in_ms[7];
      v22 = &v20[v21];
      LOBYTE(__comp) = 0;
      if ( v20 != v22 )
      {
        v23 = (4 * v21) >> 2;
        for ( n = 0; v23 != 1; ++n )
          v23 >>= 1;
        stlp_std::priv::__introsort_loop<vostok::animation::mixing::animation_state * *,vostok::animation::mixing::animation_state *,int,event_iterator_predicate>(
          (event_iterator_predicate)v22,
          v20,
          &v20[v21],
          0,
          2 * n,
          __comp);
        stlp_std::priv::__final_insertion_sort<vostok::animation::mixing::animation_state * *,event_iterator_predicate>(
          v20,
          (event_iterator_predicate)v20,
          v22,
          0);
      }
      do
      {
        if ( v16->bone_matrices_computer.pinned_animation.m_resource.m_object )
        {
          if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
          {
            v25 = (int)(v16->bone_matrices_computer.pinned_animation.m_data - 52);
            _InterlockedExchangeAdd((volatile signed __int32 *)(v25 + 44), 0xFFFFFFFF);
            if ( *(_DWORD *)(v25 + 16) )
            {
              if ( !*(_DWORD *)(v25 + 44) )
              {
                _InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)(v25 + 16) + 40), 1u);
                *(_DWORD *)(v25 + 16) = 0;
              }
            }
          }
        }
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v16->bone_matrices_computer.pinned_animation.m_resource);
        ++v16;
      }
      while ( v16 != __that );
    }
    v3 = target_time_in_ms;
  }
  v26 = v3[8];
  if ( v26 != vostok::buffer_vector<void const *>::size(&v30) )
  {
    v27 = (const vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v3[6];
    __compa = (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v27;
    value = (void *)&v27[34 * v26];
    if ( v27 != value )
    {
      v28 = (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v30.m_end;
      do
      {
        if ( stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
               (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v30.m_begin,
               v28,
               v27 + 32) != v28 )
        {
          if ( v27 != __compa && __compa )
          {
            qmemcpy(__compa, v27, 0x88u);
            v28 = (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v30.m_end;
          }
          __compa += 34;
        }
        v27 += 34;
      }
      while ( v27 != value );
      v3 = target_time_in_ms;
    }
    v3[8] = vostok::buffer_vector<void const *>::size(&v30);
  }
  vostok::buffer_vector<char const *>::~buffer_vector<char const *>(&v30);
}
