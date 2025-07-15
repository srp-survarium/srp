void __thiscall vostok::sound::sound_instance_proxy_internal::resume(
        vostok::sound::sound_instance_proxy_internal *this)
{
  vostok::sound::sound_instance_proxy_order *v2; // esi
  __int32 v3; // eax
  vostok::sound::world_user *m_user; // ebx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_scene,vostok::sound::sound_instance_proxy_internal &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_scene *>,boost::reference_wrapper<vostok::sound::sound_instance_proxy_internal> > > v6; // [esp-14h] [ebp-44h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+10h] [ebp-20h] BYREF

  f.functor.obj_ptr = this->m_scene;
  f.functor.vostok_pointer_size_alignment[1] = this;
  f.vtable = (boost::detail::function::vtable_base *)survarium::empty_hands::tick;
  (&f.vtable)[1] = 0;
  HIDWORD(v6.f_.f_) = survarium::empty_hands::tick;
  v6.l_ = (boost::_bi::list2<boost::_bi::value<vostok::sound::sound_scene *>,boost::reference_wrapper<vostok::sound::sound_instance_proxy_internal> >)__PAIR64__((unsigned int)f.functor.obj_ptr, 0);
  LODWORD(v6.f_.f_) = &f;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function<void __cdecl(void)> *)survarium::empty_hands::tick,
    v6,
    (int)this);
  v2 = (vostok::sound::sound_instance_proxy_order *)vostok::memory::new_helper<vostok::sound::sound_instance_proxy_order>::call<vostok::memory::base_allocator>(
                                                      this->m_user->m_orders_allocator,
                                                      "vostok::sound::sound_instance_proxy_internal::resume",
                                                      (const char *const)0x8C);
  if ( v2 )
    vostok::sound::sound_instance_proxy_order::sound_instance_proxy_order(v2, this->m_user, this, &f);
  else
    v3 = 0;
  m_user = this->m_user;
  *(_DWORD *)(v3 + 8) = 0;
  m_user = (vostok::sound::world_user *)((char *)m_user + 136);
  v5 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)_InterlockedExchange(
                                                                                         (volatile __int32 *)&m_user->m_channel.responses.m_forward_queue.m_head->m_next,
                                                                                         v3);
  m_user->m_channel.responses.m_forward_queue.m_head = (vostok::sound::sound_response *)v3;
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v5, (int *)&f);
}
