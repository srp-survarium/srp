void __thiscall vostok::animation::animation_player::compact_callbacks(
        vostok::animation::animation_player *this,
        vostok::animation::animation_player *thisa)
{
  vostok::animation::animation_player *v2; // edi
  const vostok::animation::subscribed_channel *m_first_subscribed_channel; // ebx
  const vostok::animation::subscribed_channel *v4; // esi
  void *v5; // esp
  char *channel_id; // ebx
  unsigned int v7; // kr00_4
  void *v8; // esp
  vostok::animation::subscribed_channel *v9; // ebx
  const vostok::animation::subscribed_channel *v10; // edx
  vostok::animation::animation_callback *first_callback; // edi
  void *v12; // esp
  vostok::animation::subscribed_channel *callback_uid; // ecx
  const void *animated_object; // ebx
  boost::detail::function::vtable_base *vtable; // eax
  vostok::resources::managed_resource *m_object; // eax
  vostok::animation::subscribed_channel *v17; // ecx
  vostok::mutable_buffer *p_m_callbacks_buffer; // ebx
  vostok::animation::subscribed_channel *m_data; // esi
  bool v20; // zf
  unsigned int v21; // edi
  vostok::animation::animation_callback *v22; // edi
  unsigned __int8 *v23; // esi
  vostok::animation::subscribed_channel *v24; // edx
  boost::detail::function::vtable_base *v25; // eax
  vostok::resources::managed_resource *v26; // eax
  vostok::animation::subscribed_channel *v27; // eax
  vostok::animation::subscribed_channel *next; // eax
  _DWORD v29[2]; // [esp-48h] [ebp-74h] BYREF
  _QWORD v30[3]; // [esp-40h] [ebp-6Ch] BYREF
  vostok::resources::managed_resource *v31; // [esp-28h] [ebp-54h]
  const void *v32; // [esp-24h] [ebp-50h]
  int v33; // [esp-20h] [ebp-4Ch]
  vostok::animation::subscribed_channel *v34; // [esp-1Ch] [ebp-48h]
  unsigned __int8 v35; // [esp-18h] [ebp-44h]
  char v36; // [esp-17h] [ebp-43h]
  unsigned __int8 *v37; // [esp-14h] [ebp-40h]
  unsigned __int8 v38[28]; // [esp-10h] [ebp-3Ch] BYREF
  vostok::animation::subscribed_channel *v39; // [esp+Ch] [ebp-20h]
  vostok::animation::subscribed_channel *new_channel; // [esp+10h] [ebp-1Ch]
  vostok::animation::animation_callback *k; // [esp+14h] [ebp-18h]
  unsigned int channels_count; // [esp+18h] [ebp-14h]
  const vostok::animation::subscribed_channel *first_cloned_channel; // [esp+1Ch] [ebp-10h]
  vostok::animation::subscribed_channel *previous_channel; // [esp+20h] [ebp-Ch]
  const vostok::animation::subscribed_channel *i; // [esp+24h] [ebp-8h]
  unsigned __int8 event_type; // [esp+28h] [ebp-4h]

  v2 = thisa;
  m_first_subscribed_channel = thisa->m_first_subscribed_channel;
  v4 = 0;
  thisa->m_callbacks_are_actual = 1;
  i = m_first_subscribed_channel;
  first_cloned_channel = 0;
  previous_channel = 0;
  if ( m_first_subscribed_channel )
  {
    while ( 1 )
    {
      v5 = alloca(16);
      channels_count = (unsigned int)v38;
      if ( v4 )
      {
        this = (vostok::animation::animation_player *)previous_channel;
        previous_channel->next = (vostok::animation::subscribed_channel *)v38;
      }
      else
      {
        first_cloned_channel = (const vostok::animation::subscribed_channel *)v38;
      }
      v37 = v38;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
      channel_id = (char *)m_first_subscribed_channel->channel_id;
      v7 = strlen(channel_id);
      v8 = alloca(v7 + 1);
      memcpy(v38, (unsigned __int8 *)channel_id, v7 + 1);
      v9 = (vostok::animation::subscribed_channel *)channels_count;
      v10 = i;
      *(_DWORD *)channels_count = v38;
      v9->first_callback = 0;
      v9->next = 0;
      first_callback = v10->first_callback;
      for ( k = 0; first_callback; first_callback = first_callback->next )
      {
        if ( first_callback->enabled )
        {
          v12 = alloca(56);
          if ( v29 )
          {
            callback_uid = (vostok::animation::subscribed_channel *)first_callback->callback_uid;
            animated_object = first_callback->animated_object;
            event_type = first_callback->event_type;
            v29[0] = 0;
            vtable = first_callback->callback.vtable;
            new_channel = callback_uid;
            if ( vtable )
            {
              v29[0] = vtable;
              if ( ((unsigned __int8)vtable & 1) != 0 )
              {
                v30[0] = *(_QWORD *)&first_callback->callback.functor.obj_ptr;
                v30[1] = *((_QWORD *)&first_callback->callback.functor.data + 1);
                v30[2] = *((_QWORD *)&first_callback->callback.functor.data + 2);
              }
              else
              {
                (*(void (__cdecl **)(boost::detail::function::function_buffer *, _QWORD *, _DWORD))((unsigned int)vtable
                                                                                                  & 0xFFFFFFFE))(
                  &first_callback->callback.functor,
                  v30,
                  0);
              }
            }
            v31 = 0;
            m_object = first_callback->animation.m_object;
            if ( m_object )
            {
              v31 = first_callback->animation.m_object;
              _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
            }
            v32 = animated_object;
            v9 = (vostok::animation::subscribed_channel *)channels_count;
            v33 = 0;
            v34 = new_channel;
            v35 = event_type;
            v36 = 1;
          }
          if ( k )
            k->next = (vostok::animation::animation_callback *)v29;
          else
            v9->first_callback = (vostok::animation::animation_callback *)v29;
          k = (vostok::animation::animation_callback *)v29;
        }
      }
      if ( v9->first_callback )
      {
        previous_channel = v9;
      }
      else if ( previous_channel )
      {
        previous_channel->next = 0;
      }
      else
      {
        first_cloned_channel = 0;
      }
      this = (vostok::animation::animation_player *)i->next;
      v4 = first_cloned_channel;
      i = (const vostok::animation::subscribed_channel *)this;
      if ( !this )
        break;
      m_first_subscribed_channel = i;
    }
    v2 = thisa;
  }
  vostok::animation::animation_player::destroy_subscriptions(v2->m_first_subscribed_channel);
  p_m_callbacks_buffer = &v2->m_callbacks_buffer;
  v2->m_first_subscribed_channel = 0;
  if ( v2 != (vostok::animation::animation_player *)-34104 )
    boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
      &v2->m_callbacks_buffer,
      (unsigned __int8 *)v2->m_callbacks_buffer_raw,
      0x500u);
  channels_count = 0;
  i = v4;
  if ( v4 )
  {
    do
    {
      m_data = (vostok::animation::subscribed_channel *)p_m_callbacks_buffer->m_data;
      ++channels_count;
      p_m_callbacks_buffer->m_data += 12;
      p_m_callbacks_buffer->m_size -= 12;
      v20 = v2->m_first_subscribed_channel == 0;
      new_channel = m_data;
      if ( v20 )
        v2->m_first_subscribed_channel = m_data;
      else
        previous_channel->next = m_data;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v17);
      v21 = &i->channel_id[strlen(i->channel_id) + 1] - i->channel_id;
      memcpy((unsigned __int8 *)p_m_callbacks_buffer->m_data, (unsigned __int8 *)i->channel_id, v21);
      m_data->channel_id = p_m_callbacks_buffer->m_data;
      if ( (v21 & 3) != 0 )
        v21 = v21 - (v21 & 3) + 4;
      p_m_callbacks_buffer->m_data += v21;
      p_m_callbacks_buffer->m_size -= v21;
      v17 = (vostok::animation::subscribed_channel *)i;
      m_data->next = 0;
      v22 = v17->first_callback;
      k = 0;
      if ( v22 )
      {
        do
        {
          v23 = (unsigned __int8 *)p_m_callbacks_buffer->m_data;
          p_m_callbacks_buffer->m_data += 56;
          p_m_callbacks_buffer->m_size -= 56;
          if ( v23 )
          {
            v24 = (vostok::animation::subscribed_channel *)v22->animated_object;
            v17 = (vostok::animation::subscribed_channel *)v22->callback_uid;
            event_type = v22->event_type;
            *(_DWORD *)v23 = 0;
            v25 = v22->callback.vtable;
            previous_channel = v24;
            v39 = v17;
            if ( v25 )
            {
              *(_DWORD *)v23 = v25;
              if ( ((unsigned __int8)v25 & 1) != 0 )
              {
                *((_QWORD *)v23 + 1) = *(_QWORD *)&v22->callback.functor.obj_ptr;
                *((_QWORD *)v23 + 2) = *((_QWORD *)&v22->callback.functor.data + 1);
                *((_QWORD *)v23 + 3) = *((_QWORD *)&v22->callback.functor.data + 2);
              }
              else
              {
                (*(void (__cdecl **)(boost::detail::function::function_buffer *, unsigned __int8 *, _DWORD))((unsigned int)v25 & 0xFFFFFFFE))(
                  &v22->callback.functor,
                  v23 + 8,
                  0);
              }
            }
            *((_DWORD *)v23 + 8) = 0;
            v26 = v22->animation.m_object;
            if ( v26 )
            {
              *((_DWORD *)v23 + 8) = v26;
              v17 = (vostok::animation::subscribed_channel *)_InterlockedExchangeAdd(&v26->m_reference_count, 1u);
            }
            v27 = v39;
            LOBYTE(v17) = event_type;
            *((_DWORD *)v23 + 9) = previous_channel;
            *((_DWORD *)v23 + 10) = 0;
            *((_DWORD *)v23 + 11) = v27;
            v23[48] = (unsigned __int8)v17;
            v23[49] = 1;
          }
          if ( k )
            k->next = (vostok::animation::animation_callback *)v23;
          else
            new_channel->first_callback = (vostok::animation::animation_callback *)v23;
          v22 = v22->next;
          k = (vostok::animation::animation_callback *)v23;
        }
        while ( v22 );
        m_data = new_channel;
      }
      next = i->next;
      v2 = thisa;
      previous_channel = m_data;
      i = next;
    }
    while ( next );
    v4 = first_cloned_channel;
  }
  vostok::animation::animation_player::destroy_subscriptions(v4);
  if ( !channels_count )
    v2->m_first_subscribed_channel = 0;
}
