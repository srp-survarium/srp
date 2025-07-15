btCompoundShape *__usercall btCompoundShape::btCompoundShape@<eax>(btCompoundShape *this@<ecx>, int a2@<esi>)
{
  const vostok::math::float4x4 *v2; // xmm1_4
  _BYTE *v3; // eax

  *(_DWORD *)a2 = &btCompoundShape::`vftable';
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  ++gNumAlignedAllocs;
  *(_BYTE *)(a2 + 28) = 1;
  *(_DWORD *)(a2 + 32) = 1566444395;
  *(_DWORD *)(a2 + 36) = 1566444395;
  *(_DWORD *)(a2 + 40) = 1566444395;
  *(_DWORD *)(a2 + 44) = 0;
  *(_DWORD *)(a2 + 48) = -581039253;
  *(_DWORD *)(a2 + 52) = -581039253;
  *(_DWORD *)(a2 + 56) = -581039253;
  v2 = clear_value;
  *(_DWORD *)(a2 + 60) = 0;
  *(_DWORD *)(a2 + 64) = 0;
  *(_DWORD *)(a2 + 68) = 1;
  *(_DWORD *)(a2 + 72) = 0;
  *(_DWORD *)(a2 + 80) = v2;
  *(_DWORD *)(a2 + 84) = v2;
  *(_DWORD *)(a2 + 88) = v2;
  *(_DWORD *)(a2 + 92) = 0;
  *(_DWORD *)(a2 + 4) = 31;
  v3 = sAlignedAllocFunc(0x28u, 16);
  if ( v3 )
  {
    v3[36] = 1;
    *((_DWORD *)v3 + 8) = 0;
    *((_DWORD *)v3 + 6) = 0;
    *((_DWORD *)v3 + 7) = 0;
    *(_DWORD *)v3 = 0;
    *((_DWORD *)v3 + 1) = 0;
    *((_DWORD *)v3 + 3) = 0;
    *((_DWORD *)v3 + 4) = 0;
    *((_DWORD *)v3 + 2) = -1;
    *(_DWORD *)(a2 + 64) = v3;
  }
  else
  {
    *(_DWORD *)(a2 + 64) = 0;
  }
  return (btCompoundShape *)a2;
}
