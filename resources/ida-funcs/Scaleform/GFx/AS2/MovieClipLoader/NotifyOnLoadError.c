void __thiscall Scaleform::GFx::AS2::MovieClipLoader::NotifyOnLoadError(
        Scaleform::GFx::AS2::MovieClipLoader *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::InteractiveObject *ptarget,
        char *errorCode,
        Scaleform::GFx::ASStringNode *status)
{
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  Scaleform::GFx::AS2::Value *pCurrent; // eax
  Scaleform::GFx::ASStringNode *v7; // ecx
  Scaleform::GFx::ASStringNode *ConstStringNode; // edi
  Scaleform::GFx::AS2::Value *v9; // eax
  Scaleform::GFx::AS2::Value *v11; // edi
  Scaleform::GFx::CharacterHandle *pObject; // eax
  Scaleform::GFx::AS2::ObjectInterface *v13; // edi
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *v14; // ebp
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback v17[3]; // [esp+Ch] [ebp-Ch] BYREF

  ++penv->Stack.pCurrent;
  p_Stack = &penv->Stack;
  if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
  pCurrent = p_Stack->pCurrent;
  if ( p_Stack->pCurrent )
  {
    v7 = status;
    pCurrent->T.Type = 4;
    pCurrent->NV.Int32Value = (int)v7;
  }
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                      errorCode,
                      strlen(errorCode),
                      0);
  ++ConstStringNode->RefCount;
  ++p_Stack->pCurrent;
  if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
  v9 = p_Stack->pCurrent;
  if ( p_Stack->pCurrent )
  {
    v9->T.Type = 5;
    v9->NV.Int32Value = (int)ConstStringNode;
    ++ConstStringNode->RefCount;
  }
  if ( ConstStringNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
  ++p_Stack->pCurrent;
  if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
  v11 = p_Stack->pCurrent;
  if ( p_Stack->pCurrent )
  {
    v11->T.Type = 7;
    if ( ptarget )
    {
      pObject = ptarget->pNameHandle.pObject;
      if ( !pObject )
        pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(ptarget);
      v11->NV.Int32Value = (int)pObject;
      if ( pObject )
        ++pObject->RefCount;
    }
    else
    {
      v11->NV.Int32Value = 0;
    }
  }
  if ( this )
    v13 = &this->Scaleform::GFx::AS2::ObjectInterface;
  else
    v13 = 0;
  v14 = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)(penv->Stack.pCurrent
                                                                  - penv->Stack.pPageStart
                                                                  + 32 * penv->Stack.Pages.Data.Size
                                                                  - 32);
  status = Scaleform::GFx::ASStringManager::CreateConstStringNode(
             (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
             "onLoadError",
             0xBu,
             0);
  ++status->RefCount;
  if ( v13 )
  {
    v17[0].__vftable = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)&`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage'::`4'::LocalInvokeCallback::`vftable';
    v17[1].__vftable = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)3;
    v17[2].__vftable = v14;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
      penv,
      v13,
      (const Scaleform::GFx::ASString *)&status,
      v17);
  }
  v15 = status;
  --status->RefCount;
  if ( !v15->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop3(p_Stack);
}
