void __thiscall Scaleform::GFx::AS2::ExecutionContext::SetTargetOpCode(Scaleform::GFx::AS2::ExecutionContext *this)
{
  Scaleform::GFx::AS2::Environment *pEnv; // eax
  unsigned __int8 Type; // bl
  int *v4; // edi
  int v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  bool v7; // zf
  Scaleform::GFx::ASStringNode *v8; // ecx
  bool v9; // bl
  Scaleform::GFx::InteractiveObject *pOriginalTarget; // eax
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pWithStackArray; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // edi
  Scaleform::GFx::ASStringNode *v14; // edi
  Scaleform::GFx::InteractiveObject *v15; // ecx
  Scaleform::GFx::AS2::Environment *v16; // edi
  Scaleform::GFx::AS2::Environment *v17; // esi
  Scaleform::GFx::AS2::Value *pCurrent; // ecx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  __int64 v20; // [esp-18h] [ebp-4Ch]
  Scaleform::GFx::AS2::Environment *v21; // [esp-Ch] [ebp-40h]
  Scaleform::GFx::InteractiveObject *v22; // [esp+Ch] [ebp-28h] BYREF
  Scaleform::GFx::ASString result; // [esp+10h] [ebp-24h] BYREF
  Scaleform::GFx::AS2::Value v24; // [esp+14h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v25; // [esp+24h] [ebp-10h] BYREF

  pEnv = this->pEnv;
  v22 = 0;
  Scaleform::GFx::AS2::Value::Value(&v24, pEnv->Stack.pCurrent);
  Type = v24.T.Type;
  if ( v24.T.Type != 5 )
  {
    if ( v24.T.Type == 7 )
    {
      pOriginalTarget = Scaleform::GFx::AS2::Value::ToCharacter(this->pEnv->Stack.pCurrent, this->pEnv);
      v22 = pOriginalTarget;
      goto LABEL_22;
    }
    v4 = (int *)Scaleform::GFx::AS2::Value::ToStringVersioned(&v24, &result, this->pEnv, this->Version);
    if ( Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v24);
    v5 = *v4;
    ++*(_DWORD *)(v5 + 12);
    v24.NV.Int32Value = v5;
    pNode = result.pNode;
    --result.pNode->RefCount;
    v7 = pNode->RefCount == 0;
    v24.T.Type = 5;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  Scaleform::GFx::AS2::Value::ToStringImpl(&v24, &result, this->pEnv, -1, 0);
  v8 = result.pNode;
  v9 = result.pNode->Size == 0;
  v7 = result.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  if ( v9 )
  {
    pOriginalTarget = this->pOriginalTarget;
    v22 = pOriginalTarget;
  }
  else
  {
    pWithStackArray = this->WithStack.pWithStackArray;
    v21 = this->pEnv;
    v25.T.Type = 0;
    Scaleform::GFx::AS2::Value::ToStringImpl(v21->Stack.pCurrent, &result, v21, -1, 0);
    HIDWORD(v20) = &v25;
    LODWORD(v20) = &result;
    Scaleform::GFx::AS2::Environment::GetVariable(
      this->pEnv,
      v20,
      __SPAIR64__(&v22, (unsigned int)pWithStackArray),
      0,
      0);
    v12 = result.pNode;
    --result.pNode->RefCount;
    if ( !v12->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    if ( (*((_BYTE *)this + 54) & 2) != 0 )
    {
      Scaleform::GFx::AS2::Value::ToStringImpl(
        this->pEnv->Stack.pCurrent,
        &result,
        this->pEnv,
        -1,
        (Scaleform::GFx::ASString)1);
      v13 = result.pNode;
      if ( v22 )
        Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::LogAction(
          &this->LogF,
          "-- ActionSetTarget2: %s (%d)\n",
          result.pNode->pData,
          (unsigned __int16)v22->Id.Id);
      else
        Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::LogAction(
          &this->LogF,
          "-- ActionSetTarget2: %s - no target found\n",
          result.pNode->pData);
      v7 = v13->RefCount-- == 1;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    }
    if ( v25.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v25);
    pOriginalTarget = v22;
  }
LABEL_22:
  if ( pOriginalTarget )
  {
    v16 = this->pEnv;
    *((_BYTE *)v16 + 194) &= ~2u;
    v15 = pOriginalTarget;
    v16->Target = pOriginalTarget;
  }
  else
  {
    if ( (*((_BYTE *)this + 54) & 1) != 0 )
    {
      Scaleform::GFx::AS2::Value::ToStringImpl(&v24, &result, this->pEnv, -1, (Scaleform::GFx::ASString)1);
      v14 = result.pNode;
      Scaleform::GFx::AS2::ActionLogger::LogScriptError(
        &this->LogF,
        "SetTarget2(tellTarget) with invalid target '%s'.",
        result.pNode->pData);
      v7 = v14->RefCount-- == 1;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    }
    v15 = this->pOriginalTarget;
    v16 = this->pEnv;
    *((_BYTE *)v16 + 194) |= 2u;
    v16->Target = v15;
  }
  v16->StringContext.SWFVersion = Scaleform::GFx::DisplayObjectBase::GetVersion(v15);
  v17 = this->pEnv;
  pCurrent = v17->Stack.pCurrent;
  p_Stack = &v17->Stack;
  if ( pCurrent->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(pCurrent);
  if ( --p_Stack->pCurrent < p_Stack->pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(p_Stack);
  if ( v24.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v24);
}
