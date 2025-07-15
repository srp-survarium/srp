void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::getVerticalAlign(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField)
{
  switch ( (LOBYTE(textField->pDispObj.pObject[1].pRenNode.pObject[9].pNative) >> 2) & 3 )
  {
    case 1:
      Scaleform::GFx::ASString::operator=(result, (Scaleform::GFx::ASStringNode *)"top");
      break;
    case 2:
      Scaleform::GFx::ASString::operator=(result, (Scaleform::GFx::ASStringNode *)"bottom");
      break;
    case 3:
      Scaleform::GFx::ASString::operator=(result, (Scaleform::GFx::ASStringNode *)"center");
      break;
    default:
      Scaleform::GFx::ASString::operator=(result, (Scaleform::GFx::ASStringNode *)"none");
      break;
  }
}
