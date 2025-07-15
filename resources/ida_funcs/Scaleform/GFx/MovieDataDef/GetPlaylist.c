const Scaleform::GFx::TimelineDef::Frame *__thiscall Scaleform::GFx::MovieDataDef::GetPlaylist(
        Scaleform::GFx::MovieDataDef *this,
        const Scaleform::GFx::TimelineDef::Frame *result,
        int frame)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData::GetPlaylist(this->pData.pObject, result, frame);
  return result;
}
