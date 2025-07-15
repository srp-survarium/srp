Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__thiscall Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent::Clone(
        Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // eax

  Scaleform::GFx::AS3::Instances::fl_events::GestureEvent::Clone(this, result);
  pObject = (Scaleform::GFx::AS3::Instances::fl_events::Event *)result->pObject;
  *(double *)&pObject[2].__vftable = this->TapLocalX;
  *(double *)&pObject[2].pNext = this->TapLocalY;
  *(double *)&pObject[2].RefCount = this->TapStageX;
  *(double *)&pObject[2].DynAttrs.mHash.pTable = this->TapStageY;
  LOBYTE(pObject[2].Type.pNode) = this->LocalInitialized;
  BYTE1(pObject[2].Type.pNode) = this->TapStageSet;
  return result;
}
