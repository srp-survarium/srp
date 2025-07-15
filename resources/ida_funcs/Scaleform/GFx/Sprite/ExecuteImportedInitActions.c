void __thiscall Scaleform::GFx::Sprite::ExecuteImportedInitActions(
        Scaleform::GFx::Sprite *this,
        Scaleform::GFx::MovieDefImpl *psourceMovie)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData **pObject; // esi
  unsigned int v4; // ebx
  unsigned int v5; // ebp
  unsigned __int8 (__thiscall *FileLength)(Scaleform::GFx::MovieDataDef::LoadTaskData **, Scaleform::GFx::TimelineDef::Frame *, unsigned int); // edx
  Scaleform::GFx::GFxInitImportActions *v7; // esi
  Scaleform::GFx::MovieDataDef *pdataDef; // [esp+10h] [ebp-10h]
  unsigned int fc; // [esp+14h] [ebp-Ch]
  Scaleform::GFx::TimelineDef::Frame actionsList; // [esp+18h] [ebp-8h] BYREF

  pObject = (Scaleform::GFx::MovieDataDef::LoadTaskData **)psourceMovie->pBindData.pObject->pDataDef.pObject;
  pdataDef = (Scaleform::GFx::MovieDataDef *)pObject;
  v4 = 0;
  v5 = 0;
  fc = Scaleform::GFx::MovieDataDef::LoadTaskData::GetInitActionListSize(pObject[8]);
  if ( fc )
  {
    do
    {
      FileLength = (unsigned __int8 (__thiscall *)(Scaleform::GFx::MovieDataDef::LoadTaskData **, Scaleform::GFx::TimelineDef::Frame *, unsigned int))(*pObject)->Header.FileLength;
      actionsList.pTagPtrList = 0;
      actionsList.TagCount = 0;
      if ( FileLength(pObject, &actionsList, v5) && actionsList.TagCount )
      {
        do
        {
          v7 = (Scaleform::GFx::GFxInitImportActions *)actionsList.pTagPtrList[v4];
          if ( v7->IsInitImportActionsTag(v7) )
            Scaleform::GFx::GFxInitImportActions::ExecuteInContext(v7, this, psourceMovie, 1);
          else
            v7->ExecuteWithPriority(v7, this, AP_Highest);
          ++v4;
        }
        while ( v4 < actionsList.TagCount );
        pObject = (Scaleform::GFx::MovieDataDef::LoadTaskData **)pdataDef;
        v4 = 0;
      }
      ++v5;
    }
    while ( v5 < fc );
  }
}
