DName *__thiscall DName::operator+(DName *this, DName *result, char *str)
{
  *result = *this;
  DName::operator+=(result, str);
  return result;
}
