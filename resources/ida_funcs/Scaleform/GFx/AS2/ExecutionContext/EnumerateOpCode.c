void __thiscall Scaleform::GFx::AS2::ExecutionContext::EnumerateOpCode(
        Scaleform::GFx::AS2::ExecutionContext *this,
        Scaleform::GFx::ASString actionId)
{
  Scaleform::GFx::AS2::Value *pCurrent; // ecx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  Scaleform::GFx::AS2::Environment *pEnv; // esi
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v7; // esi
  Scaleform::GFx::AS2::Environment *v8; // eax
  Scaleform::GFx::AS2::AvmCharacter *v9; // eax
  Scaleform::GFx::AS2::ObjectInterface *v10; // esi
  Scaleform::GFx::AS2::Object *v11; // eax
  Scaleform::GFx::AS2::Environment *v12; // ecx
  Scaleform::GFx::AS2::AvmCharacter *v13; // eax
  Scaleform::GFx::AS2::Object *v14; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pWithStackArray; // [esp-8h] [ebp-54h]
  Scaleform::GFx::AS2::Environment *v18; // [esp+4h] [ebp-48h]
  Scaleform::GFx::AS2::ExecutionContext::EnumerateOpCode::__l15::EnumerateOpVisitor memberVisitor; // [esp+10h] [ebp-3Ch] BYREF
  Scaleform::GFx::AS2::Value varName; // [esp+1Ch] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value nullvalue; // [esp+2Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value variable; // [esp+3Ch] [ebp-10h] BYREF

  Scaleform::GFx::AS2::Value::Value(&varName, this->pEnv->Stack.pCurrent);
  pCurrent = this->pEnv->Stack.pCurrent;
  p_Stack = &this->pEnv->Stack;
  if ( pCurrent->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(pCurrent);
  if ( --p_Stack->pCurrent < p_Stack->pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(p_Stack);
  nullvalue.T.Type = 0;
  Scaleform::GFx::AS2::Value::DropRefs(&nullvalue);
  pEnv = this->pEnv;
  v6 = ++pEnv->Stack.pCurrent;
  v7 = &pEnv->Stack;
  nullvalue.T.Type = 1;
  if ( v6 >= v7->pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(v7);
  if ( v7->pCurrent )
    Scaleform::GFx::AS2::Value::Value(v7->pCurrent, &nullvalue);
  v8 = this->pEnv;
  if ( actionId.pNode != (Scaleform::GFx::ASStringNode *)85 )
  {
    Scaleform::GFx::AS2::Value::ToStringImpl(&varName, &actionId, v8, -1, 0);
    v12 = this->pEnv;
    pWithStackArray = this->WithStack.pWithStackArray;
    variable.T.Type = 0;
    if ( Scaleform::GFx::AS2::Environment::GetVariable(v12, &actionId, &variable, pWithStackArray, 0, 0, 0) )
    {
      v18 = this->pEnv;
      if ( variable.T.Type == 7 )
      {
        v13 = Scaleform::GFx::AS2::Value::ToAvmCharacter(&variable, v18);
        if ( !v13 )
          goto LABEL_29;
        v10 = &v13->Scaleform::GFx::AS2::ObjectInterface;
      }
      else
      {
        v14 = Scaleform::GFx::AS2::Value::ToObject(&variable, v18);
        if ( !v14 )
          goto LABEL_29;
        v10 = &v14->Scaleform::GFx::AS2::ObjectInterface;
      }
      if ( v10 )
      {
        if ( variable.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&variable);
        pNode = actionId.pNode;
        --actionId.pNode->RefCount;
        if ( !pNode->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
LABEL_28:
        memberVisitor.pEnv = this->pEnv;
        memberVisitor.__vftable = (Scaleform::GFx::AS2::ExecutionContext::EnumerateOpCode::__l15::EnumerateOpVisitor_vtbl *)&`Scaleform::GFx::AS2::ExecutionContext::EnumerateOpCode'::`15'::EnumerateOpVisitor::`vftable';
        memberVisitor.pLog = &this->LogF;
        v10->VisitMembers(v10, &memberVisitor.pEnv->StringContext, &memberVisitor, 11u, 0);
        memberVisitor.__vftable = (Scaleform::GFx::AS2::ExecutionContext::EnumerateOpCode::__l15::EnumerateOpVisitor_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
        goto LABEL_33;
      }
    }
LABEL_29:
    if ( variable.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&variable);
    v16 = actionId.pNode;
    --actionId.pNode->RefCount;
    if ( !v16->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    goto LABEL_33;
  }
  if ( varName.T.Type == 7 )
  {
    v9 = Scaleform::GFx::AS2::Value::ToAvmCharacter(&varName, v8);
    if ( !v9 )
      goto LABEL_33;
    v10 = &v9->Scaleform::GFx::AS2::ObjectInterface;
  }
  else
  {
    v11 = Scaleform::GFx::AS2::Value::ToObject(&varName, v8);
    if ( !v11 )
      goto LABEL_33;
    v10 = &v11->Scaleform::GFx::AS2::ObjectInterface;
  }
  if ( v10 )
    goto LABEL_28;
LABEL_33:
  if ( nullvalue.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&nullvalue);
  if ( varName.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&varName);
}
