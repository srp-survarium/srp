void __thiscall btStridingMeshInterface::InternalProcessAllTriangles(
        btStridingMeshInterface *this,
        btInternalTriangleIndexCallback *callback,
        const btVector3 *aabbMin,
        const btVector3 *aabbMax)
{
  btStridingMeshInterface *v4; // ebx
  int (__thiscall *getNumSubParts)(btStridingMeshInterface *); // edx
  int v6; // eax
  int v7; // edi
  int m; // ebx
  unsigned __int8 *v9; // eax
  double *v10; // ecx
  double v11; // xmm4_8
  double v12; // xmm1_8
  float v13; // xmm0_4
  float v14; // xmm5_4
  int v15; // ecx
  double v16; // xmm6_8
  float v17; // xmm0_4
  int v18; // eax
  void (__thiscall *v19)(btInternalTriangleIndexCallback *, btVector3 *, int, int); // edx
  float v20; // xmm0_4
  int k; // ebx
  unsigned __int16 *v22; // eax
  double *v23; // ecx
  double v24; // xmm4_8
  double v25; // xmm1_8
  float v26; // xmm0_4
  float v27; // xmm5_4
  int v28; // ecx
  double v29; // xmm6_8
  float v30; // xmm0_4
  int v31; // eax
  float v32; // xmm0_4
  void (__thiscall *v33)(btInternalTriangleIndexCallback *, btVector3 *, int, int); // edx
  int j; // ebx
  _DWORD *v35; // eax
  double *v36; // ecx
  double v37; // xmm4_8
  double v38; // xmm1_8
  float v39; // xmm0_4
  float v40; // xmm5_4
  int v41; // ecx
  double v42; // xmm6_8
  float v43; // xmm0_4
  int v44; // eax
  float v45; // xmm0_4
  void (__thiscall *internalProcessTriangleIndex)(btInternalTriangleIndexCallback *, btVector3 *, int, int); // edx
  int jj; // ebx
  unsigned __int8 *v48; // eax
  float *v49; // ecx
  float v50; // xmm5_4
  float v51; // xmm1_4
  int v52; // ecx
  float v53; // xmm1_4
  float v54; // xmm6_4
  int v55; // eax
  float v56; // xmm0_4
  void (__thiscall *v57)(btInternalTriangleIndexCallback *, btVector3 *, int, int); // edx
  float v58; // xmm1_4
  int ii; // ebx
  unsigned __int16 *v60; // eax
  float *v61; // ecx
  float v62; // xmm5_4
  float v63; // xmm1_4
  int v64; // ecx
  float v65; // xmm1_4
  float v66; // xmm6_4
  int v67; // eax
  float v68; // xmm0_4
  void (__thiscall *v69)(btInternalTriangleIndexCallback *, btVector3 *, int, int); // edx
  float v70; // xmm1_4
  int n; // ebx
  _DWORD *v72; // eax
  float *v73; // ecx
  float v74; // xmm5_4
  float v75; // xmm1_4
  int v76; // ecx
  float v77; // xmm1_4
  float v78; // xmm6_4
  int v79; // eax
  float v80; // xmm0_4
  void (__thiscall *v81)(btInternalTriangleIndexCallback *, btVector3 *, int, int); // edx
  float v82; // xmm1_4
  int v83; // [esp+398h] [ebp-68h] BYREF
  int v84; // [esp+39Ch] [ebp-64h] BYREF
  int v85; // [esp+3A0h] [ebp-60h] BYREF
  int v86; // [esp+3A4h] [ebp-5Ch] BYREF
  int v87; // [esp+3A8h] [ebp-58h] BYREF
  int v88; // [esp+3ACh] [ebp-54h] BYREF
  int v89; // [esp+3B0h] [ebp-50h] BYREF
  btStridingMeshInterface *v90; // [esp+3B4h] [ebp-4Ch]
  int v91; // [esp+3B8h] [ebp-48h]
  int v92; // [esp+3BCh] [ebp-44h] BYREF
  unsigned __int64 v93; // [esp+3C0h] [ebp-40h]
  unsigned __int64 i; // [esp+3C8h] [ebp-38h]
  float v95; // [esp+3D0h] [ebp-30h] BYREF
  float v96; // [esp+3D4h] [ebp-2Ch]
  float v97; // [esp+3D8h] [ebp-28h]
  int v98; // [esp+3DCh] [ebp-24h]
  float v99; // [esp+3E0h] [ebp-20h]
  float v100; // [esp+3E4h] [ebp-1Ch]
  float v101; // [esp+3E8h] [ebp-18h]
  int v102; // [esp+3ECh] [ebp-14h]
  float v103; // [esp+3F0h] [ebp-10h]
  float v104; // [esp+3F4h] [ebp-Ch]
  float v105; // [esp+3F8h] [ebp-8h]
  int v106; // [esp+3FCh] [ebp-4h]

  v4 = this;
  getNumSubParts = this->getNumSubParts;
  v90 = this;
  v6 = ((int (__fastcall *)(btStridingMeshInterface *))getNumSubParts)(this);
  v93 = v4->m_scaling.mVec128.m128_u64[0];
  v7 = 0;
  v91 = v6;
  for ( i = v4->m_scaling.mVec128.m128_u64[1]; v7 < v91; ++v7 )
  {
    v4->getLockedReadOnlyVertexIndexBase(
      v4,
      (const unsigned __int8 **)&v84,
      &v92,
      (PHY_ScalarType *)&v89,
      &v83,
      (const unsigned __int8 **)&v87,
      &v86,
      &v85,
      (PHY_ScalarType *)&v88,
      v7);
    if ( v89 )
    {
      if ( v89 == 1 )
      {
        switch ( v88 )
        {
          case 2:
            for ( j = 0; j < v85; ++j )
            {
              v35 = (_DWORD *)(v87 + v86 * j);
              v36 = (double *)(v84 + v83 * *v35);
              v37 = *v36;
              v38 = v36[1];
              v39 = v36[2];
              v97 = v39 * *(float *)&i;
              *(float *)&v38 = v38;
              v96 = *(float *)&v38 * *((float *)&v93 + 1);
              v40 = v37;
              v95 = v40 * *(float *)&v93;
              v98 = 0;
              v41 = v83 * v35[1];
              v42 = *(double *)(v41 + v84);
              v43 = *(double *)(v41 + v84 + 16);
              *(float *)&v38 = *(double *)(v41 + v84 + 8);
              v101 = v43 * *(float *)&i;
              v100 = *(float *)&v38 * *((float *)&v93 + 1);
              v102 = 0;
              v99 = (float)v42 * *(float *)&v93;
              v44 = v83 * v35[2];
              v45 = (float)*(double *)(v44 + v84 + 16) * *(float *)&i;
              internalProcessTriangleIndex = callback->internalProcessTriangleIndex;
              *(float *)&v38 = (float)*(double *)(v44 + v84 + 8) * *((float *)&v93 + 1);
              v103 = (float)*(double *)(v84 + v44) * *(float *)&v93;
              v104 = *(float *)&v38;
              v105 = v45;
              v106 = 0;
              internalProcessTriangleIndex(callback, (btVector3 *)&v95, v7, j);
            }
            break;
          case 3:
            for ( k = 0; k < v85; ++k )
            {
              v22 = (unsigned __int16 *)(v87 + v86 * k);
              v23 = (double *)(v84 + v83 * *v22);
              v24 = *v23;
              v25 = v23[1];
              v26 = v23[2];
              v97 = v26 * *(float *)&i;
              *(float *)&v25 = v25;
              v96 = *(float *)&v25 * *((float *)&v93 + 1);
              v27 = v24;
              v95 = v27 * *(float *)&v93;
              v98 = 0;
              v28 = v83 * v22[1];
              v29 = *(double *)(v28 + v84);
              v30 = *(double *)(v28 + v84 + 16);
              *(float *)&v25 = *(double *)(v28 + v84 + 8);
              v101 = v30 * *(float *)&i;
              v100 = *(float *)&v25 * *((float *)&v93 + 1);
              v102 = 0;
              v99 = (float)v29 * *(float *)&v93;
              v31 = v83 * v22[2];
              v32 = (float)*(double *)(v31 + v84 + 16) * *(float *)&i;
              v33 = callback->internalProcessTriangleIndex;
              *(float *)&v25 = (float)*(double *)(v31 + v84 + 8) * *((float *)&v93 + 1);
              v103 = (float)*(double *)(v84 + v31) * *(float *)&v93;
              v104 = *(float *)&v25;
              v105 = v32;
              v106 = 0;
              v33(callback, (btVector3 *)&v95, v7, k);
            }
            break;
          case 5:
            for ( m = 0; m < v85; ++m )
            {
              v9 = (unsigned __int8 *)(v87 + v86 * m);
              v10 = (double *)(v84 + v83 * *v9);
              v11 = *v10;
              v12 = v10[1];
              v13 = v10[2];
              v97 = v13 * *(float *)&i;
              *(float *)&v12 = v12;
              v96 = *(float *)&v12 * *((float *)&v93 + 1);
              v14 = v11;
              v95 = v14 * *(float *)&v93;
              v98 = 0;
              v15 = v83 * v9[1];
              v16 = *(double *)(v15 + v84);
              v17 = *(double *)(v15 + v84 + 16);
              *(float *)&v12 = *(double *)(v15 + v84 + 8);
              v101 = v17 * *(float *)&i;
              v100 = *(float *)&v12 * *((float *)&v93 + 1);
              v102 = 0;
              v99 = (float)v16 * *(float *)&v93;
              v18 = v83 * v9[2];
              v19 = callback->internalProcessTriangleIndex;
              v20 = (float)*(double *)(v18 + v84 + 16) * *(float *)&i;
              *(float *)&v12 = (float)*(double *)(v18 + v84 + 8) * *((float *)&v93 + 1);
              v103 = (float)*(double *)(v84 + v18) * *(float *)&v93;
              v104 = *(float *)&v12;
              v105 = v20;
              v106 = 0;
              v19(callback, (btVector3 *)&v95, v7, m);
            }
            break;
        }
      }
    }
    else
    {
      switch ( v88 )
      {
        case 2:
          for ( n = 0; n < v85; ++n )
          {
            v72 = (_DWORD *)(v87 + v86 * n);
            v73 = (float *)(v84 + v83 * *v72);
            v74 = *v73;
            v75 = v73[1];
            v97 = v73[2] * *(float *)&i;
            v96 = v75 * *((float *)&v93 + 1);
            v95 = v74 * *(float *)&v93;
            v98 = 0;
            v76 = v83 * v72[1];
            v77 = *(float *)(v76 + v84 + 4);
            v78 = *(float *)(v76 + v84);
            v101 = *(float *)(v76 + v84 + 8) * *(float *)&i;
            v100 = v77 * *((float *)&v93 + 1);
            v102 = 0;
            v99 = v78 * *(float *)&v93;
            v79 = v83 * v72[2];
            v80 = *(float *)(v79 + v84 + 8) * *(float *)&i;
            v81 = callback->internalProcessTriangleIndex;
            v82 = *(float *)(v79 + v84 + 4) * *((float *)&v93 + 1);
            v103 = *(float *)(v84 + v79) * *(float *)&v93;
            v104 = v82;
            v105 = v80;
            v106 = 0;
            v81(callback, (btVector3 *)&v95, v7, n);
          }
          break;
        case 3:
          for ( ii = 0; ii < v85; ++ii )
          {
            v60 = (unsigned __int16 *)(v87 + v86 * ii);
            v61 = (float *)(v84 + v83 * *v60);
            v62 = *v61;
            v63 = v61[1];
            v97 = v61[2] * *(float *)&i;
            v96 = v63 * *((float *)&v93 + 1);
            v95 = v62 * *(float *)&v93;
            v98 = 0;
            v64 = v83 * v60[1];
            v65 = *(float *)(v64 + v84 + 4);
            v66 = *(float *)(v64 + v84);
            v101 = *(float *)(v64 + v84 + 8) * *(float *)&i;
            v100 = v65 * *((float *)&v93 + 1);
            v102 = 0;
            v99 = v66 * *(float *)&v93;
            v67 = v83 * v60[2];
            v68 = *(float *)(v67 + v84 + 8) * *(float *)&i;
            v69 = callback->internalProcessTriangleIndex;
            v70 = *(float *)(v67 + v84 + 4) * *((float *)&v93 + 1);
            v103 = *(float *)(v84 + v67) * *(float *)&v93;
            v104 = v70;
            v105 = v68;
            v106 = 0;
            v69(callback, (btVector3 *)&v95, v7, ii);
          }
          break;
        case 5:
          for ( jj = 0; jj < v85; ++jj )
          {
            v48 = (unsigned __int8 *)(v87 + v86 * jj);
            v49 = (float *)(v84 + v83 * *v48);
            v50 = *v49;
            v51 = v49[1];
            v97 = v49[2] * *(float *)&i;
            v96 = v51 * *((float *)&v93 + 1);
            v95 = v50 * *(float *)&v93;
            v98 = 0;
            v52 = v83 * v48[1];
            v53 = *(float *)(v52 + v84 + 4);
            v54 = *(float *)(v52 + v84);
            v101 = *(float *)(v52 + v84 + 8) * *(float *)&i;
            v100 = v53 * *((float *)&v93 + 1);
            v102 = 0;
            v99 = v54 * *(float *)&v93;
            v55 = v83 * v48[2];
            v56 = *(float *)(v55 + v84 + 8) * *(float *)&i;
            v57 = callback->internalProcessTriangleIndex;
            v58 = *(float *)(v55 + v84 + 4) * *((float *)&v93 + 1);
            v103 = *(float *)(v84 + v55) * *(float *)&v93;
            v104 = v58;
            v105 = v56;
            v106 = 0;
            v57(callback, (btVector3 *)&v95, v7, jj);
          }
          break;
      }
    }
    v4 = v90;
    v90->unLockReadOnlyVertexBase(v90, v7);
  }
}
