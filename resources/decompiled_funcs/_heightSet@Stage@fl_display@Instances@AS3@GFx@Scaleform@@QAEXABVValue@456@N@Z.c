void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Stage::heightSet(
        Scaleform::GFx::AS3::Instances::fl_display::Stage *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method Stage::heightSet() is not implemented\n");
}
