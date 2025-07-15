Scaleform::GFx::AS2::FunctionRef *__thiscall Scaleform::GFx::AS2::Value::ResolveFunctionName(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::FunctionRef *result,
        const Scaleform::GFx::AS2::Environment *penv)
{
  const Scaleform::GFx::AS2::Environment *v3; // edi
  Scaleform::GFx::ASStringNode *RefCount; // eax
  Scaleform::GFx::AS2::Environment *pStringNode; // esi
  bool v6; // zf
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::AS2::FunctionObject *v8; // eax
  unsigned int v9; // ecx
  Scaleform::GFx::AS2::FunctionRef *v10; // eax

  v3 = penv;
  if ( penv && this->T.Type == 11 )
  {
    RefCount = (Scaleform::GFx::ASStringNode *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
    ++RefCount->RefCount;
    pStringNode = (Scaleform::GFx::AS2::Environment *)this->V.pStringNode;
    ++pStringNode->Stack.pPageEnd;
    v6 = RefCount->RefCount-- == 1;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode(RefCount);
    pContext = v3->StringContext.pContext;
    penv = pStringNode;
    v8 = Scaleform::GFx::AS2::GlobalContext::ResolveFunctionName(pContext, (const Scaleform::GFx::ASString *)&penv);
    if ( v8 )
      v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
    result->Flags = 0;
    result->Function = v8;
    if ( v8 )
      v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
    result->pLocalFrame = 0;
    if ( v8 )
    {
      v9 = v8->RefCount;
      if ( (v9 & 0x3FFFFFF) != 0 )
      {
        v8->RefCount = v9 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
      }
    }
    v6 = pStringNode->Stack.pPageEnd-- == (Scaleform::GFx::AS2::Value *)1;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)pStringNode);
    return result;
  }
  else
  {
    v10 = result;
    result->Flags = 0;
    result->Function = 0;
    result->pLocalFrame = 0;
  }
  return v10;
}
