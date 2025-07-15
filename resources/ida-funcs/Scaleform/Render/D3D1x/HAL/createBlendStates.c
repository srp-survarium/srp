char __thiscall Scaleform::Render::D3D1x::HAL::createBlendStates(Scaleform::Render::D3D1x::HAL *this, int a2)
{
  unsigned int v2; // edi
  char v3; // bl
  unsigned int v4; // eax
  unsigned int v5; // edx
  int v6; // ecx
  int v7; // esi
  int v8; // eax
  int i; // [esp+Ch] [ebp-10Ch]
  unsigned __int8 dst[264]; // [esp+10h] [ebp-108h] BYREF

  v2 = 0;
  memset(a2 + 64380, 0, 0x94u);
  for ( i = a2 + 64380; ; i += 4 )
  {
    memset((int)dst, 0, sizeof(dst));
    v3 = 0;
    v4 = v2;
    if ( v2 < 0x24 )
    {
      *(_DWORD *)&dst[8] = 1;
      dst[36] = 15;
      if ( v2 >= 0x12 )
      {
        v4 = v2 - 18;
        v3 = 1;
      }
    }
    else
    {
      *(_DWORD *)&dst[8] = 0;
      dst[36] = 0;
    }
    v5 = 20 * (v4 % 0x12);
    v6 = dword_8D0304[v5 / 4];
    v7 = dword_8D0308[v5 / 4];
    *(_DWORD *)&dst[20] = acmodes[v5 / 0x14].BlendOp;
    *(_DWORD *)&dst[32] = *(_DWORD *)&dst[20];
    *(_DWORD *)&dst[24] = dword_8D030C[v5 / 4];
    v8 = dword_8D0310[v5 / 4];
    *(_DWORD *)&dst[12] = v6;
    *(_DWORD *)&dst[16] = v7;
    *(_DWORD *)&dst[28] = v8;
    if ( v3 )
    {
      if ( v6 == 5 )
        *(_DWORD *)&dst[12] = 2;
    }
    if ( (*(int (__stdcall **)(_DWORD, unsigned __int8 *, int))(**(_DWORD **)(a2 + 63952) + 80))(
           *(_DWORD *)(a2 + 63952),
           dst,
           i) < 0 )
      break;
    if ( ++v2 >= 0x25 )
      return 1;
  }
  return 0;
}
