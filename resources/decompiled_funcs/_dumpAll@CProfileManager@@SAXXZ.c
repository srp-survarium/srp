void __cdecl CProfileManager::dumpAll()
{
  CProfileIterator *v0; // eax
  CProfileIterator *v1; // esi

  v0 = (CProfileIterator *)operator new(8u);
  if ( v0 )
  {
    v0->CurrentParent = &CProfileManager::Root;
    v1 = v0;
    v0->CurrentChild = CProfileManager::Root.Child;
    CProfileManager::dumpRecursive(v0, 0);
    operator delete(v1);
  }
  else
  {
    CProfileManager::dumpRecursive(0, 0);
    operator delete(0);
  }
}
