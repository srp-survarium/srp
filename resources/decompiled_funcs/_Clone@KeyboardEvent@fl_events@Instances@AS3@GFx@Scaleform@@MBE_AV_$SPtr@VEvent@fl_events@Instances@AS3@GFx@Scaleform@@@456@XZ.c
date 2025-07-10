Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__thiscall Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent::Clone(
        Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // eax

  Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(this, result);
  pObject = (Scaleform::GFx::AS3::Instances::fl_events::Event *)result->pObject;
  pObject[1].__vftable = (Scaleform::GFx::AS3::Instances::fl_events::Event_vtbl *)this->EvtId.Id;
  pObject[1].pRCCRaw = this->EvtId.WcharCode;
  pObject[1].pNext = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)this->EvtId.KeyCode;
  LOBYTE(pObject[1].pPrev) = this->EvtId.AsciiCode;
  pObject[1].RefCount = *(_DWORD *)&this->EvtId.RollOverCnt;
  pObject[1].pTraits.pObject = (Scaleform::GFx::AS3::Traits *)this->KeyLocation;
  return result;
}
