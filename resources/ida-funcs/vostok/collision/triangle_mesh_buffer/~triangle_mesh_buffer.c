void __usercall vostok::collision::triangle_mesh_buffer::~triangle_mesh_buffer(
        vostok::collision::triangle_mesh_buffer *this@<ecx>,
        int a2@<esi>)
{
  if ( *(_DWORD *)(a2 + 336) )
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 344) + 24))(
      *(_DWORD *)(a2 + 344),
      *(_DWORD *)(a2 + 336));
  if ( *(_DWORD *)(a2 + 320) )
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 328) + 24))(
      *(_DWORD *)(a2 + 328),
      *(_DWORD *)(a2 + 320));
  *(_DWORD *)a2 = &stru_955E40.m_children_resources.m_thread_id;
  if ( *(_DWORD *)(a2 + 264) )
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 272) + 24))(
      *(_DWORD *)(a2 + 272),
      *(_DWORD *)(a2 + 264));
  *(_DWORD *)a2 = &vostok::collision::geometry::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource((vostok::resources::unmanaged_resource *)a2);
}
