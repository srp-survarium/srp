char __userpurge vostok::animation::mixing::n_ary_tree::tick@<al>(
        vostok::animation::mixing::n_ary_tree *this@<ecx>,
        float a2@<xmm4>,
        int target_time_in_ms,
        vostok::animation::subscribed_channel **channels_head,
        vostok::animation::subscribed_channel **callbacks_are_actual,
        boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *ignore_callbacks_time_in_ms)
{
  bool v7; // zf
  char *v9; // esi
  vostok::animation::mixing::n_ary_tree *v10; // eax
  vostok::animation::mixing::n_ary_tree *v11; // ecx
  vostok::animation::mixing::animated_object_holder *v12; // edi
  vostok::animation::mixing::animated_object_holder *v13; // eax
  vostok::math::float4x4 *object_transform; // esi
  vostok::animation::mixing::n_ary_tree *v15; // ecx
  vostok::animation::mixing::animated_object_holder *v16; // esi
  vostok::animation::mixing::animated_object_holder *v17; // edi
  vostok::animation::mixing::n_ary_tree *v18; // eax
  vostok::math::float4x4 v19; // [esp+Ch] [ebp-4Ch] BYREF
  vostok::animation::mixing::animated_object_holder *v20; // [esp+4Ch] [ebp-Ch]
  vostok::animation::mixing::animated_object_holder *v21; // [esp+50h] [ebp-8h]
  char *v22; // [esp+54h] [ebp-4h]
  char v23; // [esp+63h] [ebp+Bh]

  v7 = *(_DWORD *)(target_time_in_ms + 4) == 0;
  v23 = 0;
  if ( v7 )
  {
    *(_DWORD *)(target_time_in_ms + 44) = channels_head;
    return 0;
  }
  else
  {
    do
    {
      v9 = *(char **)(**(_DWORD **)(target_time_in_ms + 20) + 160);
      v22 = v9;
      if ( v9 > (char *)channels_head )
        break;
      v10 = *(vostok::animation::mixing::n_ary_tree **)(target_time_in_ms + 44);
      if ( v10 < (vostok::animation::mixing::n_ary_tree *)v9 )
        vostok::animation::mixing::n_ary_tree::update_animation_states(this, target_time_in_ms, v10, v9);
      if ( vostok::animation::mixing::n_ary_tree::need_new_transform(this, target_time_in_ms, (int)v9) )
      {
        vostok::animation::mixing::n_ary_tree::process_events(
          1u,
          (vostok::animation::mixing::n_ary_tree *)target_time_in_ms,
          (vostok::animation::mixing::n_ary_tree_animation_node **)v9);
        v12 = *(vostok::animation::mixing::animated_object_holder **)(target_time_in_ms + 24);
        v13 = &v12[*(_DWORD *)(target_time_in_ms + 36)];
        v20 = v13;
        while ( 1 )
        {
          v21 = v12;
          if ( v12 == v13 )
            break;
          if ( v12->need_new_transform )
          {
            object_transform = vostok::animation::mixing::n_ary_tree::get_object_transform(
                                 v11,
                                 target_time_in_ms,
                                 a2,
                                 &v19,
                                 (void *)v12->animated_object);
            v13 = v20;
            qmemcpy(&v12->new_transform, object_transform, sizeof(v12->new_transform));
            v11 = 0;
            v12 = v21;
            v9 = v22;
          }
          ++v12;
        }
        vostok::animation::mixing::n_ary_tree::process_events(
          0x1FEu,
          (vostok::animation::mixing::n_ary_tree *)target_time_in_ms,
          (vostok::animation::mixing::n_ary_tree_animation_node **)v9);
        v16 = *(vostok::animation::mixing::animated_object_holder **)(target_time_in_ms + 24);
        v17 = &v16[*(_DWORD *)(target_time_in_ms + 36)];
        while ( v16 != v17 )
        {
          if ( v16->need_new_transform )
          {
            vostok::animation::mixing::n_ary_tree::set_object_transform(
              (vostok::animation::mixing::n_ary_tree *)&v16->new_transform,
              target_time_in_ms,
              v16->animated_object,
              &v16->new_transform);
            v16->need_new_transform = 0;
          }
          ++v16;
        }
        v9 = v22;
      }
      else
      {
        vostok::animation::mixing::n_ary_tree::process_events(
          0x1FFu,
          (vostok::animation::mixing::n_ary_tree *)target_time_in_ms,
          (vostok::animation::mixing::n_ary_tree_animation_node **)v9);
      }
      *(_DWORD *)(target_time_in_ms + 44) = v9;
      if ( !vostok::animation::mixing::n_ary_tree::update_event_iterators_and_dispatch_callbacks(
              v15,
              (_DWORD *)target_time_in_ms,
              (vostok::animation::subscribed_channel **)v9,
              callbacks_are_actual,
              ignore_callbacks_time_in_ms) )
      {
        v7 = v23 == 0;
        v23 = 0;
        if ( v7 )
          continue;
      }
      v23 = 1;
    }
    while ( *(_DWORD *)(target_time_in_ms + 4) );
    if ( *(_DWORD *)(target_time_in_ms + 4) )
    {
      v18 = *(vostok::animation::mixing::n_ary_tree **)(target_time_in_ms + 44);
      if ( v18 != (vostok::animation::mixing::n_ary_tree *)channels_head )
      {
        vostok::animation::mixing::n_ary_tree::update_animation_states(
          this,
          target_time_in_ms,
          v18,
          (char *)channels_head);
        *(_DWORD *)(target_time_in_ms + 44) = channels_head;
      }
    }
    return v23;
  }
}
