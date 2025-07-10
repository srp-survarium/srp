unsigned __int64 __cdecl bn_sqr_comba4(int a1, unsigned int *a2)
{
  unsigned __int64 v3; // kr00_8
  unsigned int v4; // edx
  unsigned __int64 v5; // rax
  bool v6; // cf
  BOOL v7; // ebx
  int v8; // ecx
  unsigned int v9; // ebp
  int v10; // ebx
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // kr10_8
  int v13; // ecx
  unsigned __int64 v14; // rax
  unsigned int v15; // ebx
  int v16; // ecx
  unsigned __int64 v17; // rax
  unsigned __int64 v18; // kr20_8
  int v19; // ebp
  unsigned __int64 v20; // rax
  int v21; // ebp
  unsigned int v22; // ecx
  int v23; // ebx
  unsigned int v24; // ebp
  unsigned __int64 v25; // rax
  unsigned __int64 v26; // kr30_8
  int v27; // ebx
  unsigned __int64 v28; // rax
  unsigned int v29; // ebp
  int v30; // ebx
  unsigned __int64 v31; // rax
  BOOL v32; // ecx
  unsigned int v33; // ebx
  int v34; // kr40_4
  unsigned __int64 result; // rax

  v3 = *a2 * (unsigned __int64)*a2;
  v4 = *a2;
  *(_DWORD *)a1 = v3;
  v5 = v4 * (unsigned __int64)a2[1];
  v6 = __CFADD__(v5, v5);
  v5 *= 2LL;
  v7 = v6;
  v6 = __CFADD__(v5, HIDWORD(v3));
  v9 = (v5 + HIDWORD(v3)) >> 32;
  v8 = v5 + HIDWORD(v3);
  LODWORD(v5) = a2[2];
  v10 = v6 + v7;
  *(_DWORD *)(a1 + 4) = v8;
  v11 = *a2 * (unsigned __int64)(unsigned int)v5;
  v6 = __CFADD__(v11, v11);
  v11 *= 2LL;
  v12 = v11 + __PAIR64__(v10, v9);
  v13 = __CFADD__(v11, __PAIR64__(v10, v9)) + v6;
  v14 = a2[1] * (unsigned __int64)a2[1];
  v6 = __CFADD__(v14, v12);
  v15 = (v14 + v12) >> 32;
  HIDWORD(v14) = *a2;
  v16 = v6 + v13;
  *(_DWORD *)(a1 + 8) = v14 + v12;
  v17 = HIDWORD(v14) * (unsigned __int64)a2[3];
  v6 = __CFADD__(v17, v17);
  v17 *= 2LL;
  v18 = v17 + __PAIR64__(v16, v15);
  v19 = __CFADD__(v17, __PAIR64__(v16, v15)) + v6;
  v20 = a2[1] * (unsigned __int64)a2[2];
  v6 = __CFADD__(v20, v20);
  v20 *= 2LL;
  v21 = v6 + v19;
  v6 = __CFADD__(v20, v18);
  v22 = (v20 + v18) >> 32;
  v23 = v20 + v18;
  LODWORD(v20) = a2[3];
  v24 = v6 + v21;
  *(_DWORD *)(a1 + 12) = v23;
  v25 = a2[1] * (unsigned __int64)(unsigned int)v20;
  v6 = __CFADD__(v25, v25);
  v25 *= 2LL;
  v26 = v25 + __PAIR64__(v24, v22);
  v27 = __CFADD__(v25, __PAIR64__(v24, v22)) + v6;
  v28 = a2[2] * (unsigned __int64)a2[2];
  v6 = __CFADD__(v28, v26);
  v29 = (v28 + v26) >> 32;
  HIDWORD(v28) = a2[2];
  v30 = v6 + v27;
  *(_DWORD *)(a1 + 16) = v28 + v26;
  v31 = HIDWORD(v28) * (unsigned __int64)a2[3];
  v6 = __CFADD__(v31, v31);
  v31 *= 2LL;
  v32 = v6;
  v6 = __CFADD__(v31, __PAIR64__(v30, v29));
  v34 = v31 + v29;
  v33 = (v31 + __PAIR64__(v30, v29)) >> 32;
  LODWORD(v31) = a2[3];
  *(_DWORD *)(a1 + 20) = v34;
  result = (unsigned int)v31 * (unsigned __int64)(unsigned int)v31;
  *(_QWORD *)(a1 + 24) = result + __PAIR64__((unsigned int)v6 + v32, v33);
  return result;
}
