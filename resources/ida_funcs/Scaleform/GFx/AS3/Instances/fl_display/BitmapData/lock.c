void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::lock(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        const Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method BitmapData::lock() is not implemented\n");
}
