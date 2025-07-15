void __cdecl Scaleform::GFx::AS2::GASImeCtorFunction::SendLangBarMessage(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::Environment *Env; // ecx
  Scaleform::GFx::MovieImpl *MovieImpl; // eax
  Scaleform::RefCountVImpl *v4; // edi
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::InteractiveObject *v6; // eax
  Scaleform::GFx::AS2::Environment *v7; // ebp
  Scaleform::GFx::InteractiveObject *v8; // ebx
  Scaleform::GFx::AS2::Value *v9; // eax
  Scaleform::GFx::AS2::Environment *v10; // ebp
  Scaleform::GFx::AS2::Value *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  const Scaleform::GFx::AS2::Environment *v15; // [esp-4h] [ebp-18h]
  Scaleform::GFx::ASString command; // [esp+10h] [ebp-4h] BYREF

  v1 = fn;
  Env = fn->Env;
  if ( Env )
  {
    MovieImpl = Scaleform::GFx::AS2::Environment::GetMovieImpl(Env);
    v4 = (Scaleform::RefCountVImpl *)MovieImpl->GetStateAddRef(&MovieImpl->Scaleform::GFx::StateBag, State_IMEManager);
    if ( v4 && v1->NArgs == 3 && Scaleform::GFx::AS2::FnCall::Arg(v1, 0)->T.Type == 7 )
    {
      v15 = v1->Env;
      v5 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      v6 = Scaleform::GFx::AS2::Value::ToCharacter(v5, v15);
      v7 = v1->Env;
      v8 = v6;
      v9 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
      Scaleform::GFx::AS2::Value::ToStringImpl(v9, &command, v7, -1, 0);
      v10 = v1->Env;
      v11 = Scaleform::GFx::AS2::FnCall::Arg(v1, 2);
      Scaleform::GFx::AS2::Value::ToStringImpl(v11, (Scaleform::GFx::ASString *)&fn, v10, -1, 0);
      ((void (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::GFx::InteractiveObject *, Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::FnCall **))v4->__vftable[6].Release)(
        v4,
        v8,
        &command,
        &fn);
      v12 = (Scaleform::GFx::ASStringNode *)fn;
      --fn->ThisFunctionRef.Function;
      if ( !v12->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      pNode = command.pNode;
      --command.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    Result = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 0;
    if ( v4 )
      Scaleform::RefCountImpl::Release(v4);
  }
}
