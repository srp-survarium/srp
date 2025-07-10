int __stdcall SpeedTree::CCellContainer<SpeedTree::CGrassCell>::GetCellPtrByRowCol_Add(int a1, int a2)
{
  int v3; // [esp+0h] [ebp-60h]
  int v4; // [esp+58h] [ebp-8h] BYREF
  int v5; // [esp+5Ch] [ebp-4h]

  SpeedTree::CCellContainer<SpeedTree::CGrassCell>::GetCellItrByRowCol_Add(&v4, a1, a2);
  if ( !v4 )
    return 0;
  if ( v5 )
    v3 = v4 + *(_DWORD *)(v5 + 4);
  else
    v3 = 0;
  return v3 + 8;
}
