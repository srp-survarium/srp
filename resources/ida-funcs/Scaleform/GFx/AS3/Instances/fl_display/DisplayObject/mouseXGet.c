void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::mouseXGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        long double *result)
{
  *result = this->pDispObj.pObject->GetMouseX(this->pDispObj.pObject);
}
