void __usercall vostok::render::one_way_render_channel::process_next_frame_commands(
        vostok::render::one_way_render_channel *this@<ecx>,
        int a2@<esi>)
{
  unsigned int v2; // eax
  vostok::render::base_command_vtbl *v3; // eax
  vostok::render::base_command *v4; // eax
  __int32 v5; // edi
  int v6; // [esp+Ch] [ebp-14h] BYREF
  int v7; // [esp+14h] [ebp-Ch]
  int v8; // [esp+18h] [ebp-8h]
  unsigned int v9; // [esp+1Ch] [ebp-4h]

  v6 = 0;
  v7 = 0;
  v8 = 0;
  v2 = *(_DWORD *)(a2 + 168);
  *(_BYTE *)(a2 + 172) = 0;
  v9 = v2;
  while ( 1 )
  {
    v4 = vostok::intrusive_list<vostok::render::base_command,vostok::render::base_command *,12,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front((vostok::intrusive_list<vostok::render::base_command,vostok::render::base_command *,12,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)(a2 + 144));
    v5 = (__int32)v4;
    if ( !v4 )
      break;
    v3 = v4->__vftable;
    if ( *(_BYTE *)(v5 + 16) )
    {
      v3->defer_execution((vostok::render::base_command *)v5);
    }
    else
    {
      v3->execute((vostok::render::base_command *)v5);
      if ( *(_BYTE *)(v5 + 16) || *(_DWORD *)(v5 + 84) > v9 )
      {
        vostok::intrusive_list<vostok::render::base_command,vostok::render::base_command *,12,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
          (vostok::intrusive_list<vostok::render::base_command,vostok::render::base_command *,12,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)v5,
          &v6);
      }
      else if ( v5 != *(_DWORD *)(a2 + 64) )
      {
        *(_DWORD *)(v5 + 8) = 0;
        _InterlockedExchange((volatile __int32 *)(*(_DWORD *)(a2 + 68) + 8), v5);
        *(_DWORD *)(a2 + 68) = v5;
      }
    }
  }
  *(_DWORD *)(a2 + 152) = v7;
  *(_DWORD *)(a2 + 156) = v8;
  *(_DWORD *)(a2 + 144) = v6;
}
