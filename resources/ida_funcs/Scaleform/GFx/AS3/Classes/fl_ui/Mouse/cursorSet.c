void __thiscall Scaleform::GFx::AS3::Classes::fl_ui::Mouse::cursorSet(
        Scaleform::GFx::AS3::Classes::fl_ui::Mouse *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::AS3::MovieRoot::SetMouseCursorType(
    (Scaleform::GFx::AS3::MovieRoot *)this->pTraits.pObject->pVM[1].__vftable,
    value,
    0);
}
