Scaleform::GFx::Text::IMEStyle::Category __usercall Scaleform::GFx::AS2::GFx_StringToIMEStyleCategory@<eax>(
        Scaleform::GFx::ASString *categoryStr@<edi>)
{
  Scaleform::GFx::Text::IMEStyle::Category result; // eax
  bool v2; // zf

  result = strcmp(categoryStr->pNode->pData, "compositionSegment");
  if ( result )
  {
    if ( !strcmp(categoryStr->pNode->pData, "clauseSegment") )
    {
      return 1;
    }
    else if ( !strcmp(categoryStr->pNode->pData, "convertedSegment") )
    {
      return 2;
    }
    else if ( Scaleform::GFx::ASString::operator==(categoryStr, "phraseLengthAdj") )
    {
      return 3;
    }
    else
    {
      v2 = !Scaleform::GFx::ASString::operator==(categoryStr, "lowConfSegment");
      result = SC_LowConfSegment;
      if ( v2 )
        return 5;
    }
  }
  return result;
}
