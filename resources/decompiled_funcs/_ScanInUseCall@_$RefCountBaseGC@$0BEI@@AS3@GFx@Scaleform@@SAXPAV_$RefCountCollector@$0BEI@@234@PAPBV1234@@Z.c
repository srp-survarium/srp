void __cdecl Scaleform::GFx::AS3::RefCountBaseGC<328>::ScanInUseCall(
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        const Scaleform::GFx::AS3::RefCountBaseGC<328> **pchild)
{
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *v2; // eax

  if ( (++(*pchild)->RefCount & 0x70000000) != 0 )
  {
    (*pchild)->RefCount &= 0x8FFFFFFF;
    v2 = *pchild;
    if ( ((*pchild)->RefCount & 0x1000000) != 0 )
    {
      v2->pPrev->pNext = v2->pNext;
      v2->pNext->pPrev = v2->pPrev;
      v2->pPrev = prcc->pLastPtr->pNext->pPrev;
      v2->pNext = prcc->pLastPtr->pNext;
      prcc->pLastPtr->pNext->pPrev = v2;
      prcc->pLastPtr->pNext = v2;
    }
  }
}
