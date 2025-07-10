DName *__cdecl operator+(DName *result, char *s, const DName *rd)
{
  DName *v3; // eax
  DName v5; // [esp+0h] [ebp-8h] BYREF

  v3 = DName::DName(&v5, s);
  DName::operator+(v3, result, rd);
  return result;
}
