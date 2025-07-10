const Scaleform::GFx::TimelineDef::Frame *__thiscall Scaleform::GFx::SpriteDef::GetPlaylist(
        Scaleform::GFx::SpriteDef *this,
        const Scaleform::GFx::TimelineDef::Frame *result,
        int frameNumber)
{
  Scaleform::GFx::TimelineDef::Frame *Data; // eax
  Scaleform::GFx::ExecuteTag **pTagPtrList; // edx
  Scaleform::GFx::TimelineDef::Frame *v5; // ecx
  const Scaleform::GFx::TimelineDef::Frame *v6; // eax
  unsigned int TagCount; // ecx

  Data = this->Playlist.Data.Data;
  pTagPtrList = Data[frameNumber].pTagPtrList;
  v5 = &Data[frameNumber];
  v6 = result;
  TagCount = v5->TagCount;
  result->pTagPtrList = pTagPtrList;
  result->TagCount = TagCount;
  return v6;
}
