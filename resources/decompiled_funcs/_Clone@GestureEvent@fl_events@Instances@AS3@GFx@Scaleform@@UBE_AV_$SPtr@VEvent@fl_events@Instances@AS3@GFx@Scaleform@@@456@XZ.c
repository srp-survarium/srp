Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__thiscall Scaleform::GFx::AS3::Instances::fl_events::GestureEvent::Clone(
        Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // eax

  Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(this, result);
  pObject = (Scaleform::GFx::AS3::Instances::fl_events::Event *)result->pObject;
  LOBYTE(pObject[1].__vftable) = this->AltKey;
  BYTE1(pObject[1].__vftable) = this->CtrlKey;
  BYTE2(pObject[1].__vftable) = this->ShiftKey;
  HIBYTE(pObject[1].__vftable) = this->CommandKey;
  LOBYTE(pObject[1]._pRCC) = this->ControlKey;
  *(double *)&pObject[1].pPrev = this->LocalX;
  *(double *)&pObject[1].pTraits.pObject = this->LocalY;
  *(double *)&pObject[1].pUserDataHolder = this->StageX;
  *(double *)&pObject[1].CurrentTarget.pObject = this->StageY;
  pObject[1].Phase = this->Phase;
  *((_BYTE *)&pObject[1] + 48) = this->LocalInitialized;
  return result;
}
