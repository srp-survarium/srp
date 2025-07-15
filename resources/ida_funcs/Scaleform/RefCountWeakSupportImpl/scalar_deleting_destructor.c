Scaleform::RefCountWeakSupportImpl *__thiscall Scaleform::RefCountWeakSupportImpl::`scalar deleting destructor'(
        Scaleform::RefCountWeakSupportImpl *this,
        char a2)
{
  Scaleform::WeakPtrProxy *pWeakProxy; // eax
  Scaleform::WeakPtrProxy *v4; // eax

  pWeakProxy = this->pWeakProxy;
  this->__vftable = (Scaleform::RefCountWeakSupportImpl_vtbl *)&Scaleform::RefCountWeakSupportImpl::`vftable';
  if ( pWeakProxy )
  {
    pWeakProxy->pObject = 0;
    v4 = this->pWeakProxy;
    if ( v4->RefCount-- == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
  }
  this->__vftable = (Scaleform::RefCountWeakSupportImpl_vtbl *)&Scaleform::RefCountNTSImplCore::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
