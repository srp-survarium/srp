void __thiscall Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent::toString(
        Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method ErrorEvent::toString() is not implemented\n");
}
