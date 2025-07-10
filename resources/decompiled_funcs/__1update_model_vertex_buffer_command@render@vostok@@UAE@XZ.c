void __usercall vostok::render::update_model_vertex_buffer_command::~update_model_vertex_buffer_command(
        vostok::render::update_model_vertex_buffer_command *this@<ecx>,
        int a2@<edi>)
{
  int v2; // ebx
  int v3; // esi
  int v4; // eax

  v2 = *(_DWORD *)(a2 + 88);
  v3 = *(_DWORD *)(a2 + 84);
  for ( *(_DWORD *)a2 = &vostok::render::update_model_vertex_buffer_command::`vftable'; v3 != v2; v3 += 12 )
    (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(a2 + 108) + 24))(*(_DWORD *)(a2 + 108), *(_DWORD *)(v3 + 8) - 8);
  v4 = *(_DWORD *)(a2 + 100);
  if ( v4 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v4 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 100) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 100));
  if ( *(_DWORD *)(a2 + 84) )
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 92) + 24))(*(_DWORD *)(a2 + 92), *(_DWORD *)(a2 + 84));
}
