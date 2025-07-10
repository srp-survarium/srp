void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::mouseYGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        long double *result)
{
  *result = this->pDispObj.pObject->GetMouseY(this->pDispObj.pObject);
}
