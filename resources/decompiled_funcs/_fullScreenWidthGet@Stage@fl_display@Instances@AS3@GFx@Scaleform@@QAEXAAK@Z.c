void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Stage::fullScreenWidthGet(
        Scaleform::GFx::AS3::Instances::fl_display::Stage *this,
        unsigned int *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method Stage::fullScreenWidthGet() is not implemented\n");
}
