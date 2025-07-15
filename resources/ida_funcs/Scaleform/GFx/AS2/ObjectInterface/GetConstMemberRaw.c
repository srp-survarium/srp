bool __thiscall Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(
        Scaleform::GFx::AS2::ObjectInterface *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        char *pname,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::ASStringContext *v4; // edi
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  Scaleform::GFx::AS2::Value *v7; // ecx
  bool v8; // bl
  Scaleform::GFx::ASStringNode *v9; // eax

  v4 = psc;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      (Scaleform::GFx::ASStringManager *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                      pname,
                      strlen(pname),
                      0);
  v7 = val;
  psc = (Scaleform::GFx::AS2::ASStringContext *)ConstStringNode;
  ++ConstStringNode->RefCount;
  v8 = this->GetMemberRaw(this, v4, (const Scaleform::GFx::ASString *)&psc, v7);
  v9 = (Scaleform::GFx::ASStringNode *)psc;
  --*(_DWORD *)&psc[1].SWFVersion;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  return v8;
}
