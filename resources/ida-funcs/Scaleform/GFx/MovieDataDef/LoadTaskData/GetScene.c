Scaleform::GFx::MovieDataDef::SceneInfo *__thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::GetScene(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        unsigned int index)
{
  Scaleform::ArrayLH<Scaleform::GFx::MovieDataDef::SceneInfo,2,Scaleform::ArrayDefaultPolicy> *pObject; // ecx

  pObject = this->Scenes.pObject;
  if ( pObject && index < pObject->Data.Size )
    return &pObject->Data.Data[index];
  else
    return 0;
}
