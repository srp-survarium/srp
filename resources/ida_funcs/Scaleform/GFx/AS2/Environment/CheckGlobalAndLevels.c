Scaleform::GFx::Bool3W *__userpurge Scaleform::GFx::AS2::Environment::CheckGlobalAndLevels@<eax>(
        Scaleform::GFx::AS2::Environment *this@<ecx>,
        Scaleform::GFx::ASMovieRootBase *a2@<ebx>,
        Scaleform::GFx::Bool3W *result,
        const Scaleform::GFx::AS2::Environment::GetVarParams *params)
{
  const Scaleform::GFx::AS2::Environment::GetVarParams *v5; // edi
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  Scaleform::GFx::ASMovieRootBase *v7; // ecx
  Scaleform::GFx::ASStringNode *v8; // edx
  Scaleform::GFx::Sprite *LevelMovie; // eax
  Scaleform::GFx::Bool3W *v10; // eax
  Scaleform::GFx::MovieImpl *pMovieRoot; // edx
  const Scaleform::GFx::ASString *VarName; // ebp
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::ASMovieRootBase *pObject; // ebx
  Scaleform::GFx::ASStringNode **p_pNode; // ebp
  Scaleform::GFx::ASStringNode *v16; // ecx
  unsigned int v17; // eax
  char *pData; // [esp-Ch] [ebp-20h]
  char *caseSensitive; // [esp+10h] [ebp-4h]

  v5 = params;
  if ( this->StringContext.SWFVersion <= 6u )
  {
    pMovieRoot = this->StringContext.pContext->pMovieRoot;
    VarName = params->VarName;
    pNode = params->VarName->pNode;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    if ( !pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pNode);
    if ( pObject[21].AdvanceFrame == (void (__thiscall *)(Scaleform::GFx::ASMovieRootBase *, bool))VarName->pNode->pLower )
      goto LABEL_3;
    p_pNode = &v5->VarName->pNode;
    a2 = this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
    v16 = v5->VarName->pNode;
    if ( !v16->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v16);
    if ( *(Scaleform::GFx::ASStringNode **)(*(_DWORD *)&a2[20].AVMVersion + 8) == (*p_pNode)->pLower )
    {
      Scaleform::GFx::AS2::Value::SetAsObject(v5->pResult, this->StringContext.pContext->pGlobal.pObject);
      v10 = result;
      result->Value = 1;
      return v10;
    }
  }
  else
  {
    pContext = this->StringContext.pContext;
    v7 = pContext->pMovieRoot->pASMovieRoot.pObject;
    v8 = params->VarName->pNode;
    if ( (Scaleform::GFx::ASStringNode *)v7[21].__vftable == v8 )
    {
LABEL_3:
      LevelMovie = (Scaleform::GFx::Sprite *)this->Target->GetTopParent(this->Target, 0);
LABEL_4:
      Scaleform::GFx::AS2::Value::SetAsCharacter(v5->pResult, LevelMovie);
      v10 = result;
      result->Value = 1;
      return v10;
    }
    if ( *(Scaleform::GFx::ASStringNode **)&v7[20].AVMVersion == v8 )
    {
      Scaleform::GFx::AS2::Value::SetAsObject(params->pResult, pContext->pGlobal.pObject);
      v10 = result;
      result->Value = 1;
      return v10;
    }
  }
  LOBYTE(caseSensitive) = this->StringContext.SWFVersion > 6u;
  pData = (char *)v5->VarName->pNode->pData;
  params = 0;
  v17 = Scaleform::GFx::AS2::MovieRoot::ParseLevelName(
          caseSensitive,
          (unsigned int)a2,
          pData,
          (char **)&params,
          (bool)caseSensitive);
  if ( v17 == -1 || LOBYTE(params->VarName) )
  {
    v10 = result;
    result->Value = 0;
  }
  else
  {
    LevelMovie = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(
                   (Scaleform::GFx::AS2::MovieRoot *)this->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
                   v17);
    if ( LevelMovie )
      goto LABEL_4;
    v10 = result;
    result->Value = 2;
  }
  return v10;
}
