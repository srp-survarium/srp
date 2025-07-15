void __thiscall Scaleform::GFx::AS2::RefCountCollector<323>::ReinsertToList(
        Scaleform::GFx::AS2::RefCountCollector<323> *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *pchild)
{
  if ( (pchild->Roots.Size & 0x8000000) != 0 )
  {
    *(_DWORD *)(*(_DWORD *)&pchild->Roots.gap0 + 4) = pchild->RefCount;
    *(_DWORD *)(pchild->RefCount + 8) = *(_DWORD *)&pchild->Roots.gap0;
    *(_DWORD *)&pchild->Roots.gap0 = *(_DWORD *)&this->pLastPtr->pRCC->Roots.gap0;
    pchild->RefCount = (volatile int)this->pLastPtr->pRCC;
    *(_DWORD *)&this->pLastPtr->pRCC->Roots.gap0 = pchild;
    this->pLastPtr->pRCC = pchild;
  }
}
