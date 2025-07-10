void __cdecl Scaleform::GFx::AS2::GASIme::BroadcastOnDisplayStatusWindow(Scaleform::GFx::ASStringNode *penv)
{
  Scaleform::GFx::AS2::Environment *v1; // esi
  Scaleform::GFx::AS2::GlobalContext *Size; // ecx
  Scaleform::GFx::AS2::ASStringContext *p_Size; // edi
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  Scaleform::GFx::AS2::Object *v5; // ebx
  Scaleform::GFx::AS2::StringManager *v6; // eax
  Scaleform::GFx::AS2::Object *v7; // eax
  Scaleform::GFx::AS2::ObjectInterface *v8; // ebx
  int v9; // ebp
  Scaleform::GFx::AS2::StringManager *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString systemPackageStr; // [esp+18h] [ebp-24h] BYREF
  Scaleform::GFx::AS2::Value systemPackage; // [esp+1Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value imeCtorVal; // [esp+2Ch] [ebp-10h] BYREF

  v1 = (Scaleform::GFx::AS2::Environment *)penv;
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
    v5 = Scaleform::GFx::AS2::Value::ToObject(&systemPackage, v1);
    v6 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(p_Size->pContext);
    if ( v5->GetMemberRaw(
           &v5->Scaleform::GFx::AS2::ObjectInterface,
           p_Size,
           (const Scaleform::GFx::ASString *)&v6->Builtins[22],
           &imeCtorVal) )
    {
      v7 = Scaleform::GFx::AS2::Value::ToObject(&imeCtorVal, v1);
      if ( v7 )
      {
        v8 = &v7->Scaleform::GFx::AS2::ObjectInterface;
        if ( v7 != (Scaleform::GFx::AS2::Object *)-16 )
        {
          v9 = v1->Stack.pCurrent - v1->Stack.pPageStart + 32 * v1->Stack.Pages.Data.Size - 32;
          v10 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(p_Size->pContext);
          penv = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   v10->pStringManager,
                   "onDisplayStatusWindow",
                   0x15u,
                   0);
          ++penv->RefCount;
          Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage(v1, v8, (const Scaleform::GFx::ASString *)&penv, 0, v9);
          v11 = penv;
          --penv->RefCount;
          if ( !v11->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v11);
        }
      }
    }
  }
  pNode = systemPackageStr.pNode;
  --systemPackageStr.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::GFx::AS2::Value::~Value(&systemPackage);
  Scaleform::GFx::AS2::Value::~Value(&imeCtorVal);
}
