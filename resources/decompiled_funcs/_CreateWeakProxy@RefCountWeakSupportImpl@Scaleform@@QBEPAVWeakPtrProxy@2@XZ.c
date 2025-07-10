Scaleform::WeakPtrProxy *__thiscall Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(
        Scaleform::RefCountWeakSupportImpl *this)
{
  Scaleform::WeakPtrProxy *result; // eax
  int v3; // [esp+4h] [ebp-4h] BYREF

  if ( this->pWeakProxy
    || ((v3 = 2,
         (result = (Scaleform::WeakPtrProxy *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                this,
                                                8,
                                                &v3)) == 0)
      ? (result = 0)
      : (Scaleform::WeakPtrProxy *)(result->RefCount = 1, result->pObject = this),
        (this->pWeakProxy = result) != 0) )
  {
    ++this->pWeakProxy->RefCount;
    return this->pWeakProxy;
  }
  return result;
}
