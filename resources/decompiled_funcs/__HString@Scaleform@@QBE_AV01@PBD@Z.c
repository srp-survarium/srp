Scaleform::String *__thiscall Scaleform::String::operator+(
        Scaleform::String *this,
        Scaleform::String *result,
        char *str)
{
  char *v3; // eax

  Scaleform::String::String(result, this);
  v3 = str;
  if ( !str )
    v3 = (char *)&buf;
  Scaleform::String::AppendString(result, v3, 0xFFFFFFFF);
  return result;
}
