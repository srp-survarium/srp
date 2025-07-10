void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Stage::isFocusInaccessible(
        Scaleform::GFx::AS3::Instances::fl_display::Stage *this,
        bool *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method Stage::isFocusInaccessible() is not implemented\n");
}
