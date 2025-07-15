char __thiscall Scaleform::Render::D3D1x::HAL::createDepthStencilStates(Scaleform::Render::D3D1x::HAL *this, int a2)
{
  int v2; // eax
  int v3; // eax
  unsigned __int8 dst[52]; // [esp+Ch] [ebp-38h] BYREF
  int v6; // [esp+40h] [ebp-4h]

  memset((void *)(a2 + 64528), 0, 0x20u);
  v6 = 0;
  while ( 1 )
  {
    memset((int)dst, 0, sizeof(dst));
    v2 = 7;
    *(_DWORD *)&dst[8] = 8;
    dst[16] = -1;
    dst[17] = -1;
    *(_DWORD *)&dst[32] = 8;
    *(_DWORD *)&dst[24] = 1;
    *(_DWORD *)&dst[20] = 1;
    *(_DWORD *)&dst[28] = 1;
    switch ( v6 )
    {
      case 0:
        *(_DWORD *)&dst[12] = 0;
        break;
      case 1:
        *(_DWORD *)&dst[32] = 8;
        v2 = 3;
        goto LABEL_6;
      case 2:
        *(_DWORD *)&dst[12] = 1;
        *(_DWORD *)&dst[32] = 4;
        *(_DWORD *)&dst[28] = 3;
        *(_DWORD *)&dst[20] = 1;
        *(_DWORD *)&dst[24] = 1;
        break;
      case 3:
        *(_DWORD *)&dst[32] = 3;
LABEL_6:
        *(_DWORD *)&dst[12] = 1;
        *(_DWORD *)&dst[28] = v2;
        *(_DWORD *)&dst[24] = v2;
        break;
      case 4:
        *(_DWORD *)dst = 1;
        *(_DWORD *)&dst[8] = 8;
        *(_DWORD *)&dst[4] = 1;
        break;
      case 5:
        *(_DWORD *)&dst[12] = 1;
        *(_DWORD *)&dst[32] = 4;
        *(_DWORD *)&dst[28] = 1;
        break;
      case 6:
        *(_DWORD *)&dst[4] = 1;
        *(_DWORD *)dst = 1;
        *(_DWORD *)&dst[8] = 3;
        break;
      case 7:
        *(_DWORD *)&dst[4] = 0;
        *(_DWORD *)dst = 0;
        break;
      default:
        break;
    }
    v3 = *(_DWORD *)(a2 + 63952);
    *(_DWORD *)&dst[36] = *(_DWORD *)&dst[20];
    *(_DWORD *)&dst[40] = *(_DWORD *)&dst[24];
    *(_DWORD *)&dst[44] = *(_DWORD *)&dst[28];
    *(_DWORD *)&dst[48] = *(_DWORD *)&dst[32];
    if ( (*(int (__stdcall **)(int, unsigned __int8 *, int))(*(_DWORD *)v3 + 84))(v3, dst, a2 + 4 * v6 + 64528) < 0 )
      return 0;
    if ( (unsigned int)++v6 >= 8 )
      return 1;
  }
}
