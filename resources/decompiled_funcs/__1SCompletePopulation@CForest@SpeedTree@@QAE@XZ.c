void __usercall SpeedTree::CForest::SCompletePopulation::~SCompletePopulation(
        SpeedTree::CForest::SCompletePopulation *this@<ecx>,
        int a2@<edi>)
{
  unsigned __int8 *v2; // [esp+0h] [ebp-Ch]
  unsigned int v3; // [esp+4h] [ebp-8h]
  SpeedTree::CArray<SpeedTree::CInstance,1> *pRawBlock; // [esp+8h] [ebp-4h] BYREF

  *(_DWORD *)(a2 + 20) = &SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1>::`vftable';
  if ( !*(_BYTE *)(a2 + 36)
    || (SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1>::SetExternalMemory(
          (SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1> *)this,
          v2,
          v3),
        !*(_BYTE *)(a2 + 36)) )
  {
    pRawBlock = *(SpeedTree::CArray<SpeedTree::CInstance,1> **)(a2 + 24);
    SpeedTree::st_delete_array<SpeedTree::CArray<SpeedTree::CInstance,1>>(&pRawBlock);
    *(_DWORD *)(a2 + 24) = 0;
    *(_DWORD *)(a2 + 32) = 0;
  }
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)a2 = &SpeedTree::CArray<SpeedTree::CCore *,1>::`vftable';
  if ( *(_BYTE *)(a2 + 16) )
  {
    SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::clear((SpeedTree::CArray<SpeedTree::CCore *,1> *)a2);
    if ( *(_BYTE *)(a2 + 16) )
    {
      *(_DWORD *)(a2 + 12) = 0;
      *(_DWORD *)(a2 + 4) = 0;
    }
    *(_BYTE *)(a2 + 16) = 0;
  }
  SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::clear((SpeedTree::CArray<SpeedTree::CCore *,1> *)a2);
}
