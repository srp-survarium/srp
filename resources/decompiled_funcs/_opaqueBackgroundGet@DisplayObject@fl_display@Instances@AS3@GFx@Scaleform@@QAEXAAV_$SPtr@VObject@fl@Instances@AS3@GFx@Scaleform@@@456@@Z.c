void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::opaqueBackgroundGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method DisplayObject::opaqueBackgroundGet() is not implemented\n");
}
