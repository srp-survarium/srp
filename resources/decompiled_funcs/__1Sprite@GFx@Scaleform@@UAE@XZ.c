void __thiscall Scaleform::GFx::Sprite::~Sprite(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::Sprite::ActiveSounds *pActiveSounds; // edi
  Scaleform::GFx::CharacterHandle *pObject; // edi
  Scaleform::GFx::DrawingContext *v4; // ecx
  Scaleform::GFx::TimelineDef *v5; // ecx

  pActiveSounds = this->pActiveSounds;
  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::Sprite_vtbl *)&Scaleform::GFx::Sprite::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *)&Scaleform::GFx::Sprite::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  if ( pActiveSounds )
  {
    Scaleform::GFx::Sprite::ActiveSounds::~ActiveSounds(pActiveSounds);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pActiveSounds);
  }
  Scaleform::GFx::DisplayList::Clear(&this->mDisplayList, this);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)this);
  pObject = this->pHitAreaHandle.pObject;
  if ( pObject )
  {
    if ( --pObject->RefCount <= 0 )
    {
      Scaleform::GFx::CharacterHandle::~CharacterHandle(pObject);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
  v4 = this->pDrawingAPI.pObject;
  if ( v4 )
    Scaleform::RefCountNTSImpl::Release(v4);
  v5 = this->pDef.pObject;
  if ( v5 )
    Scaleform::GFx::Resource::Release(v5);
  Scaleform::GFx::DisplayObjContainer::~DisplayObjContainer(this);
}
