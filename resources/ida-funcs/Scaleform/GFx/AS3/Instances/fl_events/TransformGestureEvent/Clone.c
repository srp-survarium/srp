Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__thiscall Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent::Clone(
        Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  double *pObject; // eax

  Scaleform::GFx::AS3::Instances::fl_events::GestureEvent::Clone(this, result);
  pObject = (double *)result->pObject;
  pObject[13] = this->OffsetX;
  pObject[14] = this->OffsetY;
  pObject[17] = this->ScaleX;
  pObject[18] = this->ScaleY;
  pObject[19] = this->Rotation;
  return result;
}
