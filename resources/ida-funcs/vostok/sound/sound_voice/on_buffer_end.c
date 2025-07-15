void __thiscall vostok::sound::sound_voice::on_buffer_end(
        vostok::sound::sound_voice *this,
        void *buffer_context,
        int a3)
{
  char *v3; // eax
  vostok::memory::pthreads3_allocator *v4; // ecx
  boost::function<void __cdecl(void)> *v5; // ecx
  vostok::sound::sound_order *v6; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_voice,void *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_voice *>,boost::_bi::value<void *> > > v8; // [esp-10h] [ebp-58h]
  const char *v9; // [esp+0h] [ebp-48h]
  unsigned int v10; // [esp+4h] [ebp-44h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+10h] [ebp-38h] BYREF
  void (__thiscall *v12)(vostok::sound::sound_voice *, void *); // [esp+34h] [ebp-14h]
  void *v13; // [esp+38h] [ebp-10h]
  int v14; // [esp+3Ch] [ebp-Ch]
  vostok::sound::functor_command<vostok::sound::sound_order> *v15; // [esp+40h] [ebp-8h]
  int v16; // [esp+44h] [ebp-4h]

  v16 = 0;
  v3 = type_info::raw_name(&vostok::sound::functor_command<vostok::sound::sound_order> `RTTI Type Descriptor');
  v15 = (vostok::sound::functor_command<vostok::sound::sound_order> *)vostok::memory::pthreads3_allocator::malloc_impl(
                                                                        v4,
                                                                        (unsigned int)&vostok::memory::g_mt_allocator,
                                                                        (const char *const)0x30,
                                                                        v3,
                                                                        v9,
                                                                        v10);
  if ( v15 )
  {
    v13 = buffer_context;
    v14 = a3;
    v12 = vostok::sound::sound_voice::on_buffer_end_impl;
    v8.l_.a1_.t_ = (vostok::sound::sound_voice *)vostok::sound::sound_voice::on_buffer_end_impl;
    v8.l_.a2_.t_ = buffer_context;
    v8.f_.f_ = (void (__thiscall *)(vostok::sound::sound_voice *, void *))&f;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v5, v8, a3);
    v16 = 1;
    vostok::sound::functor_command<vostok::sound::sound_order>::functor_command<vostok::sound::sound_order>(
      v15,
      &vostok::memory::g_mt_allocator,
      &f);
  }
  else
  {
    v6 = 0;
  }
  vostok::sound::sound_world::add_xaudio_order(
    *(vostok::sound::sound_world **)(*((_DWORD *)buffer_context + 3) + 280),
    v6);
  if ( (v16 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v7,
      (int *)&f);
}
