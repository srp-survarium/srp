void __thiscall Scaleform::GFx::AS2::KeyCtorFunction::OnKeyDown(
        Scaleform::GFx::AS2::KeyCtorFunction *this,
        Scaleform::GFx::InteractiveObject *pmovie,
        const Scaleform::GFx::EventId *evt,
        int __formal)
{
  Scaleform::GFx::AS2::KeyCtorFunction::NotifyListeners(
    (Scaleform::GFx::AS2::KeyCtorFunction *)((char *)this - 56),
    pmovie,
    (Scaleform::GFx::ASString)evt);
}
