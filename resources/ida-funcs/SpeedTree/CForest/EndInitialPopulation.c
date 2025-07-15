void __thiscall SpeedTree::CForest::EndInitialPopulation(SpeedTree::CForest *this)
{
  int v1; // [esp+0h] [ebp-2Ch]
  int v2; // [esp+24h] [ebp-8h] BYREF
  int v3; // [esp+28h] [ebp-4h]

  SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::begin(&v2);
  while ( v2 )
  {
    if ( v3 )
      v1 = v2 + *(_DWORD *)(v3 + 4);
    else
      v1 = 0;
    *(_BYTE *)(v1 + 136) = 0;
    SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::iterator_base::operator++(&v2);
  }
}
