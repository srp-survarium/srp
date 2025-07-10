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
