char __thiscall vostok::animation::mixing::n_ary_tree::update_event_iterators_and_dispatch_callbacks(
        vostok::animation::mixing::n_ary_tree *this,
        _DWORD *target_time_in_ms,
        vostok::animation::subscribed_channel **channels_head,
        vostok::animation::subscribed_channel **callbacks_are_actual,
        boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *ignore_callbacks_time_in_ms)
{
  _DWORD *v5; // edi
  int v6; // ebx
  int v7; // esi
  vostok::animation::subscribed_channel **v8; // eax
  unsigned __int16 v9; // ax
  int v10; // edi
  void *v11; // esp
  __int16 v12; // cx
  vostok::animation::mixing::callback_generator_info *v13; // eax
  int v14; // ecx
  vostok::animation::mixing::n_ary_tree *v15; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *m_object; // esi
  boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *v17; // ecx
  char v18; // bl
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v19; // ecx
  vostok::animation::mixing::callback_generator_info v21; // [esp+14h] [ebp-38h] BYREF
  vostok::animation::mixing::callback_generator_info *v22; // [esp+3Ch] [ebp-10h]
  int v23; // [esp+40h] [ebp-Ch]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v24; // [esp+44h] [ebp-8h]
  vostok::animation::mixing::n_ary_tree *v25; // [esp+48h] [ebp-4h]

  v24 = 0;
  v25 = 0;
  v5 = target_time_in_ms;
  v6 = target_time_in_ms[4];
  v7 = v6 + 176 * target_time_in_ms[8];
  if ( v6 != v7 )
  {
    do
    {
      v8 = *(vostok::animation::subscribed_channel ***)(v6 + 160);
      if ( v8 )
      {
        if ( v8 == channels_head )
        {
          v9 = *(_WORD *)(v6 + 164);
          if ( (v9 & 0x3E) != 0 )
          {
            v10 = *(_DWORD *)(v6 + 168);
            if ( !*(_BYTE *)(v10 + 83) || (v9 & 2) != 0 )
            {
              if ( *(_BYTE *)(v10 + 86) )
              {
                v23 = v9;
                v11 = alloca(24);
                v12 = *(_WORD *)(v6 + 164);
                v13 = &v21;
                v22 = &v21;
                if ( (v12 & 4) != 0 )
                  v14 = *(_DWORD *)(v6 + 96);
                else
                  v14 = *(_DWORD *)(v6 + 92);
                if ( &v21 )
                {
                  vostok::animation::mixing::callback_generator_info::callback_generator_info(
                    &v21,
                    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(*(_DWORD *)(*(_DWORD *)(v6 + 168) + 16) + 20 * v14),
                    *(const void **)(*(_DWORD *)(v6 + 168) + 36),
                    *(float *)(v6 + 108),
                    v23,
                    *(_BYTE *)(v6 + 166),
                    *(_DWORD *)(v10 + 48),
                    v14);
                  v13 = v22;
                }
                this = v25;
                if ( v25 )
                  v25->m_time_root = (vostok::animation::mixing::n_ary_tree_animation_node *)v13;
                else
                  v24 = &v13->animation.vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>;
                v25 = (vostok::animation::mixing::n_ary_tree *)v13;
              }
            }
          }
        }
      }
      v6 += 176;
    }
    while ( v6 != v7 );
    v5 = target_time_in_ms;
  }
  vostok::animation::mixing::n_ary_tree::remove_animations(this, (const unsigned int)v5, (int)channels_head);
  vostok::animation::mixing::n_ary_tree::update_event_iterators(
    v15,
    v5,
    (vostok::animation::mixing::n_ary_tree_event_iterator *)channels_head);
  m_object = v24;
  v18 = vostok::animation::mixing::n_ary_tree::dispatch_callbacks(
          v24,
          v17,
          callbacks_are_actual,
          (unsigned int)channels_head,
          ignore_callbacks_time_in_ms);
  while ( m_object )
  {
    v19 = m_object;
    m_object = (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)m_object[2].m_object;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(v19);
  }
  return v18;
}
