void __usercall vostok::render::one_way_render_channel::process_next_frame_commands(
        vostok::render::one_way_render_channel *this@<ecx>,
        int a2@<edi>)
{
  unsigned int v2; // eax
  __int32 v3; // esi
  int v4; // eax
  void (__thiscall **v5)(__int32); // edx
  pop_front_predicate predicate; // [esp+Ch] [ebp-14h]
  int new_next_frame_commands_queue; // [esp+10h] [ebp-10h]
  __int32 new_next_frame_commands_queue_8; // [esp+18h] [ebp-8h]
  __int32 new_next_frame_commands_queue_12; // [esp+1Ch] [ebp-4h]

  v2 = *(_DWORD *)(a2 + 176);
  *(_BYTE *)(a2 + 180) = 0;
  new_next_frame_commands_queue = 0;
  new_next_frame_commands_queue_8 = 0;
  new_next_frame_commands_queue_12 = 0;
  predicate.m_current_frame_id = v2;
  while ( *(_DWORD *)(a2 + 160) )
  {
    v3 = *(_DWORD *)(a2 + 160);
    --*(_DWORD *)(a2 + 152);
    v4 = *(_DWORD *)(v3 + 8);
    *(_DWORD *)(a2 + 160) = v4;
    if ( !v4 )
      *(_DWORD *)(a2 + 164) = 0;
    *(_DWORD *)(v3 + 8) = 0;
    v5 = *(void (__thiscall ***)(__int32))v3;
    if ( *(_BYTE *)(v3 + 12) )
    {
      v5[1](v3);
    }
    else
    {
      (*v5)(v3);
      if ( *(_BYTE *)(v3 + 12) || *(_DWORD *)(v3 + 80) > predicate.m_current_frame_id )
      {
        ++new_next_frame_commands_queue;
        *(_DWORD *)(v3 + 8) = 0;
        if ( new_next_frame_commands_queue_8 )
          *(_DWORD *)(new_next_frame_commands_queue_12 + 8) = v3;
        else
          new_next_frame_commands_queue_8 = v3;
        new_next_frame_commands_queue_12 = v3;
      }
      else if ( v3 != *(_DWORD *)(a2 + 64) )
      {
        *(_DWORD *)(v3 + 4) = 0;
        _InterlockedExchange((volatile __int32 *)(*(_DWORD *)(a2 + 68) + 4), v3);
        *(_DWORD *)(a2 + 68) = v3;
      }
    }
  }
  *(_DWORD *)(a2 + 160) = new_next_frame_commands_queue_8;
  *(_DWORD *)(a2 + 164) = new_next_frame_commands_queue_12;
  *(_DWORD *)(a2 + 152) = new_next_frame_commands_queue;
}
