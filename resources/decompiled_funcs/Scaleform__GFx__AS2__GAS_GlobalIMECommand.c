void __cdecl Scaleform::GFx::AS2::GAS_GlobalIMECommand(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::MovieImpl *pMovieImpl; // ebx
  Scaleform::RefCountVImpl *v3; // edi
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::AS2::FnCall_vtbl *v5; // ebp
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // ecx
  Scaleform::GFx::AS2::Environment *Env; // [esp-14h] [ebp-20h]
  Scaleform::GFx::AS2::Environment *v11; // [esp-14h] [ebp-20h]
  Scaleform::GFx::ASString result; // [esp+8h] [ebp-4h] BYREF

  v1 = fn;
  if ( fn->NArgs >= 2 )
  {
    pMovieImpl = fn->Env->Target->pASRoot->pMovieImpl;
    v3 = (Scaleform::RefCountVImpl *)pMovieImpl->GetStateAddRef(&pMovieImpl->Scaleform::GFx::StateBag, State_IMEManager);
    if ( v3 )
    {
      Env = v1->Env;
      v4 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
      Scaleform::GFx::AS2::Value::ToStringImpl(v4, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
      v5 = fn->__vftable;
      v11 = v1->Env;
      v6 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(v6, &result, v11, -1, 0);
      pNode = result.pNode;
      ((void (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::GFx::MovieImpl *, const char *, Scaleform::GFx::AS2::FnCall_vtbl *))v3->Release)(
        v3,
        pMovieImpl,
        result.pNode->pData,
        v5);
      v8 = pNode->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v9 = (Scaleform::GFx::ASStringNode *)fn;
      v8 = fn->ThisFunctionRef.Function-- == (Scaleform::GFx::AS2::FunctionObject *)1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      Scaleform::RefCountImpl::Release(v3);
    }
  }
}
