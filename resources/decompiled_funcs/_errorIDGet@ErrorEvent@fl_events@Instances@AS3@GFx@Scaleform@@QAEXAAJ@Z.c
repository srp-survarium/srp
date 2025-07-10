void __thiscall Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent::errorIDGet(
        Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent *this,
        int *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method ErrorEvent::errorIDGet() is not implemented\n");
}
