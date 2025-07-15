void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Stage::fullScreenSourceRectGet(
        Scaleform::GFx::AS3::Instances::fl_display::Stage *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle> *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method Stage::fullScreenSourceRectGet() is not implemented\n");
}
