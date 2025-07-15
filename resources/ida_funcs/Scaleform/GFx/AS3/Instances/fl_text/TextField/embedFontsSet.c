void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::embedFontsSet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        const Scaleform::GFx::AS3::Value *result,
        bool value)
{
  if ( value )
    BYTE1(this->pDispObj.pObject[1].pRenNode.pObject[9].pNative) &= ~0x20u;
  else
    BYTE1(this->pDispObj.pObject[1].pRenNode.pObject[9].pNative) |= 0x20u;
}
