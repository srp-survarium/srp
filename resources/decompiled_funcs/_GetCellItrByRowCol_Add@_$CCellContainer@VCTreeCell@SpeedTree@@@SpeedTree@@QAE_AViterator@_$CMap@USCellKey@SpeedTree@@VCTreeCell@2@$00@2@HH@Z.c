_DWORD *__stdcall SpeedTree::CCellContainer<SpeedTree::CTreeCell>::GetCellItrByRowCol_Add(_DWORD *a1, int a2, int a3)
{
  int *v3; // eax
  int v4; // edx
  int v5; // eax
  int v7; // [esp+4h] [ebp-A4h]
  _BYTE v8[8]; // [esp+84h] [ebp-24h] BYREF
  int v9; // [esp+8Ch] [ebp-1Ch]
  int v10; // [esp+90h] [ebp-18h]
  int v11; // [esp+94h] [ebp-14h]
  _DWORD v12[2]; // [esp+98h] [ebp-10h] BYREF
  int v13; // [esp+A0h] [ebp-8h] BYREF
  int v14; // [esp+A4h] [ebp-4h]

  v12[0] = a2;
  v12[1] = a3;
  SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::find(&v13, v12);
  v9 = 0;
  v10 = 0;
  if ( !v13 )
  {
    v11 = SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::operator[](v12);
    *(_DWORD *)(v11 + 4) = a2;
    *(_DWORD *)(v11 + 8) = a3;
    v3 = (int *)SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::find(v8, v12);
    v4 = *v3;
    v5 = v3[1];
    v13 = v4;
    v14 = v5;
  }
  v7 = v14;
  *a1 = v13;
  a1[1] = v7;
  return a1;
}
