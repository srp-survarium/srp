void __usercall survarium::artefact_container_core::~artefact_container_core(
        survarium::artefact_container_core *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax

  v2 = *(_DWORD *)(a2 + 32);
  if ( v2 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v2 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 32) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 32));
  survarium::usable_object::~usable_object((survarium::usable_object *)a2);
}
