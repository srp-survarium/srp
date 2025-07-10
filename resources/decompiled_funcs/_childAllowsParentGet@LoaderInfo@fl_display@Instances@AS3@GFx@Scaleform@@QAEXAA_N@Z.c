void __thiscall Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::childAllowsParentGet(
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *this,
        bool *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method LoaderInfo::childAllowsParentGet() is not implemented\n");
}
