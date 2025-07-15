char __thiscall SpeedTree::CArray<int,1>::push_back(int this, _DWORD *a2)
{
  char v4; // [esp+47h] [ebp-1h]

  v4 = 1;
  if ( *(_BYTE *)(this + 16) )
  {
    if ( *(_DWORD *)(this + 8) >= *(_DWORD *)(this + 12) )
      return 0;
    else
      *(_DWORD *)(*(_DWORD *)(this + 4) + 4 * (*(_DWORD *)(this + 8))++) = *a2;
  }
  else
  {
    if ( *(_DWORD *)(this + 8) == *(_DWORD *)(this + 12) )
    {
      if ( *(_DWORD *)(this + 12) < 8u )
        *(_DWORD *)(this + 12) = 8;
      SpeedTree::CArray<int,1>::reserve(2 * *(_DWORD *)(this + 12) + 1);
    }
    *(_DWORD *)(*(_DWORD *)(this + 4) + 4 * (*(_DWORD *)(this + 8))++) = *a2;
  }
  return v4;
}


char __thiscall SpeedTree::CArray<float,1>::push_back(int this, float *a2)
{
  char v4; // [esp+47h] [ebp-1h]

  v4 = 1;
  if ( *(_BYTE *)(this + 16) )
  {
    if ( *(_DWORD *)(this + 8) >= *(_DWORD *)(this + 12) )
      return 0;
    else
      *(float *)(*(_DWORD *)(this + 4) + 4 * (*(_DWORD *)(this + 8))++) = *a2;
  }
  else
  {
    if ( *(_DWORD *)(this + 8) == *(_DWORD *)(this + 12) )
    {
      if ( *(_DWORD *)(this + 12) < 8u )
        *(_DWORD *)(this + 12) = 8;
      SpeedTree::CArray<float,1>::reserve(this, 2 * *(_DWORD *)(this + 12) + 1);
    }
    *(float *)(*(_DWORD *)(this + 4) + 4 * (*(_DWORD *)(this + 8))++) = *a2;
  }
  return v4;
}


char __thiscall SpeedTree::CArray<SpeedTree::CCore *,1>::push_back(
        SpeedTree::CArray<SpeedTree::CCore *,1> *this,
        SpeedTree::CCore *const *tNew)
{
  unsigned int m_uiSize; // eax
  unsigned int m_uiDataSize; // eax

  if ( this->m_bExternalMemory )
  {
    m_uiSize = this->m_uiSize;
    if ( m_uiSize >= this->m_uiDataSize )
    {
      return 0;
    }
    else
    {
      this->m_pData[m_uiSize] = *tNew;
      ++this->m_uiSize;
      return 1;
    }
  }
  else
  {
    m_uiDataSize = this->m_uiDataSize;
    if ( this->m_uiSize == m_uiDataSize )
    {
      if ( m_uiDataSize < 8 )
        this->m_uiDataSize = 8;
      SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::reserve(this, 2 * this->m_uiDataSize + 1);
    }
    this->m_pData[this->m_uiSize++] = *tNew;
    return 1;
  }
}


char __thiscall SpeedTree::CArray<SpeedTree::CGrassCell *,1>::push_back(int this, _DWORD *a2)
{
  char v4; // [esp+47h] [ebp-1h]

  v4 = 1;
  if ( *(_BYTE *)(this + 16) )
  {
    if ( *(_DWORD *)(this + 8) >= *(_DWORD *)(this + 12) )
      return 0;
    else
      *(_DWORD *)(*(_DWORD *)(this + 4) + 4 * (*(_DWORD *)(this + 8))++) = *a2;
  }
  else
  {
    if ( *(_DWORD *)(this + 8) == *(_DWORD *)(this + 12) )
    {
      if ( *(_DWORD *)(this + 12) < 8u )
        *(_DWORD *)(this + 12) = 8;
      SpeedTree::CArray<void *,1>::reserve(this, 2 * *(_DWORD *)(this + 12) + 1);
    }
    *(_DWORD *)(*(_DWORD *)(this + 4) + 4 * (*(_DWORD *)(this + 8))++) = *a2;
  }
  return v4;
}


char __thiscall SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::push_back(
        SpeedTree::CArray<SpeedTree::CCore *,1> *this,
        SpeedTree::CCore **a2)
{
  char v4; // [esp+47h] [ebp-1h]

  v4 = 1;
  if ( this->m_bExternalMemory )
  {
    if ( this->m_uiSize >= this->m_uiDataSize )
      return 0;
    else
      this->m_pData[this->m_uiSize++] = *a2;
  }
  else
  {
    if ( this->m_uiSize == this->m_uiDataSize )
    {
      if ( this->m_uiDataSize < 8 )
        this->m_uiDataSize = 8;
      SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::reserve(this, 2 * this->m_uiDataSize + 1);
    }
    this->m_pData[this->m_uiSize++] = *a2;
  }
  return v4;
}


char __thiscall SpeedTree::CArray<SpeedTree::SInstanceLod,1>::push_back(int this, const void *a2)
{
  char v4; // [esp+6Bh] [ebp-1h]

  v4 = 1;
  if ( *(_BYTE *)(this + 16) )
  {
    if ( *(_DWORD *)(this + 8) >= *(_DWORD *)(this + 12) )
      return 0;
    else
      qmemcpy((void *)(32 * (*(_DWORD *)(this + 8))++ + *(_DWORD *)(this + 4)), a2, 0x20u);
  }
  else
  {
    if ( *(_DWORD *)(this + 8) == *(_DWORD *)(this + 12) )
    {
      if ( *(_DWORD *)(this + 12) < 8u )
        *(_DWORD *)(this + 12) = 8;
      SpeedTree::CArray<SpeedTree::SInstanceLod,1>::reserve(2 * *(_DWORD *)(this + 12) + 1);
    }
    qmemcpy((void *)(32 * (*(_DWORD *)(this + 8))++ + *(_DWORD *)(this + 4)), a2, 0x20u);
  }
  return v4;
}


char __thiscall SpeedTree::CArray<SpeedTree::CInstance,1>::push_back(
        SpeedTree::CArray<SpeedTree::CInstance,1> *this,
        const SpeedTree::CInstance *tNew)
{
  unsigned int m_uiSize; // eax
  unsigned int m_uiDataSize; // eax
  unsigned int v6; // edx
  SpeedTree::CInstance *m_pData; // eax
  SpeedTree::CInstance *v8; // eax

  if ( this->m_bExternalMemory )
  {
    m_uiSize = this->m_uiSize;
    if ( m_uiSize >= this->m_uiDataSize )
    {
      return 0;
    }
    else
    {
      this->m_pData[m_uiSize] = *tNew;
      ++this->m_uiSize;
      return 1;
    }
  }
  else
  {
    m_uiDataSize = this->m_uiDataSize;
    if ( this->m_uiSize == m_uiDataSize )
    {
      if ( m_uiDataSize < 8 )
        this->m_uiDataSize = 8;
      SpeedTree::CArray<SpeedTree::CInstance,1>::reserve(this, (SpeedTree::CInstance *)(2 * this->m_uiDataSize + 1));
    }
    v6 = this->m_uiSize;
    m_pData = this->m_pData;
    *(_QWORD *)&m_pData[v6].m_vPos.x = *(_QWORD *)&tNew->m_vPos.x;
    v8 = &m_pData[v6];
    *(_QWORD *)&v8->m_vPos.z = *(_QWORD *)&tNew->m_vPos.z;
    *(_QWORD *)&v8->m_vGeometricCenter.x = *(_QWORD *)&tNew->m_vGeometricCenter.x;
    *(_QWORD *)&v8->m_vGeometricCenter.z = *(_QWORD *)&tNew->m_vGeometricCenter.z;
    *(_DWORD *)v8->m_anRotationVector = *(_DWORD *)tNew->m_anRotationVector;
    ++this->m_uiSize;
    return 1;
  }
}


char __userpurge SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1>::push_back@<al>(
        SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1> *this@<ecx>,
        int a2@<eax>,
        const SpeedTree::CArray<SpeedTree::CInstance,1> *tNew)
{
  unsigned int v4; // eax
  int v5; // edx
  unsigned int v7; // eax
  int v8; // eax
  int v9; // ecx

  if ( *(_BYTE *)(a2 + 16) )
  {
    v4 = *(_DWORD *)(a2 + 8);
    if ( v4 >= *(_DWORD *)(a2 + 12) )
    {
      return 0;
    }
    else
    {
      v5 = *(_DWORD *)(a2 + 4);
      *(_DWORD *)(a2 + 8) = v4 + 1;
      SpeedTree::CArray<SpeedTree::CInstance,1>::operator=(
        (SpeedTree::CArray<SpeedTree::CInstance,1> *)(v5 + 20 * v4),
        tNew);
      return 1;
    }
  }
  else
  {
    v7 = *(_DWORD *)(a2 + 12);
    if ( *(_DWORD *)(a2 + 8) == v7 )
    {
      if ( v7 < 8 )
        *(_DWORD *)(a2 + 12) = 8;
      SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1>::reserve(
        (SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1> *)(2 * *(_DWORD *)(a2 + 12) + 1),
        2 * *(_DWORD *)(a2 + 12) + 1);
    }
    v8 = *(_DWORD *)(a2 + 8);
    v9 = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(a2 + 8) = v8 + 1;
    SpeedTree::CArray<SpeedTree::CInstance,1>::operator=(
      (SpeedTree::CArray<SpeedTree::CInstance,1> *)(v9 + 20 * v8),
      tNew);
    return 1;
  }
}
