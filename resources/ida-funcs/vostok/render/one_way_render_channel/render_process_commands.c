char __userpurge vostok::render::one_way_render_channel::render_process_commands@<al>(
        vostok::render::one_way_render_channel *this@<ecx>,
        int a2@<eax>,
        bool wait_for_command_if_queue_is_empty)
{
  unsigned int i; // esi
  int v5; // ecx
  unsigned int v6; // ebx
  __int32 v7; // eax
  int v8; // esi
  void (__thiscall **v9)(int); // eax
  unsigned int v10; // ebp

  if ( *(_BYTE *)(a2 + 180) )
    vostok::render::one_way_render_channel::process_next_frame_commands(this, a2);
  if ( !*(_DWORD *)(*(_DWORD *)(a2 + 64) + 4) && wait_for_command_if_queue_is_empty )
  {
    for ( i = 0; ; ++i )
    {
      v5 = *(_DWORD *)(a2 + 64);
      if ( *(_DWORD *)(v5 + 4) || i >= 0x40 )
        break;
      if ( !SwitchToThread() )
        Sleep(0);
    }
    if ( !*(_DWORD *)(v5 + 4) )
      vostok::threading::event::wait((vostok::threading::event *)v5, a2 + 144);
  }
  v6 = *(_DWORD *)(a2 + 176);
  while ( 1 )
  {
    v7 = *(_DWORD *)(a2 + 64);
    v8 = *(_DWORD *)(v7 + 4);
    if ( !v8 )
      break;
    *(_DWORD *)(a2 + 64) = v8;
    if ( !*(_BYTE *)(v7 + 12) && *(_DWORD *)(v7 + 80) <= v6 )
    {
      *(_DWORD *)(v7 + 4) = 0;
      _InterlockedExchange((volatile __int32 *)(*(_DWORD *)(a2 + 68) + 4), v7);
      *(_DWORD *)(a2 + 68) = v7;
    }
    v9 = *(void (__thiscall ***)(int))v8;
    if ( *(_BYTE *)(v8 + 12) )
    {
      v9[1](v8);
    }
    else
    {
      v10 = *(_DWORD *)(a2 + 176);
      (*v9)(v8);
      if ( *(_BYTE *)(v8 + 12) || *(_DWORD *)(v8 + 80) > v6 )
      {
        *(_DWORD *)(v8 + 8) = 0;
        ++*(_DWORD *)(a2 + 152);
        if ( *(_DWORD *)(a2 + 160) )
          *(_DWORD *)(*(_DWORD *)(a2 + 164) + 8) = v8;
        else
          *(_DWORD *)(a2 + 160) = v8;
        *(_DWORD *)(a2 + 164) = v8;
      }
      if ( v10 < *(_DWORD *)(a2 + 176) )
      {
        *(_BYTE *)(a2 + 180) = *(_DWORD *)(a2 + 160) != 0;
        return 0;
      }
    }
  }
  return 1;
}
