void __cdecl Scaleform::GFx::AS2::GASImeCtorFunction::GetCompositionString(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // ecx
  Scaleform::GFx::MovieImpl *MovieImpl; // eax
  int v3; // eax
  Scaleform::RefCountVImpl *v4; // ebx
  wchar_t *v5; // esi
  Scaleform::GFx::MovieImpl *v6; // eax
  Scaleform::GFx::ASStringManager *v7; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::AS2::Value *Result; // edi
  bool v10; // zf

  Env = fn->Env;
  if ( Env )
  {
    MovieImpl = Scaleform::GFx::AS2::Environment::GetMovieImpl(Env);
    v3 = (int)MovieImpl->GetStateAddRef(&MovieImpl->Scaleform::GFx::StateBag, State_IMEManager);
    v4 = (Scaleform::RefCountVImpl *)v3;
    v5 = 0;
    if ( v3 )
      v5 = (wchar_t *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 88))(v3);
    v6 = Scaleform::GFx::AS2::Environment::GetMovieImpl(fn->Env);
    v7 = v6->pASMovieRoot.pObject->GetStringManager(v6->pASMovieRoot.pObject);
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(v7, v5, -1);
    ++StringNode->RefCount;
    Result = fn->Result;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 5;
    Result->NV.Int32Value = (int)StringNode;
    v10 = ++StringNode->RefCount == 1;
    --StringNode->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
    if ( v4 )
      Scaleform::RefCountImpl::Release(v4);
  }
}
