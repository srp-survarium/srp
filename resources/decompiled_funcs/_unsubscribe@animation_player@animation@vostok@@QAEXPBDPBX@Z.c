void __userpurge vostok::animation::animation_player::unsubscribe(
        vostok::animation::animation_player *channel_id@<eax>,
        vostok::animation::animation_player *this,
        boost::function<void __cdecl(unsigned int,float,float,char const *)> *callback_uid)
{
  vostok::animation::subscribed_channel *i; // esi
  const char *v5; // eax
  vostok::animation::animation_player *v6; // ecx
  bool v7; // cf
  unsigned __int8 v8; // dl
  int v9; // eax
  vostok::animation::animation_callback *first_callback; // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v11; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v12; // ecx
  void (__cdecl *v13)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v14)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v15)(_BYTE *, _BYTE *, int); // eax
  boost::function2<void,unsigned int,unsigned int> f; // [esp+10h] [ebp-60h] BYREF
  boost::function2<void,unsigned int,unsigned int> v17; // [esp+30h] [ebp-40h] BYREF
  int v18; // [esp+50h] [ebp-20h]
  _BYTE v19[24]; // [esp+58h] [ebp-18h] BYREF

  for ( i = this->m_first_subscribed_channel; ; i = i->next )
  {
    v5 = i->channel_id;
    v6 = channel_id;
    while ( 1 )
    {
      v7 = *v5 < (unsigned int)v6->m_tree_buffers[0][0];
      if ( *v5 != v6->m_tree_buffers[0][0] )
        break;
      if ( !*v5 )
        goto LABEL_7;
      v8 = v5[1];
      v7 = v8 < (unsigned int)v6->m_tree_buffers[0][1];
      if ( v8 != v6->m_tree_buffers[0][1] )
        break;
      v5 += 2;
      v6 = (vostok::animation::animation_player *)((char *)v6 + 2);
      if ( !v8 )
      {
LABEL_7:
        v9 = 0;
        goto LABEL_9;
      }
    }
    v9 = -v7 - (v7 - 1);
LABEL_9:
    if ( !v9 )
      break;
  }
  first_callback = i->first_callback;
  if ( first_callback )
  {
    while ( 1 )
    {
      v6 = (vostok::animation::animation_player *)callback_uid;
      if ( first_callback->callback_uid == callback_uid )
        break;
      first_callback = first_callback->next;
      if ( !first_callback )
        goto LABEL_29;
    }
    v18 = 0;
    f.vtable = 0;
    if ( first_callback != (vostok::animation::animation_callback *)&f )
    {
      v17.vtable = 0;
      boost::function1<void,vostok::resources::query_result *>::move_assign(&v17, &f, callback_uid);
      boost::function1<void,vostok::resources::query_result *>::move_assign(
        &f,
        (boost::function2<void,unsigned int,unsigned int> *)first_callback,
        v11);
      boost::function1<void,vostok::resources::query_result *>::move_assign(
        (boost::function2<void,unsigned int,unsigned int> *)first_callback,
        &v17,
        v12);
      if ( v17.vtable )
      {
        if ( ((int)v17.vtable & 1) == 0 )
        {
          v13 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v17.vtable & 0xFFFFFFFE);
          if ( v13 )
            v13(&v17.functor, &v17.functor, 2);
        }
      }
      if ( f.vtable )
      {
        if ( ((int)f.vtable & 1) == 0 )
        {
          v14 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)f.vtable & 0xFFFFFFFE);
          if ( v14 )
            v14(&f.functor, &f.functor, 2);
        }
      }
      if ( v18 )
      {
        if ( (v18 & 1) == 0 )
        {
          v15 = *(void (__cdecl **)(_BYTE *, _BYTE *, int))(v18 & 0xFFFFFFFE);
          if ( v15 )
            v15(v19, v19, 2);
        }
      }
    }
    first_callback->callback_uid = 0;
    first_callback->enabled = 0;
    this->m_callbacks_are_actual = 0;
  }
LABEL_29:
  if ( !this->m_in_tick )
    vostok::animation::animation_player::compact_callbacks(v6, this);
}
