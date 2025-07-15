void __thiscall Scaleform::GFx::InteractiveObject::InsertToPlayListAfter(
        Scaleform::GFx::InteractiveObject *this,
        Scaleform::GFx::InteractiveObject *pafterCh)
{
  Scaleform::GFx::InteractiveObject *pPlayNext; // eax

  if ( (this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x10) == 0
    && (this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x1000) == 0
    && this->Depth >= -1 )
  {
    this->pPlayPrev = pafterCh;
    this->pPlayNext = pafterCh->pPlayNext;
    pafterCh->pPlayNext = this;
    pPlayNext = this->pPlayNext;
    if ( pPlayNext )
      pPlayNext->pPlayPrev = this;
  }
}
