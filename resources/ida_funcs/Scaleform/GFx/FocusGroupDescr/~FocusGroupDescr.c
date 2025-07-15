void __thiscall Scaleform::GFx::FocusGroupDescr::~FocusGroupDescr(Scaleform::GFx::FocusGroupDescr *this)
{
  Scaleform::GFx::CharacterHandle *pObject; // esi
  Scaleform::WeakPtrProxy *v3; // eax
  bool v4; // zf
  Scaleform::Render::TreeShape *v5; // ecx

  pObject = this->ModalClip.pObject;
  if ( pObject )
  {
    if ( --pObject->RefCount <= 0 )
    {
      Scaleform::GFx::CharacterHandle::~CharacterHandle(pObject);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
  v3 = this->LastFocused.pProxy.pObject;
  if ( v3 )
  {
    v4 = v3->RefCount-- == 1;
    if ( v4 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
  }
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *)&this->TabableArray);
  v5 = this->FocusRectNode.pObject;
  if ( this->FocusRectNode.pObject )
  {
    v4 = v5->RefCount-- == 1;
    if ( v4 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v5);
  }
}
