double __thiscall Scaleform::GFx::AS3::SoundObject::GetPosition(Scaleform::GFx::AS3::SoundObject *this)
{
  Scaleform::GFx::Sprite *v2; // eax
  float position; // [esp+4h] [ebp-4h]

  position = 0.0;
  v2 = (Scaleform::GFx::Sprite *)Scaleform::GFx::CharacterHandle::ResolveCharacter(
                                   this->pTargetHandle.pObject,
                                   this->pMovieRoot);
  if ( v2
    && ((v2->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
       & 0x400) != 0
      ? (unsigned int)v2
      : 0) != 0 )
  {
    return (float)(Scaleform::GFx::Sprite::GetActiveSoundPosition(
                     (v2->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
                    & 0x400) != 0
                   ? v2
                   : 0,
                     &this->Scaleform::GFx::ASSoundIntf)
                 * 1000.0);
  }
  return position;
}
