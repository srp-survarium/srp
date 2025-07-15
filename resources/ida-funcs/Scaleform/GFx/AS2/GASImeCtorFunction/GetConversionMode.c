void __cdecl Scaleform::GFx::AS2::GASImeCtorFunction::GetConversionMode(Scaleform::GFx::ASStringNode *fn)
{
  Scaleform::GFx::ASStringNode *v1; // esi
  Scaleform::GFx::AS2::Environment *pData; // ecx
  Scaleform::GFx::MovieImpl *MovieImpl; // eax
  Scaleform::RefCountVImpl *v4; // edi
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::AS2::Value *pManager; // esi
  Scaleform::GFx::ASStringNode *v8; // eax

  v1 = fn;
  pData = (Scaleform::GFx::AS2::Environment *)fn[1].pData;
  if ( pData )
  {
    MovieImpl = Scaleform::GFx::AS2::Environment::GetMovieImpl(pData);
    v4 = (Scaleform::RefCountVImpl *)MovieImpl->GetStateAddRef(&MovieImpl->Scaleform::GFx::StateBag, State_IMEManager);
    StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(*((Scaleform::GFx::AS2::GlobalContext **)v1[1].pData
                                                                         + 29));
    fn = Scaleform::GFx::ASStringManager::CreateConstStringNode(StringManager->pStringManager, "UNKNOWN", 7u, 0);
    ++fn->RefCount;
    if ( v4 )
    {
      v6 = (Scaleform::GFx::ASStringNode *)((int (__thiscall *)(Scaleform::RefCountVImpl *))v4->__vftable[2].AddRef)(v4);
      Scaleform::GFx::ASString::operator=((Scaleform::GFx::ASString *)&fn, v6);
    }
    pManager = (Scaleform::GFx::AS2::Value *)v1->pManager;
    if ( pManager->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(pManager);
    pManager->T.Type = 5;
    pManager->NV.Int32Value = (int)fn;
    ++fn->RefCount;
    v8 = fn;
    --fn->RefCount;
    if ( !v8->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    if ( v4 )
      Scaleform::RefCountImpl::Release(v4);
  }
}
