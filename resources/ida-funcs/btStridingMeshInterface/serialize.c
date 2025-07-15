const char *__thiscall btStridingMeshInterface::serialize(
        btStridingMeshInterface *this,
        _DWORD *dataBuffer,
        btSerializer *serializer)
{
  btStridingMeshInterface *v3; // ebx
  btStridingMeshInterface_vtbl *v4; // eax
  int v5; // eax
  _DWORD *v6; // ecx
  btChunk *v7; // eax
  _DWORD *m_oldPtr; // edi
  int v9; // eax
  btChunk *v10; // eax
  btSerializer_vtbl *v11; // edx
  _BYTE *v12; // ecx
  _BYTE *v13; // eax
  btChunk *v14; // eax
  btSerializer_vtbl *v15; // edx
  int *p_m_length; // ecx
  _WORD *v17; // eax
  btChunk *v18; // eax
  btSerializer_vtbl *v19; // edx
  btChunk *v20; // ebx
  void **p_m_oldPtr; // ecx
  void **v22; // eax
  btChunk *v23; // eax
  btSerializer_vtbl *v24; // edx
  int v25; // eax
  int v26; // edx
  double *p_m_number; // ecx
  double *v28; // eax
  btChunk *v29; // eax
  btSerializer_vtbl *v30; // edx
  btChunk *v31; // ebx
  int v32; // eax
  int v33; // edx
  float *v34; // ecx
  float *v35; // eax
  float *v36; // eax
  float *m128_f32; // ebx
  int v38; // ecx
  double v39; // st7
  int v41; // [esp+60h] [ebp-3Ch]
  int v42; // [esp+60h] [ebp-3Ch]
  int v43; // [esp+60h] [ebp-3Ch]
  int v44; // [esp+64h] [ebp-38h] BYREF
  int v45; // [esp+68h] [ebp-34h] BYREF
  int v46; // [esp+6Ch] [ebp-30h]
  int v47; // [esp+70h] [ebp-2Ch] BYREF
  int v48; // [esp+74h] [ebp-28h] BYREF
  int v49; // [esp+78h] [ebp-24h] BYREF
  int v50; // [esp+7Ch] [ebp-20h] BYREF
  btStridingMeshInterface *v51; // [esp+80h] [ebp-1Ch]
  int v52; // [esp+84h] [ebp-18h] BYREF
  btChunk *v53; // [esp+88h] [ebp-14h]
  btChunk *v54; // [esp+8Ch] [ebp-10h]
  int v55; // [esp+90h] [ebp-Ch] BYREF
  int i; // [esp+94h] [ebp-8h]
  btChunk *v57; // [esp+98h] [ebp-4h]

  v3 = this;
  v4 = this->__vftable;
  v51 = this;
  v5 = ((int (__fastcall *)(btStridingMeshInterface *))v4->getNumSubParts)(this);
  v6 = dataBuffer;
  *dataBuffer = 0;
  dataBuffer[5] = v5;
  if ( v5 )
  {
    v7 = serializer->allocate(serializer, 32, v5);
    m_oldPtr = v7->m_oldPtr;
    v57 = v7;
    *dataBuffer = serializer->getUniquePointer(serializer, m_oldPtr);
    v9 = v3->getNumSubParts(v3);
    v46 = 0;
    for ( i = v9; v46 < i; m_oldPtr += 8 )
    {
      v3->getLockedReadOnlyVertexIndexBase(
        v3,
        (const unsigned __int8 **)&v50,
        &v45,
        (PHY_ScalarType *)&v55,
        &v49,
        (const unsigned __int8 **)&v48,
        &v47,
        &v44,
        (PHY_ScalarType *)&v52,
        v46);
      m_oldPtr[6] = v44;
      m_oldPtr[7] = v45;
      m_oldPtr[5] = 0;
      m_oldPtr[2] = 0;
      m_oldPtr[3] = 0;
      *m_oldPtr = 0;
      m_oldPtr[1] = 0;
      if ( v52 == 2 )
      {
        if ( 3 * v44 )
        {
          v18 = serializer->allocate(serializer, 4, 3 * v44);
          v19 = serializer->__vftable;
          v20 = v18;
          v54 = (btChunk *)v18->m_oldPtr;
          v43 = 0;
          m_oldPtr[2] = v19->getUniquePointer(serializer, v54);
          if ( v44 > 0 )
          {
            p_m_oldPtr = &v54->m_oldPtr;
            do
            {
              v22 = (void **)(v48 + v47 * v43++);
              *(p_m_oldPtr - 2) = *v22;
              *(p_m_oldPtr - 1) = v22[1];
              *p_m_oldPtr = v22[2];
              p_m_oldPtr += 3;
            }
            while ( v43 < v44 );
          }
          serializer->finalizeChunk(serializer, v20, "btIntIndexData", 1497453121, v20->m_oldPtr);
          v3 = v51;
        }
      }
      else if ( v52 == 3 )
      {
        if ( v44 )
        {
          v14 = serializer->allocate(serializer, 8, v44);
          v15 = serializer->__vftable;
          v53 = v14;
          v54 = (btChunk *)v14->m_oldPtr;
          v42 = 0;
          m_oldPtr[3] = v15->getUniquePointer(serializer, v54);
          if ( v44 > 0 )
          {
            p_m_length = &v54->m_length;
            do
            {
              v17 = (_WORD *)(v48 + v47 * v42++);
              *((_WORD *)p_m_length - 2) = *v17;
              *((_WORD *)p_m_length - 1) = v17[1];
              *(_WORD *)p_m_length = v17[2];
              p_m_length += 2;
            }
            while ( v42 < v44 );
          }
          serializer->finalizeChunk(serializer, v53, "btShortIntIndexTripletData", 1497453121, v53->m_oldPtr);
        }
      }
      else if ( v52 == 5 && v44 )
      {
        v10 = serializer->allocate(serializer, 4, v44);
        v11 = serializer->__vftable;
        v54 = v10;
        v53 = (btChunk *)v10->m_oldPtr;
        v41 = 0;
        m_oldPtr[4] = v11->getUniquePointer(serializer, v53);
        if ( v44 > 0 )
        {
          v12 = (char *)&v53->m_chunkCode + 2;
          do
          {
            v13 = (_BYTE *)(v48 + v47 * v41++);
            *(v12 - 2) = *v13;
            *(v12 - 1) = v13[1];
            *v12 = v13[2];
            v12 += 4;
          }
          while ( v41 < v44 );
        }
        serializer->finalizeChunk(serializer, v54, "btCharIndexTripletData", 1497453121, v54->m_oldPtr);
      }
      if ( v55 )
      {
        if ( v55 == 1 && v45 )
        {
          v23 = serializer->allocate(serializer, 32, v45);
          v24 = serializer->__vftable;
          v53 = v23;
          v54 = (btChunk *)v23->m_oldPtr;
          v25 = (int)v24->getUniquePointer(serializer, v54);
          v26 = 0;
          m_oldPtr[1] = v25;
          if ( v45 > 0 )
          {
            p_m_number = (double *)&v54->m_number;
            do
            {
              v28 = (double *)(v50 + v49 * v26++);
              *(p_m_number - 2) = *v28;
              *(p_m_number - 1) = v28[1];
              *p_m_number = v28[2];
              p_m_number += 4;
            }
            while ( v26 < v45 );
          }
          serializer->finalizeChunk(serializer, v53, "btVector3DoubleData", 1497453121, v53->m_oldPtr);
        }
      }
      else if ( v45 )
      {
        v29 = serializer->allocate(serializer, 16, v45);
        v30 = serializer->__vftable;
        v31 = v29;
        v54 = (btChunk *)v29->m_oldPtr;
        v32 = (int)v30->getUniquePointer(serializer, v54);
        v33 = 0;
        *m_oldPtr = v32;
        if ( v45 > 0 )
        {
          v34 = (float *)&v54->m_oldPtr;
          do
          {
            v35 = (float *)(v50 + v49 * v33++);
            *(v34 - 2) = *v35;
            *(v34 - 1) = v35[1];
            *v34 = v35[2];
            v34 += 4;
          }
          while ( v33 < v45 );
        }
        serializer->finalizeChunk(serializer, v31, "btVector3FloatData", 1497453121, v31->m_oldPtr);
        v3 = v51;
      }
      v3->unLockReadOnlyVertexBase(v3, v46++);
    }
    serializer->finalizeChunk(serializer, v57, "btMeshPartData", 1497453121, v57->m_oldPtr);
    v6 = dataBuffer;
  }
  v36 = (float *)(v6 + 1);
  m128_f32 = v3->m_scaling.mVec128.m128_f32;
  v38 = 4;
  do
  {
    v39 = *m128_f32++;
    *v36++ = v39;
    --v38;
  }
  while ( v38 );
  return "btStridingMeshInterfaceData";
}
