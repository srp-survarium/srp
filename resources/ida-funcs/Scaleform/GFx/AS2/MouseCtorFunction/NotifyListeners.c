void __thiscall Scaleform::GFx::AS2::MouseCtorFunction::NotifyListeners(
        Scaleform::GFx::AS2::MouseCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *mouseIndex,
        Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *eventName,
        Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *ptargetName,
        Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *button,
        Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *delta,
        bool dblClick)
{
  Scaleform::GFx::AS2::ObjectInterface *v8; // eax
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback v9[6]; // [esp+0h] [ebp-1Ch] BYREF
  bool v10; // [esp+18h] [ebp-4h]

  v9[1].__vftable = mouseIndex;
  v9[3].__vftable = ptargetName;
  v9[4].__vftable = button;
  v9[5].__vftable = delta;
  v9[0].__vftable = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)&Scaleform::GFx::AS2::MouseCtorFunction::LocalInvokeCallback::`vftable';
  v9[2].__vftable = eventName;
  v10 = dblClick;
  if ( this )
    v8 = &this->Scaleform::GFx::AS2::ObjectInterface;
  else
    v8 = 0;
  Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
    penv,
    v8,
    (const Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount
  + (_DWORD)eventName,
    v9);
}
