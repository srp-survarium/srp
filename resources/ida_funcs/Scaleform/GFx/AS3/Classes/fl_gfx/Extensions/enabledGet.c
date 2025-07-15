void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::enabledGet(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        bool *result)
{
  *result = (bool)this->pTraits.pObject->pVM[1].ExceptionObj.Bonus.pWeakProxy;
}
