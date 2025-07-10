void __thiscall vostok::sound::sound_world::serialize_proxy(
        vostok::sound::sound_world *this,
        vostok::sound::sound_instance_proxy_internal *proxy,
        boost::function<void __cdecl(vostok::memory::writer *,vostok::memory::writer *)> *fn,
        vostok::memory::writer *w)
{
  vostok::memory::writer *v4; // eax
  boost::function<void __cdecl(vostok::memory::writer *,vostok::memory::writer *)> v5; // [esp-6Ch] [ebp-110h] BYREF
  vostok::memory::writer *v6; // [esp-4Ch] [ebp-F0h]
  vostok::memory::writer *v7; // [esp-48h] [ebp-ECh]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::sound::sound_instance_proxy_internal,boost::function<void __cdecl(vostok::memory::writer *,vostok::memory::writer *)> &,vostok::memory::writer *,vostok::memory::writer *>,boost::_bi::list4<boost::_bi::value<vostok::sound::sound_instance_proxy_internal *>,boost::_bi::value<boost::function<void __cdecl(vostok::memory::writer *,vostok::memory::writer *)> >,boost::_bi::value<vostok::memory::writer *>,boost::_bi::value<vostok::memory::writer *> > > v8; // [esp-44h] [ebp-E8h] BYREF
  int v9; // [esp-4h] [ebp-A8h]
  vostok::sound::functor_command<vostok::sound::sound_response> *v10; // [esp+0h] [ebp-A4h]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::sound::sound_instance_proxy_internal,boost::function<void __cdecl(vostok::memory::writer *,vostok::memory::writer *)> &,vostok::memory::writer *,vostok::memory::writer *>,boost::_bi::list4<boost::_bi::value<vostok::sound::sound_instance_proxy_internal *>,boost::_bi::value<boost::function<void __cdecl(vostok::memory::writer *,vostok::memory::writer *)> >,boost::_bi::value<vostok::memory::writer *>,boost::_bi::value<vostok::memory::writer *> > > *v11; // [esp+4h] [ebp-A0h]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::sound::sound_instance_proxy_internal,boost::function<void __cdecl(vostok::memory::writer *,vostok::memory::writer *)> &,vostok::memory::writer *,vostok::memory::writer *>,boost::_bi::list4<boost::_bi::value<vostok::sound::sound_instance_proxy_internal *>,boost::_bi::value<boost::function<void __cdecl(vostok::memory::writer *,vostok::memory::writer *)> >,boost::_bi::value<vostok::memory::writer *>,boost::_bi::value<vostok::memory::writer *> > > *result; // [esp+8h] [ebp-9Ch]
  vostok::memory::writer *v13; // [esp+Ch] [ebp-98h]
  const vostok::sound::sound_world *thisa; // [esp+10h] [ebp-94h]
  boost::function0<void> *v15; // [esp+20h] [ebp-84h]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v16; // [esp+30h] [ebp-74h]
  vostok::sound::sound_response *v17; // [esp+34h] [ebp-70h]
  vostok::memory::base_allocator *m_owner_allocator; // [esp+38h] [ebp-6Ch]
  vostok::sound::world_user *channel; // [esp+3Ch] [ebp-68h]
  char v20; // [esp+43h] [ebp-61h]
  vostok::sound::world_user *m_user; // [esp+44h] [ebp-60h]
  unsigned int v22; // [esp+48h] [ebp-5Ch] BYREF
  unsigned int m_size; // [esp+4Ch] [ebp-58h]
  vostok::memory::writer *v24; // [esp+50h] [ebp-54h]
  vostok::memory::doug_lea_allocator *m_object; // [esp+54h] [ebp-50h]
  int v26; // [esp+58h] [ebp-4Ch]
  void (__thiscall *__ptr64 f)(vostok::sound::sound_instance_proxy_internal *, boost::function<void __cdecl(vostok::memory::writer *,vostok::memory::writer *)> *, vostok::memory::writer *, vostok::memory::writer *); // [esp+5Ch] [ebp-48h]
  boost::function<void __cdecl(void)> v28; // [esp+6Ch] [ebp-38h] BYREF
  vostok::sound::sound_response *v29; // [esp+8Ch] [ebp-18h]
  vostok::memory::writer *v30; // [esp+90h] [ebp-14h]
  char v31; // [esp+97h] [ebp-Dh]
  vostok::sound::new_sound_propagator *prop; // [esp+98h] [ebp-Ch]
  vostok::memory::writer *sound_thread_writer; // [esp+9Ch] [ebp-8h]
  vostok::sound::functor_command<vostok::sound::sound_response> *response; // [esp+A0h] [ebp-4h]

  thisa = this;
  v26 = 0;
  v31 = 0;
  m_object = (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object;
  v24 = (vostok::memory::writer *)vostok::memory::doug_lea_allocator::malloc_impl(
                                    (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
                                    0x2Cu);
  v30 = v24;
  if ( v24 )
  {
    vostok::memory::writer::writer(v30, (vostok::memory::base_allocator *)vostok::sound::g_allocator.m_object);
    v13 = v4;
  }
  else
  {
    v13 = 0;
  }
  sound_thread_writer = v13;
  m_size = proxy->m_propagators.m_size;
  v22 = m_size;
  v13->write(v13, &v22, 4u);
  for ( prop = proxy->m_propagators.m_first; prop; prop = prop->m_next_for_proxies )
    ;
  m_user = proxy->m_user;
  channel = vostok::sound::world_user::get_channel(m_user);
  v20 = 0;
  m_owner_allocator = channel->m_channel.responses.m_owner_allocator;
  v17 = (vostok::sound::sound_response *)vostok::memory::base_allocator::malloc_impl(m_owner_allocator, 0x28u);
  v29 = v17;
  if ( v17 )
  {
    LODWORD(f) = vostok::sound::sound_instance_proxy_internal::on_propagators_serialized;
    HIDWORD(f) = 0;
    v9 = 0;
    result = &v8;
    v7 = w;
    v6 = sound_thread_writer;
    v16 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)&v5;
    v5.vtable = 0;
    boost::function1<void,vostok::sound::create_sound_propagator_params const &>::assign_to_own(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)&v5,
      (const boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)fn);
    v11 = boost::bind<void,vostok::sound::sound_instance_proxy_internal,boost::function<void __cdecl (vostok::memory::writer *,vostok::memory::writer *)> &,vostok::memory::writer *,vostok::memory::writer *,vostok::sound::sound_instance_proxy_internal *,boost::function<void __cdecl (vostok::memory::writer *,vostok::memory::writer *)>,vostok::memory::writer *,vostok::memory::writer *>(
            result,
            f,
            proxy,
            v5,
            v6,
            v7);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(&v28, v8, v9);
    v26 |= 1u;
    vostok::sound::sound_response::sound_response(v29);
    v29->__vftable = (vostok::sound::sound_response_vtbl *)&vostok::sound::functor_command<vostok::sound::sound_response>::`vftable';
    v15 = (boost::function0<void> *)&v29[1];
    v29[1].__vftable = 0;
    boost::function0<void>::assign_to_own(v15, &v28);
    v10 = (vostok::sound::functor_command<vostok::sound::sound_response> *)v29;
  }
  else
  {
    v10 = 0;
  }
  response = v10;
  if ( (v26 & 1) != 0 )
  {
    v26 &= ~1u;
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v28);
  }
  vostok::sound::world_user::add_response(proxy->m_user, response);
}
