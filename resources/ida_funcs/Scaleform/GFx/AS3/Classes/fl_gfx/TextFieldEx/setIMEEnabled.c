void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setIMEEnabled(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField,
        bool isEnabled)
{
  Scaleform::GFx::DisplayObject *pObject; // eax

  pObject = textField->pDispObj.pObject;
  if ( isEnabled )
    *(_DWORD *)&pObject[1].ClipDepth &= ~0x800u;
  else
    *(_DWORD *)&pObject[1].ClipDepth |= 0x800u;
}
