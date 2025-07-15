void __thiscall Scaleform::GFx::AS3::Classes::fl_system::Capabilities::screenDPIGet(
        Scaleform::GFx::AS3::Classes::fl_system::Capabilities *this,
        long double *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method class_::Capabilities::screenDPIGet() is not implemented\n");
}
