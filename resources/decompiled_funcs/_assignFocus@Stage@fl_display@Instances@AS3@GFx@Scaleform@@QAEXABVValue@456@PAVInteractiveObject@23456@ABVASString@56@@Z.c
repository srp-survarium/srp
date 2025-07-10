void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Stage::assignFocus(
        Scaleform::GFx::AS3::Instances::fl_display::Stage *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *objectToFocus,
        const Scaleform::GFx::ASString *direction)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method Stage::assignFocus() is not implemented\n");
}
