int __thiscall SpeedTree::CForest::DeleteTreeCell(_BYTE *this, int a2, _DWORD *a3)
{
  int v4; // [esp-8h] [ebp-58h] BYREF
  int v5; // [esp+0h] [ebp-50h]
  int v6; // [esp+4h] [ebp-4Ch]
  int v7; // [esp+8h] [ebp-48h]
  int v8; // [esp+Ch] [ebp-44h]
  int v9; // [esp+10h] [ebp-40h]
  int v10; // [esp+14h] [ebp-3Ch]
  _BYTE *v11; // [esp+18h] [ebp-38h]
  int *v12; // [esp+1Ch] [ebp-34h]
  int v13; // [esp+44h] [ebp-Ch]
  int v14; // [esp+4Ch] [ebp-4h] BYREF

  v11 = this;
  if ( a3[1] )
  {
    if ( *a3 )
      v10 = *a3 + *(_DWORD *)(a3[1] + 4);
    else
      v10 = 0;
    v9 = v10;
  }
  else
  {
    v9 = 0;
  }
  if ( *(_DWORD *)(v9 + 140) != -1 )
  {
    if ( a3[1] )
    {
      if ( *a3 )
        v8 = *a3 + *(_DWORD *)(a3[1] + 4);
      else
        v8 = 0;
      v7 = v8;
    }
    else
    {
      v7 = 0;
    }
    v13 = *(_DWORD *)(v7 + 140);
    v14 = v13;
    SpeedTree::CArray<int,1>::push_back(&v14);
    if ( a3[1] )
    {
      if ( *a3 )
        v6 = *a3 + *(_DWORD *)(a3[1] + 4);
      else
        v6 = 0;
      v5 = v6;
    }
    else
    {
      v5 = 0;
    }
    *(_DWORD *)(v5 + 140) = -1;
  }
  v11[76] = 1;
  v12 = &v4;
  SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::erase(a2, *a3, a3[1]);
  return a2;
}
