const char *__thiscall Scaleform::GFx::AS2::NumberObject::GetTextValue(
        Scaleform::GFx::AS2::NumberObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::String *v2; // esi
  const __m128i *v3; // eax
  __int64 v5; // [esp+8h] [ebp-50h]
  char v6; // [esp+18h] [ebp-40h] BYREF

  HIDWORD(v5) = 64;
  v2 = (Scaleform::String *)this;
  LODWORD(v5) = &v6;
  v3 = (const __m128i *)Scaleform::GFx::NumberUtil::ToString(*(double *)&this->ResolveHandler.Flags, v5, 10);
  v2 += 12;
  Scaleform::String::operator=(v2, v3);
  return (const char *)((v2->HeapTypeBits & 0xFFFFFFFC) + 8);
}
