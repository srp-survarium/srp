void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::enabledGet(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        bool *result)
{
  *result = *(&this->pTraits.pObject->pVM[1].HandleException + 4);
}
