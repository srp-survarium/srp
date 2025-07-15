void __thiscall vostok::animation::animation_player::compact_callbacks(
        vostok::animation::animation_player *this,
        int a2)
{
  int v2; // edi
  const char **p_channel_id; // ebx
  void *v4; // esp
  unsigned int v5; // ebx
  void *v6; // esp
  vostok::animation::animation_callback *first_callback; // ebx
  void *v8; // esp
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *v9; // eax
  int v10; // esi
  unsigned int v11; // ecx
  vostok::animation::subscribed_channel *next; // eax
  unsigned __int8 **v13; // ebx
  unsigned __int8 *v14; // eax
  unsigned int v15; // eax
  unsigned __int8 *v16; // eax
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v17; // [esp-48h] [ebp-6Ch] BYREF
  unsigned int v18; // [esp-14h] [ebp-38h]
  _DWORD v19[2]; // [esp-10h] [ebp-34h] BYREF
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *v20; // [esp-8h] [ebp-2Ch]
  unsigned __int8 *v21; // [esp+Ch] [ebp-18h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *v22; // [esp+10h] [ebp-14h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *v23; // [esp+14h] [ebp-10h]
  vostok::animation::subscribed_channel *channels_head; // [esp+18h] [ebp-Ch]
  _DWORD *v25; // [esp+1Ch] [ebp-8h]
  vostok::animation::subscribed_channel *v26; // [esp+20h] [ebp-4h]

  channels_head = 0;
  v25 = 0;
  v2 = a2;
  p_channel_id = *(const char ***)(a2 + 65736);
  *(_BYTE *)(a2 + 65750) = 1;
  v26 = (vostok::animation::subscribed_channel *)p_channel_id;
  if ( p_channel_id )
  {
    while ( 1 )
    {
      v4 = alloca(16);
      if ( channels_head )
        v25[1] = v19;
      else
        channels_head = (vostok::animation::subscribed_channel *)v19;
      v18 = (unsigned int)v19;
      vostok::memory::process_allocator::finalize_impl((vostok::render::stage_screen_space_reflections *)this);
      v5 = &(*p_channel_id)[strlen(*p_channel_id) + 1] - *p_channel_id;
      v6 = alloca(v5);
      memcpy((unsigned __int8 *)v19, (unsigned __int8 *)v26->channel_id, v5);
      v19[0] = v19;
      v20 = 0;
      v19[1] = 0;
      first_callback = v26->first_callback;
      v23 = 0;
      while ( first_callback )
      {
        if ( first_callback->enabled )
        {
          v8 = alloca(56);
          v9 = &v17;
          v22 = &v17;
          if ( &v17 )
          {
            vostok::animation::animation_callback::animation_callback(
              (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)first_callback,
              &first_callback->animation,
              &v17,
              (void *)first_callback->callback_uid,
              first_callback->event_type,
              (boost::detail::function::vtable_base *)first_callback->animated_object);
            v9 = v22;
          }
          this = (vostok::animation::animation_player *)v23;
          if ( v23 )
            v23[1].functor.obj_ptr = v9;
          else
            v20 = v9;
          v23 = v9;
        }
        first_callback = first_callback->next;
      }
      if ( v20 )
      {
        v25 = v19;
      }
      else if ( v25 )
      {
        v25[1] = 0;
      }
      else
      {
        channels_head = 0;
      }
      v26 = v26->next;
      if ( !v26 )
        break;
      p_channel_id = &v26->channel_id;
    }
    v2 = a2;
  }
  vostok::animation::animation_player::destroy_subscriptions(*(const vostok::animation::subscribed_channel **)(v2 + 65736));
  *(_DWORD *)(v2 + 65736) = 0;
  v10 = v2 + 65740;
  v11 = v18;
  if ( v2 != -65740 )
  {
    *(_DWORD *)v10 = v2 + 65752;
    *(_DWORD *)(v2 + 65744) = 2560;
  }
  v23 = 0;
  next = channels_head;
  while ( 1 )
  {
    v26 = next;
    if ( !next )
      break;
    v13 = *(unsigned __int8 ***)v10;
    v23 = (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)((char *)v23 + 1);
    *(_DWORD *)v10 += 12;
    *(_DWORD *)(v10 + 4) -= 12;
    if ( *(_DWORD *)(v2 + 65736) )
      v25[1] = v13;
    else
      *(_DWORD *)(v2 + 65736) = v13;
    v18 = (unsigned int)v13;
    vostok::memory::process_allocator::finalize_impl((vostok::render::stage_screen_space_reflections *)v11);
    memcpy(
      *(unsigned __int8 **)v10,
      (unsigned __int8 *)v26->channel_id,
      &v26->channel_id[strlen(v26->channel_id) + 1] - v26->channel_id);
    v14 = *(unsigned __int8 **)v10;
    v18 = 4;
    *v13 = v14;
    v15 = vostok::math::align_up<unsigned long>(v18);
    *(_DWORD *)v10 += v15;
    *(_DWORD *)(v10 + 4) -= v15;
    v13[1] = 0;
    v22 = 0;
    v11 = (unsigned int)v26->first_callback;
    v25 = (_DWORD *)v11;
    if ( v11 )
    {
      while ( 1 )
      {
        v16 = *(unsigned __int8 **)v10;
        *(_DWORD *)v10 += 56;
        *(_DWORD *)(v10 + 4) -= 56;
        v21 = v16;
        if ( v16 )
        {
          vostok::animation::animation_callback::animation_callback(
            (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)v11,
            (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(v11 + 32),
            (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)v16,
            *(void **)(v11 + 44),
            *(_BYTE *)(v11 + 48),
            *(boost::detail::function::vtable_base **)(v11 + 36));
          v11 = (unsigned int)v25;
          v16 = v21;
        }
        if ( v22 )
          v22[1].functor.obj_ptr = v16;
        else
          v13[2] = v16;
        v11 = *(_DWORD *)(v11 + 40);
        v22 = (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)v16;
        v25 = (_DWORD *)v11;
        if ( !v11 )
          break;
        v11 = (unsigned int)v25;
      }
    }
    next = v26->next;
    v2 = a2;
    v25 = v13;
  }
  vostok::animation::animation_player::destroy_subscriptions(channels_head);
  if ( !v23 )
    *(_DWORD *)(v2 + 65736) = 0;
}
