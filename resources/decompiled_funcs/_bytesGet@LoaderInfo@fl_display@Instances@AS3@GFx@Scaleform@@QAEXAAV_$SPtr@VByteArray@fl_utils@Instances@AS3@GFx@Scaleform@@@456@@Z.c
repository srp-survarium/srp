void __thiscall Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::bytesGet(
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray> *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method LoaderInfo::bytesGet() is not implemented\n");
}
