const Scaleform::GFx::MovieDataDef::SceneInfo *__thiscall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::GetSceneInfo(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip *this,
        unsigned int frameNumber)
{
  Scaleform::GFx::DisplayObject *pObject; // esi
  Scaleform::GFx::MovieDefImpl *(__thiscall *GetResourceMovieDef)(Scaleform::GFx::DisplayObjectBase *); // edx
  int v4; // eax
  Scaleform::GFx::MovieDataDef::SceneInfo *Scenes; // ebx
  int v6; // eax
  unsigned int *i; // ecx
  unsigned int cnt; // [esp+10h] [ebp-4h] BYREF

  pObject = this->pDispObj.pObject;
  if ( (*(int (__thiscall **)(Scaleform::GFx::CharacterHandle *))(pObject[1].pNameHandle.pObject->RefCount + 16))(pObject[1].pNameHandle.pObject) != 2 )
    return 0;
  GetResourceMovieDef = pObject->GetResourceMovieDef;
  cnt = 0;
  v4 = (int)GetResourceMovieDef(pObject);
  Scenes = Scaleform::GFx::MovieDataDef::LoadTaskData::GetScenes(
             *(Scaleform::GFx::MovieDataDef::LoadTaskData **)(*(_DWORD *)(*(_DWORD *)(v4 + 28) + 12) + 32),
             &cnt);
  v6 = 0;
  if ( !cnt )
    return 0;
  for ( i = &Scenes->Offset; frameNumber < *i || frameNumber >= *i + i[1]; i += 8 )
  {
    if ( ++v6 >= cnt )
      return 0;
  }
  return &Scenes[v6];
}
