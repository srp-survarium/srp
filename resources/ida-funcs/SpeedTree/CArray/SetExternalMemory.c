int __thiscall SpeedTree::CArray<char,1>::SetExternalMemory(int this, int a2, int a3)
{
  int result; // eax
  unsigned int j; // [esp+1Ch] [ebp-8h]
  unsigned int i; // [esp+20h] [ebp-4h]

  SpeedTree::CArray<char,1>::clear(this);
  result = this;
  if ( *(_BYTE *)(this + 16) )
  {
    for ( i = 0; i < *(_DWORD *)(this + 12); ++i )
      ;
    *(_DWORD *)(this + 12) = 0;
    result = this;
    *(_DWORD *)(this + 4) = 0;
  }
  if ( a2 )
  {
    result = a3;
    *(_DWORD *)(this + 12) = a3;
    *(_DWORD *)(this + 4) = a2;
    for ( j = 0; j < *(_DWORD *)(this + 12); ++j )
      result = j + 1;
    *(_BYTE *)(this + 16) = 1;
  }
  else
  {
    *(_BYTE *)(this + 16) = 0;
  }
  return result;
}


int __thiscall SpeedTree::CArray<unsigned char,1>::SetExternalMemory(int this, int a2, int a3)
{
  int result; // eax
  unsigned int j; // [esp+1Ch] [ebp-8h]
  unsigned int i; // [esp+20h] [ebp-4h]

  SpeedTree::CArray<unsigned char,1>::clear(this);
  result = this;
  if ( *(_BYTE *)(this + 16) )
  {
    for ( i = 0; i < *(_DWORD *)(this + 12); ++i )
      ;
    *(_DWORD *)(this + 12) = 0;
    result = this;
    *(_DWORD *)(this + 4) = 0;
  }
  if ( a2 )
  {
    result = a3;
    *(_DWORD *)(this + 12) = a3;
    *(_DWORD *)(this + 4) = a2;
    for ( j = 0; j < *(_DWORD *)(this + 12); ++j )
      result = j + 1;
    *(_BYTE *)(this + 16) = 1;
  }
  else
  {
    *(_BYTE *)(this + 16) = 0;
  }
  return result;
}


int __thiscall SpeedTree::CArray<float,1>::SetExternalMemory(int this, int a2, unsigned int a3)
{
  int result; // eax
  unsigned int j; // [esp+1Ch] [ebp-8h]
  unsigned int i; // [esp+20h] [ebp-4h]

  SpeedTree::CArray<int,1>::clear(this);
  result = this;
  if ( *(_BYTE *)(this + 16) )
  {
    for ( i = 0; i < *(_DWORD *)(this + 12); ++i )
      ;
    *(_DWORD *)(this + 12) = 0;
    result = this;
    *(_DWORD *)(this + 4) = 0;
  }
  if ( a2 )
  {
    result = this;
    *(_DWORD *)(this + 12) = a3 >> 2;
    *(_DWORD *)(this + 4) = a2;
    for ( j = 0; j < *(_DWORD *)(this + 12); ++j )
      result = j + 1;
    *(_BYTE *)(this + 16) = 1;
  }
  else
  {
    *(_BYTE *)(this + 16) = 0;
  }
  return result;
}


void __thiscall SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::SetExternalMemory(
        SpeedTree::CArray<SpeedTree::CCore *,1> *this,
        unsigned __int8 *pMemory,
        unsigned int uiSize)
{
  SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::clear(this);
  if ( this->m_bExternalMemory )
  {
    this->m_uiDataSize = 0;
    this->m_pData = 0;
  }
  if ( pMemory )
  {
    this->m_uiDataSize = uiSize >> 2;
    this->m_pData = (SpeedTree::CCore **)pMemory;
    this->m_bExternalMemory = 1;
  }
  else
  {
    this->m_bExternalMemory = 0;
  }
}


void __thiscall SpeedTree::CArray<SpeedTree::CInstance,1>::SetExternalMemory(
        SpeedTree::CArray<SpeedTree::CInstance,1> *this,
        unsigned __int8 *pMemory,
        unsigned int uiSize)
{
  int v4; // ebx
  unsigned int v5; // edi
  int v6; // ebp
  unsigned int v7; // edi
  SpeedTree::CInstance *v8; // ecx
  SpeedTree::CInstance *pRawBlock; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  if ( !this->m_bExternalMemory )
  {
    pRawBlock = this->m_pData;
    SpeedTree::st_delete_array<SpeedTree::CInstance>(&pRawBlock);
    this->m_pData = 0;
    this->m_uiDataSize = 0;
  }
  this->m_uiSize = 0;
  if ( this->m_bExternalMemory )
  {
    v5 = 0;
    if ( this->m_uiDataSize )
    {
      v6 = 0;
      do
      {
        SpeedTree::CCellBaseTreeItr::~CCellBaseTreeItr((SpeedTree::CCellBaseTreeItr *)&this->m_pData[v6]);
        ++v5;
        ++v6;
      }
      while ( v5 < this->m_uiDataSize );
    }
    this->m_uiDataSize = 0;
    this->m_pData = 0;
  }
  if ( pMemory )
  {
    v7 = 0;
    this->m_uiDataSize = uiSize / 0x24;
    for ( this->m_pData = (SpeedTree::CInstance *)pMemory; v7 < this->m_uiDataSize; ++v4 )
    {
      v8 = &this->m_pData[v4];
      if ( v8 )
        SpeedTree::CInstance::CInstance(v8);
      ++v7;
    }
    this->m_bExternalMemory = 1;
  }
  else
  {
    this->m_bExternalMemory = 0;
  }
}


void __usercall SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1>::SetExternalMemory(
        SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1> *this@<ecx>,
        int a2@<esi>)
{
  unsigned int v2; // edi
  int v3; // ebp
  SpeedTree::CArray<SpeedTree::CInstance,1> *pRawBlock; // [esp+4h] [ebp-4h] BYREF

  if ( !*(_BYTE *)(a2 + 16) )
  {
    pRawBlock = *(SpeedTree::CArray<SpeedTree::CInstance,1> **)(a2 + 4);
    SpeedTree::st_delete_array<SpeedTree::CArray<SpeedTree::CInstance,1>>(&pRawBlock);
    *(_DWORD *)(a2 + 4) = 0;
    *(_DWORD *)(a2 + 12) = 0;
  }
  *(_DWORD *)(a2 + 8) = 0;
  if ( *(_BYTE *)(a2 + 16) )
  {
    v2 = 0;
    if ( *(_DWORD *)(a2 + 12) )
    {
      v3 = 0;
      do
      {
        (**(void (__thiscall ***)(int, _DWORD))(*(_DWORD *)(a2 + 4) + v3))(*(_DWORD *)(a2 + 4) + v3, 0);
        ++v2;
        v3 += 20;
      }
      while ( v2 < *(_DWORD *)(a2 + 12) );
    }
    *(_DWORD *)(a2 + 12) = 0;
    *(_DWORD *)(a2 + 4) = 0;
  }
  *(_BYTE *)(a2 + 16) = 0;
}
