void __thiscall Scaleform::GFx::Sprite::ExecuteImportedInitActions(
        Scaleform::GFx::Sprite *this,
        Scaleform::GFx::MovieDefImpl *psourceMovie)
{
  Scaleform::GFx::MovieDataDef *pObject; // esi
  unsigned int v4; // ebx
  unsigned int v5; // ebp
  bool (__thiscall *GetInitActions)(struct Scaleform::GFx::MovieDataDef *, Scaleform::GFx::TimelineDef::Frame *, int); // edx
  Scaleform::GFx::GFxInitImportActions *v7; // esi
  Scaleform::GFx::MovieDataDef *v8; // [esp+10h] [ebp-10h]
  unsigned int InitActionListSize; // [esp+14h] [ebp-Ch]
  int v10; // [esp+18h] [ebp-8h] BYREF
  unsigned int v11; // [esp+1Ch] [ebp-4h]

  pObject = psourceMovie->pBindData.pObject->pDataDef.pObject;
  v8 = pObject;
  v4 = 0;
  v5 = 0;
  InitActionListSize = Scaleform::GFx::MovieDataDef::LoadTaskData::GetInitActionListSize(pObject->pData.pObject);
  if ( InitActionListSize )
  {
    do
    {
      GetInitActions = pObject->GetInitActions;
      v10 = 0;
      v11 = 0;
      if ( GetInitActions(pObject, (Scaleform::GFx::TimelineDef::Frame *)&v10, v5) && v11 )
      {
        do
        {
          v7 = *(Scaleform::GFx::GFxInitImportActions **)(v10 + 4 * v4);
          if ( v7->IsInitImportActionsTag(v7) )
            Scaleform::GFx::GFxInitImportActions::ExecuteInContext(v7, this, psourceMovie, 1);
          else
            v7->ExecuteWithPriority(v7, this, AP_Highest);
          ++v4;
        }
        while ( v4 < v11 );
        pObject = v8;
        v4 = 0;
      }
      ++v5;
    }
    while ( v5 < InitActionListSize );
  }
}
