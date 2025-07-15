char __userpurge vostok::render::one_way_render_channel::render_process_commands@<al>(
        vostok::render::one_way_render_channel *this@<ecx>,
        int a2@<edi>,
        bool wait_for_command_if_queue_is_empty)
{
  unsigned int v3; // ebx
  int v4; // eax
  __int32 v5; // eax
  int v6; // esi
  void (__thiscall **v7)(int); // eax
  unsigned int v8; // ebx
  unsigned int v10; // [esp+14h] [ebp+8h]

  if ( *(_BYTE *)(a2 + 172) )
    vostok::render::one_way_render_channel::process_next_frame_commands(this, a2);
  v3 = 0;
  if ( !*(_DWORD *)(*(_DWORD *)(a2 + 64) + 8) && wait_for_command_if_queue_is_empty )
  {
    while ( 1 )
    {
      v4 = *(_DWORD *)(a2 + 64);
      if ( *(_DWORD *)(v4 + 8) )
        break;
      if ( v3 >= 0x40 )
      {
        if ( !*(_DWORD *)(v4 + 8) )
          vostok::threading::event::wait((vostok::threading::event *)this, (HANDLE *)(a2 + 136), 0x10u);
        break;
      }
      vostok::threading::yield(0, (vostok::tasks *)this);
      ++v3;
    }
  }
  v10 = *(_DWORD *)(a2 + 168);
  while ( 1 )
  {
    v5 = *(_DWORD *)(a2 + 64);
    v6 = *(_DWORD *)(v5 + 8);
    if ( !v6 )
      break;
    *(_DWORD *)(a2 + 64) = v6;
    if ( !*(_BYTE *)(v5 + 16) && *(_DWORD *)(v5 + 84) <= v10 )
    {
      *(_DWORD *)(v5 + 8) = 0;
      _InterlockedExchange((volatile __int32 *)(*(_DWORD *)(a2 + 68) + 8), v5);
      *(_DWORD *)(a2 + 68) = v5;
    }
    v7 = *(void (__thiscall ***)(int))v6;
    if ( *(_BYTE *)(v6 + 16) )
    {
      v7[1](v6);
    }
    else
    {
      v8 = *(_DWORD *)(a2 + 168);
      (*v7)(v6);
      if ( *(_BYTE *)(v6 + 16) || *(_DWORD *)(v6 + 84) > v10 )
        vostok::intrusive_list<vostok::render::base_command,vostok::render::base_command *,12,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
          (vostok::intrusive_list<vostok::render::base_command,vostok::render::base_command *,12,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)v6,
          (_DWORD *)(a2 + 144));
      if ( v8 < *(_DWORD *)(a2 + 168) )
      {
        *(_BYTE *)(a2 + 172) = *(_DWORD *)(a2 + 152) != 0;
        return 0;
      }
    }
  }
  return 1;
}
