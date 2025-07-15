void __userpurge vostok::render::culling::portal_sector_structure::update_portals_visability(
        vostok::render::culling::portal_sector_structure *this@<ecx>,
        _DWORD *a2@<esi>,
        const vostok::math::frustum *f,
        const unsigned __int8 *oclusion_results)
{
  int v4; // ecx
  int i; // eax
  int v6; // ecx
  _BYTE *v7; // ecx
  _BYTE *j; // edi
  int v9; // eax
  _BYTE *v10; // [esp+0h] [ebp-200Ch] BYREF
  _BYTE *v11; // [esp+4h] [ebp-2008h]
  char *v12; // [esp+8h] [ebp-2004h]
  _BYTE v13[8192]; // [esp+Ch] [ebp-2000h] BYREF
  char vars0; // [esp+200Ch] [ebp+0h] BYREF

  v4 = a2[69];
  for ( i = a2[68]; i != v4; i += 76 )
    *(_BYTE *)(i + 72) = 0;
  v6 = a2[78];
  v10 = v13;
  v11 = v13;
  v12 = &vars0;
  if ( (*(unsigned __int8 (__thiscall **)(int, _DWORD, const vostok::math::frustum *, _BYTE **))(*(_DWORD *)v6 + 64))(
         v6,
         0,
         f,
         &v10) )
  {
    v7 = v10;
    for ( j = v11; v7 != j; *(_BYTE *)(76 * v9 + a2[68] + 72) = oclusion_results[v9] != 0 )
    {
      v9 = *((_DWORD *)v7 + 1) >> 1;
      v7 += 8;
    }
  }
}
