void __thiscall Scaleform::GFx::AS2::StyleSheetObject::NotifyOnLoad(
        Scaleform::GFx::AS2::StyleSheetObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::ASString success)
{
  char pNode; // bl
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  Scaleform::GFx::AS2::Value *pCurrent; // eax
  unsigned int v7; // ebx
  Scaleform::GFx::AS2::ObjectInterface *v8; // edi
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [esp+10h] [ebp-Ch] BYREF
  int v11; // [esp+14h] [ebp-8h]
  unsigned int v12; // [esp+18h] [ebp-4h]

  pNode = (char)success.pNode;
  p_Stack = &penv->Stack;
  this->CSS.State = (LOBYTE(success.pNode) == 0) + 2;
  if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
  pCurrent = p_Stack->pCurrent;
  if ( p_Stack->pCurrent )
  {
    pCurrent->T.Type = 2;
    pCurrent->V.BooleanValue = pNode;
  }
  v7 = penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 32;
  v8 = &this->Scaleform::GFx::AS2::ObjectInterface;
  success.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                    (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                    "onLoad",
                    6u,
                    0);
  ++success.pNode->RefCount;
  if ( v8 )
  {
    v11 = 1;
    pcallback.__vftable = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)&`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage'::`4'::LocalInvokeCallback::`vftable';
    v12 = v7;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(penv, v8, &success, &pcallback);
  }
  v9 = success.pNode;
  --success.pNode->RefCount;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  if ( p_Stack->pCurrent->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(p_Stack->pCurrent);
  --p_Stack->pCurrent;
  if ( penv->Stack.pCurrent < penv->Stack.pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(p_Stack);
}
