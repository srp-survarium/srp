void __thiscall btStridingMeshInterface::InternalProcessAllTriangles(
        btStridingMeshInterface *this,
        btInternalTriangleIndexCallback *callback,
        const btVector3 *aabbMin,
        const btVector3 *aabbMax)
{
  btStridingMeshInterface *v4; // esi
  btStridingMeshInterface_vtbl *v5; // eax
  int v6; // eax
  int v7; // ebx
  int v8; // edi
  unsigned __int8 *v9; // ecx
  double *v10; // eax
  double v11; // xmm0_8
  double v12; // xmm2_8
  float v13; // xmm1_4
  double *v14; // eax
  float v15; // xmm1_4
  float v16; // xmm3_4
  double *v17; // eax
  double v18; // xmm1_8
  double v19; // xmm2_8
  double v20; // xmm3_8
  btInternalTriangleIndexCallback_vtbl *v21; // eax
  unsigned __int16 *v22; // ecx
  double *v23; // eax
  double v24; // xmm0_8
  double v25; // xmm2_8
  float v26; // xmm1_4
  double *v27; // eax
  float v28; // xmm1_4
  float v29; // xmm3_4
  double *v30; // eax
  double v31; // xmm1_8
  double v32; // xmm2_8
  double v33; // xmm3_8
  btInternalTriangleIndexCallback_vtbl *v34; // eax
  _DWORD *v35; // ecx
  double *v36; // eax
  double v37; // xmm0_8
  double v38; // xmm2_8
  float v39; // xmm1_4
  double *v40; // eax
  float v41; // xmm1_4
  float v42; // xmm3_4
  double *v43; // eax
  double v44; // xmm1_8
  double v45; // xmm2_8
  double v46; // xmm3_8
  btInternalTriangleIndexCallback_vtbl *v47; // eax
  unsigned __int8 *v48; // ecx
  float *v49; // eax
  float v50; // xmm1_4
  float v51; // xmm2_4
  float *v52; // eax
  float v53; // xmm1_4
  float v54; // xmm2_4
  float *v55; // eax
  float v56; // xmm1_4
  float v57; // xmm2_4
  float v58; // xmm3_4
  btInternalTriangleIndexCallback_vtbl *v59; // eax
  unsigned __int16 *v60; // ecx
  float *v61; // eax
  float v62; // xmm1_4
  float v63; // xmm2_4
  float *v64; // eax
  float v65; // xmm1_4
  float v66; // xmm2_4
  float *v67; // eax
  float v68; // xmm1_4
  float v69; // xmm2_4
  float v70; // xmm3_4
  btInternalTriangleIndexCallback_vtbl *v71; // eax
  _DWORD *v72; // ecx
  float *v73; // eax
  float v74; // xmm1_4
  float v75; // xmm2_4
  float *v76; // eax
  float v77; // xmm1_4
  float v78; // xmm2_4
  float *v79; // eax
  float v80; // xmm1_4
  float v81; // xmm2_4
  float v82; // xmm3_4
  btInternalTriangleIndexCallback_vtbl *v83; // eax
  int v84; // [esp+28h] [ebp-68h] BYREF
  int v85; // [esp+2Ch] [ebp-64h] BYREF
  int v86; // [esp+30h] [ebp-60h] BYREF
  int v87; // [esp+34h] [ebp-5Ch] BYREF
  int v88; // [esp+38h] [ebp-58h] BYREF
  int v89; // [esp+3Ch] [ebp-54h] BYREF
  btStridingMeshInterface *v90; // [esp+40h] [ebp-50h]
  int v91; // [esp+44h] [ebp-4Ch] BYREF
  int v92; // [esp+48h] [ebp-48h]
  int v93; // [esp+4Ch] [ebp-44h] BYREF
  float v94; // [esp+50h] [ebp-40h]
  float v95; // [esp+54h] [ebp-3Ch]
  float v96; // [esp+58h] [ebp-38h]
  int i; // [esp+5Ch] [ebp-34h]
  float v98; // [esp+60h] [ebp-30h] BYREF
  float v99; // [esp+64h] [ebp-2Ch]
  float v100; // [esp+68h] [ebp-28h]
  int v101; // [esp+6Ch] [ebp-24h]
  float v102; // [esp+70h] [ebp-20h]
  float v103; // [esp+74h] [ebp-1Ch]
  float v104; // [esp+78h] [ebp-18h]
  int v105; // [esp+7Ch] [ebp-14h]
  float v106; // [esp+80h] [ebp-10h]
  float v107; // [esp+84h] [ebp-Ch]
  float v108; // [esp+88h] [ebp-8h]
  int v109; // [esp+8Ch] [ebp-4h]

  v4 = this;
  v5 = this->__vftable;
  v90 = this;
  v6 = ((int (__fastcall *)(btStridingMeshInterface *))v5->getNumSubParts)(this);
  v4 = (btStridingMeshInterface *)((char *)v4 + 16);
  v94 = *(float *)&v4->__vftable;
  v4 = (btStridingMeshInterface *)((char *)v4 + 4);
  v95 = *(float *)&v4->__vftable;
  v4 = (btStridingMeshInterface *)((char *)v4 + 4);
  v96 = *(float *)&v4->__vftable;
  v7 = 0;
  v92 = v6;
  for ( i = *((_DWORD *)&v4->__vftable + 1); v7 < v92; ++v7 )
  {
    v90->getLockedReadOnlyVertexIndexBase(
      v90,
      (const unsigned __int8 **)&v85,
      &v93,
      (PHY_ScalarType *)&v91,
      &v84,
      (const unsigned __int8 **)&v88,
      &v87,
      &v86,
      (PHY_ScalarType *)&v89,
      v7);
    v8 = 0;
    if ( v91 )
    {
      if ( v91 == 1 )
      {
        if ( v89 == 2 )
        {
          if ( v86 > 0 )
          {
            do
            {
              v35 = (_DWORD *)(v88 + v87 * v8);
              v36 = (double *)(v85 + v84 * *v35);
              v37 = v36[2];
              v38 = *v36;
              v39 = v36[1];
              v99 = v39 * v95;
              *(float *)&v38 = v38;
              v98 = *(float *)&v38 * v94;
              *(float *)&v37 = v37;
              v100 = *(float *)&v37 * v96;
              v101 = 0;
              v40 = (double *)(v85 + v84 * v35[1]);
              v41 = v40[2];
              *(float *)&v38 = v40[1];
              v42 = *v40;
              v102 = v42 * v94;
              v103 = *(float *)&v38 * v95;
              v104 = v41 * v96;
              v105 = 0;
              v43 = (double *)(v85 + v84 * v35[2]);
              v44 = v43[2];
              v45 = v43[1];
              v46 = *v43;
              v47 = callback->__vftable;
              v106 = (float)v46 * v94;
              v107 = (float)v45 * v95;
              v108 = (float)v44 * v96;
              v109 = 0;
              v47->internalProcessTriangleIndex(callback, (btVector3 *)&v98, v7, v8++);
            }
            while ( v8 < v86 );
          }
        }
        else if ( v89 == 3 )
        {
          if ( v86 > 0 )
          {
            do
            {
              v22 = (unsigned __int16 *)(v88 + v87 * v8);
              v23 = (double *)(v85 + v84 * *v22);
              v24 = v23[2];
              v25 = *v23;
              v26 = v23[1];
              v99 = v26 * v95;
              *(float *)&v25 = v25;
              v98 = *(float *)&v25 * v94;
              *(float *)&v24 = v24;
              v100 = *(float *)&v24 * v96;
              v101 = 0;
              v27 = (double *)(v85 + v84 * v22[1]);
              v28 = v27[2];
              *(float *)&v25 = v27[1];
              v29 = *v27;
              v102 = v29 * v94;
              v103 = *(float *)&v25 * v95;
              v104 = v28 * v96;
              v105 = 0;
              v30 = (double *)(v85 + v84 * v22[2]);
              v31 = v30[2];
              v32 = v30[1];
              v33 = *v30;
              v34 = callback->__vftable;
              v106 = (float)v33 * v94;
              v107 = (float)v32 * v95;
              v108 = (float)v31 * v96;
              v109 = 0;
              v34->internalProcessTriangleIndex(callback, (btVector3 *)&v98, v7, v8++);
            }
            while ( v8 < v86 );
          }
        }
        else if ( v89 == 5 && v86 > 0 )
        {
          do
          {
            v9 = (unsigned __int8 *)(v88 + v87 * v8);
            v10 = (double *)(v85 + v84 * *v9);
            v11 = v10[2];
            v12 = *v10;
            v13 = v10[1];
            v99 = v13 * v95;
            *(float *)&v12 = v12;
            v98 = *(float *)&v12 * v94;
            *(float *)&v11 = v11;
            v100 = *(float *)&v11 * v96;
            v101 = 0;
            v14 = (double *)(v85 + v84 * v9[1]);
            v15 = v14[2];
            *(float *)&v12 = v14[1];
            v16 = *v14;
            v102 = v16 * v94;
            v103 = *(float *)&v12 * v95;
            v104 = v15 * v96;
            v105 = 0;
            v17 = (double *)(v85 + v84 * v9[2]);
            v18 = v17[2];
            v19 = v17[1];
            v20 = *v17;
            v21 = callback->__vftable;
            v106 = (float)v20 * v94;
            v107 = (float)v19 * v95;
            v108 = (float)v18 * v96;
            v109 = 0;
            v21->internalProcessTriangleIndex(callback, (btVector3 *)&v98, v7, v8++);
          }
          while ( v8 < v86 );
        }
      }
    }
    else if ( v89 == 2 )
    {
      if ( v86 > 0 )
      {
        do
        {
          v72 = (_DWORD *)(v88 + v87 * v8);
          v73 = (float *)(v85 + v84 * *v72);
          v74 = v73[1] * v95;
          v75 = *v73 * v94;
          v100 = v73[2] * v96;
          v98 = v75;
          v99 = v74;
          v101 = 0;
          v76 = (float *)(v85 + v84 * v72[1]);
          v77 = v76[2] * v96;
          v78 = v76[1] * v95;
          v102 = *v76 * v94;
          v103 = v78;
          v104 = v77;
          v105 = 0;
          v79 = (float *)(v85 + v84 * v72[2]);
          v80 = v79[2] * v96;
          v81 = v79[1] * v95;
          v82 = *v79 * v94;
          v83 = callback->__vftable;
          v106 = v82;
          v107 = v81;
          v108 = v80;
          v109 = 0;
          v83->internalProcessTriangleIndex(callback, (btVector3 *)&v98, v7, v8++);
        }
        while ( v8 < v86 );
      }
    }
    else if ( v89 == 3 )
    {
      if ( v86 > 0 )
      {
        do
        {
          v60 = (unsigned __int16 *)(v88 + v87 * v8);
          v61 = (float *)(v85 + v84 * *v60);
          v62 = v61[1] * v95;
          v63 = *v61 * v94;
          v100 = v61[2] * v96;
          v98 = v63;
          v99 = v62;
          v101 = 0;
          v64 = (float *)(v85 + v84 * v60[1]);
          v65 = v64[2] * v96;
          v66 = v64[1] * v95;
          v102 = *v64 * v94;
          v103 = v66;
          v104 = v65;
          v105 = 0;
          v67 = (float *)(v85 + v84 * v60[2]);
          v68 = v67[2] * v96;
          v69 = v67[1] * v95;
          v70 = *v67 * v94;
          v71 = callback->__vftable;
          v106 = v70;
          v107 = v69;
          v108 = v68;
          v109 = 0;
          v71->internalProcessTriangleIndex(callback, (btVector3 *)&v98, v7, v8++);
        }
        while ( v8 < v86 );
      }
    }
    else if ( v89 == 5 && v86 > 0 )
    {
      do
      {
        v48 = (unsigned __int8 *)(v88 + v87 * v8);
        v49 = (float *)(v85 + v84 * *v48);
        v50 = v49[1] * v95;
        v51 = *v49 * v94;
        v100 = v49[2] * v96;
        v98 = v51;
        v99 = v50;
        v101 = 0;
        v52 = (float *)(v85 + v84 * v48[1]);
        v53 = v52[2] * v96;
        v54 = v52[1] * v95;
        v102 = *v52 * v94;
        v103 = v54;
        v104 = v53;
        v105 = 0;
        v55 = (float *)(v85 + v84 * v48[2]);
        v56 = v55[2] * v96;
        v57 = v55[1] * v95;
        v58 = *v55 * v94;
        v59 = callback->__vftable;
        v106 = v58;
        v107 = v57;
        v108 = v56;
        v109 = 0;
        v59->internalProcessTriangleIndex(callback, (btVector3 *)&v98, v7, v8++);
      }
      while ( v8 < v86 );
    }
    v90->unLockReadOnlyVertexBase(v90, v7);
  }
}
