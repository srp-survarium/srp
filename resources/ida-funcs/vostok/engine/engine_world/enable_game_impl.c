void __userpurge vostok::engine::engine_world::enable_game_impl(
        vostok::engine::engine_world *this@<ecx>,
        unsigned int a2@<eax>,
        int value)
{
  void (__cdecl *v4)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  int v5; // esi
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::engine_user::world,bool>,boost::_bi::list2<boost::_bi::value<vostok::engine_user::world *>,boost::_bi::value<bool> > > v6; // [esp-Ch] [ebp-4Ch]
  int v7; // [esp+0h] [ebp-40h]
  boost::function<void __cdecl(void)> *v8; // [esp+10h] [ebp-30h]
  __int64 v9; // [esp+14h] [ebp-2Ch]
  boost::function<void __cdecl(void)> callback; // [esp+20h] [ebp-20h] BYREF

  if ( *(_DWORD *)(a2 + 656) )
  {
    if ( (*(unsigned __int8 (__thiscall **)(unsigned int))(*(_DWORD *)a2 + 100))(a2) )
    {
      (***(void (__thiscall ****)(_DWORD, int))(a2 + 656))(*(_DWORD *)(a2 + 656), value);
    }
    else
    {
      HIDWORD(v9) = *(_DWORD *)(a2 + 656);
      LOBYTE(v8) = value;
      LODWORD(v9) =  __thiscall vostok::network::world::`vcall'{0,{flat}};
      *(_QWORD *)&v6.f_.f_ = v9;
      *(_DWORD *)&v6.l_.a2_.t_ = v8;
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v8, (int)&callback, a2, v6, v7);
      vostok::apc::run(logic, &callback, continue_process_loop, wait_for_completion);
      if ( callback.vtable )
      {
        if ( ((int)callback.vtable & 1) == 0 )
        {
          v4 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
          if ( v4 )
            v4(&callback.functor, &callback.functor, 2);
        }
      }
    }
  }
  *(_BYTE *)(a2 + 710) = value;
  v5 = *(_DWORD *)(a2 + 632);
  _InterlockedExchange((volatile __int32 *)(v5 + 384), (_BYTE)value != 0);
  if ( !(_BYTE)value )
    _InterlockedExchange((volatile __int32 *)(v5 + 388), 1);
}
