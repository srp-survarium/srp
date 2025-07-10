char __cdecl Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ObjectInterface *pthis,
        const Scaleform::GFx::ASString *eventName,
        int nArgs,
        int firstArgBottomIndex)
{
  Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage::__l4::LocalInvokeCallback Callback; // [esp+0h] [ebp-Ch] BYREF

  if ( !pthis )
    return 0;
  Callback.NArgs = nArgs;
  Callback.FirstArgBottomIndex = firstArgBottomIndex;
  Callback.__vftable = (Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage::__l4::LocalInvokeCallback_vtbl *)&`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage'::`4'::LocalInvokeCallback::`vftable';
  Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(penv, pthis, eventName, &Callback);
  return 1;
}
