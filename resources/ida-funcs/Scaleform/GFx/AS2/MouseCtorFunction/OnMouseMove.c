void __thiscall Scaleform::GFx::AS2::MouseCtorFunction::OnMouseMove(
        Scaleform::GFx::AS2::MouseCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *mouseIndex)
{
  Scaleform::GFx::AS2::MouseCtorFunction::NotifyListeners(
    (Scaleform::GFx::AS2::MouseCtorFunction *)((char *)this - 56),
    penv,
    mouseIndex,
    (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)0x69,
    0,
    0,
    0,
    0);
}
