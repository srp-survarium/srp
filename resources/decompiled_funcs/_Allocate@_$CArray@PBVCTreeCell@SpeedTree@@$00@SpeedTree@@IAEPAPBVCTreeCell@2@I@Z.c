SpeedTree::CCore **__thiscall SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::Allocate(
        SpeedTree::CArray<SpeedTree::CCore *,1> *this,
        unsigned int uiSize)
{
  _DWORD *v2; // eax

  if ( !SpeedTree::g_pAllocator )
    return 0;
  v2 = SpeedTree::g_pAllocator->Alloc(SpeedTree::g_pAllocator, 4 * uiSize + 4);
  if ( !v2 )
    return 0;
  SpeedTree::g_siHeapMemoryUsed += 4 * uiSize + 4;
  ++SpeedTree::g_siNumHeapAllocs;
  *v2 = uiSize;
  return (SpeedTree::CCore **)(v2 + 1);
}
