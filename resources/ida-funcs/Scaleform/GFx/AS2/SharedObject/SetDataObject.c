void __thiscall Scaleform::GFx::AS2::SharedObject::SetDataObject(
        Scaleform::GFx::AS2::SharedObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Object *pobj)
{
  Scaleform::GFx::AS2::Environment *v3; // edi
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::GFx::AS2::Environment *ConstStringNode; // eax
  Scaleform::GFx::AS2::Object *v7; // ecx
  Scaleform::GFx::AS2::Value *v8; // eax
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::AS2::PropFlags flags; // [esp+Bh] [ebp-11h] BYREF
  Scaleform::GFx::AS2::Value v11; // [esp+Ch] [ebp-10h] BYREF

  v3 = penv;
  pMovieImpl = penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  flags.Flags = 0;
  ConstStringNode = (Scaleform::GFx::AS2::Environment *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                          (Scaleform::GFx::ASStringManager *)pMovieImpl,
                                                          "data",
                                                          4u,
                                                          0);
  v7 = pobj;
  penv = ConstStringNode;
  ++ConstStringNode->Stack.pPageEnd;
  Scaleform::GFx::AS2::Value::Value(&v11, v7);
  Scaleform::GFx::AS2::Object::SetMember(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v3,
    (const Scaleform::GFx::ASString *)&penv,
    v8,
    &flags);
  v9 = (Scaleform::GFx::ASStringNode *)penv;
  --penv->Stack.pPageEnd;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
}
