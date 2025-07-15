void __thiscall Scaleform::GFx::AS3::Instances::fl_events::MouseEvent::clickCountGet(
        Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *this,
        int *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method MouseEvent::clickCountGet() is not implemented\n");
}
