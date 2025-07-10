int __cdecl Scaleform::GFx::AS3::Classes::fl_display::BlendMode::GetBlendMode(Scaleform::GFx::ASString *value)
{
  int v1; // ebx

  v1 = 0;
  if ( !strcmp(value->pNode->pData, "normal") )
    return 1;
  if ( !strcmp(value->pNode->pData, "add") )
    return 8;
  if ( !strcmp(value->pNode->pData, "alpha") )
    return 11;
  if ( Scaleform::GFx::ASString::operator==(value, "multiply") )
    return 3;
  if ( Scaleform::GFx::ASString::operator==(value, "subtract") )
    return 9;
  if ( Scaleform::GFx::ASString::operator==(value, "layer") )
    return 2;
  if ( Scaleform::GFx::ASString::operator==(value, "screen") )
    return 4;
  if ( Scaleform::GFx::ASString::operator==(value, "lighten") )
    return 5;
  if ( Scaleform::GFx::ASString::operator==(value, "darken") )
    return 6;
  if ( Scaleform::GFx::ASString::operator==(value, "difference") )
    return 7;
  if ( Scaleform::GFx::ASString::operator==(value, "invert") )
    return 10;
  if ( Scaleform::GFx::ASString::operator==(value, "erase") )
    return 12;
  if ( Scaleform::GFx::ASString::operator==(value, "overlay") )
    return 13;
  if ( Scaleform::GFx::ASString::operator==(value, "hardlight") )
    return 14;
  return v1;
}
