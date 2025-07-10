void __userpurge survarium::booby_trap_set::booby_trap_set(
        survarium::booby_trap_set *this@<ecx>,
        int a2@<esi>,
        survarium::game_world *game_world)
{
  __int64 v3; // xmm0_8
  boost::detail::function::vtable_base *vtable; // eax
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::booby_trap_set>,boost::_bi::list1<boost::_bi::value<survarium::booby_trap_set *> > > v6; // [esp-10h] [ebp-38h]
  int v7; // [esp+0h] [ebp-28h]
  boost::function0<void> f; // [esp+8h] [ebp-20h] BYREF

  survarium::booby_trap_set_core::booby_trap_set_core((survarium::booby_trap_set_core *)a2);
  f.vtable = (boost::detail::function::vtable_base *)survarium::booby_trap_set::on_player_death;
  (&f.vtable)[1] = 0;
  v6.f_.f_ = (void (__thiscall *__ptr64)(survarium::booby_trap_set *))(unsigned int)survarium::booby_trap_set::on_player_death;
  f.functor.obj_ptr = (void *)a2;
  v3 = *(_QWORD *)&f.functor.obj_ptr;
  *(_DWORD *)a2 = &survarium::booby_trap_set::`vftable';
  *(_QWORD *)&v6.l_.a1_.t_ = v3;
  boost::function0<void>::function0<void>(0, (int)&f, a2, v6, v7);
  *(_DWORD *)(a2 + 328) = 0;
  boost::function0<void>::assign_to_own((boost::function0<void> *)(a2 + 328), &f);
  vtable = f.vtable;
  *(_DWORD *)(a2 + 360) = 0;
  if ( vtable )
  {
    if ( ((unsigned __int8)vtable & 1) == 0 )
    {
      v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((unsigned int)vtable & 0xFFFFFFFE);
      if ( v5 )
        v5(&f.functor, &f.functor, 2);
    }
  }
  *(_DWORD *)(a2 + 372) = 0;
  *(_DWORD *)(a2 + 376) = 0;
  *(_DWORD *)(a2 + 380) = 0;
  *(_DWORD *)(a2 + 384) = game_world;
}
