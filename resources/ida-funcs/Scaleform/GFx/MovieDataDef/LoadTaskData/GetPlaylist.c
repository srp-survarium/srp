const Scaleform::GFx::TimelineDef::Frame *__thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::GetPlaylist(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        const Scaleform::GFx::TimelineDef::Frame *result,
        int frameNumber)
{
  Scaleform::GFx::TimelineDef::Frame *v4; // eax
  Scaleform::GFx::ExecuteTag **v5; // edx
  Scaleform::GFx::TimelineDef::Frame *v6; // ecx
  const Scaleform::GFx::TimelineDef::Frame *v7; // eax
  unsigned int v8; // ecx
  Scaleform::Lock *p_PlaylistLock; // edi
  Scaleform::GFx::TimelineDef::Frame *Data; // edx
  Scaleform::GFx::ExecuteTag **pTagPtrList; // ecx
  unsigned int TagCount; // edx

  if ( this->LoadState < LS_LoadFinished )
  {
    p_PlaylistLock = &this->PlaylistLock;
    EnterCriticalSection(&this->PlaylistLock.cs);
    Data = this->Playlist.Data.Data;
    pTagPtrList = Data[frameNumber].pTagPtrList;
    TagCount = Data[frameNumber].TagCount;
    result->pTagPtrList = pTagPtrList;
    result->TagCount = TagCount;
    LeaveCriticalSection(&p_PlaylistLock->cs);
    return result;
  }
  else
  {
    v4 = this->Playlist.Data.Data;
    v5 = v4[frameNumber].pTagPtrList;
    v6 = &v4[frameNumber];
    v7 = result;
    v8 = v6->TagCount;
    result->pTagPtrList = v5;
    result->TagCount = v8;
  }
  return v7;
}
