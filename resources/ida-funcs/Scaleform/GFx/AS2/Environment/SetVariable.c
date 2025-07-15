char __userpurge Scaleform::GFx::AS2::Environment::SetVariable@<al>(
        Scaleform::GFx::AS2::Environment *this@<ecx>,
        int a2@<ebp>,
        Scaleform::GFx::ASString *varname,
        const Scaleform::GFx::AS2::Value *val,
        const Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pwithStack,
        bool doDisplayErrors)
{
  const Scaleform::GFx::ASString *v7; // edi
  Scaleform::GFx::AS2::Value *v8; // eax
  Scaleform::GFx::ASStringNode *v9; // ebp
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  const Scaleform::GFx::ASString *RefCount; // eax
  const Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v13; // edx
  Scaleform::GFx::AS2::ObjectInterface *v14; // eax
  bool (__thiscall *SetMember)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::Environment *, const Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::Value *, const Scaleform::GFx::AS2::PropFlags *); // edx
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  int v19; // [esp+4h] [ebp-44h]
  Scaleform::GFx::AS2::Value owner; // [esp+10h] [ebp-38h] BYREF
  Scaleform::GFx::AS2::Value curval; // [esp+20h] [ebp-28h] BYREF
  Scaleform::GFx::AS2::Environment::GetVarParams params; // [esp+30h] [ebp-18h] BYREF

  v7 = varname;
  if ( (this->Target->pASRoot->pMovieImpl->Flags & 4) != 0 )
  {
    Scaleform::GFx::AS2::Value::Value(&curval, val);
    Scaleform::GFx::AS2::Value::ToStringImpl(
      v8,
      (Scaleform::GFx::ASString *)&varname,
      this,
      -1,
      (const Scaleform::GFx::ASString)1);
    if ( curval.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&curval);
    v19 = a2;
    v9 = (Scaleform::GFx::ASStringNode *)varname;
    Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogAction(
      this,
      "-------------- %s = %s\n",
      v7->pNode->pData,
      (const char *)varname->pNode);
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
  owner.T.Type = 0;
  RefCount = (const Scaleform::GFx::ASString *)pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
  v13 = pwithStack;
  params.pResult = &curval;
  varname = (Scaleform::GFx::ASString *)RefCount;
  ++RefCount[3].pNode;
  params.pWithStack = v13;
  curval.T.Type = 0;
  params.VarName = v7;
  params.ppNewTarget = 0;
  params.pOwner = &owner;
  params.ExcludeFlags = 0;
  Scaleform::GFx::AS2::Environment::FindVariable(this, a2, (int)this, &params, 0, (Scaleform::GFx::ASString *)&varname);
  if ( !owner.T.Type || owner.T.Type == 10 )
  {
    if ( doDisplayErrors && this->IsVerboseActionErrors(this) )
      Scaleform::GFx::AS2::Environment::LogScriptError(
        this,
        "SetVariable failed: can't resolve the path \"%s\"",
        v7->pNode->pData);
  }
  else
  {
    v14 = Scaleform::GFx::AS2::Value::ToObjectInterface(&owner, this);
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
      if ( curval.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&curval);
      v16 = (Scaleform::GFx::ASStringNode *)varname;
      --varname[3].pNode;
      if ( !v16->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
      if ( owner.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&owner);
      return 1;
    }
  }
  if ( curval.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&curval);
  v18 = (Scaleform::GFx::ASStringNode *)varname;
  --varname[3].pNode;
  if ( !v18->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  if ( owner.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&owner);
  return 0;
}
