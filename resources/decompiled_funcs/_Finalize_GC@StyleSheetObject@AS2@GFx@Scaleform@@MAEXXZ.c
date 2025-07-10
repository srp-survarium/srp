void __thiscall Scaleform::GFx::AS2::StyleSheetObject::Finalize_GC(Scaleform::GFx::AS2::StyleSheetObject *this)
{
  ((void (__thiscall *)(Scaleform::GFx::Text::StyleManager *, _DWORD))this->CSS.~Scaleform::GFx::Text::StyleManager)(
    &this->CSS,
    0);
  Scaleform::GFx::AS2::Object::Finalize_GC(this);
}
