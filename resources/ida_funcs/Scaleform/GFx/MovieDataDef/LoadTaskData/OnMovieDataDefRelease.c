void __thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::OnMovieDataDefRelease(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this)
{
  if ( this->LoadState <= LS_LoadingFrames )
    this->LoadingCanceled = 1;
}
