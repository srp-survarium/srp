void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::setMouseCursorType(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *cursor,
        unsigned int mouseIndex)
{
  Scaleform::GFx::AS3::MovieRoot::SetMouseCursorType(
    (Scaleform::GFx::AS3::MovieRoot *)this->pTraits.pObject->pVM[1].__vftable,
    cursor,
    mouseIndex);
}
