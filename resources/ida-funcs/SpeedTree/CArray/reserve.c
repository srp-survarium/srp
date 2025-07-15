bool __thiscall SpeedTree::CArray<char,1>::reserve(int this, unsigned int siNumElements)
{
  char *pRawBlock; // [esp+Ch] [ebp-40h] BYREF
  unsigned int i; // [esp+3Ch] [ebp-10h]
  char *v6; // [esp+40h] [ebp-Ch]
  char *v7; // [esp+44h] [ebp-8h]
  char *v8; // [esp+48h] [ebp-4h]

  if ( *(_BYTE *)(this + 16) )
    return *(_DWORD *)(this + 12) >= siNumElements;
  if ( siNumElements > *(_DWORD *)(this + 12) )
  {
    v8 = SpeedTree::st_new_array<char>(siNumElements);
    if ( *(_DWORD *)(this + 8) )
    {
      v6 = v8;
      v7 = *(char **)(this + 4);
      for ( i = 0; i < *(_DWORD *)(this + 8); ++i )
        *v6++ = *v7++;
    }
    pRawBlock = *(char **)(this + 4);
    SpeedTree::st_delete_array<char>(&pRawBlock);
    *(_DWORD *)(this + 4) = v8;
    *(_DWORD *)(this + 12) = siNumElements;
  }
  return 1;
}


bool __thiscall SpeedTree::CArray<unsigned char,1>::reserve(int this, unsigned int count)
{
  _DWORD v4[4]; // [esp+Ch] [ebp-40h] BYREF
  unsigned int i; // [esp+3Ch] [ebp-10h]
  unsigned int *v6; // [esp+40h] [ebp-Ch]
  _BYTE *v7; // [esp+44h] [ebp-8h]
  unsigned int *v8; // [esp+48h] [ebp-4h]

  if ( *(_BYTE *)(this + 16) )
    return *(_DWORD *)(this + 12) >= count;
  if ( count > *(_DWORD *)(this + 12) )
  {
    v8 = SpeedTree::st_new_array<unsigned char>(count);
    if ( *(_DWORD *)(this + 8) )
    {
      v6 = v8;
      v7 = *(_BYTE **)(this + 4);
      for ( i = 0; i < *(_DWORD *)(this + 8); ++i )
      {
        *(_BYTE *)v6 = *v7;
        v6 = (unsigned int *)((char *)v6 + 1);
        ++v7;
      }
    }
    v4[0] = *(_DWORD *)(this + 4);
    SpeedTree::st_delete_array<unsigned char>(v4);
    *(_DWORD *)(this + 4) = v8;
    *(_DWORD *)(this + 12) = count;
  }
  return 1;
}


bool __thiscall SpeedTree::CArray<int,1>::reserve(int this, unsigned int a2)
{
  _DWORD v4[4]; // [esp+8h] [ebp-40h] BYREF
  unsigned int i; // [esp+38h] [ebp-10h]
  _DWORD *v6; // [esp+3Ch] [ebp-Ch]
  _DWORD *v7; // [esp+40h] [ebp-8h]
  int v8; // [esp+44h] [ebp-4h]

  if ( *(_BYTE *)(this + 16) )
    return *(_DWORD *)(this + 12) >= a2;
  if ( a2 > *(_DWORD *)(this + 12) )
  {
    v8 = SpeedTree::CArray<float,1>::Allocate(a2);
    if ( *(_DWORD *)(this + 8) )
    {
      v6 = (_DWORD *)v8;
      v7 = *(_DWORD **)(this + 4);
      for ( i = 0; i < *(_DWORD *)(this + 8); ++i )
        *v6++ = *v7++;
    }
    v4[0] = *(_DWORD *)(this + 4);
    SpeedTree::st_delete_array<float>(v4);
    *(_DWORD *)(this + 4) = v8;
    *(_DWORD *)(this + 12) = a2;
  }
  return 1;
}


bool __thiscall SpeedTree::CArray<float,1>::reserve(int this, unsigned int a2)
{
  _DWORD v4[4]; // [esp+8h] [ebp-40h] BYREF
  unsigned int i; // [esp+38h] [ebp-10h]
  float *v6; // [esp+3Ch] [ebp-Ch]
  float *v7; // [esp+40h] [ebp-8h]
  float *v8; // [esp+44h] [ebp-4h]

  if ( *(_BYTE *)(this + 16) )
    return *(_DWORD *)(this + 12) >= a2;
  if ( a2 > *(_DWORD *)(this + 12) )
  {
    v8 = (float *)SpeedTree::CArray<float,1>::Allocate(a2);
    if ( *(_DWORD *)(this + 8) )
    {
      v6 = v8;
      v7 = *(float **)(this + 4);
      for ( i = 0; i < *(_DWORD *)(this + 8); ++i )
        *v6++ = *v7++;
    }
    v4[0] = *(_DWORD *)(this + 4);
    SpeedTree::st_delete_array<float>(v4);
    *(_DWORD *)(this + 4) = v8;
    *(_DWORD *)(this + 12) = a2;
  }
  return 1;
}


bool __thiscall SpeedTree::CArray<void *,1>::reserve(int this, unsigned int a2)
{
  void **pRawBlock; // [esp+8h] [ebp-40h] BYREF
  unsigned int i; // [esp+38h] [ebp-10h]
  _DWORD *v6; // [esp+3Ch] [ebp-Ch]
  _DWORD *v7; // [esp+40h] [ebp-8h]
  _DWORD *v8; // [esp+44h] [ebp-4h]

  if ( *(_BYTE *)(this + 16) )
    return *(_DWORD *)(this + 12) >= a2;
  if ( a2 > *(_DWORD *)(this + 12) )
  {
    v8 = (_DWORD *)SpeedTree::CArray<float,1>::Allocate(a2);
    if ( *(_DWORD *)(this + 8) )
    {
      v6 = v8;
      v7 = *(_DWORD **)(this + 4);
      for ( i = 0; i < *(_DWORD *)(this + 8); ++i )
        *v6++ = *v7++;
    }
    pRawBlock = *(void ***)(this + 4);
    SpeedTree::st_delete_array<unsigned int>(&pRawBlock);
    *(_DWORD *)(this + 4) = v8;
    *(_DWORD *)(this + 12) = a2;
  }
  return 1;
}


bool __thiscall SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::reserve(
        SpeedTree::CArray<SpeedTree::CCore *,1> *this,
        unsigned int uiSize)
{
  SpeedTree::CCore **v4; // eax
  SpeedTree::CCore **v5; // ebx
  SpeedTree::CCore **m_pData; // ecx
  unsigned int v7; // edx
  SpeedTree::CCore **v8; // eax
  _DWORD *v9; // eax

  if ( this->m_bExternalMemory )
    return this->m_uiDataSize >= uiSize;
  if ( uiSize > this->m_uiDataSize )
  {
    v4 = SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::Allocate(this, uiSize);
    v5 = v4;
    if ( this->m_uiSize )
    {
      m_pData = this->m_pData;
      v7 = 0;
      do
      {
        *v4 = *m_pData;
        ++v7;
        ++v4;
        ++m_pData;
      }
      while ( v7 < this->m_uiSize );
    }
    v8 = this->m_pData;
    if ( v8 )
    {
      v9 = v8 - 1;
      if ( v9 )
      {
        SpeedTree::g_siHeapMemoryUsed += -4 - 4 * *v9;
        if ( SpeedTree::g_pAllocator )
          SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, v9);
      }
    }
    this->m_pData = v5;
    this->m_uiDataSize = uiSize;
  }
  return 1;
}


bool __thiscall SpeedTree::CArray<SpeedTree::SInstanceLod,1>::reserve(int this, unsigned int a2)
{
  SpeedTree::SInstanceLod *pRawBlock; // [esp+10h] [ebp-5Ch] BYREF
  unsigned int i; // [esp+5Ch] [ebp-10h]
  char *v6; // [esp+60h] [ebp-Ch]
  char *v7; // [esp+64h] [ebp-8h]
  char *v8; // [esp+68h] [ebp-4h]

  if ( *(_BYTE *)(this + 16) )
    return *(_DWORD *)(this + 12) >= a2;
  if ( a2 > *(_DWORD *)(this + 12) )
  {
    v8 = (char *)SpeedTree::CArray<SpeedTree::SInstanceLod,1>::Allocate(a2);
    if ( *(_DWORD *)(this + 8) )
    {
      v6 = v8;
      v7 = *(char **)(this + 4);
      for ( i = 0; i < *(_DWORD *)(this + 8); ++i )
      {
        qmemcpy(v6, v7, 0x20u);
        v6 += 32;
        v7 += 32;
      }
    }
    pRawBlock = *(SpeedTree::SInstanceLod **)(this + 4);
    SpeedTree::st_delete_array<SpeedTree::SInstanceLod>(&pRawBlock);
    *(_DWORD *)(this + 4) = v8;
    *(_DWORD *)(this + 12) = a2;
  }
  return 1;
}


bool __thiscall SpeedTree::CArray<SpeedTree::CInstance,1>::reserve(
        SpeedTree::CArray<SpeedTree::CInstance,1> *this,
        SpeedTree::CInstance *uiSize)
{
  unsigned int v4; // ebp
  SpeedTree::CInstance *v5; // eax
  SpeedTree::CInstance *v6; // ebx
  SpeedTree::CInstance *m_pData; // ecx
  unsigned int v8; // edx

  if ( this->m_bExternalMemory )
    return this->m_uiDataSize >= (unsigned int)uiSize;
  v4 = (unsigned int)uiSize;
  if ( (unsigned int)uiSize > this->m_uiDataSize )
  {
    v5 = SpeedTree::st_new_array<SpeedTree::CInstance>((unsigned int)uiSize, "CArray");
    v6 = v5;
    if ( this->m_uiSize )
    {
      m_pData = this->m_pData;
      v8 = 0;
      do
      {
        *(_QWORD *)&v5->m_vPos.x = *(_QWORD *)&m_pData->m_vPos.x;
        *(_QWORD *)&v5->m_vPos.z = *(_QWORD *)&m_pData->m_vPos.z;
        *(_QWORD *)&v5->m_vGeometricCenter.x = *(_QWORD *)&m_pData->m_vGeometricCenter.x;
        *(_QWORD *)&v5->m_vGeometricCenter.z = *(_QWORD *)&m_pData->m_vGeometricCenter.z;
        *(_DWORD *)v5->m_anRotationVector = *(_DWORD *)m_pData->m_anRotationVector;
        ++v8;
        ++v5;
        ++m_pData;
      }
      while ( v8 < this->m_uiSize );
    }
    uiSize = this->m_pData;
    SpeedTree::st_delete_array<SpeedTree::CInstance>(&uiSize);
    this->m_pData = v6;
    this->m_uiDataSize = v4;
  }
  return 1;
}


bool __userpurge SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1>::reserve@<al>(
        SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1> *this@<ecx>,
        int a2@<edi>,
        unsigned int uiSize)
{
  SpeedTree::CArray<SpeedTree::CInstance,1> *v4; // eax
  int v5; // ecx
  const SpeedTree::CArray<SpeedTree::CInstance,1> *v6; // ebx
  unsigned int v7; // ebp
  SpeedTree::CArray<SpeedTree::CInstance,1> *v8; // esi
  SpeedTree::CArray<SpeedTree::CInstance,1> *pRawBlock; // [esp+0h] [ebp-8h] BYREF
  SpeedTree::CArray<SpeedTree::CInstance,1> *pNewData; // [esp+4h] [ebp-4h]

  if ( *(_BYTE *)(a2 + 16) )
    return *(_DWORD *)(a2 + 12) >= uiSize;
  if ( uiSize > *(_DWORD *)(a2 + 12) )
  {
    v4 = SpeedTree::st_new_array<SpeedTree::CArray<SpeedTree::CInstance,1>>(uiSize);
    v5 = *(_DWORD *)(a2 + 8);
    pNewData = v4;
    if ( v5 )
    {
      v6 = *(const SpeedTree::CArray<SpeedTree::CInstance,1> **)(a2 + 4);
      v7 = 0;
      v8 = v4;
      do
      {
        SpeedTree::CArray<SpeedTree::CInstance,1>::operator=(v8, v6);
        ++v7;
        ++v8;
        ++v6;
      }
      while ( v7 < *(_DWORD *)(a2 + 8) );
    }
    pRawBlock = *(SpeedTree::CArray<SpeedTree::CInstance,1> **)(a2 + 4);
    SpeedTree::st_delete_array<SpeedTree::CArray<SpeedTree::CInstance,1>>(&pRawBlock);
    *(_DWORD *)(a2 + 4) = pNewData;
    *(_DWORD *)(a2 + 12) = uiSize;
  }
  return 1;
}
