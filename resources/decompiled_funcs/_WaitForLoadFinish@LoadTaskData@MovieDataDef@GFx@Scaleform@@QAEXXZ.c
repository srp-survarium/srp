void __thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::WaitForLoadFinish(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this)
{
  if ( this->LoadState <= LS_LoadingFrames )
    Scaleform::GFx::LoadUpdateSync::WaitForLoadFinished(this->pFrameUpdate.pObject);
}
