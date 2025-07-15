char __usercall Scaleform::Render::D3D1x::HAL::createRasterStates@<al>(
        Scaleform::Render::D3D1x::HAL *this@<ecx>,
        int a2@<esi>)
{
  int v2; // ebx
  _DWORD v4[10]; // [esp+8h] [ebp-28h] BYREF

  *(_DWORD *)(a2 + 64564) = 0;
  *(_DWORD *)(a2 + 64568) = 0;
  v2 = 0;
  while ( 1 )
  {
    memset(v4, 0, sizeof(v4));
    v4[1] = 1;
    v4[6] = 1;
    v4[0] = 3;
    if ( v2 == 1 )
      v4[0] = 2;
    if ( (*(int (__stdcall **)(_DWORD, _DWORD *, int))(**(_DWORD **)(a2 + 63952) + 88))(
           *(_DWORD *)(a2 + 63952),
           v4,
           a2 + 4 * v2 + 64564) < 0 )
      break;
    if ( (unsigned int)++v2 >= 2 )
      return 1;
  }
  return 0;
}
