void __thiscall Scaleform::GFx::AS3::Instances::fl_events::GestureEvent::updateAfterEvent(
        Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *this,
        const Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method instance::GestureEvent::updateAfterEvent() is not implemented\n");
}
