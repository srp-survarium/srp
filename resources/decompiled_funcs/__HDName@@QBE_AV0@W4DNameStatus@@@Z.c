DName *__thiscall DName::operator+(DName *this, DName *result, DNameStatus st)
{
  *result = *this;
  DName::operator+=(result, st);
  return result;
}
