void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::getMouseCursorType(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        Scaleform::GFx::ASString *result,
        unsigned int mouseIndex)
{
  Scaleform::GFx::AS3::MovieRoot::GetMouseCursorType(
    (Scaleform::GFx::AS3::MovieRoot *)this->pTraits.pObject->pVM[1].__vftable,
    result,
    mouseIndex);
}
