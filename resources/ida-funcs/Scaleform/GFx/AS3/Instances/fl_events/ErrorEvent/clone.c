void __thiscall Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent::clone(
        Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method ErrorEvent::clone() is not implemented\n");
}
