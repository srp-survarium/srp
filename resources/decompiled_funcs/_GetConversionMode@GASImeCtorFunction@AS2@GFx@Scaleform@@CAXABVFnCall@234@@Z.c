void __cdecl Scaleform::GFx::AS2::GASImeCtorFunction::GetConversionMode(Scaleform::GFx::ASStringNode *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::Environment *pData; // ecx
  Scaleform::GFx::MovieImpl *MovieImpl; // eax
  Scaleform::RefCountVImpl *v4; // edi
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  char *v6; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::ASStringNode *v8; // eax

  v1 = (const Scaleform::GFx::AS2::FnCall *)fn;
  pData = (Scaleform::GFx::AS2::Environment *)fn[1].pData;
  if ( pData )
  {
    MovieImpl = Scaleform::GFx::AS2::Environment::GetMovieImpl(pData);
    v4 = (Scaleform::RefCountVImpl *)MovieImpl->GetStateAddRef(&MovieImpl->Scaleform::GFx::StateBag, State_IMEManager);
    StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v1->Env->StringContext.pContext);
    fn = Scaleform::GFx::ASStringManager::CreateConstStringNode(StringManager->pStringManager, "UNKNOWN", 7u, 0);
    ++fn->RefCount;
    if ( v4 )
    {
      v6 = (char *)((int (__thiscall *)(Scaleform::RefCountVImpl *))v4->__vftable[2].AddRef)(v4);
      Scaleform::GFx::ASString::operator=((Scaleform::GFx::ASString *)&fn, v6);
    }
    Result = v1->Result;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 5;
    Result->NV.Int32Value = (int)fn;
    ++fn->RefCount;
    v8 = fn;
    --fn->RefCount;
    if ( !v8->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    if ( v4 )
      Scaleform::RefCountImpl::Release(v4);
  }
}
