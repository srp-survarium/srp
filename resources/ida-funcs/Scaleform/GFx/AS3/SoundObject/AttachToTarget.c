void __thiscall Scaleform::GFx::AS3::SoundObject::AttachToTarget(
        Scaleform::GFx::AS3::SoundObject *this,
        Scaleform::GFx::Sprite *psprite)
{
  Scaleform::GFx::CharacterHandle *pObject; // eax
  Scaleform::GFx::CharacterHandle *v4; // ebx
  Scaleform::GFx::CharacterHandle *v5; // esi

  pObject = psprite->pNameHandle.pObject;
  if ( !pObject )
    pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(psprite);
  v4 = pObject;
  if ( pObject )
    ++pObject->RefCount;
  v5 = this->pTargetHandle.pObject;
  if ( v5 )
  {
    if ( --v5->RefCount <= 0 )
    {
      Scaleform::GFx::CharacterHandle::~CharacterHandle(v5);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
    }
  }
  this->pTargetHandle.pObject = v4;
  if ( this )
    Scaleform::GFx::Sprite::AttachSoundObject(
      psprite,
      (Scaleform::GFx::AS3::ClassTraits::Traits *)&this->Scaleform::GFx::ASSoundIntf);
  else
    Scaleform::GFx::Sprite::AttachSoundObject(psprite, 0);
}
