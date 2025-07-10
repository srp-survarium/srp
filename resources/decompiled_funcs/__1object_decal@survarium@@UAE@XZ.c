void __usercall survarium::object_decal::~object_decal(survarium::object_decal *this@<ecx>, int a2@<esi>)
{
  int v2; // eax

  *(_DWORD *)a2 = &survarium::object_decal::`vftable';
  v2 = *(_DWORD *)(a2 + 372);
  if ( v2 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v2 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 372) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 372));
  vostok::resources::unmanaged_resource::~unmanaged_resource((vostok::resources::unmanaged_resource *)a2);
}
