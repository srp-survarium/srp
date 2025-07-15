bool __cdecl vostok::animation::mixing::n_ary_tree::dispatch_callbacks(
        const vostok::animation::mixing::callback_generator_info *callback_generators_head,
        const vostok::animation::subscribed_channel **channels_head,
        unsigned int current_time_in_ms,
        bool *callbacks_are_actual)
{
  const vostok::animation::mixing::callback_generator_info *v4; // ebx
  bool *v5; // ebp
  bool v6; // al
  const vostok::animation::subscribed_channel *i; // edi
  char v8; // al
  unsigned __int16 event_type; // dx
  vostok::animation::animation_callback *j; // esi
  vostok::resources::managed_resource *m_object; // eax
  const void *animated_object; // eax
  bool v13; // zf
  const char *channel_id; // ecx
  unsigned int user_data; // eax
  survarium::game_camera *v16; // eax
  bool v17; // al
  bool v18; // al
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v19; // ecx
  vostok::resources::managed_resource *v20; // eax
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *v21; // ecx
  const unsigned __int8 *m_data; // eax
  const unsigned __int8 *v23; // ecx
  const unsigned __int8 *v24; // eax
  int v25; // eax
  const unsigned __int8 *v26; // esi
  int v27; // ecx
  const vostok::animation::event_channel *v28; // edi
  char *v29; // ebp
  const vostok::animation::event_channel *v30; // eax
  int v31; // ecx
  const unsigned __int8 *v32; // eax
  unsigned int v33; // ebp
  float v34; // xmm1_4
  const unsigned __int8 *v35; // ecx
  int v36; // esi
  int v37; // eax
  int v38; // edi
  unsigned int v39; // edi
  int v40; // edx
  float v41; // xmm2_4
  int v42; // eax
  int v43; // edx
  float v44; // xmm3_4
  unsigned int v45; // eax
  float v46; // xmm0_4
  const vostok::animation::subscribed_channel *v47; // edi
  vostok::animation::animation_callback *first_callback; // esi
  unsigned __int8 v49; // cl
  vostok::resources::managed_resource *v50; // eax
  unsigned __int8 v51; // al
  const void *v52; // eax
  const char *v53; // edx
  unsigned int v54; // eax
  unsigned __int8 animation_interval_id; // cl
  survarium::game_camera *v56; // eax
  bool v57; // al
  bool v58; // al
  const unsigned __int8 *v59; // eax
  const unsigned __int8 *v60; // ecx
  const unsigned __int8 *v61; // eax
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v62; // [esp-4h] [ebp-288h] BYREF
  bool result; // [esp+13h] [ebp-271h]
  const vostok::animation::subscribed_channel *subscribed_channel; // [esp+14h] [ebp-270h] BYREF
  unsigned __int8 domain_data; // [esp+1Bh] [ebp-269h]
  const vostok::animation::mixing::callback_generator_info *generator; // [esp+1Ch] [ebp-268h]
  vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> pinned_animation; // [esp+20h] [ebp-264h] BYREF
  unsigned int knot_upper_id; // [esp+2Ch] [ebp-258h]
  _DWORD v69[5]; // [esp+30h] [ebp-254h] BYREF
  unsigned __int8 v70; // [esp+44h] [ebp-240h]
  unsigned __int8 v71; // [esp+45h] [ebp-23Fh]
  char v72; // [esp+46h] [ebp-23Eh]
  vostok::animation::animation_callback_params params; // [esp+48h] [ebp-23Ch] BYREF
  boost::bad_function_call v74; // [esp+60h] [ebp-224h] BYREF
  boost::bad_function_call v75; // [esp+170h] [ebp-114h] BYREF

  v4 = callback_generators_head;
  v5 = callbacks_are_actual;
  v6 = 0;
  result = 0;
  generator = callback_generators_head;
  if ( callback_generators_head )
  {
    do
    {
      if ( (v4->event_type & 0x1E) != 0 )
      {
        for ( i = *channels_head; i; i = i->next )
        {
          v8 = *i->channel_id;
          if ( v8 < 4 )
          {
            if ( (event_type = v4->event_type, (event_type & 0x18) != 0) && v8 == 1
              || (event_type & 4) != 0 && v8 == 2
              || (event_type & 2) != 0 && v8 == 3 )
            {
              for ( j = i->first_callback; j; j = j->next )
              {
                if ( j->enabled )
                {
                  m_object = j->animation.m_object;
                  if ( !m_object
                    || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
                    || m_object == v4->animation.m_object )
                  {
                    animated_object = j->animated_object;
                    if ( !animated_object || animated_object == v4->animated_object )
                    {
                      v13 = j->callback.vtable == 0;
                      channel_id = i->channel_id;
                      params.animated_object = v4->animated_object;
                      user_data = v4->user_data;
                      params.channel_id = channel_id;
                      LOBYTE(channel_id) = v4->animation_interval_id;
                      params.animation = &v4->animation;
                      params.callback_time_in_ms = current_time_in_ms;
                      params.animation_user_data = user_data;
                      params.domain_data = -1;
                      params.animation_interval_id = (unsigned __int8)channel_id;
                      params.interrupt_animation_player_tick = 0;
                      if ( v13 )
                      {
                        boost::bad_function_call::bad_function_call(&v74);
                        boost::throw_exception(v16);
                        stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)&v74);
                      }
                      v17 = !(*(int (__cdecl **)(boost::detail::function::function_buffer *, vostok::animation::animation_callback_params *))(((int)j->callback.vtable & 0xFFFFFFFE) + 4))(
                               &j->callback.functor,
                               &params)
                         && j->enabled;
                      j->enabled = v17;
                      v18 = *v5 && v17;
                      v13 = !result;
                      *v5 = v18;
                      if ( !v13 || (result = 0, params.interrupt_animation_player_tick) )
                        result = 1;
                    }
                  }
                }
              }
            }
          }
        }
      }
      if ( (v4->event_type & 0x20) != 0 )
      {
        v19.m_object = v4->animation.m_object;
        v20 = 0;
        subscribed_channel = 0;
        if ( v19.m_object )
        {
          v20 = v19.m_object;
          subscribed_channel = (const vostok::animation::subscribed_channel *)v19.m_object;
          _InterlockedExchangeAdd(&v19.m_object->m_reference_count, 1u);
        }
        v21 = (vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&v62;
        v62.m_object = 0;
        if ( v20 )
        {
          v62.m_object = v20;
          v21 = (vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)_InterlockedExchangeAdd(&v20->m_reference_count, 1u);
        }
        vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
          v21,
          &pinned_animation.m_resource,
          v62);
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&subscribed_channel);
        m_data = pinned_animation.m_data;
        if ( *((_DWORD *)pinned_animation.m_data + 2) )
        {
          for ( subscribed_channel = *channels_head; subscribed_channel; subscribed_channel = subscribed_channel->next )
          {
            v25 = *((_DWORD *)pinned_animation.m_data + 2);
            v26 = pinned_animation.m_data + 8;
            if ( v25 != -1 )
            {
              if ( v25 )
              {
                v27 = *((_DWORD *)pinned_animation.m_data + 3);
                v28 = (const vostok::animation::event_channel *)&v26[44 * v25 + v27];
                v29 = (char *)&v26[v27];
                v30 = stlp_std::priv::__find_if<vostok::animation::event_channel const *,vostok::animation::find_predicate>(
                        (const vostok::animation::event_channel *)&v26[v27],
                        v28,
                        (vostok::animation::find_predicate)subscribed_channel->channel_id);
                if ( v30 != v28 )
                {
                  v31 = ((char *)v30 - v29) / 44;
                  if ( v31 != -1 && ((unsigned __int8)(1 << v31) & v4->channel_ids) == 1 << v31 )
                  {
                    v32 = &v26[44 * v31 + *((_DWORD *)v26 + 1)];
                    v33 = *((_DWORD *)v32 + 8);
                    v34 = (float)v4->animation_time * 30.0;
                    v35 = v32 + 32;
                    v36 = (int)&v32[v33 + 32 + *((_DWORD *)v32 + 9)];
                    v37 = (int)(4 * v33) >> 2;
                    while ( v37 > 0 )
                    {
                      v38 = v37 >> 1;
                      if ( v34 <= *(float *)(v36 + 4 * (v37 >> 1)) )
                      {
                        v37 >>= 1;
                      }
                      else
                      {
                        v36 += 4 * v38 + 4;
                        v37 += -1 - v38;
                      }
                    }
                    v39 = ((int)(4 * v33 - *((_DWORD *)v35 + 1) - v33 - (_DWORD)v35 + v36 - 4) >> 2) % v33;
                    knot_upper_id = ((int)(v36 - *((_DWORD *)v35 + 1) - (_DWORD)v35 - v33) >> 2) % v33;
                    v40 = *((_DWORD *)pinned_animation.m_data + 5);
                    v41 = *(float *)&pinned_animation.m_data[20 * *(_DWORD *)&pinned_animation.m_data[v40]
                                                           - 4
                                                           + v40
                                                           + *(_DWORD *)&pinned_animation.m_data[v40 + 4]]
                        - *(float *)&pinned_animation.m_data[16 * *(_DWORD *)&pinned_animation.m_data[v40]
                                                           + v40
                                                           + *(_DWORD *)&pinned_animation.m_data[v40 + 4]];
                    v42 = 4 * v39;
                    v43 = *((_DWORD *)v35 + 1);
                    if ( v34 < *(float *)&v35[4 * v39 + v33 + v43] )
                      v44 = *(float *)&v35[v33 + v42 + v43] - v41;
                    else
                      v44 = *(float *)&v35[v42 + v43 + v33];
                    v45 = knot_upper_id;
                    v46 = *(float *)&v35[4 * knot_upper_id + *((_DWORD *)v35 + 1) + v33];
                    if ( *(float *)&v35[4 * knot_upper_id + v33 + *((_DWORD *)v35 + 1)] < v34 )
                      v46 = v46 + v41;
                    if ( v46 <= v34 )
                      v34 = v46;
                    if ( (float)(v34 - v44) <= (float)(v46 - v34) )
                      v45 = v39;
                    v47 = subscribed_channel;
                    first_callback = subscribed_channel->first_callback;
                    v4 = generator;
                    v49 = v35[*((_DWORD *)v35 + 1) + v45 % v33];
                    domain_data = v49;
                    if ( first_callback )
                    {
                      while ( 1 )
                      {
                        if ( first_callback->enabled )
                        {
                          v50 = first_callback->animation.m_object;
                          if ( !v50
                            || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
                            || v50 == v4->animation.m_object )
                          {
                            v51 = first_callback->event_type;
                            if ( v51 == 0xFF || v51 == v49 )
                            {
                              v52 = first_callback->animated_object;
                              if ( !v52 || v52 == v4->animated_object )
                              {
                                v13 = first_callback->callback.vtable == 0;
                                v53 = v47->channel_id;
                                v69[0] = v4->animated_object;
                                v54 = v4->user_data;
                                v70 = v49;
                                animation_interval_id = v4->animation_interval_id;
                                v69[1] = v4;
                                v69[2] = v53;
                                v69[3] = current_time_in_ms;
                                v69[4] = v54;
                                v71 = animation_interval_id;
                                v72 = 0;
                                if ( v13 )
                                {
                                  boost::bad_function_call::bad_function_call(&v75);
                                  boost::throw_exception(v56);
                                  stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)&v75);
                                }
                                v57 = !(*(int (__cdecl **)(boost::detail::function::function_buffer *, _DWORD *))(((int)first_callback->callback.vtable & 0xFFFFFFFE) + 4))(
                                         &first_callback->callback.functor,
                                         v69)
                                   && first_callback->enabled;
                                first_callback->enabled = v57;
                                v58 = *callbacks_are_actual && v57;
                                v13 = !result;
                                *callbacks_are_actual = v58;
                                if ( !v13 || (result = 0, v72) )
                                  result = 1;
                              }
                            }
                          }
                        }
                        first_callback = first_callback->next;
                        if ( !first_callback )
                          break;
                        v49 = domain_data;
                      }
                    }
                  }
                }
              }
            }
          }
          if ( pinned_animation.m_resource.m_object )
          {
            if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
            {
              v59 = pinned_animation.m_data;
              v60 = pinned_animation.m_data - 8;
              _InterlockedExchangeAdd((volatile signed __int32 *)pinned_animation.m_data - 2, 0xFFFFFFFF);
              v61 = v59 - 36;
              if ( *(_DWORD *)v61 )
              {
                if ( !*(_DWORD *)v60 )
                {
                  _InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)v61 + 40), 1u);
                  *(_DWORD *)v61 = 0;
                }
              }
            }
          }
          vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&pinned_animation.m_resource);
          v5 = callbacks_are_actual;
        }
        else
        {
          if ( pinned_animation.m_resource.m_object )
          {
            if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
            {
              v23 = pinned_animation.m_data - 8;
              _InterlockedExchangeAdd((volatile signed __int32 *)pinned_animation.m_data - 2, 0xFFFFFFFF);
              v24 = m_data - 36;
              if ( *(_DWORD *)v24 )
              {
                if ( !*(_DWORD *)v23 )
                {
                  _InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)v24 + 40), 1u);
                  *(_DWORD *)v24 = 0;
                }
              }
            }
          }
          vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&pinned_animation.m_resource);
        }
      }
      v4 = v4->next;
      generator = v4;
    }
    while ( v4 );
    return result;
  }
  return v6;
}
