void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::visibleSet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        const Scaleform::GFx::AS3::Value *result,
        BOOL value)
{
  this->pDispObj.pObject->SetVisible(this->pDispObj.pObject, value);
}
