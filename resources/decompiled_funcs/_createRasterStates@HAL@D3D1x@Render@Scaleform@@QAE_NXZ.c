char __usercall Scaleform::Render::D3D1x::HAL::createRasterStates@<al>(
        Scaleform::Render::D3D1x::HAL *this@<ecx>,
        int a2@<edi>)
{
  int v2; // esi
  _QWORD v4[2]; // [esp+40h] [ebp-30h] BYREF
  __int128 v5; // [esp+50h] [ebp-20h]
  __int64 v6; // [esp+60h] [ebp-10h]

  v2 = 0;
  *(_QWORD *)(a2 + 64396) = 0;
  while ( 1 )
  {
    v4[1] = 0;
    v5 = 0;
    v6 = 0;
    DWORD2(v5) = 1;
    v4[0] = 0x100000003LL;
    if ( v2 == 1 )
      LODWORD(v4[0]) = 2;
    if ( (*(int (__stdcall **)(_DWORD, _QWORD *, int))(**(_DWORD **)(a2 + 63792) + 88))(
           *(_DWORD *)(a2 + 63792),
           v4,
           a2 + 4 * v2 + 64396) < 0 )
      break;
    if ( (unsigned int)++v2 >= 2 )
      return 1;
  }
  return 0;
}
