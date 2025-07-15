void __usercall vostok::engine::engine_world::run(vostok::engine::engine_world *this@<ecx>, int a2@<esi>)
{
  MSG Msg; // [esp+4h] [ebp-1Ch] BYREF

  if ( !*(_BYTE *)(a2 + 752) )
  {
    if ( *(_DWORD *)(a2 + 676) && vostok::threading::core_count(this) == 1 )
    {
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 676) + 4))(*(_DWORD *)(a2 + 676));
      if ( !*(_DWORD *)(a2 + 732) )
        (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)a2 + 64))(a2, 0);
    }
    else
    {
      while ( 1 )
      {
        if ( !*(_DWORD *)(a2 + 676) )
        {
          while ( PeekMessageA(&Msg, 0, 0, 0, 1u) )
          {
            TranslateMessage(&Msg);
            DispatchMessageA(&Msg);
            if ( Msg.message == 18 )
              return;
          }
        }
        if ( *(_DWORD *)(a2 + 732) )
          break;
        (*(void (__thiscall **)(int))(*(_DWORD *)a2 + 100))(a2);
      }
    }
  }
}
