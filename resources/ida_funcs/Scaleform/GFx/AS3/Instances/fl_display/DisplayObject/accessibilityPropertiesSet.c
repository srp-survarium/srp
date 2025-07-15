void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::accessibilityPropertiesSet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_accessibility::AccessibilityProperties *value)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(
    UI,
    Output_Warning,
    "The method instance::DisplayObject::accessibilityPropertiesSet() is not implemented\n");
}
