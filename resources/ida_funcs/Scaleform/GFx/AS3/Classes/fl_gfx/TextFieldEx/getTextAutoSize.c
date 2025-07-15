void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::getTextAutoSize(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField)
{
  if ( ((LOBYTE(textField->pDispObj.pObject[1].pRenNode.pObject[9].pNative) >> 4) & 3) == 1 )
  {
    Scaleform::GFx::ASString::operator=(result, "shrink");
  }
  else if ( ((LOBYTE(textField->pDispObj.pObject[1].pRenNode.pObject[9].pNative) >> 4) & 3) == 2 )
  {
    Scaleform::GFx::ASString::operator=(result, "fit");
  }
  else
  {
    Scaleform::GFx::ASString::operator=(result, "none");
  }
}
