void __thiscall survarium::booby_trap_core::set_transform(
        survarium::booby_trap_core *this,
        const vostok::math::float4x4 *transform,
        const void *a3)
{
  bool v3; // zf
  int v4; // esi
  int v5; // eax

  v3 = LODWORD(transform[6].j.z) == 1;
  qmemcpy(&transform[6].lines[2], a3, sizeof(const vostok::math::float4x4));
  if ( v3 )
  {
    (*(void (__thiscall **)(_DWORD, const void *))(**(_DWORD **)LODWORD(transform->k.y) + 20))(
      *(_DWORD *)LODWORD(transform->k.y),
      a3);
    (*(void (__thiscall **)(_DWORD, const void *))(**(_DWORD **)LODWORD(transform[1].k.w) + 20))(
      *(_DWORD *)LODWORD(transform[1].k.w),
      a3);
    if ( *(_BYTE *)(LODWORD(transform[7].k.y) + 336) )
    {
      (*(void (__thiscall **)(_DWORD, const void *))(*(_DWORD *)LODWORD(transform->i.y) + 24))(
        LODWORD(transform->i.y),
        a3);
      v4 = *(_DWORD *)LODWORD(transform->i.z);
      v5 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(transform->i.y) + 4))(LODWORD(transform->i.y));
      (*(void (__thiscall **)(_DWORD, int))(v4 + 32))(LODWORD(transform->i.z), v5);
    }
  }
}
