void __userpurge survarium::lobby_menu::request_status_from_server(
        survarium::lobby_menu *this@<ecx>,
        int a2@<eax>,
        unsigned int delay_ms)
{
  unsigned int v4; // ebp
  survarium::scheduler::record *v5; // eax
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::lobby_menu,unsigned int,unsigned int>,boost::_bi::list3<boost::_bi::value<survarium::lobby_menu *>,boost::arg<1>,boost::arg<2> > > v7; // [esp-10h] [ebp-40h]
  int v8; // [esp+0h] [ebp-30h]
  boost::function<void __cdecl(unsigned int,unsigned int)> active; // [esp+10h] [ebp-20h] BYREF

  if ( !*(_BYTE *)(a2 + 268) )
  {
    v4 = *(_DWORD *)(*(_DWORD *)(a2 + 168) + 1012);
    active.vtable = (boost::detail::function::vtable_base *)survarium::lobby_menu::request_status_from_server_impl;
    (&active.vtable)[1] = 0;
    v7.f_.f_ = (void (__thiscall *__ptr64)(survarium::lobby_menu *, unsigned int, unsigned int))(unsigned int)survarium::lobby_menu::request_status_from_server_impl;
    active.functor.obj_ptr = (void *)a2;
    *(_QWORD *)&v7.l_.a1_.t_ = *(_QWORD *)&active.functor.obj_ptr;
    boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
      0,
      (int)&active,
      a2,
      v7,
      v8);
    v5 = survarium::scheduler::register_object(
           (survarium::scheduler *)&active,
           (survarium::scheduler *)(*(_DWORD *)(a2 + 168) + 896),
           (survarium::scheduler::identifier *)(a2 + 200),
           &active,
           1);
    *(_DWORD *)&v5->survarium::scheduler::scheduler_record = delay_ms | 0x80000000;
    v5->m_max_update_count = 1;
    v5->m_last_update_time = v4;
    if ( active.vtable )
    {
      if ( ((int)active.vtable & 1) == 0 )
      {
        v6 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)active.vtable & 0xFFFFFFFE);
        if ( v6 )
          v6(&active.functor, &active.functor, 2);
      }
    }
  }
}
