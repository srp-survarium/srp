void __cdecl Scaleform::GFx::AS2::GAS_GetInputLanguage(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // ebx
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::RefCountVImpl *v4; // edi
  const Scaleform::GFx::AS2::FnCall *ConstStringNode; // esi
  const Scaleform::String *v6; // eax
  void *v7; // esi
  Scaleform::GFx::AS2::Value *Result; // ebx
  bool v9; // zf
  int v10; // [esp+8h] [ebp-4h] BYREF

  v1 = fn;
  Env = fn->Env;
  if ( Env )
  {
    pMovieImpl = Env->Target->pASRoot->pMovieImpl;
    v4 = (Scaleform::RefCountVImpl *)pMovieImpl->GetStateAddRef(&pMovieImpl->Scaleform::GFx::StateBag, State_IMEManager);
    ConstStringNode = (const Scaleform::GFx::AS2::FnCall *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                             (Scaleform::GFx::ASStringManager *)v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                                                             "UNKNOWN",
                                                             7u,
                                                             0);
    ++ConstStringNode->ThisFunctionRef.Function;
    fn = ConstStringNode;
    if ( v4 )
    {
      v6 = (const Scaleform::String *)((int (__thiscall *)(Scaleform::RefCountVImpl *, int *))v4->__vftable[3].AddRef)(
                                        v4,
                                        &v10);
      Scaleform::GFx::ASString::operator=<Scaleform::String>((Scaleform::GFx::ASString *)&fn, v6);
      v7 = (void *)(v10 & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((v10 & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
      ConstStringNode = fn;
    }
    Result = v1->Result;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 5;
    Result->NV.Int32Value = (int)ConstStringNode;
    v9 = ++ConstStringNode->ThisFunctionRef.Function == (Scaleform::GFx::AS2::FunctionObject *)1;
    --ConstStringNode->ThisFunctionRef.Function;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)ConstStringNode);
    if ( v4 )
      Scaleform::RefCountImpl::Release(v4);
  }
}
