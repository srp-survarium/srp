void __cdecl Scaleform::GFx::AS2::GASIme::BroadcastOnSetIMEName(
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::ASString *imeName)
{
  Scaleform::GFx::AS2::Environment *v2; // ebp
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::AS2::GlobalContext **p_pContext; // edi
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  Scaleform::GFx::AS2::Object *v6; // esi
  Scaleform::GFx::AS2::StringManager *v7; // eax
  Scaleform::GFx::AS2::Object *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS2::Value **p_pCurrent; // esi
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *v11; // ebx
  Scaleform::GFx::AS2::StringManager *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // [esp+18h] [ebp-38h] BYREF
  Scaleform::GFx::AS2::ObjectInterface *v16; // [esp+1Ch] [ebp-34h]
  Scaleform::GFx::AS2::Value v; // [esp+20h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value v18; // [esp+30h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v19; // [esp+40h] [ebp-10h] BYREF

  v2 = penv;
  pContext = penv->StringContext.pContext;
  p_pContext = &penv->StringContext.pContext;
  v19.T.Type = 0;
  v18.T.Type = 0;
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
         &v18) )
  {
    v6 = Scaleform::GFx::AS2::Value::ToObject(&v18, v2);
    v7 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(*p_pContext);
    if ( v6->GetMemberRaw(
           &v6->Scaleform::GFx::AS2::ObjectInterface,
           (Scaleform::GFx::AS2::ASStringContext *)p_pContext,
           (const Scaleform::GFx::ASString *)&v7->Builtins[22],
           &v19) )
    {
      v8 = Scaleform::GFx::AS2::Value::ToObject(&v19, v2);
      if ( v8 )
      {
        v16 = &v8->Scaleform::GFx::AS2::ObjectInterface;
        if ( v8 != (Scaleform::GFx::AS2::Object *)-16 )
        {
          pNode = imeName->pNode;
          p_pCurrent = &v2->Stack.pCurrent;
          if ( imeName->pNode->Size )
          {
            v.NV.Int32Value = (int)imeName->pNode;
            v.T.Type = 5;
            ++pNode->RefCount;
            ++*p_pCurrent;
            if ( v2->Stack.pCurrent >= v2->Stack.pPageEnd )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v2->Stack);
            if ( *p_pCurrent )
              Scaleform::GFx::AS2::Value::Value(*p_pCurrent, &v);
            Scaleform::GFx::AS2::Value::~Value(&v);
          }
          else
          {
            ++*p_pCurrent;
            if ( v2->Stack.pCurrent >= v2->Stack.pPageEnd )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v2->Stack);
            if ( *p_pCurrent )
              (*p_pCurrent)->T.Type = 1;
          }
          v11 = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)(v2->Stack.pCurrent
                                                                          - v2->Stack.pPageStart
                                                                          + 32 * v2->Stack.Pages.Data.Size
                                                                          - 32);
          v12 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(*p_pContext);
          penv = (Scaleform::GFx::AS2::Environment *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                       v12->pStringManager,
                                                       "onSetIMEName",
                                                       0xCu,
                                                       0);
          ++penv->Stack.pPageEnd;
          Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage(
            v2,
            v16,
            (const Scaleform::GFx::ASString *)&penv,
            (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)1,
            v11);
          v13 = (Scaleform::GFx::ASStringNode *)penv;
          --penv->Stack.pPageEnd;
          if ( !v13->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v13);
          Scaleform::GFx::AS2::Value::~Value(*p_pCurrent);
          --*p_pCurrent;
          if ( v2->Stack.pCurrent < v2->Stack.pPageStart )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v2->Stack);
        }
      }
    }
  }
  v14 = ConstStringNode;
  --ConstStringNode->RefCount;
  if ( !v14->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  Scaleform::GFx::AS2::Value::~Value(&v18);
  Scaleform::GFx::AS2::Value::~Value(&v19);
}
