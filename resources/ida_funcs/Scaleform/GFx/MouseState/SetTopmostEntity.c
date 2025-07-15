void __thiscall Scaleform::GFx::MouseState::SetTopmostEntity(
        Scaleform::GFx::MouseState *this,
        Scaleform::GFx::InteractiveObject *pch)
{
  Scaleform::WeakPtrProxy *pObject; // eax
  bool v4; // zf
  Scaleform::WeakPtrProxy *WeakProxy; // ebx
  Scaleform::WeakPtrProxy *v6; // eax
  char v7; // cl
  Scaleform::WeakPtrProxy *v8; // eax

  if ( this->TopmostEntity.pProxy.pObject )
    ++this->TopmostEntity.pProxy.pObject->RefCount;
  pObject = this->PrevTopmostEntity.pProxy.pObject;
  if ( pObject )
  {
    v4 = pObject->RefCount-- == 1;
    if ( v4 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
  }
  this->PrevTopmostEntity.pProxy.pObject = this->TopmostEntity.pProxy.pObject;
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (2 * *((_BYTE *)this + 52))) & 2;
  if ( pch )
  {
    WeakProxy = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(pch);
    v6 = this->TopmostEntity.pProxy.pObject;
    if ( this->TopmostEntity.pProxy.pObject )
    {
      v4 = v6->RefCount-- == 1;
      if ( v4 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
    }
    v7 = *((_BYTE *)this + 52) ^ (pch == 0);
    this->TopmostEntity.pProxy.pObject = WeakProxy;
    *((_BYTE *)this + 52) ^= v7 & 1;
  }
  else
  {
    v8 = this->TopmostEntity.pProxy.pObject;
    if ( this->TopmostEntity.pProxy.pObject )
    {
      v4 = v8->RefCount-- == 1;
      if ( v4 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
    }
    *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ 1) & 1;
    this->TopmostEntity.pProxy.pObject = 0;
  }
}
