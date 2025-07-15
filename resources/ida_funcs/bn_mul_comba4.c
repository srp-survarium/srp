_DWORD *__cdecl bn_mul_comba4(_DWORD *a1, unsigned int *a2, unsigned int *a3)
{
  int v3; // ecx
  unsigned int v4; // edx
  unsigned __int64 v5; // rax
  bool v6; // cf
  int v7; // ecx
  unsigned __int64 v8; // kr08_8
  unsigned __int64 v9; // rax
  int v10; // ebp
  int v11; // ebx
  unsigned __int64 v12; // rax
  int v13; // ebp
  int v14; // ebx
  BOOL v15; // ett
  BOOL v16; // ecx
  unsigned __int64 v17; // rax
  int v18; // ebp
  int v19; // ebx
  BOOL v20; // ett
  int v21; // ecx
  unsigned __int64 v22; // rax
  int v23; // ebx
  int v24; // ecx
  unsigned __int64 v25; // rax
  int v26; // ebx
  int v27; // ecx
  BOOL v28; // ett
  BOOL v29; // ebp
  unsigned __int64 v30; // rax
  int v31; // ebx
  int v32; // ecx
  BOOL v33; // ett
  int v34; // ebp
  unsigned __int64 v35; // rax
  int v36; // ebx
  int v37; // ecx
  BOOL v38; // ett
  int v39; // ebp
  unsigned __int64 v40; // rax
  int v41; // ecx
  int v42; // ebp
  unsigned __int64 v43; // rax
  int v44; // ecx
  int v45; // ebp
  BOOL v46; // ett
  BOOL v47; // ebx
  unsigned __int64 v48; // rax
  int v49; // ecx
  int v50; // ebp
  BOOL v51; // ett
  int v52; // ebx
  unsigned __int64 v53; // rax
  int v54; // ebp
  int v55; // ebx
  unsigned __int64 v56; // rax
  int v57; // ebp
  int v58; // ebx
  BOOL v59; // ett
  BOOL v60; // ecx
  unsigned __int64 v61; // rax
  int v62; // ebx
  int v63; // ecx
  unsigned __int64 v64; // rax
  int v65; // ebx
  _DWORD *result; // eax

  v3 = (*a3 * (unsigned __int64)*a2) >> 32;
  v4 = *a3;
  *a1 = *a3 * *a2;
  v5 = v4 * (unsigned __int64)a2[1];
  v6 = __CFADD__((_DWORD)v5, v3);
  v7 = v5 + v3;
  v8 = HIDWORD(v5) + (unsigned __int64)v6;
  v9 = a3[1] * (unsigned __int64)*a2;
  v6 = __CFADD__(__CFADD__((_DWORD)v9, v7), (_DWORD)v8) | __CFADD__(HIDWORD(v9), __CFADD__((_DWORD)v9, v7) + (_DWORD)v8);
  v10 = HIDWORD(v9) + __CFADD__((_DWORD)v9, v7) + (_DWORD)v8;
  HIDWORD(v9) = *a3;
  v11 = v6 + HIDWORD(v8);
  a1[1] = v9 + v7;
  v12 = HIDWORD(v9) * (unsigned __int64)a2[2];
  v6 = __CFADD__((_DWORD)v12, v10);
  v13 = v12 + v10;
  v15 = v6;
  v6 = __CFADD__(v6, v11);
  v14 = v15 + v11;
  v6 |= __CFADD__(HIDWORD(v12), v14);
  v14 += HIDWORD(v12);
  v16 = v6;
  v17 = a3[1] * (unsigned __int64)a2[1];
  v6 = __CFADD__((_DWORD)v17, v13);
  v18 = v17 + v13;
  v20 = v6;
  v6 = __CFADD__(v6, v14);
  v19 = v20 + v14;
  v6 |= __CFADD__(HIDWORD(v17), v19);
  v19 += HIDWORD(v17);
  v21 = v6 + v16;
  v22 = a3[2] * (unsigned __int64)*a2;
  v6 = __CFADD__(__CFADD__((_DWORD)v22, v18), v19);
  v23 = __CFADD__((_DWORD)v22, v18) + v19;
  v6 |= __CFADD__(HIDWORD(v22), v23);
  v23 += HIDWORD(v22);
  HIDWORD(v22) = *a3;
  v24 = v6 + v21;
  a1[2] = v22 + v18;
  v25 = HIDWORD(v22) * (unsigned __int64)a2[3];
  v6 = __CFADD__((_DWORD)v25, v23);
  v26 = v25 + v23;
  v28 = v6;
  v6 = __CFADD__(v6, v24);
  v27 = v28 + v24;
  v6 |= __CFADD__(HIDWORD(v25), v27);
  v27 += HIDWORD(v25);
  v29 = v6;
  v30 = a3[1] * (unsigned __int64)a2[2];
  v6 = __CFADD__((_DWORD)v30, v26);
  v31 = v30 + v26;
  v33 = v6;
  v6 = __CFADD__(v6, v27);
  v32 = v33 + v27;
  v6 |= __CFADD__(HIDWORD(v30), v32);
  v32 += HIDWORD(v30);
  v34 = v6 + v29;
  v35 = a3[2] * (unsigned __int64)a2[1];
  v6 = __CFADD__((_DWORD)v35, v31);
  v36 = v35 + v31;
  v38 = v6;
  v6 = __CFADD__(v6, v32);
  v37 = v38 + v32;
  v6 |= __CFADD__(HIDWORD(v35), v37);
  v37 += HIDWORD(v35);
  v39 = v6 + v34;
  v40 = a3[3] * (unsigned __int64)*a2;
  v6 = __CFADD__(__CFADD__((_DWORD)v40, v36), v37);
  v41 = __CFADD__((_DWORD)v40, v36) + v37;
  v6 |= __CFADD__(HIDWORD(v40), v41);
  v41 += HIDWORD(v40);
  HIDWORD(v40) = a3[1];
  v42 = v6 + v39;
  a1[3] = v40 + v36;
  v43 = HIDWORD(v40) * (unsigned __int64)a2[3];
  v6 = __CFADD__((_DWORD)v43, v41);
  v44 = v43 + v41;
  v46 = v6;
  v6 = __CFADD__(v6, v42);
  v45 = v46 + v42;
  v6 |= __CFADD__(HIDWORD(v43), v45);
  v45 += HIDWORD(v43);
  v47 = v6;
  v48 = a3[2] * (unsigned __int64)a2[2];
  v6 = __CFADD__((_DWORD)v48, v44);
  v49 = v48 + v44;
  v51 = v6;
  v6 = __CFADD__(v6, v45);
  v50 = v51 + v45;
  v6 |= __CFADD__(HIDWORD(v48), v50);
  v50 += HIDWORD(v48);
  v52 = v6 + v47;
  v53 = a3[3] * (unsigned __int64)a2[1];
  v6 = __CFADD__(__CFADD__((_DWORD)v53, v49), v50);
  v54 = __CFADD__((_DWORD)v53, v49) + v50;
  v6 |= __CFADD__(HIDWORD(v53), v54);
  v54 += HIDWORD(v53);
  HIDWORD(v53) = a3[2];
  v55 = v6 + v52;
  a1[4] = v53 + v49;
  v56 = HIDWORD(v53) * (unsigned __int64)a2[3];
  v6 = __CFADD__((_DWORD)v56, v54);
  v57 = v56 + v54;
  v59 = v6;
  v6 = __CFADD__(v6, v55);
  v58 = v59 + v55;
  v6 |= __CFADD__(HIDWORD(v56), v58);
  v58 += HIDWORD(v56);
  v60 = v6;
  v61 = a3[3] * (unsigned __int64)a2[2];
  v6 = __CFADD__(__CFADD__((_DWORD)v61, v57), v58);
  v62 = __CFADD__((_DWORD)v61, v57) + v58;
  v6 |= __CFADD__(HIDWORD(v61), v62);
  v62 += HIDWORD(v61);
  HIDWORD(v61) = a3[3];
  v63 = v6 + v60;
  a1[5] = v61 + v57;
  v64 = HIDWORD(v61) * (unsigned __int64)a2[3];
  v6 = __CFADD__((_DWORD)v64, v62);
  v65 = v64 + v62;
  result = a1;
  a1[6] = v65;
  a1[7] = HIDWORD(v64) + v6 + v63;
  return result;
}
