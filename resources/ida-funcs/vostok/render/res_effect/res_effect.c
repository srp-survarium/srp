void __usercall vostok::render::res_effect::res_effect(vostok::render::res_effect *this@<ecx>, int a2@<esi>)
{
  vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)a2, 1u);
  *(_DWORD *)a2 = &vostok::render::res_effect::`vftable';
  *(_DWORD *)(a2 + 264) = 0;
  *(_DWORD *)(a2 + 268) = 0;
  *(_DWORD *)(a2 + 272) = 0;
  *(_DWORD *)(a2 + 280) = 0;
  *(_DWORD *)(a2 + 284) = 0;
  *(_DWORD *)(a2 + 288) = 0;
  *(_BYTE *)(a2 + 292) = 0;
}
