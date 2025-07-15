char __userpurge vostok::animation::mixing::n_ary_tree::tick@<al>(
        vostok::animation::mixing::n_ary_tree *this@<ecx>,
        float a2@<xmm4>,
        int target_time_in_ms,
        vostok::animation::subscribed_channel **channels_head,
        vostok::animation::subscribed_channel **callbacks_are_actual,
        bool *callbacks_are_actuala)
{
  bool v7; // zf
  vostok::animation::mixing::n_ary_tree *v9; // ecx
  vostok::animation::mixing::animation_state **m_reference_count; // esi
  vostok::animation::subscribed_channel **v11; // edi
  vostok::animation::mixing::animated_object_holder *v12; // ebx
  vostok::animation::mixing::animated_object_holder *v13; // eax
  vostok::math::float4x4 *object_transform; // esi
  vostok::animation::mixing::n_ary_tree *v15; // ecx
  int v16; // esi
  int i; // edi
  vostok::animation::subscribed_channel **v18; // [esp+10h] [ebp-4Ch]
  vostok::animation::mixing::animated_object_holder *e; // [esp+14h] [ebp-48h]
  vostok::math::float4x4 animated_object; // [esp+18h] [ebp-44h] BYREF
  char user_handled_callbacks; // [esp+60h] [ebp+4h]

  v7 = *(_DWORD *)(target_time_in_ms + 4) == 0;
  user_handled_callbacks = 0;
  if ( v7 )
  {
    *(_DWORD *)(target_time_in_ms + 40) = channels_head;
    return 0;
  }
  else
  {
    while ( 1 )
    {
      v9 = *(vostok::animation::mixing::n_ary_tree **)(target_time_in_ms + 20);
      m_reference_count = (vostok::animation::mixing::animation_state **)v9->m_reference_counter.m_object[41].m_reference_count;
      v11 = channels_head;
      v18 = (vostok::animation::subscribed_channel **)m_reference_count;
      if ( m_reference_count > (vostok::animation::mixing::animation_state **)channels_head )
        break;
      if ( *(_DWORD *)(target_time_in_ms + 40) < (unsigned int)m_reference_count )
        vostok::animation::mixing::n_ary_tree::update_animation_states(
          (vostok::animation::mixing::n_ary_tree *)target_time_in_ms,
          (unsigned int)m_reference_count,
          a2,
          *(vostok::animation::mixing::n_ary_tree **)(target_time_in_ms + 40));
      if ( vostok::animation::mixing::n_ary_tree::need_new_transform(
             v9,
             (const vostok::animation::mixing::n_ary_tree *)target_time_in_ms,
             (unsigned int)m_reference_count) )
      {
        vostok::animation::mixing::n_ary_tree::process_events(
          (vostok::animation::mixing::n_ary_tree *)target_time_in_ms,
          1u,
          a2,
          (unsigned int)m_reference_count);
        v12 = *(vostok::animation::mixing::animated_object_holder **)(target_time_in_ms + 24);
        v13 = &v12[*(_DWORD *)(target_time_in_ms + 32)];
        for ( e = v13; v12 != v13; ++v12 )
        {
          if ( v12->need_new_transform )
          {
            object_transform = vostok::animation::mixing::n_ary_tree::get_object_transform(
                                 (vostok::animation::mixing::n_ary_tree *)&animated_object,
                                 (const vostok::animation::mixing::n_ary_tree *)target_time_in_ms,
                                 &animated_object,
                                 v12->animated_object);
            v13 = e;
            qmemcpy((void *)&v12->new_transform, object_transform, sizeof(v12->new_transform));
            m_reference_count = (vostok::animation::mixing::animation_state **)v18;
          }
        }
        vostok::animation::mixing::n_ary_tree::process_events(
          (vostok::animation::mixing::n_ary_tree *)target_time_in_ms,
          0x1FEu,
          a2,
          (unsigned int)m_reference_count);
        v16 = *(_DWORD *)(target_time_in_ms + 24);
        for ( i = v16 + 136 * *(_DWORD *)(target_time_in_ms + 32); v16 != i; v16 += 136 )
        {
          if ( *(_BYTE *)(v16 + 132) )
          {
            vostok::animation::mixing::n_ary_tree::set_object_transform(
              v15,
              target_time_in_ms,
              a2,
              *(const void **)(v16 + 128),
              (const vostok::math::float4x4 *)(v16 + 64));
            *(_BYTE *)(v16 + 132) = 0;
          }
        }
        m_reference_count = (vostok::animation::mixing::animation_state **)v18;
      }
      else
      {
        vostok::animation::mixing::n_ary_tree::process_events(
          (vostok::animation::mixing::n_ary_tree *)target_time_in_ms,
          0x1FFu,
          a2,
          (unsigned int)m_reference_count);
      }
      *(_DWORD *)(target_time_in_ms + 40) = m_reference_count;
      if ( vostok::animation::mixing::n_ary_tree::update_event_iterators_and_dispatch_callbacks(
             (vostok::animation::mixing::n_ary_tree *)callbacks_are_actuala,
             (vostok::animation::mixing::n_ary_tree *)target_time_in_ms,
             m_reference_count,
             callbacks_are_actual,
             callbacks_are_actuala)
        || (v7 = user_handled_callbacks == 0, user_handled_callbacks = 0, !v7) )
      {
        user_handled_callbacks = 1;
      }
      if ( !*(_DWORD *)(target_time_in_ms + 4) )
      {
        v11 = channels_head;
        break;
      }
    }
    if ( *(_DWORD *)(target_time_in_ms + 4) )
    {
      if ( *(vostok::animation::subscribed_channel ***)(target_time_in_ms + 40) != v11 )
      {
        vostok::animation::mixing::n_ary_tree::update_animation_states(
          (vostok::animation::mixing::n_ary_tree *)target_time_in_ms,
          (unsigned int)v11,
          a2,
          *(vostok::animation::mixing::n_ary_tree **)(target_time_in_ms + 40));
        *(_DWORD *)(target_time_in_ms + 40) = v11;
      }
    }
    return user_handled_callbacks;
  }
}
