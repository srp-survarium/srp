int __thiscall Scaleform::String::CompareNoCase(Scaleform::String *this, const Scaleform::String *str)
{
  return Scaleform::String::CompareNoCase(
           (const char *)((this->HeapTypeBits & 0xFFFFFFFC) + 8),
           (const char *)((str->HeapTypeBits & 0xFFFFFFFC) + 8));
}
