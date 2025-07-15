void __usercall survarium::lobby_menu::request_friends_status_from_server(
        survarium::lobby_menu *this@<ecx>,
        int a2@<eax>)
{
  unsigned int v3; // ebx
  survarium::scheduler::record *v4; // eax
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::lobby_menu,unsigned int,unsigned int>,boost::_bi::list3<boost::_bi::value<survarium::lobby_menu *>,boost::arg<1>,boost::arg<2> > > v6; // [esp-10h] [ebp-44h]
  int v7; // [esp+0h] [ebp-34h]
  boost::function<void __cdecl(unsigned int,unsigned int)> active; // [esp+10h] [ebp-24h] BYREF

  if ( !*(_BYTE *)(a2 + 268) )
  {
    v3 = *(_DWORD *)(*(_DWORD *)(a2 + 168) + 1012);
    active.vtable = (boost::detail::function::vtable_base *)survarium::lobby_menu::request_friends_status_from_server_impl;
    (&active.vtable)[1] = 0;
    v6.f_.f_ = (void (__thiscall *__ptr64)(survarium::lobby_menu *, unsigned int, unsigned int))(unsigned int)survarium::lobby_menu::request_friends_status_from_server_impl;
    active.functor.obj_ptr = (void *)a2;
    *(_QWORD *)&v6.l_.a1_.t_ = *(_QWORD *)&active.functor.obj_ptr;
    boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
      0,
      (int)&active,
      a2,
      v6,
      v7);
    v4 = survarium::scheduler::register_object(
           (survarium::scheduler *)&active,
           (survarium::scheduler *)(*(_DWORD *)(a2 + 168) + 896),
           (survarium::scheduler::identifier *)(a2 + 204),
           &active,
           1);
    *(_DWORD *)&v4->survarium::scheduler::scheduler_record = -2147473648;
    v4->m_max_update_count = 1;
    v4->m_last_update_time = v3;
    if ( active.vtable )
    {
      if ( ((int)active.vtable & 1) == 0 )
      {
        v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)active.vtable & 0xFFFFFFFE);
        if ( v5 )
          v5(&active.functor, &active.functor, 2);
      }
    }
  }
}
