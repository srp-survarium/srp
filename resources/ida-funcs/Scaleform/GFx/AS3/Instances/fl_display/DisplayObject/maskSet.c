void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::maskSet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *value)
{
  if ( value )
  {
    if ( !value->pDispObj.pObject )
      value->CreateStageObject(value);
    Scaleform::GFx::DisplayObject::SetMask(this->pDispObj.pObject, value->pDispObj.pObject);
  }
  else
  {
    Scaleform::GFx::DisplayObject::SetMask(this->pDispObj.pObject, 0);
  }
}
