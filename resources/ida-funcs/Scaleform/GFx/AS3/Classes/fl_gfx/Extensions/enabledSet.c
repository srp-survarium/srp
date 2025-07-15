void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::enabledSet(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        const Scaleform::GFx::AS3::Value *result,
        bool value)
{
  *(&this->pTraits.pObject->pVM[1].HandleException + 4) = value;
}
