DName *__cdecl UnDecorator::getLexicalFrame(DName *result)
{
  const DName *Dimension; // eax
  DName *v2; // eax
  DName v4; // [esp+0h] [ebp-10h] BYREF
  DName resulta; // [esp+8h] [ebp-8h] BYREF

  Dimension = UnDecorator::getDimension(&resulta, 0);
  v2 = operator+(&v4, 96, Dimension);
  DName::operator+(v2, result, 39);
  return result;
}
