void __thiscall Scaleform::GFx::Sprite::OnEventUnload(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::Sprite::ActiveSounds *pActiveSounds; // edi
  bool v3; // zf

  pActiveSounds = this->pActiveSounds;
  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x1000u;
  if ( pActiveSounds )
  {
    Scaleform::GFx::Sprite::ActiveSounds::~ActiveSounds(pActiveSounds);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pActiveSounds);
  }
  v3 = this->pHitAreaHandle.pObject == 0;
  this->pActiveSounds = 0;
  if ( !v3 )
    Scaleform::GFx::Sprite::SetHitArea(this, 0);
  Scaleform::GFx::DisplayList::Clear(&this->mDisplayList, this);
  Scaleform::GFx::InteractiveObject::OnEventUnload(this);
}
