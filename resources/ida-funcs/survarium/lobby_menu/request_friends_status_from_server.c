void __thiscall survarium::lobby_menu::request_friends_status_from_server(
        survarium::lobby_menu *this,
        unsigned int delay_ms)
{
  survarium::scheduler *v2; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::lobby_menu,unsigned int,unsigned int>,boost::_bi::list3<boost::_bi::value<survarium::lobby_menu *>,boost::arg<1>,boost::arg<2> > > v4; // [esp-14h] [ebp-48h]
  bool v5; // [esp+0h] [ebp-34h]
  unsigned int v6; // [esp+4h] [ebp-30h]
  unsigned int v7; // [esp+8h] [ebp-2Ch]
  boost::function<void __cdecl(unsigned int,unsigned int)> f; // [esp+10h] [ebp-24h] BYREF

  if ( !*(_BYTE *)(delay_ms + 1656) )
  {
    if ( *(int *)(delay_ms + 1588) < 0 )
      survarium::scheduler::unregister(
        (survarium::scheduler *)this,
        delay_ms + 168,
        (survarium::scheduler::identifier *)(delay_ms + 1588));
    f.functor.bound_memfunc_ptr.obj_ptr = (void *)delay_ms;
    f.functor.vostok_pointer_size_alignment[2] = survarium::lobby_menu::request_friends_status_from_server_impl;
    f.functor.vostok_pointer_size_alignment[3] = 0;
    HIDWORD(v4.f_.f_) = survarium::lobby_menu::request_friends_status_from_server_impl;
    *(_QWORD *)&v4.l_.a1_.t_ = __PAIR64__(delay_ms, 0);
    LODWORD(v4.f_.f_) = &f;
    boost::function<void __cdecl (unsigned int,unsigned int)>::function<void __cdecl (unsigned int,unsigned int)>(
      0,
      v4,
      (int)f.functor.vostok_pointer_size_alignment[5]);
    survarium::scheduler::register_for_update(
      (survarium::scheduler *)(delay_ms + 168),
      0x2710u,
      v2,
      (survarium::scheduler::identifier *)(delay_ms + 1588),
      &f,
      v5,
      v6,
      v7);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v3,
      (int *)&f);
  }
}
