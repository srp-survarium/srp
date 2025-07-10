void __thiscall Scaleform::GFx::AS2::LoadVarsObject::LoadVarsObject(
        Scaleform::GFx::AS2::LoadVarsObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // ebp
  Scaleform::GFx::AS2::ObjectInterface *v4; // edi
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  Scaleform::GFx::AS2::Object *Prototype; // eax
  Scaleform::GFx::ASStringManager *pMovieImpl; // ecx
  Scaleform::GFx::ASStringNode *ConstStringNode; // ebp
  Scaleform::GFx::ASStringManager *v9; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringManager *v12; // ecx
  Scaleform::GFx::ASStringNode *v13; // eax
  int v14; // [esp+0h] [ebp-24h]
  int v15; // [esp+4h] [ebp-20h]
  Scaleform::GFx::ASString name; // [esp+10h] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value val; // [esp+14h] [ebp-10h] BYREF

  v2 = penv;
  Scaleform::GFx::AS2::Object::Object(this, penv);
  v4 = &this->Scaleform::GFx::AS2::ObjectInterface;
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::LoadVarsObject_vtbl *)&Scaleform::GFx::AS2::Object::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::LoadVarsObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  p_StringContext = &v2->StringContext;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2->StringContext.pContext, ASBuiltin_LoadVars);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    &v2->StringContext,
    Prototype);
  if ( this != (Scaleform::GFx::AS2::LoadVarsObject *)-16 )
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      (unsigned __int8 *)this,
      (Scaleform::GFx::AS2::LocalFrame **)v2,
      &this->Scaleform::GFx::AS2::ObjectInterface,
      &v2->StringContext,
      GAS_AsBcFunctionTable,
      1u,
      v14);
  Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance(
    (int)v4,
    (int)p_StringContext,
    &v2->StringContext,
    &this->Scaleform::GFx::AS2::ObjectInterface,
    v14,
    v15);
  this->BytesLoadedCurrent = -1.0;
  this->BytesLoadedTotal = -1.0;
  Scaleform::GFx::AS2::AsBroadcaster::AddListener(v2, v4, v4);
  pMovieImpl = (Scaleform::GFx::ASStringManager *)p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  LOBYTE(penv) = 1;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      pMovieImpl,
                      "application/x-www-form-urlencoded",
                      0x21u,
                      0);
  ++ConstStringNode->RefCount;
  ++ConstStringNode->RefCount;
  v9 = (Scaleform::GFx::ASStringManager *)p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  val.T.Type = 5;
  val.NV.Int32Value = (int)ConstStringNode;
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v9, "contentType", 0xBu, 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    &name,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&penv);
  pNode = name.pNode;
  --name.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  if ( ConstStringNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
  v12 = (Scaleform::GFx::ASStringManager *)p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  LOBYTE(penv) = 1;
  val.T.Type = 0;
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v12, "loaded", 6u, 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    &name,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&penv);
  v13 = name.pNode;
  --name.pNode->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
}
