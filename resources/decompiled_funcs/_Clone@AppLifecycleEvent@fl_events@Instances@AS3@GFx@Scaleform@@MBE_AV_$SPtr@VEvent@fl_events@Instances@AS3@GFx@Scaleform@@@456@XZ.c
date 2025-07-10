Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__thiscall Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent::Clone(
        Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(this, result);
  Scaleform::GFx::AS3::Value::Assign((Scaleform::GFx::AS3::Value *)&result->pObject[1].DynAttrs, &this->Status);
  return result;
}
