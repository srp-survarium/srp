void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::zSet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  ((void (__thiscall *)(Scaleform::GFx::DisplayObject *, _DWORD, _DWORD))this->pDispObj.pObject->SetZ)(
    this->pDispObj.pObject,
    COERCE_UNSIGNED_INT64(value * 20.0),
    HIDWORD(COERCE_UNSIGNED_INT64(value * 20.0)));
}
