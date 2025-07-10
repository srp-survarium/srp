void __thiscall Scaleform::GFx::AS3::RefCountCollector<328>::ReinsertToList(
        Scaleform::GFx::AS3::RefCountCollector<328> *this,
        const Scaleform::GFx::AS3::RefCountBaseGC<328> *pchild)
{
  if ( (pchild->RefCount & 0x1000000) != 0 )
  {
    pchild->pPrev->pNext = pchild->pNext;
    pchild->pNext->pPrev = pchild->pPrev;
    pchild->pPrev = this->pLastPtr->pNext->pPrev;
    pchild->pNext = this->pLastPtr->pNext;
    this->pLastPtr->pNext->pPrev = pchild;
    this->pLastPtr->pNext = pchild;
  }
}
