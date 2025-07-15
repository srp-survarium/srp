char __usercall Scaleform::Render::D3D1x::HAL::checkMaskBufferCaps@<al>(
        Scaleform::Render::D3D1x::HAL *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax
  int v3; // eax
  _DWORD v5[6]; // [esp+8h] [ebp-20h] BYREF
  int v6; // [esp+20h] [ebp-8h] BYREF
  int v7; // [esp+24h] [ebp-4h] BYREF

  if ( *(_BYTE *)(a2 + 64376) )
    goto LABEL_14;
  v2 = *(_DWORD *)(a2 + 63956);
  *(_BYTE *)(a2 + 64377) = 0;
  *(_BYTE *)(a2 + 64378) = 0;
  v7 = 0;
  v6 = 0;
  (*(void (__stdcall **)(int, int, int *, int *))(*(_DWORD *)v2 + 356))(v2, 1, &v6, &v7);
  if ( !v7 )
    goto LABEL_10;
  (*(void (__stdcall **)(int, _DWORD *))(*(_DWORD *)v7 + 32))(v7, v5);
  switch ( v5[0] )
  {
    case 0x14:
      goto LABEL_8;
    case 0x28:
LABEL_9:
      *(_BYTE *)(a2 + 64378) = 1;
      break;
    case 0x2D:
LABEL_8:
      *(_BYTE *)(a2 + 64377) = 1;
      goto LABEL_9;
    case 0x37:
      goto LABEL_9;
  }
LABEL_10:
  v3 = v6;
  *(_BYTE *)(a2 + 64376) = 1;
  if ( v3 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v3 + 8))(v3);
  if ( v7 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v7 + 8))(v7);
LABEL_14:
  if ( *(_BYTE *)(a2 + 64377) || *(_BYTE *)(a2 + 64378) )
    return 1;
  if ( !warned_0 )
    warned_0 = 1;
  return 0;
}
