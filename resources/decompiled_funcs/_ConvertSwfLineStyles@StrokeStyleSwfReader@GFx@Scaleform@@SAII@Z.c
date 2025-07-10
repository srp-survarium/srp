unsigned int __cdecl Scaleform::GFx::StrokeStyleSwfReader::ConvertSwfLineStyles(__int16 swfLineStyle)
{
  unsigned int result; // eax

  result = (swfLineStyle & 1) != 0;
  if ( (swfLineStyle & 2) != 0 )
    result |= 2u;
  if ( (swfLineStyle & 4) != 0 )
    result |= 4u;
  if ( (swfLineStyle & 6) == 6 )
    result = 6;
  if ( (swfLineStyle & 0x10) != 0 )
    result |= 0x10u;
  if ( (swfLineStyle & 0x20) != 0 )
    result |= 0x20u;
  if ( (swfLineStyle & 0x40) != 0 )
    result |= 0x40u;
  if ( (swfLineStyle & 0x80u) != 0 )
    result |= 0x80u;
  if ( (swfLineStyle & 0x100) != 0 )
    result |= 0x100u;
  if ( (swfLineStyle & 0x200) != 0 )
    result |= 0x200u;
  if ( (swfLineStyle & 8) != 0 )
    result |= 8u;
  return result;
}
