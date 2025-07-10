void __thiscall Scaleform::GFx::AS2::XmlObject::NotifyOnData(
        Scaleform::GFx::AS2::XmlObject *this,
        Scaleform::GFx::ASStringNode *penv,
        Scaleform::GFx::AS2::Value val)
{
  Scaleform::GFx::AS2::Environment *v3; // ebx
  Scaleform::GFx::AS2::Value **p_pCurrent; // esi
  Scaleform::GFx::AS2::ObjectInterface *v6; // ebp
  int v7; // edi
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  Scaleform::GFx::ASStringNode *v9; // eax

  v3 = (Scaleform::GFx::AS2::Environment *)penv;
  penv->pManager = (Scaleform::GFx::ASStringManager *)((char *)penv->pManager + 16);
  p_pCurrent = &v3->Stack.pCurrent;
  if ( v3->Stack.pCurrent >= v3->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v3->Stack);
  if ( *p_pCurrent )
    Scaleform::GFx::AS2::Value::Value(*p_pCurrent, &val);
  if ( this )
    v6 = &this->Scaleform::GFx::AS2::ObjectInterface;
  else
    v6 = 0;
  v7 = v3->Stack.pCurrent - v3->Stack.pPageStart + 32 * v3->Stack.Pages.Data.Size - 32;
  StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v3->StringContext.pContext);
  penv = Scaleform::GFx::ASStringManager::CreateConstStringNode(StringManager->pStringManager, "onData", 6u, 0);
  ++penv->RefCount;
  Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage(v3, v6, (const Scaleform::GFx::ASString *)&penv, 1, v7);
  v9 = penv;
  --penv->RefCount;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  Scaleform::GFx::AS2::Value::~Value(*p_pCurrent);
  --*p_pCurrent;
  if ( v3->Stack.pCurrent < v3->Stack.pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v3->Stack);
  Scaleform::GFx::AS2::Value::~Value(&val);
}
