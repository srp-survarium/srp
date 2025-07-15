void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::ySet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  ((void (__thiscall *)(Scaleform::GFx::DisplayObject *, _DWORD, _DWORD))this->pDispObj.pObject->SetY)(
    this->pDispObj.pObject,
    LODWORD(value),
    HIDWORD(value));
}
