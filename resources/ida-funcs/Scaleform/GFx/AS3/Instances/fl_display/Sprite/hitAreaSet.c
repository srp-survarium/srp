void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Sprite::hitAreaSet(
        Scaleform::GFx::AS3::Instances::fl_display::Sprite *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::Sprite *value)
{
  if ( value )
  {
    if ( !value->pDispObj.pObject )
      value->CreateStageObject(value);
    Scaleform::GFx::Sprite::SetHitArea(
      (Scaleform::GFx::Sprite *)this->pDispObj.pObject,
      (Scaleform::GFx::Sprite *)value->pDispObj.pObject);
  }
  else
  {
    Scaleform::GFx::Sprite::SetHitArea((Scaleform::GFx::Sprite *)this->pDispObj.pObject, 0);
  }
}
