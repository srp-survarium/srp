void __thiscall Scaleform::GFx::AS3::Instances::fl_events::FocusEvent::directionGet(
        Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method FocusEvent::directionGet() is not implemented\n");
}
