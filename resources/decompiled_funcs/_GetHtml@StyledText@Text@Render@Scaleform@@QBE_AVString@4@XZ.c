Scaleform::String *__thiscall Scaleform::Render::Text::StyledText::GetHtml(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::String *result)
{
  const Scaleform::StringBuffer *Html; // eax
  Scaleform::StringBuffer retStr; // [esp+4h] [ebp-18h] BYREF

  Scaleform::StringBuffer::StringBuffer(&retStr, Scaleform::Memory::pGlobalHeap);
  Html = Scaleform::Render::Text::StyledText::GetHtml(this, &retStr);
  Scaleform::String::String(result, Html);
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&retStr);
  return result;
}
