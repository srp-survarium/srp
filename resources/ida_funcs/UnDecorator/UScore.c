const char *__cdecl UnDecorator::UScore(Tokens tok)
{
  const char *result; // eax

  result = tokenTable[tok];
  if ( (UnDecorator::disableFlags & 1) != 0 )
    result += 2;
  return result;
}
