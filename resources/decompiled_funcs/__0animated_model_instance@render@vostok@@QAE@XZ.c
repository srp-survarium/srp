void __usercall vostok::render::animated_model_instance::animated_model_instance(
        vostok::render::animated_model_instance *this@<ecx>,
        int a2@<esi>)
{
  vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)a2, 1u);
  *(_DWORD *)a2 = &vostok::render::animated_model_instance::`vftable';
  *(_DWORD *)(a2 + 264) = 0;
  *(_DWORD *)(a2 + 268) = 0;
  *(_DWORD *)(a2 + 272) = a2 + 284;
  *(_DWORD *)(a2 + 276) = a2 + 284;
  *(_BYTE *)(a2 + 284) = 0;
  *(_DWORD *)(a2 + 280) = a2 + 316;
}
