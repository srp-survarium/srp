void __thiscall Scaleform::GFx::AS2::XmlObject::NotifyOnLoad(
        Scaleform::GFx::AS2::XmlObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASStringNode *success)
{
  char v3; // bl
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  bool (__thiscall *SetMemberRaw)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::Value *, const Scaleform::GFx::AS2::PropFlags *); // edx
  Scaleform::GFx::AS2::ObjectInterface *v8; // ebp
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  Scaleform::GFx::AS2::Value *pCurrent; // eax
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *v12; // ebx
  Scaleform::GFx::AS2::StringManager *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  char v15; // [esp+13h] [ebp-11h] BYREF
  Scaleform::GFx::AS2::Value v16; // [esp+14h] [ebp-10h] BYREF

  v3 = (char)success;
  pContext = penv->StringContext.pContext;
  v15 = 2;
  v16.T.Type = 2;
  v16.V.BooleanValue = (char)success;
  StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(pContext);
  success = Scaleform::GFx::ASStringManager::CreateConstStringNode(StringManager->pStringManager, "loaded", 6u, 0);
  ++success->RefCount;
  SetMemberRaw = this->SetMemberRaw;
  v8 = &this->Scaleform::GFx::AS2::ObjectInterface;
  SetMemberRaw(
    v8,
    &penv->StringContext,
    (const Scaleform::GFx::ASString *)&success,
    &v16,
    (const Scaleform::GFx::AS2::PropFlags *)&v15);
  v9 = success;
  --success->RefCount;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  Scaleform::GFx::AS2::Value::~Value(&v16);
  ++penv->Stack.pCurrent;
  p_Stack = &penv->Stack;
  if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
  pCurrent = p_Stack->pCurrent;
  if ( p_Stack->pCurrent )
  {
    pCurrent->T.Type = 2;
    pCurrent->V.BooleanValue = v3;
  }
  v12 = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)(penv->Stack.pCurrent
                                                                  - penv->Stack.pPageStart
                                                                  + 32 * penv->Stack.Pages.Data.Size
                                                                  - 32);
  v13 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(penv->StringContext.pContext);
  success = Scaleform::GFx::ASStringManager::CreateConstStringNode(v13->pStringManager, "onLoad", 6u, 0);
  ++success->RefCount;
  Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage(
    penv,
    v8,
    (const Scaleform::GFx::ASString *)&success,
    (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)1,
    v12);
  v14 = success;
  --success->RefCount;
  if ( !v14->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  Scaleform::GFx::AS2::Value::~Value(p_Stack->pCurrent);
  --p_Stack->pCurrent;
  if ( penv->Stack.pCurrent < penv->Stack.pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(p_Stack);
}
