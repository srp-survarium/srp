void __thiscall Scaleform::GFx::AS2::ExecutionContext::EnumerateOpCode(
        Scaleform::GFx::AS2::ExecutionContext *this,
        Scaleform::GFx::ASStringNode *actionId)
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
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  __int64 v17; // [esp-10h] [ebp-5Ch]
  __int64 pWithStackArray; // [esp-8h] [ebp-54h]
  Scaleform::GFx::AS2::Environment *v19; // [esp+4h] [ebp-48h]
  void **v20; // [esp+10h] [ebp-3Ch] BYREF
  Scaleform::GFx::AS2::Environment *v21; // [esp+14h] [ebp-38h]
  Scaleform::GFx::AS2::ActionLogger *p_LogF; // [esp+18h] [ebp-34h]
  Scaleform::GFx::AS2::Value v23; // [esp+1Ch] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value v; // [esp+2Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v25; // [esp+3Ch] [ebp-10h] BYREF

  Scaleform::GFx::AS2::Value::Value(&v23, this->pEnv->Stack.pCurrent);
  pCurrent = this->pEnv->Stack.pCurrent;
  p_Stack = &this->pEnv->Stack;
  if ( pCurrent->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(pCurrent);
  if ( --p_Stack->pCurrent < p_Stack->pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(p_Stack);
  v.T.Type = 0;
  Scaleform::GFx::AS2::Value::DropRefs(&v);
  pEnv = this->pEnv;
  v6 = ++pEnv->Stack.pCurrent;
  v7 = &pEnv->Stack;
  v.T.Type = 1;
  if ( v6 >= v7->pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(v7);
  if ( v7->pCurrent )
    Scaleform::GFx::AS2::Value::Value(v7->pCurrent, &v);
  v8 = this->pEnv;
  if ( actionId != (Scaleform::GFx::ASStringNode *)85 )
  {
    Scaleform::GFx::AS2::Value::ToStringImpl(&v23, (Scaleform::GFx::ASString *)&actionId, v8, -1, 0);
    v12 = this->pEnv;
    pWithStackArray = (unsigned int)this->WithStack.pWithStackArray;
    HIDWORD(v17) = &v25;
    LODWORD(v17) = &actionId;
    v25.T.Type = 0;
    if ( Scaleform::GFx::AS2::Environment::GetVariable(v12, v17, pWithStackArray, 0, 0) )
    {
      v19 = this->pEnv;
      if ( v25.T.Type == 7 )
      {
        v13 = Scaleform::GFx::AS2::Value::ToAvmCharacter(&v25, v19);
        if ( !v13 )
          goto LABEL_31;
        v10 = &v13->Scaleform::GFx::AS2::ObjectInterface;
      }
      else
      {
        v14 = Scaleform::GFx::AS2::Value::ToObject(&v25, v19);
        if ( !v14 )
          goto LABEL_31;
        v10 = &v14->Scaleform::GFx::AS2::ObjectInterface;
      }
      if ( v10 )
      {
        if ( v25.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v25);
        v15 = actionId;
        --actionId->RefCount;
        if ( !v15->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v15);
LABEL_28:
        if ( (*((_BYTE *)this + 54) & 2) != 0 )
          Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::LogAction(
            &this->LogF,
            "---enumerate - Push: NULL\n");
        v21 = this->pEnv;
        v20 = (void **)&`Scaleform::GFx::AS2::ExecutionContext::EnumerateOpCode'::`17'::EnumerateOpVisitor::`vftable';
        p_LogF = &this->LogF;
        v10->VisitMembers(v10, &v21->StringContext, (Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *)&v20, 11u, 0);
        v20 = &Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
        goto LABEL_35;
      }
    }
LABEL_31:
    if ( v25.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v25);
    v16 = actionId;
    --actionId->RefCount;
    if ( !v16->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    goto LABEL_35;
  }
  if ( v23.T.Type == 7 )
  {
    v9 = Scaleform::GFx::AS2::Value::ToAvmCharacter(&v23, v8);
    if ( !v9 )
      goto LABEL_35;
    v10 = &v9->Scaleform::GFx::AS2::ObjectInterface;
  }
  else
  {
    v11 = Scaleform::GFx::AS2::Value::ToObject(&v23, v8);
    if ( !v11 )
      goto LABEL_35;
    v10 = &v11->Scaleform::GFx::AS2::ObjectInterface;
  }
  if ( v10 )
    goto LABEL_28;
LABEL_35:
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  if ( v23.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v23);
}
