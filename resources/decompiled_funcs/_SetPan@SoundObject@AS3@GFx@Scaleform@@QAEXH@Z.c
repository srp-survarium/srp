void __thiscall Scaleform::GFx::AS3::SoundObject::SetPan(Scaleform::GFx::AS3::SoundObject *this, int pan)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // edx
  Scaleform::GFx::Sprite *v3; // eax

  pMovieRoot = this->pMovieRoot;
  this->Pan = pan;
  v3 = (Scaleform::GFx::Sprite *)Scaleform::GFx::CharacterHandle::ResolveCharacter(
                                   this->pTargetHandle.pObject,
                                   pMovieRoot);
  if ( v3 )
  {
    if ( ((v3->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
         & 0x400) != 0
        ? (unsigned int)v3
        : 0) != 0 )
      Scaleform::GFx::Sprite::UpdateActiveSoundPan(
        (v3->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
       & 0x400) != 0
      ? v3
      : 0);
  }
}
