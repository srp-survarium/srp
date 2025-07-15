void __thiscall survarium::lobby_menu::request_status_from_server(
        survarium::lobby_menu *this,
        survarium::lobby_menu *delay_ms,
        unsigned int a3)
{
  survarium::scheduler *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::lobby_menu,unsigned int,unsigned int>,boost::_bi::list3<boost::_bi::value<survarium::lobby_menu *>,boost::arg<1>,boost::arg<2> > > v5; // [esp-14h] [ebp-44h]
  bool v6; // [esp+0h] [ebp-30h]
  unsigned int v7; // [esp+4h] [ebp-2Ch]
  unsigned int v8; // [esp+8h] [ebp-28h]
  boost::function<void __cdecl(unsigned int,unsigned int)> f; // [esp+10h] [ebp-20h] BYREF

  if ( !delay_ms->m_in_destroying )
  {
    if ( a3 )
    {
      if ( *(_DWORD *)&delay_ms->m_update_status_handler < 0 )
        survarium::scheduler::unregister(
          (survarium::scheduler *)this,
          (int)&delay_ms->m_scheduler,
          &delay_ms->m_update_status_handler);
      f.functor.bound_memfunc_ptr.obj_ptr = delay_ms;
      f.functor.vostok_pointer_size_alignment[2] = survarium::lobby_menu::request_status_from_server_impl;
      f.functor.vostok_pointer_size_alignment[3] = 0;
      HIDWORD(v5.f_.f_) = survarium::lobby_menu::request_status_from_server_impl;
      *(_QWORD *)&v5.l_.a1_.t_ = __PAIR64__((unsigned int)delay_ms, 0);
      LODWORD(v5.f_.f_) = &f;
      boost::function<void __cdecl (unsigned int,unsigned int)>::function<void __cdecl (unsigned int,unsigned int)>(
        0,
        v5,
        (int)f.functor.vostok_pointer_size_alignment[5]);
      survarium::scheduler::register_for_update(
        &delay_ms->m_scheduler,
        a3,
        v3,
        &delay_ms->m_update_status_handler,
        &f,
        v6,
        v7,
        v8);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v4,
        (int *)&f);
    }
    else
    {
      survarium::lobby_menu::request_status_from_server_impl(delay_ms, 0, 0);
    }
  }
}
