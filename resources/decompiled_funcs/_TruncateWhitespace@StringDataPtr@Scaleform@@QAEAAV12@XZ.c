Scaleform::StringDataPtr *__thiscall Scaleform::StringDataPtr::TruncateWhitespace(Scaleform::StringDataPtr *this)
{
  Scaleform::StringDataPtr result; // [esp+4h] [ebp-8h] BYREF

  *this = *Scaleform::StringDataPtr::GetTruncateWhitespace(this, &result);
  return this;
}
