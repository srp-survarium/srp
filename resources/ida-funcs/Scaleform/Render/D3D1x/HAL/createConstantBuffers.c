char __usercall Scaleform::Render::D3D1x::HAL::createConstantBuffers@<al>(
        Scaleform::Render::D3D1x::HAL *this@<ecx>,
        int a2@<esi>)
{
  int i; // ebx
  int v3; // eax
  _DWORD v5[6]; // [esp+8h] [ebp-1Ch] BYREF
  int v6; // [esp+20h] [ebp-4h]

  v6 = 0;
  memset((void *)(a2 + 64572), 0, 0x20u);
  memset(v5, 0, sizeof(v5));
  for ( i = a2 + 64572; ; i += 4 )
  {
    v3 = *(_DWORD *)(a2 + 63952);
    v5[0] = 16576;
    v5[1] = 2;
    v5[2] = 4;
    v5[3] = &_sbh_sizeHeaderList;
    if ( (*(int (__stdcall **)(int, _DWORD *, _DWORD, int))(*(_DWORD *)v3 + 12))(v3, v5, 0, i) < 0 )
      break;
    if ( (unsigned int)++v6 >= 8 )
      return 1;
  }
  return 0;
}
