void __thiscall survarium::game::load_config_query(survarium::game *this, char *cfg_name, bool create_renderer)
{
  void (__cdecl *v3)(_QWORD *, _QWORD *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::game,vostok::resources::queries_result &,bool>,boost::_bi::list3<boost::_bi::value<survarium::game *>,boost::arg<1>,boost::_bi::value<bool> > > v4; // [esp-10h] [ebp-48h]
  int v5; // [esp+0h] [ebp-38h]
  assert_on_fail_bool v6; // [esp+0h] [ebp-38h]
  vostok::memory::base_allocator allocator; // [esp+Ch] [ebp-2Ch] BYREF
  _QWORD v8[3]; // [esp+20h] [ebp-18h] BYREF

  allocator.m_arena_id = (const char *)survarium::game::on_config_loaded;
  LOBYTE(allocator.m_arena_end) = create_renderer;
  *(_DWORD *)&allocator.m_use_memory_monitor = 0;
  v4.f_.f_ = (void (__thiscall *__ptr64)(survarium::game *, vostok::resources::queries_result *, bool))(unsigned int)survarium::game::on_config_loaded;
  v8[0] = __PAIR64__((unsigned int)allocator.m_arena_end, (unsigned int)this);
  v4.l_ = (boost::_bi::list3<boost::_bi::value<survarium::game *>,boost::arg<1>,boost::_bi::value<bool> >)__PAIR64__((unsigned int)allocator.m_arena_end, (unsigned int)this);
  boost::function1<void,vostok::resources::queries_result &>::function1<void,vostok::resources::queries_result &>(
    (boost::function1<void,vostok::resources::queries_result &> *)this,
    (int)&allocator.m_arena_id,
    0,
    v4,
    v5);
  allocator.m_arena_start = cfg_name;
  allocator.m_arena_end = (void *)3;
  allocator.__vftable = 0;
  vostok::resources::query_resources_and_wait(
    (const vostok::resources::request *)&allocator.m_arena_start,
    (unsigned int)survarium::g_allocator.f_.f_,
    (const boost::function<void __cdecl(vostok::resources::queries_result &)> *)&allocator.m_arena_id,
    &allocator,
    0,
    0,
    v6);
  if ( allocator.m_arena_id && ((int)allocator.m_arena_id & 1) == 0 )
  {
    v3 = *(void (__cdecl **)(_QWORD *, _QWORD *, int))((int)allocator.m_arena_id & 0xFFFFFFFE);
    if ( v3 )
      v3(v8, v8, 2);
  }
}
