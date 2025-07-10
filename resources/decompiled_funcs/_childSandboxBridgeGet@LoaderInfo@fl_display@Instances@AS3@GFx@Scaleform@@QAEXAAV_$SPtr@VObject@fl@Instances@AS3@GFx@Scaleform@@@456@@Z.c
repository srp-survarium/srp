void __thiscall Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::childSandboxBridgeGet(
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method LoaderInfo::childSandboxBridgeGet() is not implemented\n");
}
