void __thiscall Scaleform::GFx::AS3::Classes::fl_ui::Mouse::cursorGet(
        Scaleform::GFx::AS3::Classes::fl_ui::Mouse *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::MovieRoot::GetMouseCursorType(
    (Scaleform::GFx::AS3::MovieRoot *)this->pTraits.pObject->pVM[1].__vftable,
    result,
    0);
}
