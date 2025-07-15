void __thiscall Scaleform::GFx::AS3::RefCountCollector<328>::RemoveFromRoots(
        Scaleform::GFx::AS3::RefCountCollector<328> *this,
        const Scaleform::GFx::AS3::RefCountBaseGC<328> *root)
{
  signed int RefCount; // edx
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *pPrev; // ecx
  Scaleform::GFx::AS3::RefCountCollector<328>::RootDesc *v5; // edx
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *pNext; // ecx

  RefCount = root->RefCount;
  if ( RefCount < 0 && (RefCount & 0x1000000) == 0 )
  {
    pPrev = root->pPrev;
    v5 = &this->Roots[root->pRCCRaw & 3];
    if ( pPrev )
      pPrev->pNext = root->pNext;
    else
      v5->pRootHead = root->pNext;
    pNext = root->pNext;
    if ( pNext )
      pNext->pPrev = root->pPrev;
    root->RefCount &= ~0x80000000;
    root->pNext = 0;
    root->pPrev = 0;
    --v5->nRoots;
  }
}
