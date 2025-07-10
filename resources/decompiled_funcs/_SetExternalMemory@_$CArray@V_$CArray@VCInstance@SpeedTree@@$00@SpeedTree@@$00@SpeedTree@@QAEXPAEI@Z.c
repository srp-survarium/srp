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
