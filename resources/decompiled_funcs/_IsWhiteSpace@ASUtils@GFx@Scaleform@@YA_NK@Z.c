BOOL __cdecl Scaleform::GFx::ASUtils::IsWhiteSpace(unsigned int c)
{
  return c == 32
      || c == 10
      || c == 13
      || c == 9
      || c == 12
      || c == 11
      || c >= 0x2000 && c <= 0x200B
      || c == 8232
      || c == 8233
      || c == 8287
      || c == 12288;
}
