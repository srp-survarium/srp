Scaleform::GFx::MovieDataDef::SceneInfo *__thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::GetScenes(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        unsigned int *count)
{
  if ( this->Scenes.pObject )
  {
    *count = this->Scenes.pObject->Data.Size;
    return this->Scenes.pObject->Data.Data;
  }
  else
  {
    *count = 0;
    return 0;
  }
}
