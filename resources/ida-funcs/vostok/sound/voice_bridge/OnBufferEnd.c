void __stdcall vostok::sound::voice_bridge::OnBufferEnd(vostok::sound::voice_bridge *this, int pBufferContext)
{
  char *v2; // eax
  vostok::memory::pthreads3_allocator *v3; // ecx
  vostok::sound::sound_order *v4; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  vostok::sound::sound_voice *m_handler; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::sound::sound_buffer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::sound::sound_buffer *> > > v7; // [esp-14h] [ebp-5Ch]
  const char *v8; // [esp+0h] [ebp-48h]
  unsigned int v9; // [esp+4h] [ebp-44h]
  char v10; // [esp+10h] [ebp-38h]
  vostok::sound::functor_command<vostok::sound::sound_order> *v11; // [esp+14h] [ebp-34h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+28h] [ebp-20h] BYREF

  v10 = 0;
  v2 = type_info::raw_name(&vostok::sound::functor_command<vostok::sound::sound_order> `RTTI Type Descriptor');
  v11 = (vostok::sound::functor_command<vostok::sound::sound_order> *)vostok::memory::pthreads3_allocator::malloc_impl(
                                                                        v3,
                                                                        (unsigned int)&vostok::memory::g_mt_allocator,
                                                                        (const char *const)0x30,
                                                                        v2,
                                                                        v8,
                                                                        v9);
  if ( v11 )
  {
    HIDWORD(v7.f_.f_) = vostok::sound::sound_world::free_sound_buffer;
    v7.l_ = (boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::sound::sound_buffer *> >)__PAIR64__(this->m_params.world, 0);
    LODWORD(v7.f_.f_) = &f;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)vostok::sound::sound_world::free_sound_buffer,
      v7,
      pBufferContext);
    v10 = 1;
    vostok::sound::functor_command<vostok::sound::sound_order>::functor_command<vostok::sound::sound_order>(
      v11,
      &vostok::memory::g_mt_allocator,
      &f);
  }
  else
  {
    v4 = 0;
  }
  vostok::sound::sound_world::add_xaudio_order(this->m_params.world, v4);
  if ( (v10 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v5,
      (int *)&f);
  m_handler = this->m_handler_;
  if ( m_handler )
    vostok::sound::sound_voice::on_buffer_end((vostok::sound::sound_voice *)v5, m_handler, pBufferContext);
}
