char __stdcall SpeedTree::CForest::GetInstances(
        const struct SpeedTree::CCore *a1,
        SpeedTree::CArray<SpeedTree::CInstance,1> *a2)
{
  int v3; // [esp+4h] [ebp-A8h]
  int *v4; // [esp+5Ch] [ebp-50h]
  int v5; // [esp+60h] [ebp-4Ch]
  _BYTE v6[8]; // [esp+68h] [ebp-44h] BYREF
  int v7; // [esp+70h] [ebp-3Ch]
  int v8; // [esp+74h] [ebp-38h]
  int i; // [esp+78h] [ebp-34h]
  int v10; // [esp+7Ch] [ebp-30h] BYREF
  const struct SpeedTree::CInstance *Instances; // [esp+80h] [ebp-2Ch]
  SpeedTree::CCellInstances *v12; // [esp+84h] [ebp-28h]
  SpeedTree::CCellBaseTreeItr v13; // [esp+88h] [ebp-24h] BYREF
  int v14; // [esp+94h] [ebp-18h] BYREF
  int v15; // [esp+98h] [ebp-14h]
  char v16; // [esp+9Fh] [ebp-Dh]
  int v17; // [esp+A8h] [ebp-4h]

  v16 = 0;
  v4 = (int *)SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::begin(v6);
  v5 = v4[1];
  v14 = *v4;
  v15 = v5;
  while ( 1 )
  {
    v7 = 0;
    v8 = 0;
    if ( !v14 )
      break;
    if ( v15 )
      v3 = v14 + *(_DWORD *)(v15 + 4);
    else
      v3 = 0;
    v12 = (SpeedTree::CCellInstances *)(v3 + 64);
    SpeedTree::CCellInstances::FirstBaseTree((SpeedTree::CCellInstances *)(v3 + 64), &v13);
    v17 = 0;
    while ( SpeedTree::CCellBaseTreeItr::TreePtr(&v13) )
    {
      if ( !a1 || SpeedTree::CCellBaseTreeItr::TreePtr(&v13) == a1 )
      {
        v10 = 0;
        Instances = SpeedTree::CCellInstances::GetInstances(v12, &v13, &v10);
        for ( i = 0; i < v10; ++i )
          SpeedTree::CArray<SpeedTree::CInstance,1>::push_back(a2, &Instances[i]);
      }
      SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::iterator_base::operator++(&v13);
    }
    v17 = -1;
    SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::iterator_base::operator++(&v14);
  }
  return 1;
}
