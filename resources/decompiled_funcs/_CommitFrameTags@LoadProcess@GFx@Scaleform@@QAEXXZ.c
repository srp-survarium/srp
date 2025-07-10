void __thiscall Scaleform::GFx::LoadProcess::CommitFrameTags(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::LoadProcess::LoadStateType LoadState; // eax
  Scaleform::GFx::TimelineIODef_vtbl *v3; // edi
  Scaleform::GFx::TimelineDef::Frame *v4; // eax
  Scaleform::GFx::MovieDataDef::LoadTaskData *v5; // ebx
  void (__thiscall **p_SetLoadingPlaylistFrame)(Scaleform::GFx::MovieDataDef::LoadTaskData *, const Scaleform::GFx::TimelineDef::Frame *, Scaleform::GFx::LogState *); // edi
  Scaleform::GFx::TimelineDef::Frame *v7; // eax
  Scaleform::GFx::MovieDataDef::LoadTaskData *v8; // ebx
  void (__thiscall **p_SetLoadingInitActionFrame)(Scaleform::GFx::MovieDataDef::LoadTaskData *, const Scaleform::GFx::TimelineDef::Frame *, Scaleform::GFx::LogState *); // edi
  Scaleform::GFx::TimelineDef::Frame *v10; // eax
  Scaleform::GFx::LogState *v11; // [esp-8h] [ebp-18h]
  Scaleform::GFx::LogState *v12; // [esp-8h] [ebp-18h]
  Scaleform::GFx::LogState *pObject; // [esp-4h] [ebp-14h]
  Scaleform::GFx::TimelineDef::Frame result; // [esp+8h] [ebp-8h] BYREF

  LoadState = this->LoadState;
  if ( LoadState == LS_LoadingSprite )
  {
    v3 = this->pTimelineDef->__vftable;
    pObject = this->pLoadStates.pObject->pLog.pObject;
    v4 = Scaleform::GFx::LoadProcess::TagArrayToFrame(this, &result, &this->FrameTags[1]);
    v3->SetLoadingPlaylistFrame(this->pTimelineDef, v4, pObject);
  }
  else
  {
    v5 = this->pLoadData.pObject;
    v11 = this->pLoadStates.pObject->pLog.pObject;
    p_SetLoadingPlaylistFrame = &v5->SetLoadingPlaylistFrame;
    v7 = Scaleform::GFx::LoadProcess::TagArrayToFrame(this, &result, &this->FrameTags[LoadState]);
    (*p_SetLoadingPlaylistFrame)(v5, v7, v11);
    v8 = this->pLoadData.pObject;
    v12 = this->pLoadStates.pObject->pLog.pObject;
    p_SetLoadingInitActionFrame = &v8->SetLoadingInitActionFrame;
    v10 = Scaleform::GFx::LoadProcess::TagArrayToFrame(this, &result, &this->InitActionTags);
    (*p_SetLoadingInitActionFrame)(v8, v10, v12);
  }
}
