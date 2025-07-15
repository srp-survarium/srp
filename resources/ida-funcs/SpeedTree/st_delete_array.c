void __cdecl SpeedTree::st_delete_array<char>(char **pRawBlock)
{
  char *v1; // eax

  if ( *pRawBlock )
  {
    v1 = *pRawBlock - 4;
    if ( *pRawBlock != (char *)4 )
    {
      SpeedTree::g_siHeapMemoryUsed += -4 - *(_DWORD *)v1;
      if ( SpeedTree::g_pAllocator )
        SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, v1);
      *pRawBlock = 0;
    }
  }
}


void __cdecl SpeedTree::st_delete_array<unsigned char>(_DWORD *a1)
{
  unsigned int i; // [esp+0h] [ebp-Ch]
  unsigned int *pointer; // [esp+8h] [ebp-4h]

  if ( *a1 )
  {
    pointer = (unsigned int *)(*a1 - 4);
    if ( *a1 != 4 )
    {
      if ( *a1 )
      {
        SpeedTree::g_siHeapMemoryUsed -= *pointer + 4;
        for ( i = 0; i < *pointer; ++i )
          ;
        if ( SpeedTree::g_pAllocator )
          SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, pointer);
        else
          free(pointer);
        *a1 = 0;
      }
    }
  }
}


void __cdecl SpeedTree::st_delete_array<unsigned int>(void ***pRawBlock)
{
  void **v1; // eax

  if ( *pRawBlock )
  {
    v1 = *pRawBlock - 1;
    if ( *pRawBlock != (void **)4 )
    {
      SpeedTree::g_siHeapMemoryUsed += -4 - 4 * (_DWORD)*v1;
      if ( SpeedTree::g_pAllocator )
        SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, v1);
      *pRawBlock = 0;
    }
  }
}


void __cdecl SpeedTree::st_delete_array<float>(_DWORD *a1)
{
  unsigned int i; // [esp+0h] [ebp-Ch]
  unsigned int *pointer; // [esp+8h] [ebp-4h]

  if ( *a1 )
  {
    pointer = (unsigned int *)(*a1 - 4);
    if ( *a1 != 4 )
    {
      if ( *a1 )
      {
        SpeedTree::g_siHeapMemoryUsed -= 4 * *pointer + 4;
        for ( i = 0; i < *pointer; ++i )
          ;
        if ( SpeedTree::g_pAllocator )
          SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, pointer);
        else
          free(pointer);
        *a1 = 0;
      }
    }
  }
}


void __cdecl SpeedTree::st_delete_array<SpeedTree::SCollisionObject>(int *a1)
{
  unsigned int i; // [esp+4h] [ebp-Ch]
  int v2; // [esp+8h] [ebp-8h]
  unsigned int *pointer; // [esp+Ch] [ebp-4h]

  if ( *a1 )
  {
    pointer = (unsigned int *)(*a1 - 4);
    if ( *a1 != 4 )
    {
      v2 = *a1;
      if ( *a1 )
      {
        SpeedTree::g_siHeapMemoryUsed -= 292 * *pointer + 4;
        for ( i = 0; i < *pointer; ++i )
          SpeedTree::SCollisionObject::~SCollisionObject((void *)(v2 + 292 * i));
        if ( SpeedTree::g_pAllocator )
          SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, pointer);
        else
          free(pointer);
        *a1 = 0;
      }
    }
  }
}


void __cdecl SpeedTree::st_delete_array<SpeedTree::SIndexedTriangles>(int *a1)
{
  unsigned int i; // [esp+4h] [ebp-Ch]
  int v2; // [esp+8h] [ebp-8h]
  unsigned int *pointer; // [esp+Ch] [ebp-4h]

  if ( *a1 )
  {
    pointer = (unsigned int *)(*a1 - 4);
    if ( *a1 != 4 )
    {
      v2 = *a1;
      if ( *a1 )
      {
        SpeedTree::g_siHeapMemoryUsed -= 68 * *pointer + 4;
        for ( i = 0; i < *pointer; ++i )
          SpeedTree::CCellBaseTreeItr::~CCellBaseTreeItr((SpeedTree::CCellBaseTreeItr *)(v2 + 68 * i));
        if ( SpeedTree::g_pAllocator )
          SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, pointer);
        else
          free(pointer);
        *a1 = 0;
      }
    }
  }
}


void __cdecl SpeedTree::st_delete_array<SpeedTree::SInstanceLod>(SpeedTree::SInstanceLod **pRawBlock)
{
  SpeedTree::SLodSnapshot *p_m_sLodSnapshot; // eax

  if ( *pRawBlock )
  {
    p_m_sLodSnapshot = &(*pRawBlock)[-1].m_sLodSnapshot;
    if ( *pRawBlock != (SpeedTree::SInstanceLod *)4 )
    {
      SpeedTree::g_siHeapMemoryUsed += -4 - 32 * *(_DWORD *)p_m_sLodSnapshot;
      if ( SpeedTree::g_pAllocator )
        SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, p_m_sLodSnapshot);
      *pRawBlock = 0;
    }
  }
}


void __cdecl SpeedTree::st_delete_array<SpeedTree::SLeafCards>(int *a1)
{
  unsigned int i; // [esp+4h] [ebp-Ch]
  int v2; // [esp+8h] [ebp-8h]
  unsigned int *pointer; // [esp+Ch] [ebp-4h]

  if ( *a1 )
  {
    pointer = (unsigned int *)(*a1 - 4);
    if ( *a1 != 4 )
    {
      v2 = *a1;
      if ( *a1 )
      {
        SpeedTree::g_siHeapMemoryUsed -= 60 * *pointer + 4;
        for ( i = 0; i < *pointer; ++i )
          SpeedTree::CCellBaseTreeItr::~CCellBaseTreeItr((SpeedTree::CCellBaseTreeItr *)(v2 + 60 * i));
        if ( SpeedTree::g_pAllocator )
          SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, pointer);
        else
          free(pointer);
        *a1 = 0;
      }
    }
  }
}


void __cdecl SpeedTree::st_delete_array<SpeedTree::SMaterial>(int *a1)
{
  unsigned int i; // [esp+4h] [ebp-Ch]
  int v2; // [esp+8h] [ebp-8h]
  unsigned int *pointer; // [esp+Ch] [ebp-4h]

  if ( *a1 )
  {
    pointer = (unsigned int *)(*a1 - 4);
    if ( *a1 != 4 )
    {
      v2 = *a1;
      if ( *a1 )
      {
        SpeedTree::g_siHeapMemoryUsed -= 1692 * *pointer + 4;
        for ( i = 0; i < *pointer; ++i )
          SpeedTree::SMaterial::~SMaterial((SpeedTree::SMaterial *)(v2 + 1692 * i));
        if ( SpeedTree::g_pAllocator )
          SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, pointer);
        else
          free(pointer);
        *a1 = 0;
      }
    }
  }
}


void __cdecl SpeedTree::st_delete_array<SMaterialSerial>(_DWORD *a1)
{
  unsigned int i; // [esp+0h] [ebp-Ch]
  unsigned int *pointer; // [esp+8h] [ebp-4h]

  if ( *a1 )
  {
    pointer = (unsigned int *)(*a1 - 4);
    if ( *a1 != 4 )
    {
      if ( *a1 )
      {
        SpeedTree::g_siHeapMemoryUsed -= 1648 * *pointer + 4;
        for ( i = 0; i < *pointer; ++i )
          ;
        if ( SpeedTree::g_pAllocator )
          SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, pointer);
        else
          free(pointer);
        *a1 = 0;
      }
    }
  }
}


void __cdecl SpeedTree::st_delete_array<SpeedTree::CInstance>(SpeedTree::CInstance **pRawBlock)
{
  SpeedTree::CCellBaseTreeItr *v1; // edi
  unsigned int *p_m_pCell; // ebx
  unsigned int v3; // eax
  unsigned int v4; // esi

  v1 = (SpeedTree::CCellBaseTreeItr *)*pRawBlock;
  if ( *pRawBlock )
  {
    p_m_pCell = (unsigned int *)&v1[-1].m_pCell;
    if ( v1 != (SpeedTree::CCellBaseTreeItr *)4 )
    {
      v3 = *p_m_pCell;
      SpeedTree::g_siHeapMemoryUsed += -4 - 36 * *p_m_pCell;
      v4 = 0;
      if ( v3 )
      {
        do
        {
          SpeedTree::CCellBaseTreeItr::~CCellBaseTreeItr(v1);
          ++v4;
          v1 += 3;
        }
        while ( v4 < *p_m_pCell );
      }
      if ( SpeedTree::g_pAllocator )
        SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, p_m_pCell);
      *pRawBlock = 0;
    }
  }
}


void __cdecl SpeedTree::st_delete_array<SpeedTree::CArray<SpeedTree::CInstance,1>>(
        SpeedTree::CArray<SpeedTree::CInstance,1> **pRawBlock)
{
  void (__thiscall ***v1)(_DWORD, _DWORD); // esi
  unsigned int *v2; // ebx
  unsigned int v3; // eax
  unsigned int v4; // edi

  v1 = (void (__thiscall ***)(_DWORD, _DWORD))*pRawBlock;
  if ( *pRawBlock )
  {
    v2 = (unsigned int *)(v1 - 1);
    if ( v1 != (void (__thiscall ***)(_DWORD, _DWORD))4 )
    {
      v3 = *v2;
      SpeedTree::g_siHeapMemoryUsed += -4 - 20 * *v2;
      v4 = 0;
      if ( v3 )
      {
        do
        {
          (**v1)(v1, 0);
          ++v4;
          v1 += 5;
        }
        while ( v4 < *v2 );
      }
      if ( SpeedTree::g_pAllocator )
        SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, v2);
      *pRawBlock = 0;
    }
  }
}
