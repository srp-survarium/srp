bool __thiscall Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
        Scaleform::GFx::AS2::ObjectInterface *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        char *pname,
        const Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::ASStringContext *v5; // edi
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  bool v8; // bl
  Scaleform::GFx::ASStringNode *v9; // eax
  const Scaleform::GFx::AS2::Value *v11; // [esp-8h] [ebp-18h]
  const Scaleform::GFx::AS2::PropFlags *v12; // [esp-4h] [ebp-14h]

  v5 = psc;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      (Scaleform::GFx::ASStringManager *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                      pname,
                      strlen(pname),
                      0);
  v12 = flags;
  v11 = val;
  psc = (Scaleform::GFx::AS2::ASStringContext *)ConstStringNode;
  ++ConstStringNode->RefCount;
  v8 = this->SetMemberRaw(this, v5, (const Scaleform::GFx::ASString *)&psc, v11, v12);
  v9 = (Scaleform::GFx::ASStringNode *)psc;
  --*(_DWORD *)&psc[1].SWFVersion;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  return v8;
}
