void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::alphaGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        long double *result)
{
  *result = Scaleform::GFx::DisplayObjectBase::GetAlpha(this->pDispObj.pObject) / 100.0;
}
