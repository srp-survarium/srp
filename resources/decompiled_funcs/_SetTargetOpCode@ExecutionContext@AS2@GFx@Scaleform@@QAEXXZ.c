void __thiscall Scaleform::GFx::AS2::ExecutionContext::SetTargetOpCode(Scaleform::GFx::AS2::ExecutionContext *this)
{
  Scaleform::GFx::AS2::Environment *pEnv; // eax
  unsigned __int8 Type; // bl
  Scaleform::GFx::AS2::Environment *v4; // eax
  int *v5; // edi
  int v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // ecx
  bool v10; // bl
  Scaleform::GFx::InteractiveObject *pOriginalTarget; // eax
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pWithStackArray; // edi
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::AS2::Environment *v14; // edi
  Scaleform::GFx::InteractiveObject *v15; // ecx
  Scaleform::GFx::AS2::Environment *v16; // esi
  Scaleform::GFx::AS2::Value *pCurrent; // ecx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  Scaleform::GFx::AS2::Environment *v19; // [esp-Ch] [ebp-40h]
  Scaleform::GFx::InteractiveObject *target; // [esp+Ch] [ebp-28h] BYREF
  Scaleform::GFx::ASString result; // [esp+10h] [ebp-24h] BYREF
  Scaleform::GFx::AS2::Value targetVal; // [esp+14h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value val; // [esp+24h] [ebp-10h] BYREF

  pEnv = this->pEnv;
  target = 0;
  Scaleform::GFx::AS2::Value::Value(&targetVal, pEnv->Stack.pCurrent);
  Type = targetVal.T.Type;
  if ( targetVal.T.Type != 5 )
  {
    v4 = this->pEnv;
    if ( targetVal.T.Type == 7 )
    {
      pOriginalTarget = Scaleform::GFx::AS2::Value::ToCharacter(v4->Stack.pCurrent, this->pEnv);
      target = pOriginalTarget;
      goto LABEL_16;
    }
    v5 = (int *)Scaleform::GFx::AS2::Value::ToStringVersioned(&targetVal, &result, v4, this->Version);
    if ( Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&targetVal);
    v6 = *v5;
    ++*(_DWORD *)(v6 + 12);
    targetVal.NV.Int32Value = v6;
    pNode = result.pNode;
    --result.pNode->RefCount;
    v8 = pNode->RefCount == 0;
    targetVal.T.Type = 5;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  Scaleform::GFx::AS2::Value::ToStringImpl(&targetVal, &result, this->pEnv, -1, 0);
  v9 = result.pNode;
  v10 = result.pNode->Size == 0;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  if ( v10 )
  {
    pOriginalTarget = this->pOriginalTarget;
    target = pOriginalTarget;
  }
  else
  {
    pWithStackArray = this->WithStack.pWithStackArray;
    v19 = this->pEnv;
    val.T.Type = 0;
    Scaleform::GFx::AS2::Value::ToStringImpl(v19->Stack.pCurrent, &result, v19, -1, 0);
    Scaleform::GFx::AS2::Environment::GetVariable(this->pEnv, &result, &val, pWithStackArray, &target, 0, 0);
    v13 = result.pNode;
    --result.pNode->RefCount;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
    pOriginalTarget = target;
  }
LABEL_16:
  v14 = this->pEnv;
  if ( pOriginalTarget )
  {
    *((_BYTE *)v14 + 194) &= ~2u;
    v15 = pOriginalTarget;
    v14->Target = pOriginalTarget;
  }
  else
  {
    v15 = this->pOriginalTarget;
    *((_BYTE *)v14 + 194) |= 2u;
    v14->Target = v15;
  }
  v14->StringContext.SWFVersion = Scaleform::GFx::DisplayObjectBase::GetVersion(v15);
  v16 = this->pEnv;
  pCurrent = v16->Stack.pCurrent;
  p_Stack = &v16->Stack;
  if ( pCurrent->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(pCurrent);
  if ( --p_Stack->pCurrent < p_Stack->pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(p_Stack);
  if ( targetVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&targetVal);
}
