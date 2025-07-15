void __thiscall Scaleform::GFx::SpriteDef::InitEmptyClipDef(Scaleform::GFx::SpriteDef *this)
{
  this->FrameCount = 1;
  Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,265>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Playlist.Data,
    1u);
}
