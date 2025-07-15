void __thiscall Scaleform::GFx::AS2::StyleSheetObject::NotifyOnLoad(
        Scaleform::GFx::AS2::StyleSheetObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASStringNode *success)
{
  char v3; // bl
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  Scaleform::GFx::AS2::Value *pCurrent; // eax
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *v7; // ebx
  Scaleform::GFx::AS2::ObjectInterface *v8; // edi
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback v10[3]; // [esp+10h] [ebp-Ch] BYREF

  v3 = (char)success;
  p_Stack = &penv->Stack;
  this->CSS.State = ((_BYTE)success == 0) + 2;
  if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
  pCurrent = p_Stack->pCurrent;
  if ( p_Stack->pCurrent )
  {
    pCurrent->T.Type = 2;
    pCurrent->V.BooleanValue = v3;
  }
  v7 = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)(penv->Stack.pCurrent
                                                                 - penv->Stack.pPageStart
                                                                 + 32 * penv->Stack.Pages.Data.Size
                                                                 - 32);
  v8 = &this->Scaleform::GFx::AS2::ObjectInterface;
  success = Scaleform::GFx::ASStringManager::CreateConstStringNode(
              (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
              "onLoad",
              6u,
              0);
  ++success->RefCount;
  if ( v8 )
  {
    v10[1].__vftable = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)1;
    v10[0].__vftable = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)&`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage'::`4'::LocalInvokeCallback::`vftable';
    v10[2].__vftable = v7;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
      penv,
      v8,
      (const Scaleform::GFx::ASString *)&success,
      v10);
  }
  v9 = success;
  --success->RefCount;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  if ( p_Stack->pCurrent->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(p_Stack->pCurrent);
  --p_Stack->pCurrent;
  if ( penv->Stack.pCurrent < penv->Stack.pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(p_Stack);
}
