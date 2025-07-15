void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::enabledSet(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        const Scaleform::GFx::AS3::Value *result,
        bool value)
{
  LOBYTE(this->pTraits.pObject->pVM[1].ExceptionObj.Bonus.pWeakProxy) = value;
}
