Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__thiscall Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent::Clone(
        Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // eax

  Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(this, result);
  pObject = (Scaleform::GFx::AS3::Instances::fl_events::Event *)result->pObject;
  pObject[1].pRCCRaw = this->ControllerIdx;
  *(double *)&pObject[1].pPrev = this->XValue;
  *(double *)&pObject[1].pTraits.pObject = this->YValue;
  return result;
}
