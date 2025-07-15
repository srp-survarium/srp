Scaleform::StringDataPtr *__thiscall Scaleform::GFx::AS3::Abc::StringView::ToStringDataPtr(
        Scaleform::GFx::AS3::Abc::StringView *this,
        Scaleform::StringDataPtr *result)
{
  Scaleform::StringDataPtr *v2; // eax
  unsigned int v3; // eax
  const unsigned __int8 *d; // [esp+0h] [ebp-4h] BYREF

  d = (const unsigned __int8 *)this;
  d = this->Data;
  if ( d )
  {
    v3 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&d);
    Scaleform::GFx::AS3::Abc::ReadStringPtr<unsigned char>(result, (const char **)&d, v3);
    return result;
  }
  else
  {
    v2 = result;
    result->pStr = uri;
    result->Size = 0;
  }
  return v2;
}
