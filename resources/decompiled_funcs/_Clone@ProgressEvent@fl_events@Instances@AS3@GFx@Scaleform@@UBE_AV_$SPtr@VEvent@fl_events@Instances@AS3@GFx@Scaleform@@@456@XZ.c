Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__thiscall Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::Clone(
        Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // eax

  Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(this, result);
  pObject = (Scaleform::GFx::AS3::Instances::fl_events::Event *)result->pObject;
  pObject[1].__vftable = (Scaleform::GFx::AS3::Instances::fl_events::Event_vtbl *)this->BytesLoaded;
  pObject[1].pRCCRaw = this->BytesTotal;
  return result;
}
