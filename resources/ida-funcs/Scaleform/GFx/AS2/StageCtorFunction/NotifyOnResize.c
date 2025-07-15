void __thiscall Scaleform::GFx::AS2::StageCtorFunction::NotifyOnResize(
        Scaleform::GFx::AS2::StageCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  Scaleform::GFx::AS2::ObjectInterface *v6; // ebx
  Scaleform::GFx::MovieImpl *pMovieRoot; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS2::ObjectInterface *v9; // esi
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::ASString eventName; // [esp+3Ch] [ebp-34h] BYREF
  unsigned int v12; // [esp+40h] [ebp-30h]
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [esp+44h] [ebp-2Ch] BYREF
  int v14; // [esp+48h] [ebp-28h]
  unsigned int v15; // [esp+4Ch] [ebp-24h]
  Scaleform::GFx::AS2::Value result; // [esp+50h] [ebp-20h] BYREF
  Scaleform::Render::Rect<float> rect; // [esp+60h] [ebp-10h] BYREF

  pContext = penv->StringContext.pContext;
  if ( pContext->GFxExtensions.Value == 1 )
  {
    pMovieImpl = penv->Target->pASRoot->pMovieImpl;
    pMovieImpl->GetVisibleFrameRect(pMovieImpl, &rect);
    Scaleform::GFx::AS2::StageCtorFunction::CreateRectangleObject(&result, penv, &rect);
    ++penv->Stack.pCurrent;
    p_Stack = &penv->Stack;
    if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
    if ( p_Stack->pCurrent )
      Scaleform::GFx::AS2::Value::Value(p_Stack->pCurrent, &result);
    if ( this )
      v6 = &this->Scaleform::GFx::AS2::ObjectInterface;
    else
      v6 = 0;
    pMovieRoot = penv->StringContext.pContext->pMovieRoot;
    v12 = penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 32;
    eventName.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                        (Scaleform::GFx::ASStringManager *)pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                        "onResize",
                        8u,
                        0);
    ++eventName.pNode->RefCount;
    if ( v6 )
    {
      v14 = 1;
      pcallback.__vftable = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)&`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage'::`4'::LocalInvokeCallback::`vftable';
      v15 = v12;
      Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(penv, v6, &eventName, &pcallback);
    }
    pNode = eventName.pNode;
    --eventName.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( p_Stack->pCurrent->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(p_Stack->pCurrent);
    --p_Stack->pCurrent;
    if ( penv->Stack.pCurrent < penv->Stack.pPageStart )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&penv->Stack);
    if ( result.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&result);
  }
  else
  {
    if ( this )
      v9 = &this->Scaleform::GFx::AS2::ObjectInterface;
    else
      v9 = 0;
    eventName.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                        (Scaleform::GFx::ASStringManager *)pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                        "onResize",
                        8u,
                        0);
    ++eventName.pNode->RefCount;
    if ( v9 )
    {
      pcallback.__vftable = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)&`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage'::`4'::LocalInvokeCallback::`vftable';
      v14 = 0;
      v15 = 0;
      Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(penv, v9, &eventName, &pcallback);
    }
    v10 = eventName.pNode;
    --eventName.pNode->RefCount;
    if ( !v10->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  }
}


void __cdecl Scaleform::GFx::AS2::StageCtorFunction::NotifyOnResize(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::AS2::Object *v2; // eax
  Scaleform::GFx::AS2::ObjectInterface *v3; // eax
  Scaleform::GFx::AS2::Value stageCtorVal; // [esp+Ch] [ebp-10h] BYREF

  Env = fn->Env;
  stageCtorVal.T.Type = 0;
  if ( Env->StringContext.pContext->pGlobal.pObject->GetMemberRaw(
         &Env->StringContext.pContext->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface,
         &Env->StringContext,
         (const Scaleform::GFx::ASString *)&Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[11].AVMVersion,
         &stageCtorVal)
    && stageCtorVal.T.Type != 11 )
  {
    v2 = Scaleform::GFx::AS2::Value::ToObject(&stageCtorVal, fn->Env);
    if ( v2 )
    {
      v3 = &v2->Scaleform::GFx::AS2::ObjectInterface;
      if ( v3 )
        Scaleform::GFx::AS2::StageCtorFunction::NotifyOnResize(
          (Scaleform::GFx::AS2::StageCtorFunction *)&v3[-2].pProto,
          fn->Env);
    }
  }
  if ( stageCtorVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&stageCtorVal);
}
