void __usercall vostok::render::res_effect::res_effect(vostok::render::res_effect *this@<ecx>, int a2@<esi>)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(this, (_DWORD *)a2, fs_iterator_class);
  *(_DWORD *)a2 = &vostok::render::res_effect::`vftable';
  *(_DWORD *)(a2 + 264) = a2 + 276;
  *(_DWORD *)(a2 + 268) = a2 + 276;
  *(_DWORD *)(a2 + 272) = a2 + 17940;
  *(_DWORD *)(a2 + 17940) = a2 + 17952;
  *(_DWORD *)(a2 + 17944) = a2 + 17952;
  *(_DWORD *)(a2 + 17948) = a2 + 22048;
  *(_DWORD *)(a2 + 22052) = a2 + 22064;
  *(_DWORD *)(a2 + 22056) = a2 + 22064;
  *(_DWORD *)(a2 + 22060) = a2 + 22192;
  *(_BYTE *)(a2 + 22192) = 0;
}
