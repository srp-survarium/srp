void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::rotationZGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        long double *result)
{
  *result = this->pDispObj.pObject->GetRotation(this->pDispObj.pObject);
}
