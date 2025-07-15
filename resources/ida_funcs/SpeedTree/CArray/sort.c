int __thiscall SpeedTree::CArray<SpeedTree::CGrassCell *,1>::sort<CGrassCellSorter>(int this, int a2, char a3)
{
  int result; // eax
  char v4; // [esp+9Ch] [ebp-Ch] BYREF
  char v5; // [esp+9Dh] [ebp-Bh] BYREF
  __int16 v6; // [esp+9Eh] [ebp-Ah] BYREF
  int v7; // [esp+A0h] [ebp-8h] BYREF
  unsigned __int8 dst[4]; // [esp+A4h] [ebp-4h] BYREF

  result = this;
  if ( *(_DWORD *)(this + 8) >= 2u )
  {
    if ( a3 )
    {
      v6 = 0;
      return SpeedTree::ArrayQuickSort<SpeedTree::CGrassCell *,CGrassCellSorter,SpeedTree::CArrayPointerMemorySwap,SpeedTree::CArrayPointerMemoryCopy>(
               *(unsigned __int8 **)(this + 4),
               (unsigned __int8 *)(*(_DWORD *)(this + 4) + 4 * *(_DWORD *)(this + 8) - 4),
               a2,
               (int)&v6,
               (int)&v6 + 1,
               dst);
    }
    else
    {
      v5 = 0;
      v4 = 0;
      return SpeedTree::ArrayQuickSort<SpeedTree::CGrassCell *,CGrassCellSorter,SpeedTree::CArrayPointerSwap,SpeedTree::CArrayPointerCopy>(
               *(_DWORD *)(this + 4),
               *(_DWORD *)(this + 4) + 4 * *(_DWORD *)(this + 8) - 4,
               a2,
               &v4,
               &v5,
               &v7);
    }
  }
  return result;
}
