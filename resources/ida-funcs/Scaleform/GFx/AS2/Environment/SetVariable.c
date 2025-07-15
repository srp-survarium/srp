char __userpurge Scaleform::GFx::AS2::Environment::SetVariable@<al>(
        Scaleform::GFx::AS2::Environment *this@<ecx>,
        const Scaleform::GFx::ASString *a2@<ebp>,
        Scaleform::GFx::ASStringNode *varname,
        const Scaleform::GFx::AS2::Value *val,
        const Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pwithStack,
        bool doDisplayErrors)
{
  const Scaleform::GFx::ASString *v7; // edi
  Scaleform::GFx::AS2::Value *v8; // eax
  Scaleform::GFx::ASStringNode *v9; // ebp
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::ASStringNode *RefCount; // eax
  const Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v13; // edx
  Scaleform::GFx::AS2::ObjectInterface *v14; // eax
  bool (__thiscall *SetMember)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::Environment *, const Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::Value *, const Scaleform::GFx::AS2::PropFlags *); // edx
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  const Scaleform::GFx::ASString *v19; // [esp+4h] [ebp-44h]
  Scaleform::GFx::AS2::Value v20; // [esp+10h] [ebp-38h] BYREF
  Scaleform::GFx::AS2::Value v21; // [esp+20h] [ebp-28h] BYREF
  Scaleform::GFx::AS2::Environment::GetVarParams v22; // [esp+30h] [ebp-18h] BYREF

  v7 = (const Scaleform::GFx::ASString *)varname;
  if ( (this->Target->pASRoot->pMovieImpl->Flags & 4) != 0 )
  {
    Scaleform::GFx::AS2::Value::Value(&v21, val);
    Scaleform::GFx::AS2::Value::ToStringImpl(
      v8,
      (Scaleform::GFx::ASString *)&varname,
      this,
      -1,
      (Scaleform::GFx::ASString)1);
    if ( v21.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v21);
    v19 = a2;
    v9 = varname;
    Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogAction(
      this,
      "-------------- %s = %s\n",
      v7->pNode->pData,
      varname->pData);
    if ( v9->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    a2 = v19;
  }
  if ( (v7->pNode->HashFlags & 0x2000000) != 0 || !Scaleform::GFx::AS2::Environment::IsPath(v7) )
  {
    Scaleform::GFx::AS2::Environment::SetVariableRaw(this, v7, val, pwithStack);
    return 1;
  }
  pContext = this->StringContext.pContext;
  v20.T.Type = 0;
  RefCount = (Scaleform::GFx::ASStringNode *)pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
  v13 = pwithStack;
  v22.pResult = &v21;
  varname = RefCount;
  ++RefCount->RefCount;
  v22.pWithStack = v13;
  v21.T.Type = 0;
  v22.VarName = v7;
  v22.ppNewTarget = 0;
  v22.pOwner = &v20;
  v22.ExcludeFlags = 0;
  Scaleform::GFx::AS2::Environment::FindVariable(this, a2, (int)this, &v22, 0, (Scaleform::GFx::ASString *)&varname);
  if ( !v20.T.Type || v20.T.Type == 10 )
  {
    if ( doDisplayErrors && this->IsVerboseActionErrors(this) )
      Scaleform::GFx::AS2::Environment::LogScriptError(
        this,
        "SetVariable failed: can't resolve the path \"%s\"",
        v7->pNode->pData);
  }
  else
  {
    v14 = Scaleform::GFx::AS2::Value::ToObjectInterface(&v20, this);
    if ( v14 )
    {
      SetMember = v14->SetMember;
      doDisplayErrors = 0;
      SetMember(
        v14,
        this,
        (const Scaleform::GFx::ASString *)&varname,
        val,
        (const Scaleform::GFx::AS2::PropFlags *)&doDisplayErrors);
      if ( v21.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v21);
      v16 = varname;
      --varname->RefCount;
      if ( !v16->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
      if ( v20.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v20);
      return 1;
    }
  }
  if ( v21.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v21);
  v18 = varname;
  --varname->RefCount;
  if ( !v18->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  if ( v20.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v20);
  return 0;
}
