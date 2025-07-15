void __thiscall Scaleform::GFx::AS2::MouseCtorFunction::NotifyListeners(
        Scaleform::GFx::AS2::MouseCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv,
        unsigned int mouseIndex,
        Scaleform::GFx::AS2::ASBuiltinType eventName,
        const Scaleform::GFx::ASString *ptargetName,
        unsigned int button,
        int delta,
        bool dblClick)
{
  Scaleform::GFx::AS2::ObjectInterface *v8; // eax
  Scaleform::GFx::AS2::MouseCtorFunction::LocalInvokeCallback Callback; // [esp+0h] [ebp-1Ch] BYREF

  Callback.MouseIndex = mouseIndex;
  Callback.pTargetName = ptargetName;
  Callback.Button = button;
  Callback.Delta = delta;
  Callback.__vftable = (Scaleform::GFx::AS2::MouseCtorFunction::LocalInvokeCallback_vtbl *)&Scaleform::GFx::AS2::MouseCtorFunction::LocalInvokeCallback::`vftable';
  Callback.EventName = eventName;
  Callback.DoubleClick = dblClick;
  if ( this )
    v8 = &this->Scaleform::GFx::AS2::ObjectInterface;
  else
    v8 = 0;
  Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
    penv,
    v8,
    (const Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount
  + eventName,
    &Callback);
}
