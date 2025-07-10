void __thiscall Scaleform::GFx::AS2::BitmapData::commonInit(
        Scaleform::GFx::AS2::BitmapData *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  Scaleform::GFx::AS2::Object *Prototype; // eax
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v5; // edx
  Scaleform::GFx::AS2::ObjectInterface *v6; // edi
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::AS2::GlobalContext *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // [esp+28h] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value v12; // [esp+2Ch] [ebp-10h] BYREF

  p_StringContext = &penv->StringContext;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_BitmapData);
  v5 = this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable;
  v6 = &this->Scaleform::GFx::AS2::ObjectInterface;
  v5->Set__proto__(v6, p_StringContext, Prototype);
  pContext = p_StringContext->pContext;
  LOBYTE(penv) = 4;
  v12.T.Type = 10;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      (Scaleform::GFx::ASStringManager *)pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                      "width",
                      5u,
                      0);
  ++ConstStringNode->RefCount;
  v6->SetMemberRaw(
    v6,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&ConstStringNode,
    &v12,
    (const Scaleform::GFx::AS2::PropFlags *)&penv);
  v8 = ConstStringNode;
  --ConstStringNode->RefCount;
  if ( !v8->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  if ( v12.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v12);
  v9 = p_StringContext->pContext;
  LOBYTE(penv) = 4;
  v12.T.Type = 10;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      (Scaleform::GFx::ASStringManager *)v9->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                      "height",
                      6u,
                      0);
  ++ConstStringNode->RefCount;
  v6->SetMemberRaw(
    v6,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&ConstStringNode,
    &v12,
    (const Scaleform::GFx::AS2::PropFlags *)&penv);
  v10 = ConstStringNode;
  --ConstStringNode->RefCount;
  if ( !v10->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  if ( v12.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v12);
}
