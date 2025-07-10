Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__thiscall Scaleform::GFx::AS3::Instances::fl_events::MouseEvent::Clone(
        Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // edi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *v4; // eax

  Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(this, result);
  pObject = (Scaleform::GFx::AS3::Instances::fl_events::Event *)result->pObject;
  LOBYTE(pObject[1].Type.pNode) = this->AltKey;
  BYTE1(pObject[1].Type.pNode) = this->CtrlKey;
  BYTE2(pObject[1].Type.pNode) = this->ShiftKey;
  pObject[1].__vftable = (Scaleform::GFx::AS3::Instances::fl_events::Event_vtbl *)this->Delta;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&pObject[1].4,
    (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&this->RelatedObj);
  *(double *)&pObject[1].pPrev = this->LocalX;
  v4 = result;
  *(double *)&pObject[1].pTraits.pObject = this->LocalY;
  pObject[1].pUserDataHolder = (Scaleform::GFx::AS3::Object::UserDataHolder *)this->ButtonsMask;
  return v4;
}
