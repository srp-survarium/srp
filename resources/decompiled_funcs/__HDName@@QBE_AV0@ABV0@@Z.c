DName *__thiscall DName::operator+(DName *this, DName *result, const DName *rd)
{
  *result = *this;
  DName::operator+=(result, rd);
  return result;
}
