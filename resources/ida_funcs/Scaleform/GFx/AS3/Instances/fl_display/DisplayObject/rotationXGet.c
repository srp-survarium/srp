void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::rotationXGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        long double *result)
{
  *result = this->pDispObj.pObject->GetXRotation(this->pDispObj.pObject);
}
