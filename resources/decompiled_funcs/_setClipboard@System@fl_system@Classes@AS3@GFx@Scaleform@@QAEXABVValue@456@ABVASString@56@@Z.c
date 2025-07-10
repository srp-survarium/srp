void __thiscall Scaleform::GFx::AS3::Classes::fl_system::System::setClipboard(
        Scaleform::GFx::AS3::Classes::fl_system::System *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *string)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method class_::System::setClipboard() is not implemented\n");
}
