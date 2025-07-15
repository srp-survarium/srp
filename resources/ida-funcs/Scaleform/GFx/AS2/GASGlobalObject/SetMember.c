char __thiscall Scaleform::GFx::AS2::GASGlobalObject::SetMember(
        Scaleform::GFx::AS2::GASGlobalObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::ASStringNode *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::Environment *v5; // edi
  Scaleform::GFx::ASStringNode *p_StringContext; // ebp
  Scaleform::GFx::ASMovieRootBase *pObject; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax
  Scaleform::GFx::ASStringManager *v11; // ecx
  Scaleform::GFx::ASStringNode *ConstStringNode; // edi
  char v14; // bl
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // ebx
  bool v18; // al
  Scaleform::GFx::MovieImpl *v19; // ebx
  bool v20; // al
  Scaleform::GFx::AS2::Value v21; // [esp+10h] [ebp-10h] BYREF

  v5 = penv;
  p_StringContext = (Scaleform::GFx::ASStringNode *)&penv->StringContext;
  pObject = penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
  pNode = name->pNode;
  if ( name->pNode == (Scaleform::GFx::ASStringNode *)pObject[22].pMovieImpl )
  {
    this->ResolveHandler.pLocalFrame->Callee.V.FunctionValue.Flags = !Scaleform::GFx::AS2::Value::ToBool(
                                                                        (Scaleform::GFx::AS2::Value *)val,
                                                                        (int)penv,
                                                                        penv)
                                                                   + 1;
    pLocalFrame = this->ResolveHandler.pLocalFrame;
    v11 = *(Scaleform::GFx::ASStringManager **)(pLocalFrame->PrevFrame.pObject->RefCount + 788);
    if ( pLocalFrame->Callee.V.FunctionValue.Flags == 1 )
    {
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v11, "4.2.21", 6u, 0);
      ++ConstStringNode->RefCount;
      v21.T.Type = 5;
      v21.NV.Int32Value = (int)ConstStringNode;
      ++ConstStringNode->RefCount;
      Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
        (Scaleform::GFx::AS2::ObjectInterface *)this,
        p_StringContext,
        "gfxVersion",
        &v21);
      if ( v21.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v21);
      if ( ConstStringNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
      v5 = penv;
    }
    else
    {
      val = Scaleform::GFx::ASStringManager::CreateConstStringNode(v11, "gfxVersion", 0xAu, 0);
      ++val->RefCount;
      ((void (__thiscall *)(Scaleform::GFx::AS2::GASGlobalObject *, Scaleform::GFx::ASStringNode *, Scaleform::GFx::ASStringNode **))this->GetASCharacter)(
        this,
        p_StringContext,
        &val);
      v16 = val;
      --val->RefCount;
      if ( !v16->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    }
    v21.T.Type = 10;
    v14 = Scaleform::GFx::AS2::Object::SetMember(this, v5, name, &v21, flags);
    if ( v21.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v21);
    return v14;
  }
  else
  {
    if ( this->ResolveHandler.pLocalFrame->Callee.V.FunctionValue.Flags == 1 )
    {
      if ( pNode == (Scaleform::GFx::ASStringNode *)pObject[22].pASSupport.pObject )
      {
        pMovieImpl = penv->Target->pASRoot->pMovieImpl;
        if ( pMovieImpl )
        {
          v18 = Scaleform::GFx::AS2::Value::ToBool((Scaleform::GFx::AS2::Value *)val, (int)penv, penv);
          Scaleform::GFx::MovieImpl::SetNoInvisibleAdvanceFlag(pMovieImpl, v18);
        }
      }
      else if ( pNode == *(Scaleform::GFx::ASStringNode **)&pObject[22].AVMVersion )
      {
        v19 = penv->Target->pASRoot->pMovieImpl;
        if ( v19 )
        {
          v20 = Scaleform::GFx::AS2::Value::ToBool((Scaleform::GFx::AS2::Value *)val, (int)penv, penv);
          Scaleform::GFx::MovieImpl::SetContinueAnimationFlag(v19, v20);
        }
      }
    }
    return Scaleform::GFx::AS2::Object::SetMemberRaw(
             this,
             (Scaleform::GFx::AS2::ASStringContext *)p_StringContext,
             name,
             (Scaleform::GFx::AS2::Value *)val,
             flags);
  }
}
