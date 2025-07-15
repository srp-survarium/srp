void __thiscall Scaleform::GFx::AS2::MouseCtorFunction::OnMouseMove(
        Scaleform::GFx::AS2::MouseCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv,
        unsigned int mouseIndex)
{
  Scaleform::GFx::AS2::MouseCtorFunction::NotifyListeners(
    (Scaleform::GFx::AS2::MouseCtorFunction *)((char *)this - 56),
    penv,
    mouseIndex,
    ASBuiltin_onMouseMove,
    0,
    0,
    0,
    0);
}
