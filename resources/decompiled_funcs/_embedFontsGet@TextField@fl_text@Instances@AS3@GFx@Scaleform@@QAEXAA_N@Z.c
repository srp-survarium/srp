void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::embedFontsGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        bool *result)
{
  *result = (BYTE1(this->pDispObj.pObject[1].pRenNode.pObject[9].pNative) & 0x20) == 0;
}
