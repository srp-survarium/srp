void __cdecl Scaleform::GFx::AS2::GASIme::BroadcastOnDisplayStatusWindow(Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v1; // esi
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::AS2::GlobalContext **p_pContext; // edi
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  Scaleform::GFx::AS2::Object *v5; // ebx
  Scaleform::GFx::AS2::StringManager *v6; // eax
  Scaleform::GFx::AS2::Object *v7; // eax
  Scaleform::GFx::AS2::ObjectInterface *v8; // ebx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *v9; // ebp
  Scaleform::GFx::AS2::StringManager *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // [esp+18h] [ebp-24h] BYREF
  Scaleform::GFx::AS2::Value v14; // [esp+1Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v15; // [esp+2Ch] [ebp-10h] BYREF

  v1 = penv;
  pContext = penv->StringContext.pContext;
  p_pContext = &penv->StringContext.pContext;
  v15.T.Type = 0;
  v14.T.Type = 0;
  StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(pContext);
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      StringManager->pStringManager,
                      "System",
                      6u,
                      0);
  ++ConstStringNode->RefCount;
  if ( (*p_pContext)->pGlobal.pObject->GetMemberRaw(
         &(*p_pContext)->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface,
         (Scaleform::GFx::AS2::ASStringContext *)p_pContext,
         (const Scaleform::GFx::ASString *)&ConstStringNode,
         &v14) )
  {
    v5 = Scaleform::GFx::AS2::Value::ToObject(&v14, v1);
    v6 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(*p_pContext);
    if ( v5->GetMemberRaw(
           &v5->Scaleform::GFx::AS2::ObjectInterface,
           (Scaleform::GFx::AS2::ASStringContext *)p_pContext,
           (const Scaleform::GFx::ASString *)&v6->Builtins[22],
           &v15) )
    {
      v7 = Scaleform::GFx::AS2::Value::ToObject(&v15, v1);
      if ( v7 )
      {
        v8 = &v7->Scaleform::GFx::AS2::ObjectInterface;
        if ( v7 != (Scaleform::GFx::AS2::Object *)-16 )
        {
          v9 = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)(v1->Stack.pCurrent
                                                                         - v1->Stack.pPageStart
                                                                         + 32 * v1->Stack.Pages.Data.Size
                                                                         - 32);
          v10 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(*p_pContext);
          penv = (Scaleform::GFx::AS2::Environment *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                       v10->pStringManager,
                                                       "onDisplayStatusWindow",
                                                       0x15u,
                                                       0);
          ++penv->Stack.pPageEnd;
          Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage(v1, v8, (const Scaleform::GFx::ASString *)&penv, 0, v9);
          v11 = (Scaleform::GFx::ASStringNode *)penv;
          --penv->Stack.pPageEnd;
          if ( !v11->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v11);
        }
      }
    }
  }
  v12 = ConstStringNode;
  --ConstStringNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  Scaleform::GFx::AS2::Value::~Value(&v14);
  Scaleform::GFx::AS2::Value::~Value(&v15);
}
