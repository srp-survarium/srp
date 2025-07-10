Scaleform::GFx::PlayState __thiscall Scaleform::GFx::Sprite::GetPlayState(Scaleform::GFx::Sprite *this)
{
  if ( (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
      & 0x800) != 0 )
    return this->PlayStatePriv;
  else
    return 1;
}
