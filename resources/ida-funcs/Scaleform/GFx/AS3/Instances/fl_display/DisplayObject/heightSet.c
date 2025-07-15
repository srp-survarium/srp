void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::heightSet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  ((void (__thiscall *)(Scaleform::GFx::DisplayObject *, _DWORD, _DWORD))this->pDispObj.pObject->SetHeight)(
    this->pDispObj.pObject,
    LODWORD(value),
    HIDWORD(value));
}
