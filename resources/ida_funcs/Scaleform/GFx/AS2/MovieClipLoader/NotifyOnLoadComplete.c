void __thiscall Scaleform::GFx::AS2::MovieClipLoader::NotifyOnLoadComplete(
        Scaleform::GFx::AS2::MovieClipLoader *this,
        Scaleform::GFx::ASStringNode *penv,
        Scaleform::GFx::InteractiveObject *ptarget,
        int status)
{
  Scaleform::GFx::AS2::Environment *v4; // ebp
  Scaleform::GFx::AS2::Value **p_pCurrent; // esi
  Scaleform::GFx::AS2::Value *v7; // eax
  int v8; // ecx
  Scaleform::GFx::AS2::Value *v9; // edi
  Scaleform::GFx::InteractiveObject *v10; // ecx
  Scaleform::GFx::CharacterHandle *pObject; // eax
  Scaleform::GFx::AS2::ObjectInterface *v12; // edi
  int v13; // ebx
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::AS2::Value *v15; // ecx
  int v16; // edi
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [esp+10h] [ebp-Ch] BYREF
  int v18; // [esp+14h] [ebp-8h]
  int v19; // [esp+18h] [ebp-4h]

  v4 = (Scaleform::GFx::AS2::Environment *)penv;
  penv->pManager = (Scaleform::GFx::ASStringManager *)((char *)penv->pManager + 16);
  p_pCurrent = &v4->Stack.pCurrent;
  if ( v4->Stack.pCurrent >= v4->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v4->Stack);
  v7 = *p_pCurrent;
  if ( *p_pCurrent )
  {
    v8 = status;
    v7->T.Type = 4;
    v7->NV.Int32Value = v8;
  }
  ++*p_pCurrent;
  if ( v4->Stack.pCurrent >= v4->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v4->Stack);
  v9 = *p_pCurrent;
  if ( *p_pCurrent )
  {
    v10 = ptarget;
    v9->T.Type = 7;
    if ( v10 )
    {
      pObject = v10->pNameHandle.pObject;
      if ( !pObject )
        pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v10);
      v9->NV.Int32Value = (int)pObject;
      if ( pObject )
        ++pObject->RefCount;
    }
    else
    {
      v9->NV.Int32Value = 0;
    }
  }
  if ( this )
    v12 = &this->Scaleform::GFx::AS2::ObjectInterface;
  else
    v12 = 0;
  v13 = v4->Stack.pCurrent - v4->Stack.pPageStart + 32 * v4->Stack.Pages.Data.Size - 32;
  penv = Scaleform::GFx::ASStringManager::CreateConstStringNode(
           (Scaleform::GFx::ASStringManager *)v4->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
           "onLoadComplete",
           0xEu,
           0);
  ++penv->RefCount;
  if ( v12 )
  {
    pcallback.__vftable = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)&`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage'::`4'::LocalInvokeCallback::`vftable';
    v18 = 2;
    v19 = v13;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
      v4,
      v12,
      (const Scaleform::GFx::ASString *)&penv,
      &pcallback);
  }
  v14 = penv;
  --penv->RefCount;
  if ( !v14->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  v15 = *p_pCurrent;
  if ( &(*p_pCurrent)[-2] >= v4->Stack.pPageStart )
  {
    if ( v15->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v15);
    --*p_pCurrent;
    if ( (*p_pCurrent)->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(*p_pCurrent);
    --*p_pCurrent;
  }
  else
  {
    v16 = 2;
    do
    {
      if ( (*p_pCurrent)->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(*p_pCurrent);
      --*p_pCurrent;
      if ( v4->Stack.pCurrent < v4->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v4->Stack);
      --v16;
    }
    while ( v16 );
  }
}
