DName *__thiscall DName::operator+(DName *this, DName *result, char ch)
{
  *result = *this;
  DName::operator+=(result, ch);
  return result;
}
