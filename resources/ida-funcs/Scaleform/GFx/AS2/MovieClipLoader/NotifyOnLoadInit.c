void __thiscall Scaleform::GFx::AS2::MovieClipLoader::NotifyOnLoadInit(
        Scaleform::GFx::AS2::MovieClipLoader *this,
        Scaleform::GFx::ASStringNode *penv,
        Scaleform::GFx::InteractiveObject *ptarget)
{
  Scaleform::GFx::AS2::Environment *v3; // ebp
  Scaleform::GFx::AS2::Value **p_pCurrent; // esi
  Scaleform::GFx::AS2::Value *v6; // edi
  Scaleform::GFx::InteractiveObject *v7; // ecx
  Scaleform::GFx::CharacterHandle *pObject; // eax
  Scaleform::GFx::AS2::ObjectInterface *v9; // edi
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *v10; // ebx
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback v12[3]; // [esp+10h] [ebp-Ch] BYREF

  v3 = (Scaleform::GFx::AS2::Environment *)penv;
  penv->pManager = (Scaleform::GFx::ASStringManager *)((char *)penv->pManager + 16);
  p_pCurrent = &v3->Stack.pCurrent;
  if ( v3->Stack.pCurrent >= v3->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v3->Stack);
  v6 = *p_pCurrent;
  if ( *p_pCurrent )
  {
    v7 = ptarget;
    v6->T.Type = 7;
    if ( v7 )
    {
      pObject = v7->pNameHandle.pObject;
      if ( !pObject )
        pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v7);
      v6->NV.Int32Value = (int)pObject;
      if ( pObject )
        ++pObject->RefCount;
    }
    else
    {
      v6->NV.Int32Value = 0;
    }
  }
  if ( this )
    v9 = &this->Scaleform::GFx::AS2::ObjectInterface;
  else
    v9 = 0;
  v10 = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)(v3->Stack.pCurrent
                                                                  - v3->Stack.pPageStart
                                                                  + 32 * v3->Stack.Pages.Data.Size
                                                                  - 32);
  penv = Scaleform::GFx::ASStringManager::CreateConstStringNode(
           (Scaleform::GFx::ASStringManager *)v3->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
           "onLoadInit",
           0xAu,
           0);
  ++penv->RefCount;
  if ( v9 )
  {
    v12[0].__vftable = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)&`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage'::`4'::LocalInvokeCallback::`vftable';
    v12[1].__vftable = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)1;
    v12[2].__vftable = v10;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
      v3,
      v9,
      (const Scaleform::GFx::ASString *)&penv,
      v12);
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
