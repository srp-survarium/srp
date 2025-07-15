char __thiscall Scaleform::GFx::AS2::MovieRoot::GetVariable(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::ASStringNode *pval,
        char *ppathToVar)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  unsigned int Size; // edx
  int v6; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *i; // ecx
  Scaleform::GFx::Value *v10; // ebx
  Scaleform::GFx::MovieImpl *v11; // edx
  unsigned int v12; // ecx
  unsigned int v13; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *v14; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *v15; // edx
  Scaleform::GFx::InteractiveObject *pObject; // eax
  int v17; // ecx
  Scaleform::GFx::AS2::Environment *v18; // esi
  Scaleform::GFx::ASStringNode *v19; // eax
  Scaleform::GFx::ASStringNode *v20; // eax
  Scaleform::GFx::DoublePrecisionGuard dpg; // [esp+Ch] [ebp-18h] BYREF
  unsigned int _CurrentState; // [esp+10h] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value retVal; // [esp+14h] [ebp-10h] BYREF

  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v6 = 0;
  if ( !Size )
    return 0;
  Data = pMovieImpl->MovieLevels.Data.Data;
  for ( i = Data; i->Level; ++i )
  {
    if ( ++v6 >= Size )
      return 0;
  }
  if ( !Data[v6].pSprite.pObject )
    return 0;
  v10 = (Scaleform::GFx::Value *)pval;
  if ( !pval )
    return 0;
  _controlfp_s(&dpg.fpc, 0, 0);
  _controlfp_s(&_CurrentState, (unsigned int)&_sbh_sizeHeaderList, 0x30000u);
  v11 = this->pMovieImpl;
  v12 = v11->MovieLevels.Data.Size;
  v13 = 0;
  if ( v12 )
  {
    v14 = v11->MovieLevels.Data.Data;
    v15 = v14;
    while ( v15->Level )
    {
      ++v13;
      ++v15;
      if ( v13 >= v12 )
        goto LABEL_12;
    }
    pObject = v14[v13].pSprite.pObject;
  }
  else
  {
LABEL_12:
    pObject = 0;
  }
  v17 = (int)pObject + 4 * pObject->AvmObjOffset;
  v18 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v17 + 124))(v17);
  pval = Scaleform::GFx::ASStringManager::CreateStringNode(
           (Scaleform::GFx::ASStringManager *)v18->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
           ppathToVar);
  ++pval->RefCount;
  retVal.T.Type = 0;
  if ( !Scaleform::GFx::AS2::Environment::GetVariable(v18, (const Scaleform::GFx::ASString *)&pval, &retVal, 0, 0, 0, 0) )
  {
    if ( retVal.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&retVal);
    v20 = pval;
    --pval->RefCount;
    if ( !v20->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v20);
    _controlfp_s((unsigned int *)&ppathToVar, dpg.fpc, 0x30000u);
    return 0;
  }
  Scaleform::GFx::AS2::MovieRoot::ASValue2Value(this, v18, &retVal, v10);
  if ( retVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&retVal);
  v19 = pval;
  --pval->RefCount;
  if ( !v19->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  _controlfp_s((unsigned int *)&ppathToVar, dpg.fpc, 0x30000u);
  return 1;
}
