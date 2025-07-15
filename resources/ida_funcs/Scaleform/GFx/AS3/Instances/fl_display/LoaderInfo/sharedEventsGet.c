void __thiscall Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::sharedEventsGet(
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher> *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method LoaderInfo::sharedEventsGet() is not implemented\n");
}
