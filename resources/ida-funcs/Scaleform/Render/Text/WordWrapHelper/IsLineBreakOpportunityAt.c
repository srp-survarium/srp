bool __stdcall Scaleform::Render::Text::WordWrapHelper::IsLineBreakOpportunityAt(
        char wwMode,
        wchar_t prevChar,
        wchar_t curChar)
{
  if ( !prevChar )
    return 0;
  return (prevChar == 9
       || prevChar == 13
       || prevChar == 32
       || prevChar == 12288
       || Scaleform::Render::Text::WordWrapHelper::IsAsianChar(wwMode, curChar)
       || Scaleform::Render::Text::WordWrapHelper::IsAsianChar(wwMode, prevChar)
       || prevChar == 45)
      && !Scaleform::Render::Text::WordWrapHelper::FindCharWithFlags(wwMode, curChar, 1u)
      && !Scaleform::Render::Text::WordWrapHelper::FindCharWithFlags(wwMode, prevChar, 2u);
}
