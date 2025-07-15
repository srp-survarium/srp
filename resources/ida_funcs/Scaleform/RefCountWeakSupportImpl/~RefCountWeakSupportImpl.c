void __thiscall Scaleform::RefCountWeakSupportImpl::~RefCountWeakSupportImpl(Scaleform::RefCountWeakSupportImpl *this)
{
  Scaleform::WeakPtrProxy *pWeakProxy; // eax
  Scaleform::WeakPtrProxy *v3; // eax

  pWeakProxy = this->pWeakProxy;
  this->__vftable = (Scaleform::RefCountWeakSupportImpl_vtbl *)&Scaleform::RefCountWeakSupportImpl::`vftable';
  if ( pWeakProxy )
  {
    pWeakProxy->pObject = 0;
    v3 = this->pWeakProxy;
    if ( v3->RefCount-- == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
  }
  this->__vftable = (Scaleform::RefCountWeakSupportImpl_vtbl *)&Scaleform::RefCountNTSImplCore::`vftable';
}
