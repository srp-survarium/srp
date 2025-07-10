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
