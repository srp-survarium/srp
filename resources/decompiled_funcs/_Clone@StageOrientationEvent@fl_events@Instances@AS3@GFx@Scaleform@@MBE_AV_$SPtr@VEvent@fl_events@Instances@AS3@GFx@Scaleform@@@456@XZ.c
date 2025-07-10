Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__thiscall Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent::Clone(
        Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // ebx

  Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(this, result);
  pObject = (Scaleform::GFx::AS3::Instances::fl_events::Event *)result->pObject;
  Scaleform::GFx::AS3::Value::Assign(
    (Scaleform::GFx::AS3::Value *)&result->pObject[1].DynAttrs,
    &this->BeforeOrientation);
  Scaleform::GFx::AS3::Value::Assign((Scaleform::GFx::AS3::Value *)&pObject[1].pTraits, &this->AfterOrientation);
  return result;
}
