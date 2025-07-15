int __thiscall SpeedTree::CCellInstances::NumInstances(
        SpeedTree::CCellInstances *this,
        const struct SpeedTree::CCore *a2)
{
  int v3; // [esp+0h] [ebp-80h]
  int v4; // [esp+8h] [ebp-78h]
  int *v5; // [esp+18h] [ebp-68h]
  int v6; // [esp+1Ch] [ebp-64h]
  int *v7; // [esp+40h] [ebp-40h]
  int v8; // [esp+44h] [ebp-3Ch]
  _BYTE v9[8]; // [esp+4Ch] [ebp-34h] BYREF
  int v10; // [esp+54h] [ebp-2Ch]
  int v11; // [esp+58h] [ebp-28h]
  _BYTE v12[8]; // [esp+5Ch] [ebp-24h] BYREF
  int v13; // [esp+64h] [ebp-1Ch]
  int v14; // [esp+68h] [ebp-18h]
  int v15; // [esp+6Ch] [ebp-14h]
  int v16; // [esp+70h] [ebp-10h]
  int v17; // [esp+74h] [ebp-Ch] BYREF
  int v18; // [esp+78h] [ebp-8h]
  int v19; // [esp+7Ch] [ebp-4h]

  v19 = 0;
  if ( a2 )
  {
    v5 = (int *)SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::find(v12, &a2);
    v6 = v5[1];
    v15 = *v5;
    v16 = v6;
    v10 = 0;
    v11 = 0;
    if ( v15 )
    {
      if ( v16 )
        v3 = v15 + *(_DWORD *)(v16 + 4);
      else
        v3 = 0;
      return *(_DWORD *)(v3 + 12);
    }
  }
  else
  {
    v7 = (int *)SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::begin(v9);
    v8 = v7[1];
    v17 = *v7;
    v18 = v8;
    while ( 1 )
    {
      v13 = 0;
      v14 = 0;
      if ( !v17 )
        break;
      if ( v18 )
        v4 = v17 + *(_DWORD *)(v18 + 4);
      else
        v4 = 0;
      v19 += *(_DWORD *)(v4 + 12);
      SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::iterator_base::operator++(&v17);
    }
  }
  return v19;
}
