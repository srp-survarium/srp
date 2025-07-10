Scaleform::String *__thiscall Scaleform::String::operator+(
        Scaleform::String *this,
        Scaleform::String *result,
        const Scaleform::String *src)
{
  Scaleform::String::String(result, this);
  Scaleform::String::operator+=(result, src);
  return result;
}
