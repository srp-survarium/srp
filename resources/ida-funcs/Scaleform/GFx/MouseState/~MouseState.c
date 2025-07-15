void __thiscall Scaleform::GFx::MouseState::~MouseState(Scaleform::GFx::MouseState *this)
{
  Scaleform::WeakPtrProxy *pObject; // eax
  bool v3; // zf
  Scaleform::WeakPtrProxy *v4; // eax
  Scaleform::WeakPtrProxy *v5; // esi

  Scaleform::ConstructorMov<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>>::DestructArray(
    this->MouseButtonDownEntities.Data.Data,
    this->MouseButtonDownEntities.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->MouseButtonDownEntities.Data.Data);
  pObject = this->ActiveEntity.pProxy.pObject;
  if ( pObject )
  {
    v3 = pObject->RefCount-- == 1;
    if ( v3 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
  }
  v4 = this->PrevTopmostEntity.pProxy.pObject;
  if ( v4 )
  {
    v3 = v4->RefCount-- == 1;
    if ( v3 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
  }
  v5 = this->TopmostEntity.pProxy.pObject;
  if ( v5 )
  {
    v3 = v5->RefCount-- == 1;
    if ( v3 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
  }
}
