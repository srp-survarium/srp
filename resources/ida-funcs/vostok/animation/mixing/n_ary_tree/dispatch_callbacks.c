char __usercall vostok::animation::mixing::n_ary_tree::dispatch_callbacks@<al>(
        const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *callback_generators_head@<eax>,
        boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *a2@<ecx>,
        vostok::animation::subscribed_channel **channels_head,
        unsigned int current_time_in_ms,
        boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *callbacks_are_actual)
{
  int i; // ebx
  char v7; // al
  __int16 v8; // dx
  int j; // esi
  vostok::resources::managed_resource *v10; // eax
  vostok::resources::managed_resource *v11; // eax
  int v12; // eax
  bool v13; // al
  bool v14; // al
  bool v15; // zf
  vostok::resources::pinned_ptr_mutable<unsigned char> *v16; // ecx
  boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *v17; // ecx
  int k; // ebx
  vostok::animation::animation_event_channels *v19; // esi
  int channel_id; // eax
  float v21; // xmm1_4
  int v22; // edx
  float *v23; // esi
  int v24; // eax
  float *v25; // ebx
  boost::detail::function::vtable_base *vtable; // ebx
  unsigned int v27; // eax
  _DWORD *v28; // eax
  float v29; // xmm2_4
  boost::detail::function::vtable_base *v30; // eax
  float v31; // xmm3_4
  float v32; // xmm0_4
  unsigned int v33; // eax
  int v34; // esi
  vostok::resources::managed_resource *v35; // eax
  char v36; // al
  vostok::resources::managed_resource *v37; // eax
  int v38; // eax
  bool v39; // al
  bool v40; // al
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v42; // [esp-4h] [ebp-44h] BYREF
  char v43; // [esp+Eh] [ebp-32h]
  char v44; // [esp+Fh] [ebp-31h]
  int v45; // [esp+10h] [ebp-30h]
  int v46; // [esp+14h] [ebp-2Ch]
  unsigned int v47; // [esp+18h] [ebp-28h]
  _BYTE v48[4]; // [esp+1Ch] [ebp-24h] BYREF
  vostok::animation::animation_event_channels *v49; // [esp+20h] [ebp-20h]
  vostok::resources::managed_resource *m_object; // [esp+28h] [ebp-18h] BYREF
  const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v51; // [esp+2Ch] [ebp-14h]
  vostok::resources::managed_resource *v52; // [esp+30h] [ebp-10h]
  unsigned int v53; // [esp+34h] [ebp-Ch]
  vostok::resources::managed_resource *v54; // [esp+38h] [ebp-8h]
  char v55; // [esp+3Ch] [ebp-4h]
  stlp_std::input_iterator_tag m_object_high; // [esp+3Dh] [ebp-3h]
  char v57; // [esp+3Eh] [ebp-2h]

  v43 = 0;
  while ( callback_generators_head )
  {
    if ( ((int)callback_generators_head[5].m_object & 0x1E) != 0 )
    {
      for ( i = (int)*channels_head; i; i = *(_DWORD *)(i + 4) )
      {
        v7 = **(_BYTE **)i;
        if ( v7 < 4 )
        {
          if ( (v8 = (__int16)callback_generators_head[5].m_object, (v8 & 0x18) != 0) && (LOBYTE(a2) = v7 == 1) != 0
            || (v8 & 4) != 0 && (LOBYTE(a2) = v7 == 2) != 0
            || (v8 & 2) != 0 && v7 == 3 )
          {
            for ( j = *(_DWORD *)(i + 8); j; j = *(_DWORD *)(j + 40) )
            {
              if ( *(_BYTE *)(j + 49) )
              {
                v10 = *(vostok::resources::managed_resource **)(j + 32);
                if ( !v10
                  || (a2 = (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) == 0
                  || v10 == callback_generators_head->m_object )
                {
                  v11 = *(vostok::resources::managed_resource **)(j + 36);
                  if ( !v11 || v11 == callback_generators_head[1].m_object )
                  {
                    m_object = callback_generators_head[1].m_object;
                    v52 = *(vostok::resources::managed_resource **)i;
                    v53 = current_time_in_ms;
                    v54 = callback_generators_head[3].m_object;
                    m_object_high = (stlp_std::input_iterator_tag)HIBYTE(callback_generators_head[5].m_object);
                    v51 = callback_generators_head;
                    v55 = -1;
                    v57 = 0;
                    boost::function1<void,vostok::collision::object const &>::operator()(
                      a2,
                      (_DWORD *)j,
                      (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)&m_object);
                    v13 = !v12 && *(_BYTE *)(j + 49);
                    a2 = callbacks_are_actual;
                    *(_BYTE *)(j + 49) = v13;
                    v14 = LOBYTE(callbacks_are_actual->vtable) && v13;
                    v15 = v43 == 0;
                    LOBYTE(callbacks_are_actual->vtable) = v14;
                    if ( !v15 || (v43 = 0, v57) )
                      v43 = 1;
                  }
                }
              }
            }
          }
        }
      }
    }
    if ( ((int)callback_generators_head[5].m_object & 0x20) != 0 )
    {
      v42.m_object = (vostok::resources::managed_resource *)a2;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
        &v42,
        callback_generators_head);
      vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
        v16,
        (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)v48,
        v42);
      if ( v49[1].m_channels_count )
      {
        for ( k = (int)*channels_head; ; k = *(_DWORD *)(k + 4) )
        {
          v46 = k;
          if ( !k )
            break;
          v42.m_object = *(vostok::resources::managed_resource **)k;
          v19 = v49 + 1;
          channel_id = vostok::animation::animation_event_channels::get_channel_id(v49 + 1, (char *)v42.m_object);
          if ( channel_id != -1 )
          {
            v17 = (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)channel_id;
            LOBYTE(v17) = (1 << channel_id) & BYTE2(callback_generators_head[5].m_object);
            if ( (_BYTE)v17 == 1 << channel_id )
            {
              v21 = *(float *)&callback_generators_head[4].m_object * 30.0;
              v17 = (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)((char *)&v19[4] + 44 * channel_id + v19->m_internal_memory_position);
              v22 = *(unsigned int *)((char *)&v19[4].m_internal_memory_position
                                    + 44 * channel_id
                                    + v19->m_internal_memory_position);
              v23 = (float *)((char *)v17 + (unsigned int)v17->vtable + v22);
              v24 = (4 * (int)v17->vtable) >> 2;
              while ( v24 > 0 )
              {
                v25 = &v23[v24 >> 1];
                if ( v21 <= *v25 )
                {
                  v24 >>= 1;
                }
                else
                {
                  v23 = v25 + 1;
                  v24 += -1 - (v24 >> 1);
                }
              }
              vtable = v17->vtable;
              v27 = (signed int)((char *)v23 - (char *)(&v17->vtable)[1] - (unsigned int)v17 - (unsigned int)v17->vtable) >> 2;
              v47 = ((int)((int)v23
                         + 4 * (int)v17->vtable
                         - (unsigned int)(&v17->vtable)[1]
                         - (unsigned int)v17->vtable
                         - (_DWORD)v17
                         - 4) >> 2)
                  % (unsigned int)v17->vtable;
              v45 = v27 % (unsigned int)vtable;
              v28 = (unsigned int *)((char *)&v49->m_channels_count + v49[2].m_internal_memory_position);
              v29 = *(float *)((char *)&v28[5 * *v28 - 1] + v28[1]) - *(float *)((char *)&v28[4 * *v28] + v28[1]);
              v30 = (&v17->vtable)[1];
              if ( v21 < *(float *)((char *)&v17->vtable[v47].manager + (unsigned int)v30 + (_DWORD)v17) )
                v31 = *(float *)((char *)&v17->vtable[v47].manager + (unsigned int)v30 + (_DWORD)v17) - v29;
              else
                v31 = *(float *)((char *)&v17->vtable[v47].manager + (unsigned int)v30 + (_DWORD)v17);
              v32 = *(float *)((char *)&(&v17->vtable)[v45] + (unsigned int)v17->vtable
                                                            + (unsigned int)(&v17->vtable)[1]);
              if ( *(float *)((char *)&(&v17->vtable)[v45] + (unsigned int)(&v17->vtable)[1] + (unsigned int)v17->vtable) < v21 )
                v32 = v32 + v29;
              if ( v32 <= v21 )
                v21 = v32;
              v33 = v45;
              if ( (float)(v21 - v31) <= (float)(v32 - v21) )
                v33 = v47;
              k = v46;
              v34 = *(_DWORD *)(v46 + 8);
              LOBYTE(v17) = *((_BYTE *)&(&v17->vtable)[1]->manager + v33 % (unsigned int)v17->vtable + (unsigned int)v17);
              v44 = (char)v17;
              if ( v34 )
              {
                while ( 1 )
                {
                  if ( *(_BYTE *)(v34 + 49) )
                  {
                    v35 = *(vostok::resources::managed_resource **)(v34 + 32);
                    if ( !v35
                      || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
                      || v35 == callback_generators_head->m_object )
                    {
                      v36 = *(_BYTE *)(v34 + 48);
                      if ( v36 == -1 || v36 == (_BYTE)v17 )
                      {
                        v37 = *(vostok::resources::managed_resource **)(v34 + 36);
                        if ( !v37 || v37 == callback_generators_head[1].m_object )
                        {
                          m_object = callback_generators_head[1].m_object;
                          v52 = *(vostok::resources::managed_resource **)k;
                          v53 = current_time_in_ms;
                          v54 = callback_generators_head[3].m_object;
                          m_object_high = (stlp_std::input_iterator_tag)HIBYTE(callback_generators_head[5].m_object);
                          v51 = callback_generators_head;
                          v55 = (char)v17;
                          v57 = 0;
                          boost::function1<void,vostok::collision::object const &>::operator()(
                            v17,
                            (_DWORD *)v34,
                            (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)&m_object);
                          v39 = !v38 && *(_BYTE *)(v34 + 49);
                          v17 = callbacks_are_actual;
                          *(_BYTE *)(v34 + 49) = v39;
                          v40 = LOBYTE(callbacks_are_actual->vtable) && v39;
                          v15 = v43 == 0;
                          LOBYTE(callbacks_are_actual->vtable) = v40;
                          if ( !v15 || (v43 = 0, v57) )
                            v43 = 1;
                        }
                      }
                    }
                  }
                  v34 = *(_DWORD *)(v34 + 40);
                  if ( !v34 )
                    break;
                  LOBYTE(v17) = v44;
                }
              }
            }
          }
        }
      }
      vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
        (vostok::resources::pinned_ptr_const<unsigned char> *)v17,
        (int)v48);
    }
    callback_generators_head = (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)callback_generators_head[2].m_object;
  }
  return v43;
}
