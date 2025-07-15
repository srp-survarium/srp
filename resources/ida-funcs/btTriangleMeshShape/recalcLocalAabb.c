void __thiscall btTriangleMeshShape::recalcLocalAabb(btTriangleMeshShape *this, float *a2)
{
  int v2; // edi
  int v3; // eax
  int v4; // eax
  _DWORD *v5; // esi
  int v6; // eax
  float v7; // xmm0_4
  float *v8; // eax
  int i; // [esp+18h] [ebp-38h]
  float *v10; // [esp+1Ch] [ebp-34h]
  _DWORD v11[4]; // [esp+20h] [ebp-30h] BYREF
  _DWORD v12[4]; // [esp+30h] [ebp-20h] BYREF
  _BYTE v13[16]; // [esp+40h] [ebp-10h] BYREF

  v2 = 0;
  v10 = a2 + 4;
  for ( i = 0; ; v2 = i )
  {
    v3 = *(_DWORD *)a2;
    memset(v11, 0, sizeof(v11));
    *(float *)((char *)v11 + v2) = s_bm_current_air_resistance;
    (*(void (__thiscall **)(float *, _DWORD *, _DWORD *))(v3 + 60))(a2, v12, v11);
    v10[4] = a2[3] + *(float *)((char *)v12 + v2);
    v4 = *(_DWORD *)a2;
    *(float *)((char *)v11 + v2) = FLOAT_N1_0;
    v5 = (_DWORD *)(*(int (__thiscall **)(float *, _BYTE *, _DWORD *))(v4 + 60))(a2, v13, v11);
    v6 = i;
    i += 4;
    v12[0] = *v5++;
    v12[1] = *v5++;
    v12[2] = *v5;
    v12[3] = v5[1];
    v7 = *(float *)((char *)v12 + v6);
    v8 = v10++;
    *v8 = v7 - a2[3];
    if ( i >= 12 )
      break;
  }
}
