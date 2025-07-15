void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::alphaSet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  Scaleform::GFx::DisplayObjectBase::SetAlpha(this->pDispObj.pObject, value * 100.0);
}
