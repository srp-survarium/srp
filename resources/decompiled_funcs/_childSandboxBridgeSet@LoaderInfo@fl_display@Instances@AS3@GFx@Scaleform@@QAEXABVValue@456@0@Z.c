void __thiscall Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::childSandboxBridgeSet(
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method LoaderInfo::childSandboxBridgeSet() is not implemented\n");
}
