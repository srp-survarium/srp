const char *__thiscall btStridingMeshInterface::serialize(
        btStridingMeshInterface *this,
        float *dataBuffer,
        btSerializer *serializer)
{
  btStridingMeshInterface *v3; // ebx
  int (__thiscall *getNumSubParts)(btStridingMeshInterface *); // edx
  int v5; // eax
  float *v6; // ecx
  btChunk *v7; // eax
  _DWORD *m_oldPtr; // edi
  btSerializer_vtbl *v9; // edx
  btChunk *v10; // eax
  btSerializer_vtbl *v11; // edx
  btChunk *v12; // ebx
  void *(__thiscall *v13)(btSerializer *, void *); // eax
  int v14; // eax
  int v15; // edx
  _BYTE *v16; // ecx
  _BYTE *v17; // eax
  btChunk *v18; // eax
  btSerializer_vtbl *v19; // edx
  btChunk *v20; // ebx
  void *(__thiscall *v21)(btSerializer *, void *); // eax
  int v22; // eax
  int v23; // edx
  _WORD *v24; // ecx
  _WORD *v25; // eax
  btChunk *v26; // eax
  btSerializer_vtbl *v27; // edx
  btChunk *v28; // ebx
  void *(__thiscall *getUniquePointer)(btSerializer *, void *); // eax
  int v30; // eax
  int v31; // edx
  _DWORD *v32; // ecx
  _DWORD *v33; // eax
  btChunk *v34; // eax
  btSerializer_vtbl *v35; // edx
  int v36; // eax
  int v37; // edx
  double *v38; // ecx
  double *v39; // eax
  btChunk *v40; // eax
  btSerializer_vtbl *v41; // edx
  btChunk *v42; // ebx
  int v43; // eax
  int v44; // edx
  float *v45; // ecx
  float *v46; // eax
  const char *result; // eax
  int v48; // [esp+208h] [ebp-38h] BYREF
  int v49; // [esp+20Ch] [ebp-34h] BYREF
  btStridingMeshInterface *v50; // [esp+210h] [ebp-30h]
  int i; // [esp+214h] [ebp-2Ch]
  int v52; // [esp+218h] [ebp-28h] BYREF
  int v53; // [esp+21Ch] [ebp-24h] BYREF
  int v54; // [esp+220h] [ebp-20h] BYREF
  int v55; // [esp+224h] [ebp-1Ch] BYREF
  int v56; // [esp+228h] [ebp-18h] BYREF
  btChunk *v57; // [esp+22Ch] [ebp-14h]
  char *v58; // [esp+230h] [ebp-10h]
  int v59; // [esp+234h] [ebp-Ch] BYREF
  int v60; // [esp+238h] [ebp-8h]
  btChunk *v61; // [esp+23Ch] [ebp-4h]

  v3 = this;
  getNumSubParts = this->getNumSubParts;
  v50 = this;
  v5 = ((int (__fastcall *)(btStridingMeshInterface *))getNumSubParts)(this);
  v6 = dataBuffer;
  *((_DWORD *)dataBuffer + 5) = v5;
  *dataBuffer = 0.0;
  if ( v5 )
  {
    v7 = serializer->allocate(serializer, 32, v5);
    m_oldPtr = v7->m_oldPtr;
    v9 = serializer->__vftable;
    v61 = v7;
    *(_DWORD *)dataBuffer = v9->getUniquePointer(serializer, m_oldPtr);
    v60 = v3->getNumSubParts(v3);
    for ( i = 0; i < v60; ++i )
    {
      v3->getLockedReadOnlyVertexIndexBase(
        v3,
        (const unsigned __int8 **)&v55,
        &v49,
        (PHY_ScalarType *)&v59,
        &v54,
        (const unsigned __int8 **)&v53,
        &v52,
        &v48,
        (PHY_ScalarType *)&v56,
        i);
      m_oldPtr[6] = v48;
      m_oldPtr[7] = v49;
      m_oldPtr[5] = 0;
      m_oldPtr[2] = 0;
      m_oldPtr[3] = 0;
      *m_oldPtr = 0;
      m_oldPtr[1] = 0;
      if ( v56 == 2 )
      {
        if ( 3 * v48 )
        {
          v26 = serializer->allocate(serializer, 4, 3 * v48);
          v27 = serializer->__vftable;
          v28 = v26;
          v58 = (char *)v26->m_oldPtr;
          getUniquePointer = v27->getUniquePointer;
          v57 = v28;
          v30 = (int)getUniquePointer(serializer, v58);
          v31 = 0;
          m_oldPtr[2] = v30;
          if ( v48 > 0 )
          {
            v32 = v58 + 8;
            do
            {
              v33 = (_DWORD *)(v53 + v52 * v31++);
              *(v32 - 2) = *v33;
              *(v32 - 1) = v33[1];
              *v32 = v33[2];
              v32 += 3;
            }
            while ( v31 < v48 );
            v28 = v57;
          }
          serializer->finalizeChunk(serializer, v28, "btIntIndexData", 1497453121, v28->m_oldPtr);
          goto LABEL_24;
        }
      }
      else
      {
        if ( v56 != 3 )
        {
          if ( v56 != 5 || !v48 )
            goto LABEL_25;
          v10 = serializer->allocate(serializer, 4, v48);
          v11 = serializer->__vftable;
          v12 = v10;
          v57 = (btChunk *)v10->m_oldPtr;
          v13 = v11->getUniquePointer;
          v58 = (char *)v12;
          v14 = (int)v13(serializer, v57);
          v15 = 0;
          m_oldPtr[4] = v14;
          if ( v48 > 0 )
          {
            v16 = (char *)&v57->m_chunkCode + 2;
            do
            {
              v17 = (_BYTE *)(v53 + v52 * v15++);
              *(v16 - 2) = *v17;
              *(v16 - 1) = v17[1];
              *v16 = v17[2];
              v16 += 4;
            }
            while ( v15 < v48 );
            v12 = (btChunk *)v58;
          }
          serializer->finalizeChunk(serializer, v12, "btCharIndexTripletData", 1497453121, v12->m_oldPtr);
          goto LABEL_24;
        }
        if ( v48 )
        {
          v18 = serializer->allocate(serializer, 8, v48);
          v19 = serializer->__vftable;
          v20 = v18;
          v58 = (char *)v18->m_oldPtr;
          v21 = v19->getUniquePointer;
          v57 = v20;
          v22 = (int)v21(serializer, v58);
          v23 = 0;
          m_oldPtr[3] = v22;
          if ( v48 > 0 )
          {
            v24 = v58 + 4;
            do
            {
              v25 = (_WORD *)(v53 + v52 * v23++);
              *(v24 - 2) = *v25;
              *(v24 - 1) = v25[1];
              *v24 = v25[2];
              v24 += 4;
            }
            while ( v23 < v48 );
            v20 = v57;
          }
          serializer->finalizeChunk(serializer, v20, "btShortIntIndexTripletData", 1497453121, v20->m_oldPtr);
LABEL_24:
          v3 = v50;
        }
      }
LABEL_25:
      if ( v59 )
      {
        if ( v59 == 1 && v49 )
        {
          v34 = serializer->allocate(serializer, 32, v49);
          v35 = serializer->__vftable;
          v57 = v34;
          v58 = (char *)v34->m_oldPtr;
          v36 = (int)v35->getUniquePointer(serializer, v58);
          v37 = 0;
          m_oldPtr[1] = v36;
          if ( v49 > 0 )
          {
            v38 = (double *)(v58 + 16);
            do
            {
              v39 = (double *)(v55 + v54 * v37++);
              v38 += 4;
              *(v38 - 6) = *v39;
              *(v38 - 5) = v39[1];
              *(v38 - 4) = v39[2];
            }
            while ( v37 < v49 );
          }
          serializer->finalizeChunk(serializer, v57, "btVector3DoubleData", 1497453121, v57->m_oldPtr);
        }
      }
      else if ( v49 )
      {
        v40 = serializer->allocate(serializer, 16, v49);
        v41 = serializer->__vftable;
        v42 = v40;
        v58 = (char *)v40->m_oldPtr;
        v43 = (int)v41->getUniquePointer(serializer, v58);
        v44 = 0;
        *m_oldPtr = v43;
        if ( v49 > 0 )
        {
          v45 = (float *)(v58 + 8);
          do
          {
            v46 = (float *)(v55 + v54 * v44++);
            v45 += 4;
            *(v45 - 6) = *v46;
            *(v45 - 5) = v46[1];
            *(v45 - 4) = v46[2];
          }
          while ( v44 < v49 );
        }
        serializer->finalizeChunk(serializer, v42, "btVector3FloatData", 1497453121, v42->m_oldPtr);
        v3 = v50;
      }
      v3->unLockReadOnlyVertexBase(v3, i);
      m_oldPtr += 8;
    }
    serializer->finalizeChunk(serializer, v61, "btMeshPartData", 1497453121, v61->m_oldPtr);
    v6 = dataBuffer;
  }
  v6[1] = v3->m_scaling.mVec128.m128_f32[0];
  result = "btStridingMeshInterfaceData";
  v6[2] = v3->m_scaling.mVec128.m128_f32[1];
  v6[3] = v3->m_scaling.mVec128.m128_f32[2];
  v6[4] = v3->m_scaling.mVec128.m128_f32[3];
  return result;
}
