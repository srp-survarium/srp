DName *__thiscall DName::operator=(DName *this, const DName *rd)
{
  DName *result; // eax

  result = this;
  *this = *rd;
  return result;
}
