void __cdecl Scaleform::GFx::AS2::ObjectProto::IsPropertyEnumerable(Scaleform::GFx::ASString fn)
{
  const Scaleform::GFx::AS2::FnCall *pNode; // esi
  Scaleform::GFx::AS2::Environment *pData; // eax
  Scaleform::GFx::AS2::Value *v3; // ecx
  bool v4; // bl
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // ecx
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::AS2::Value *pManager; // esi
  Scaleform::GFx::AS2::Member m; // [esp+18h] [ebp-10h] BYREF

  pNode = (const Scaleform::GFx::AS2::FnCall *)fn.pNode;
  if ( (int)fn.pNode[1].pManager < 1 )
  {
    pManager = (Scaleform::GFx::AS2::Value *)fn.pNode->pManager;
    Scaleform::GFx::AS2::Value::DropRefs(pManager);
    pManager->T.Type = 2;
    pManager->V.BooleanValue = 0;
  }
  else
  {
    pData = (Scaleform::GFx::AS2::Environment *)fn.pNode[1].pData;
    v3 = 0;
    if ( fn.pNode[1].pLower <= (Scaleform::GFx::ASStringNode *)(32 * (pData->Stack.Pages.Data.Size - 1)
                                                              + pData->Stack.pCurrent
                                                              - pData->Stack.pPageStart) )
      v3 = &pData->Stack.Pages.Data.Data[(unsigned int)fn.pNode[1].pLower >> 5]->Values[(int)fn.pNode[1].pLower & 0x1F];
    Scaleform::GFx::AS2::Value::ToStringImpl(v3, &fn, pData, -1, 0);
    v4 = pNode->ThisPtr->HasMember(pNode->ThisPtr, &pNode->Env->StringContext, &fn, 0);
    if ( v4 )
    {
      ThisPtr = pNode->ThisPtr;
      Env = pNode->Env;
      m.mValue.T = 0;
      ThisPtr->FindMember(ThisPtr, &Env->StringContext, &fn, &m);
      if ( (m.mValue.T.PropFlags & 1) != 0 )
        v4 = 0;
      if ( m.mValue.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&m.mValue);
    }
    Result = pNode->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->V.BooleanValue = v4;
    Result->T.Type = 2;
    v8 = fn.pNode;
    --fn.pNode->RefCount;
    if ( !v8->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
}
