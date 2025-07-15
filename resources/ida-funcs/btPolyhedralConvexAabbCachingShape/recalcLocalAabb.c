void __usercall btPolyhedralConvexAabbCachingShape::recalcLocalAabb(
        btPolyhedralConvexAabbCachingShape *this@<ecx>,
        int *a2@<esi>,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        char a13)
{
  bool v13; // zf
  int v14; // eax
  float *v15; // ecx
  float *v16; // eax
  int v17; // edx
  _DWORD v18[23]; // [esp+0h] [ebp-60h] BYREF
  int v19; // [esp+5Ch] [ebp-4h]

  v13 = (_S1_6 & 1) == 0;
  *((_BYTE *)a2 + 112) = 1;
  if ( v13 )
  {
    _S1_6 |= 1u;
    directions[0].mVec128.m128_f32[0] = s_bm_current_air_resistance;
    dword_47EA894 = LODWORD(s_bm_current_air_resistance);
    dword_47EA8A8 = LODWORD(s_bm_current_air_resistance);
    dword_47EA884 = 0;
    dword_47EA888 = 0;
    dword_47EA88C = 0;
    dword_47EA890 = 0;
    dword_47EA898 = 0;
    dword_47EA89C = 0;
    dword_47EA8A0 = 0;
    dword_47EA8A4 = 0;
    dword_47EA8AC = 0;
    dword_47EA8B0 = LODWORD(FLOAT_N1_0);
    dword_47EA8B4 = 0;
    dword_47EA8B8 = 0;
    dword_47EA8BC = 0;
    dword_47EA8C0 = 0;
    dword_47EA8C4 = LODWORD(FLOAT_N1_0);
    dword_47EA8C8 = 0;
    dword_47EA8CC = 0;
    dword_47EA8D0 = 0;
    dword_47EA8D4 = 0;
    dword_47EA8D8 = LODWORD(FLOAT_N1_0);
    dword_47EA8DC = 0;
  }
  v14 = *a2;
  memset(v18, 0, sizeof(v18));
  v19 = 0;
  (*(void (__thiscall **)(int *, const btVector3 *, _DWORD *, int))(v14 + 68))(a2, directions, v18, 6);
  v19 = 3;
  v15 = (float *)&a13;
  v16 = (float *)(a2 + 20);
  v17 = 3;
  do
  {
    v16[4] = *(v15 - 12) + *((float *)a2 + 12);
    *v16++ = *v15 - *((float *)a2 + 12);
    v15 += 5;
    --v17;
  }
  while ( v17 );
}
