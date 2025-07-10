void __thiscall Scaleform::GFx::Sprite::SetPlayState(Scaleform::GFx::Sprite *this, Scaleform::GFx::PlayState s)
{
  unsigned __int16 Flags; // ax

  this->PlayStatePriv = s;
  Flags = this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags;
  if ( (Flags & 0x1000) == 0 && this->Depth >= -1 && (Flags & 0x10) == 0 )
    Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::Sprite>(this);
  if ( this->PlayStatePriv == State_Stopped )
    Scaleform::GFx::Sprite::SetStreamingSound(this, 0);
}
