void __usercall btConvexInternalAabbCachingShape::recalcLocalAabb(
        btConvexInternalAabbCachingShape *this@<ecx>,
        int a2@<esi>,
        int a3,
        int a4,
        int a5,
        float a6,
        int a7,
        int a8,
        int a9,
        int a10,
        float a11,
        int a12,
        float a13,
        int a14,
        int a15,
        int a16,
        int a17,
        float a18,
        int a19,
        int a20,
        int a21,
        int a22,
        float a23)
{
  void (__thiscall *v23)(int, const btVector3 *, btVector3 *, int); // edx
  btVector3 _supporting[6]; // [esp+Ch] [ebp-60h] BYREF
  float vars0; // [esp+6Ch] [ebp+0h]

  *(_BYTE *)(a2 + 96) = 1;
  if ( (_S1_7 & 1) == 0 )
  {
    _S1_7 |= 1u;
    directions_0[0].mVec128.m128_i32[0] = (int)clear_value;
    dword_4C270F4 = (int)clear_value;
    dword_4C27108 = (int)clear_value;
    dword_4C270E4 = 0;
    dword_4C270E8 = 0;
    dword_4C270EC = 0;
    dword_4C270F0 = 0;
    dword_4C270F8 = 0;
    dword_4C270FC = 0;
    dword_4C27100 = 0;
    dword_4C27104 = 0;
    dword_4C2710C = 0;
    dword_4C27110 = -1082130432;
    dword_4C27114 = 0;
    dword_4C27118 = 0;
    dword_4C2711C = 0;
    dword_4C27120 = 0;
    dword_4C27124 = -1082130432;
    dword_4C27128 = 0;
    dword_4C2712C = 0;
    dword_4C27130 = 0;
    dword_4C27134 = 0;
    dword_4C27138 = -1082130432;
    dword_4C2713C = 0;
  }
  v23 = *(void (__thiscall **)(int, const btVector3 *, btVector3 *, int))(*(_DWORD *)a2 + 68);
  memset(_supporting, 0, sizeof(_supporting));
  v23(a2, directions_0, _supporting, 6);
  *(float *)(a2 + 80) = *(float *)(a2 + 48) + vars0;
  *(float *)(a2 + 64) = a13 - *(float *)(a2 + 48);
  *(float *)(a2 + 84) = *(float *)(a2 + 48) + a6;
  *(float *)(a2 + 68) = a18 - *(float *)(a2 + 48);
  *(float *)(a2 + 88) = *(float *)(a2 + 48) + a11;
  *(float *)(a2 + 72) = a23 - *(float *)(a2 + 48);
}
