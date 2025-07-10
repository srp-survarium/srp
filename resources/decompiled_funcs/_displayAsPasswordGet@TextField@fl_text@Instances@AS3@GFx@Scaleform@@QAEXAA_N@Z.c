void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::displayAsPasswordGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        bool *result)
{
  *result = (*(_DWORD *)&this->pDispObj.pObject[1].ClipDepth & 4) != 0;
}
