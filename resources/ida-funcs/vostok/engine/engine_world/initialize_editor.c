void __usercall vostok::engine::engine_world::initialize_editor(
        vostok::engine::engine_world *this@<ecx>,
        _BYTE *a2@<eax>)
{
  char v3; // al
  const char *v4; // ebx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > v6; // [esp-14h] [ebp-5Ch]
  boost::function<void __cdecl(void)> f; // [esp+10h] [ebp-38h] BYREF
  void (__thiscall *v8)(vostok::engine::engine_world *); // [esp+30h] [ebp-18h]
  int v9; // [esp+34h] [ebp-14h]
  _BYTE *v10; // [esp+38h] [ebp-10h]
  int v11; // [esp+3Ch] [ebp-Ch]
  char *thread_name_for_logging; // [esp+44h] [ebp-4h]

  a2[754] = 0;
  if ( vostok::threading::core_count(this) != 1 )
  {
    g_threads.m_begin[2].m_thread_id = -1;
    v3 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)a2 + 104))(a2);
    v4 = "editor";
    thread_name_for_logging = "editor";
    if ( v3 )
      thread_name_for_logging = "editor + logic";
    if ( (*(unsigned __int8 (__thiscall **)(_BYTE *))(*(_DWORD *)a2 + 104))(a2) )
      v4 = "editor + logic";
    v10 = a2;
    v8 = vostok::engine::engine_world::editor;
    v9 = 0;
    HIDWORD(v6.f_.f_) = vostok::engine::engine_world::editor;
    v6.l_.a1_.t_ = 0;
    *((_DWORD *)&v6.l_ + 1) = a2;
    LODWORD(v6.f_.f_) = &f;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(0, v6, v11);
    vostok::threading::spawn(&f, thread_name_for_logging, v4, 0, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v5,
      (int *)&f);
  }
}
