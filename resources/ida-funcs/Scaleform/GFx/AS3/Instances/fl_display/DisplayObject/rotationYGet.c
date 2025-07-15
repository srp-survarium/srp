void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::rotationYGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        long double *result)
{
  *result = this->pDispObj.pObject->GetYRotation(this->pDispObj.pObject);
}
