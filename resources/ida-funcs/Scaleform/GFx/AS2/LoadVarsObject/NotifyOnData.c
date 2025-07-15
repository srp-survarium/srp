void __thiscall Scaleform::GFx::AS2::LoadVarsObject::NotifyOnData(
        Scaleform::GFx::AS2::LoadVarsObject *this,
        Scaleform::GFx::ASStringNode *penv,
        Scaleform::GFx::ASString *src)
{
  Scaleform::GFx::AS2::Environment *v3; // ebp
  Scaleform::GFx::AS2::Value **p_pCurrent; // esi
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::GFx::ASString *v7; // ecx
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::AS2::ObjectInterface *v9; // edi
  int v10; // ebx
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [esp+10h] [ebp-Ch] BYREF
  int v13; // [esp+14h] [ebp-8h]
  int v14; // [esp+18h] [ebp-4h]

  v3 = (Scaleform::GFx::AS2::Environment *)penv;
  penv->pManager = (Scaleform::GFx::ASStringManager *)((char *)penv->pManager + 16);
  p_pCurrent = &v3->Stack.pCurrent;
  if ( v3->Stack.pCurrent >= v3->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v3->Stack);
  v6 = *p_pCurrent;
  if ( *p_pCurrent )
  {
    v7 = src;
    v6->T.Type = 5;
    pNode = v7->pNode;
    v6->NV.Int32Value = (int)pNode;
    ++pNode->RefCount;
  }
  if ( this )
    v9 = &this->Scaleform::GFx::AS2::ObjectInterface;
  else
    v9 = 0;
  v10 = v3->Stack.pCurrent - v3->Stack.pPageStart + 32 * v3->Stack.Pages.Data.Size - 32;
  penv = Scaleform::GFx::ASStringManager::CreateConstStringNode(
           (Scaleform::GFx::ASStringManager *)v3->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
           "onData",
           6u,
           0);
  ++penv->RefCount;
  if ( v9 )
  {
    v13 = 1;
    pcallback.__vftable = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)&`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage'::`4'::LocalInvokeCallback::`vftable';
    v14 = v10;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
      v3,
      v9,
      (const Scaleform::GFx::ASString *)&penv,
      &pcallback);
  }
  v11 = penv;
  --penv->RefCount;
  if ( !v11->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  if ( (*p_pCurrent)->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(*p_pCurrent);
  --*p_pCurrent;
  if ( v3->Stack.pCurrent < v3->Stack.pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v3->Stack);
}
