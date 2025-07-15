void __thiscall Scaleform::GFx::AS2::RefCountCollector<323>::ReinsertToList(
        Scaleform::GFx::AS2::RefCountCollector<323> *this,
        Scaleform::GFx::AS2::RefCountBaseGC<323> *pchild)
{
  if ( (pchild->RefCount & 0x8000000) != 0 )
  {
    *(_DWORD *)(pchild->RootIndex + 4) = pchild->pRCC;
    *(_DWORD *)&pchild->pRCC->Roots.gap0 = pchild->RootIndex;
    pchild->RootIndex = *(_DWORD *)&this->pLastPtr->pRCC->Roots.gap0;
    pchild->pRCC = this->pLastPtr->pRCC;
    *(_DWORD *)&this->pLastPtr->pRCC->Roots.gap0 = pchild;
    this->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)pchild;
  }
}
