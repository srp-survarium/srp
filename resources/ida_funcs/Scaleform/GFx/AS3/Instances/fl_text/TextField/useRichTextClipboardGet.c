void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::useRichTextClipboardGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        bool *result)
{
  *result = BYTE1(*(_DWORD *)&this->pDispObj.pObject[1].ClipDepth) & 1;
}
