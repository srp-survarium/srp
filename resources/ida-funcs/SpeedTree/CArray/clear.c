int __thiscall SpeedTree::CArray<char,1>::clear(int this)
{
  int result; // eax
  char *pRawBlock; // [esp+8h] [ebp-14h] BYREF

  result = this;
  if ( !*(_BYTE *)(this + 16) )
  {
    pRawBlock = *(char **)(this + 4);
    SpeedTree::st_delete_array<char>(&pRawBlock);
    result = this;
    *(_DWORD *)(this + 4) = 0;
    *(_DWORD *)(this + 12) = 0;
  }
  *(_DWORD *)(this + 8) = 0;
  return result;
}


int __thiscall SpeedTree::CArray<unsigned char,1>::clear(int this)
{
  int result; // eax
  _DWORD v3[4]; // [esp+8h] [ebp-14h] BYREF

  result = this;
  if ( !*(_BYTE *)(this + 16) )
  {
    v3[0] = *(_DWORD *)(this + 4);
    SpeedTree::st_delete_array<unsigned char>(v3);
    result = this;
    *(_DWORD *)(this + 4) = 0;
    *(_DWORD *)(this + 12) = 0;
  }
  *(_DWORD *)(this + 8) = 0;
  return result;
}


int __thiscall SpeedTree::CArray<int,1>::clear(int this)
{
  int result; // eax
  _DWORD v3[4]; // [esp+8h] [ebp-14h] BYREF

  result = this;
  if ( !*(_BYTE *)(this + 16) )
  {
    v3[0] = *(_DWORD *)(this + 4);
    SpeedTree::st_delete_array<float>(v3);
    result = this;
    *(_DWORD *)(this + 4) = 0;
    *(_DWORD *)(this + 12) = 0;
  }
  *(_DWORD *)(this + 8) = 0;
  return result;
}


void __usercall SpeedTree::CArray<void *,1>::clear(SpeedTree::CArray<void *,1> *this@<ecx>, int a2@<esi>)
{
  int v2; // eax
  _DWORD *v3; // eax

  if ( !*(_BYTE *)(a2 + 16) )
  {
    v2 = *(_DWORD *)(a2 + 4);
    if ( v2 )
    {
      v3 = (_DWORD *)(v2 - 4);
      if ( v3 )
      {
        SpeedTree::g_siHeapMemoryUsed += -4 - 4 * *v3;
        if ( SpeedTree::g_pAllocator )
          SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, v3);
      }
    }
    *(_DWORD *)(a2 + 4) = 0;
    *(_DWORD *)(a2 + 12) = 0;
  }
  *(_DWORD *)(a2 + 8) = 0;
}


void __thiscall SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::clear(SpeedTree::CArray<SpeedTree::CCore *,1> *this)
{
  SpeedTree::CCore **m_pData; // eax
  _DWORD *v3; // eax

  if ( !this->m_bExternalMemory )
  {
    m_pData = this->m_pData;
    if ( m_pData )
    {
      v3 = m_pData - 1;
      if ( v3 )
      {
        SpeedTree::g_siHeapMemoryUsed += -4 - 4 * *v3;
        if ( SpeedTree::g_pAllocator )
          SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, v3);
      }
    }
    this->m_pData = 0;
    this->m_uiDataSize = 0;
  }
  this->m_uiSize = 0;
}


void __thiscall SpeedTree::CArray<SpeedTree::SInstanceLod,1>::clear(SpeedTree::CArray<SpeedTree::SInstanceLod,1> *this)
{
  SpeedTree::SInstanceLod *m_pData; // eax
  SpeedTree::SLodSnapshot *p_m_sLodSnapshot; // eax

  if ( !this->m_bExternalMemory )
  {
    m_pData = this->m_pData;
    if ( m_pData )
    {
      p_m_sLodSnapshot = &m_pData[-1].m_sLodSnapshot;
      if ( p_m_sLodSnapshot )
      {
        SpeedTree::g_siHeapMemoryUsed += -4 - 32 * *(_DWORD *)p_m_sLodSnapshot;
        if ( SpeedTree::g_pAllocator )
          SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, p_m_sLodSnapshot);
      }
    }
    this->m_pData = 0;
    this->m_uiDataSize = 0;
  }
  this->m_uiSize = 0;
}


void __thiscall SpeedTree::CArray<SpeedTree::CInstance,1>::clear(SpeedTree::CArray<SpeedTree::CInstance,1> *this)
{
  SpeedTree::CInstance *pRawBlock; // [esp+8h] [ebp-4h] BYREF

  if ( !this->m_bExternalMemory )
  {
    pRawBlock = this->m_pData;
    SpeedTree::st_delete_array<SpeedTree::CInstance>(&pRawBlock);
    this->m_pData = 0;
    this->m_uiDataSize = 0;
  }
  this->m_uiSize = 0;
}
