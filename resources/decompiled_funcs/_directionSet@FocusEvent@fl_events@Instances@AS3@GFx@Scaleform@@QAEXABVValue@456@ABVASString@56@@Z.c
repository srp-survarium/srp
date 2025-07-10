void __thiscall Scaleform::GFx::AS3::Instances::fl_events::FocusEvent::directionSet(
        Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method FocusEvent::directionSet() is not implemented\n");
}
