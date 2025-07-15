Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__thiscall Scaleform::GFx::AS3::Instances::fl_gfx::FocusEventEx::Clone(
        Scaleform::GFx::AS3::Instances::fl_gfx::FocusEventEx *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // edi

  Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(this, result);
  pObject = (Scaleform::GFx::AS3::Instances::fl_events::Event *)result->pObject;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&result->pObject[1].pUserDataHolder,
    (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&this->RelatedObj);
  LOBYTE(pObject[1].__vftable) = this->ShiftKey;
  pObject[1].pRCCRaw = this->KeyCode;
  pObject[1].pPrev = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)this->controllerIdx;
  return result;
}
