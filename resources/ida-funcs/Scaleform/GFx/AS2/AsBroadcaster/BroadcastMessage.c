char __cdecl Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ObjectInterface *pthis,
        const Scaleform::GFx::ASString *eventName,
        Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *nArgs,
        Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *firstArgBottomIndex)
{
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback v6[3]; // [esp+0h] [ebp-Ch] BYREF

  if ( !pthis )
    return 0;
  v6[1].__vftable = nArgs;
  v6[2].__vftable = firstArgBottomIndex;
  v6[0].__vftable = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)&`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage'::`4'::LocalInvokeCallback::`vftable';
  Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(penv, pthis, eventName, v6);
  return 1;
}
