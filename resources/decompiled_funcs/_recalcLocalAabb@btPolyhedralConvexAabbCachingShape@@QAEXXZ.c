void __usercall btPolyhedralConvexAabbCachingShape::recalcLocalAabb(
        btPolyhedralConvexAabbCachingShape *this@<ecx>,
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

  *(_BYTE *)(a2 + 112) = 1;
  if ( (_S1_5 & 1) == 0 )
  {
    _S1_5 |= 1u;
    directions[0].mVec128.m128_i32[0] = (int)clear_value;
    dword_4C27084 = (int)clear_value;
    dword_4C27098 = (int)clear_value;
    dword_4C27074 = 0;
    dword_4C27078 = 0;
    dword_4C2707C = 0;
    dword_4C27080 = 0;
    dword_4C27088 = 0;
    dword_4C2708C = 0;
    dword_4C27090 = 0;
    dword_4C27094 = 0;
    dword_4C2709C = 0;
    dword_4C270A0 = -1082130432;
    dword_4C270A4 = 0;
    dword_4C270A8 = 0;
    dword_4C270AC = 0;
    dword_4C270B0 = 0;
    dword_4C270B4 = -1082130432;
    dword_4C270B8 = 0;
    dword_4C270BC = 0;
    dword_4C270C0 = 0;
    dword_4C270C4 = 0;
    dword_4C270C8 = -1082130432;
    dword_4C270CC = 0;
  }
  v23 = *(void (__thiscall **)(int, const btVector3 *, btVector3 *, int))(*(_DWORD *)a2 + 68);
  memset(_supporting, 0, sizeof(_supporting));
  v23(a2, directions, _supporting, 6);
  *(float *)(a2 + 96) = *(float *)(a2 + 48) + vars0;
  *(float *)(a2 + 80) = a13 - *(float *)(a2 + 48);
  *(float *)(a2 + 100) = *(float *)(a2 + 48) + a6;
  *(float *)(a2 + 84) = a18 - *(float *)(a2 + 48);
  *(float *)(a2 + 104) = *(float *)(a2 + 48) + a11;
  *(float *)(a2 + 88) = a23 - *(float *)(a2 + 48);
}
