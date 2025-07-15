void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::multilineGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        bool *result)
{
  *result = (BYTE1(this->pDispObj.pObject[1].pRenNode.pObject[9].pNative) & 4) != 0;
}
