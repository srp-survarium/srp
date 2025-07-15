btCompoundShape *__usercall btCompoundShape::btCompoundShape@<eax>(btCompoundShape *this@<ecx>, int a2@<esi>)
{
  float v2; // xmm1_4
  btDbvt *v3; // eax
  btDbvt *v4; // eax

  *(_DWORD *)a2 = &btCompoundShape::`vftable';
  *(_DWORD *)(a2 + 8) = 0;
  *(_BYTE *)(a2 + 28) = 1;
  *(_DWORD *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(float *)(a2 + 32) = FLOAT_9_9999998e17;
  *(float *)(a2 + 36) = FLOAT_9_9999998e17;
  *(float *)(a2 + 40) = FLOAT_9_9999998e17;
  *(_DWORD *)(a2 + 44) = 0;
  *(float *)(a2 + 48) = FLOAT_N9_9999998e17;
  *(float *)(a2 + 52) = FLOAT_N9_9999998e17;
  *(float *)(a2 + 56) = FLOAT_N9_9999998e17;
  v2 = s_bm_current_air_resistance;
  *(_DWORD *)(a2 + 60) = 0;
  *(_DWORD *)(a2 + 64) = 0;
  *(_DWORD *)(a2 + 68) = 1;
  *(_DWORD *)(a2 + 72) = 0;
  *(float *)(a2 + 80) = v2;
  *(float *)(a2 + 84) = v2;
  *(float *)(a2 + 88) = v2;
  *(_DWORD *)(a2 + 92) = 0;
  *(_DWORD *)(a2 + 4) = 31;
  v3 = (btDbvt *)btAlignedAllocInternal(0x28u);
  if ( v3 )
    v4 = btDbvt::btDbvt(v3);
  else
    v4 = 0;
  *(_DWORD *)(a2 + 64) = v4;
  return (btCompoundShape *)a2;
}
