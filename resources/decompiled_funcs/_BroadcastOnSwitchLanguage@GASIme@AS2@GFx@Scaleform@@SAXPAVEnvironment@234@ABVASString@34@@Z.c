void __cdecl Scaleform::GFx::AS2::GASIme::BroadcastOnSwitchLanguage(
        Scaleform::GFx::ASStringNode *penv,
        const Scaleform::GFx::ASString *compString)
{
  Scaleform::GFx::AS2::Environment *v2; // ebp
  Scaleform::GFx::AS2::GlobalContext *Size; // ecx
  Scaleform::GFx::AS2::ASStringContext *p_Size; // edi
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  Scaleform::GFx::AS2::Object *v6; // esi
  Scaleform::GFx::AS2::StringManager *v7; // eax
  Scaleform::GFx::AS2::Object *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS2::Value **p_pCurrent; // esi
  int v11; // ebx
  Scaleform::GFx::AS2::StringManager *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::ASString systemPackageStr; // [esp+18h] [ebp-38h] BYREF
  Scaleform::GFx::AS2::ObjectInterface *pimeObj; // [esp+1Ch] [ebp-34h]
  Scaleform::GFx::AS2::Value v; // [esp+20h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value systemPackage; // [esp+30h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value imeCtorVal; // [esp+40h] [ebp-10h] BYREF

  v2 = (Scaleform::GFx::AS2::Environment *)penv;
  Size = (Scaleform::GFx::AS2::GlobalContext *)penv[4].Size;
  p_Size = (Scaleform::GFx::AS2::ASStringContext *)&penv[4].Size;
  imeCtorVal.T.Type = 0;
  systemPackage.T.Type = 0;
  StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(Size);
  systemPackageStr.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                             StringManager->pStringManager,
                             "System",
                             6u,
                             0);
  ++systemPackageStr.pNode->RefCount;
  if ( p_Size->pContext->pGlobal.pObject->GetMemberRaw(
         &p_Size->pContext->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface,
         p_Size,
         &systemPackageStr,
         &systemPackage) )
  {
    v6 = Scaleform::GFx::AS2::Value::ToObject(&systemPackage, v2);
    v7 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(p_Size->pContext);
    if ( v6->GetMemberRaw(
           &v6->Scaleform::GFx::AS2::ObjectInterface,
           p_Size,
           (const Scaleform::GFx::ASString *)&v7->Builtins[22],
           &imeCtorVal) )
    {
      v8 = Scaleform::GFx::AS2::Value::ToObject(&imeCtorVal, v2);
      if ( v8 )
      {
        pimeObj = &v8->Scaleform::GFx::AS2::ObjectInterface;
        if ( v8 != (Scaleform::GFx::AS2::Object *)-16 )
        {
          pNode = compString->pNode;
          p_pCurrent = &v2->Stack.pCurrent;
          if ( compString->pNode->Size )
          {
            v.NV.Int32Value = (int)compString->pNode;
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
          v11 = v2->Stack.pCurrent - v2->Stack.pPageStart + 32 * v2->Stack.Pages.Data.Size - 32;
          v12 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(p_Size->pContext);
          penv = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   v12->pStringManager,
                   "onSwitchLanguage",
                   0x10u,
                   0);
          ++penv->RefCount;
          Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage(
            v2,
            pimeObj,
            (const Scaleform::GFx::ASString *)&penv,
            1,
            v11);
          v13 = penv;
          --penv->RefCount;
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
  v14 = systemPackageStr.pNode;
  --systemPackageStr.pNode->RefCount;
  if ( !v14->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  Scaleform::GFx::AS2::Value::~Value(&systemPackage);
  Scaleform::GFx::AS2::Value::~Value(&imeCtorVal);
}
