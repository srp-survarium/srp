void __usercall vostok::render::debug::draw_lines_command::~draw_lines_command(
        vostok::render::debug::draw_lines_command *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax

  v2 = *(_DWORD *)(a2 + 116);
  if ( v2 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v2 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 116) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 116));
  if ( *(_DWORD *)(a2 + 100) )
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 108) + 24))(
      *(_DWORD *)(a2 + 108),
      *(_DWORD *)(a2 + 100));
  if ( *(_DWORD *)(a2 + 84) )
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 92) + 24))(*(_DWORD *)(a2 + 92), *(_DWORD *)(a2 + 84));
}
