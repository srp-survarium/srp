void __thiscall Scaleform::GFx::SpriteDef::SetLoadingPlaylistFrame(
        Scaleform::GFx::SpriteDef *this,
        const Scaleform::GFx::TimelineDef::Frame *frame,
        Scaleform::GFx::LogState *plog)
{
  int LoadingFrame; // eax
  Scaleform::Log *pObject; // eax
  unsigned int Size; // ebx

  LoadingFrame = this->LoadingFrame;
  if ( (signed int)this->Playlist.Data.Size > LoadingFrame )
  {
    this->Playlist.Data.Data[LoadingFrame] = *frame;
  }
  else if ( plog && (plog->pLog.pObject || Scaleform::Log::GetGlobalLog()) )
  {
    pObject = plog->pLog.pObject;
    Size = this->Playlist.Data.Size;
    if ( !pObject )
      pObject = Scaleform::Log::GetGlobalLog();
    Scaleform::Log::LogError(
      pObject,
      "Invalid SWF file: failed to load sprite's frame #%d since total frames counter is %d",
      this->LoadingFrame + 1,
      Size);
  }
}
