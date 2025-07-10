void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::accessibilityPropertiesGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_accessibility::AccessibilityProperties> *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(
    UI,
    Output_Warning,
    "The method instance::DisplayObject::accessibilityPropertiesGet() is not implemented\n");
}
