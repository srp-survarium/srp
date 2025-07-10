void __thiscall Scaleform::GFx::DisplayObject::~DisplayObject(Scaleform::GFx::DisplayObject *this)
{
  Scaleform::GFx::DisplayObject::ScrollRectInfo *pScrollRect; // esi
  Scaleform::RefCountNTSImpl *pObject; // ecx
  Scaleform::GFx::DisplayObject *pMaskCharacter; // ecx
  Scaleform::GFx::CharacterHandle *v5; // eax
  Scaleform::GFx::CharacterHandle *v6; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // ecx
  Scaleform::GFx::ASStringNode *v10; // ecx

  pScrollRect = this->pScrollRect;
  this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::DisplayObject_vtbl *)&Scaleform::GFx::DisplayObject::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *)&Scaleform::GFx::DisplayObject::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  if ( pScrollRect )
  {
    pObject = pScrollRect->Mask.pObject;
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pScrollRect);
  }
  if ( this->pMaskCharacter )
  {
    if ( !this->IsUsedAsMask(this) )
    {
      if ( !this->pMaskCharacter )
        goto LABEL_13;
      Scaleform::GFx::DisplayObject::SetMask(this, 0);
    }
    if ( this->pMaskCharacter )
    {
      if ( this->IsUsedAsMask(this) )
      {
        pMaskCharacter = this->pMaskCharacter;
        if ( pMaskCharacter )
          Scaleform::GFx::DisplayObject::SetMask(pMaskCharacter, 0);
      }
    }
  }
LABEL_13:
  v5 = this->pNameHandle.pObject;
  if ( v5 )
    v5->pCharacter = 0;
  v6 = this->pNameHandle.pObject;
  if ( v6 )
  {
    if ( --v6->RefCount <= 0 )
    {
      pNode = v6->OriginalName.pNode;
      v8 = pNode->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v9 = v6->NamePath.pNode;
      v8 = v9->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      v10 = v6->Name.pNode;
      v8 = v10->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
    }
  }
  Scaleform::GFx::DisplayObjectBase::~DisplayObjectBase(this);
}
