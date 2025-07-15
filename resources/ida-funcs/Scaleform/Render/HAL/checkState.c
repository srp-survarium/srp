char __thiscall Scaleform::Render::HAL::checkState(
        Scaleform::Render::HAL *this,
        unsigned int stateFlags,
        Scaleform::GFx::AS3::Value *funcName)
{
  if ( (stateFlags & this->HALState) == stateFlags )
    return 1;
  Scaleform::GFx::AS2::Object::SetValue(
    (Scaleform::GFx::AS3::Instances::fl_geom::Transform *)this,
    stateFlags,
    funcName);
  return 0;
}
