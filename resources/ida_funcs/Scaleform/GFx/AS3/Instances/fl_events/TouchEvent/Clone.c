Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__thiscall Scaleform::GFx::AS3::Instances::fl_events::TouchEvent::Clone(
        Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // edi

  Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(this, result);
  pObject = (Scaleform::GFx::AS3::Instances::fl_events::Event *)result->pObject;
  LOBYTE(pObject[1].__vftable) = this->AltKey;
  BYTE1(pObject[1].__vftable) = this->CtrlKey;
  BYTE2(pObject[1].__vftable) = this->ShiftKey;
  HIBYTE(pObject[1].__vftable) = this->CommandKey;
  LOBYTE(pObject[1]._pRCC) = this->ControlKey;
  *(double *)&pObject[2].pNext = this->Pressure;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&pObject[1].8,
    (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&this->RelatedObj);
  *(double *)&pObject[1].pPrev = this->LocalX;
  *(double *)&pObject[1].pTraits.pObject = this->LocalY;
  *(double *)&pObject[1].Phase = this->StageX;
  *(double *)&pObject[2].__vftable = this->StageY;
  *(double *)&pObject[1].pUserDataHolder = this->SizeX;
  *(double *)&pObject[1].CurrentTarget.pObject = this->SizeY;
  pObject[2].RefCount = this->TouchPointID;
  LOBYTE(pObject[2].pTraits.pObject) = this->PrimaryPoint;
  BYTE1(pObject[2].pTraits.pObject) = this->LocalInitialized;
  return result;
}
