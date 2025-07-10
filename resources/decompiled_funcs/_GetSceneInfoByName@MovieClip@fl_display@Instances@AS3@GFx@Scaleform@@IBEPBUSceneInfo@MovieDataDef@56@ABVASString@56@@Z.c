const Scaleform::GFx::MovieDataDef::SceneInfo *__thiscall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::GetSceneInfoByName(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip *this,
        const Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::DisplayObject *pObject; // esi
  Scaleform::GFx::MovieDefImpl *(__thiscall *GetResourceMovieDef)(Scaleform::GFx::DisplayObjectBase *); // edx
  int v4; // eax
  const Scaleform::GFx::MovieDataDef::SceneInfo *v5; // esi
  unsigned int v6; // eax
  unsigned int cnt; // [esp+10h] [ebp-8h] BYREF
  const Scaleform::GFx::MovieDataDef::SceneInfo *scenes; // [esp+14h] [ebp-4h]

  pObject = this->pDispObj.pObject;
  if ( (*(int (__thiscall **)(Scaleform::GFx::CharacterHandle *))(pObject[1].pNameHandle.pObject->RefCount + 16))(pObject[1].pNameHandle.pObject) != 2 )
    return 0;
  GetResourceMovieDef = pObject->GetResourceMovieDef;
  cnt = 0;
  v4 = (int)GetResourceMovieDef(pObject);
  v5 = Scaleform::GFx::MovieDataDef::LoadTaskData::GetScenes(
         *(Scaleform::GFx::MovieDataDef::LoadTaskData **)(*(_DWORD *)(*(_DWORD *)(v4 + 28) + 12) + 32),
         &cnt);
  v6 = 0;
  scenes = v5;
  if ( !cnt )
    return 0;
  while ( strcmp(name->pNode->pData, (const char *)((v5->Name.HeapTypeBits & 0xFFFFFFFC) + 8)) )
  {
    ++v6;
    ++v5;
    if ( v6 >= cnt )
      return 0;
  }
  return &scenes[v6];
}
