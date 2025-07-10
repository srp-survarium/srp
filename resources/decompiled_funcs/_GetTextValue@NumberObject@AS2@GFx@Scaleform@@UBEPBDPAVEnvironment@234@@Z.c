const char *__thiscall Scaleform::GFx::AS2::NumberObject::GetTextValue(
        Scaleform::GFx::AS2::NumberObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::String *v2; // esi
  char *v3; // eax
  char buf[64]; // [esp+18h] [ebp-40h] BYREF

  v2 = (Scaleform::String *)this;
  v3 = Scaleform::GFx::NumberUtil::ToString(*(double *)&this->ResolveHandler.Flags, buf, 0x40u, 10);
  v2 += 12;
  Scaleform::String::operator=(v2, v3);
  return (const char *)((v2->HeapTypeBits & 0xFFFFFFFC) + 8);
}
