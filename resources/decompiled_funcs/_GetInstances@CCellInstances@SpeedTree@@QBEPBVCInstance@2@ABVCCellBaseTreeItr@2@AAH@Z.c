const struct SpeedTree::CInstance *__thiscall SpeedTree::CCellInstances::GetInstances(
        SpeedTree::CCellInstances *this,
        SpeedTree::CCellBaseTreeItr *a2,
        int *a3)
{
  int v4; // [esp+0h] [ebp-50h]
  int v5; // [esp+4h] [ebp-4Ch]
  int v6; // [esp+8h] [ebp-48h]
  const struct SpeedTree::CCore *v7; // [esp+40h] [ebp-10h] BYREF
  int v8; // [esp+44h] [ebp-Ch] BYREF
  int v9; // [esp+48h] [ebp-8h]
  int v10; // [esp+4Ch] [ebp-4h]

  v7 = SpeedTree::CCellBaseTreeItr::TreePtr(a2);
  v10 = 0;
  SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::find(&v8, &v7);
  if ( v8 )
  {
    v6 = v9 ? v8 + *(_DWORD *)(v9 + 4) : 0;
    *a3 = *(_DWORD *)(v6 + 12);
    if ( *a3 > 0 )
    {
      if ( v9 )
      {
        if ( v8 )
          v5 = v8 + *(_DWORD *)(v9 + 4);
        else
          v5 = 0;
        v4 = v5;
      }
      else
      {
        v4 = 0;
      }
      return *(const struct SpeedTree::CInstance **)(v4 + 8);
    }
  }
  return (const struct SpeedTree::CInstance *)v10;
}
