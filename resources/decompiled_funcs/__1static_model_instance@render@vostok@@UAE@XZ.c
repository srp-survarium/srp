void __usercall vostok::render::static_model_instance::~static_model_instance(
        survarium::rifle_scope *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax
  int v3; // eax

  v2 = *(_DWORD *)(a2 + 268);
  if ( v2 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v2 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 268) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 268));
  v3 = *(_DWORD *)(a2 + 264);
  if ( v3 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v3 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 264) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 264));
  vostok::resources::unmanaged_resource::~unmanaged_resource((vostok::resources::unmanaged_resource *)a2);
}
