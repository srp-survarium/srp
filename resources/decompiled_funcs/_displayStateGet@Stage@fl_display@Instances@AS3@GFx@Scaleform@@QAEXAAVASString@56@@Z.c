void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Stage::displayStateGet(
        Scaleform::GFx::AS3::Instances::fl_display::Stage *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method Stage::displayStateGet() is not implemented\n");
}
