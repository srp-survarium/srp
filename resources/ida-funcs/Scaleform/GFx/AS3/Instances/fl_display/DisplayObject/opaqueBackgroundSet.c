void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::opaqueBackgroundSet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::AS3::Value *value)
{
  unsigned int v3; // eax
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  v3 = value->Flags & 0x1F;
  if ( v3 - 12 > 3 || value->value.VS._1.VInt )
  {
    if ( v3 )
    {
      UI = this->pTraits.pObject->pVM->UI;
      UI->Output(UI, Output_Warning, "The method DisplayObject::opaqueBackgroundSet() is not implemented\n");
    }
  }
}
