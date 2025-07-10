bool __thiscall Scaleform::String::operator==(Scaleform::String *this, const Scaleform::String *str)
{
  return strcmp(
           (const char *)((this->HeapTypeBits & 0xFFFFFFFC) + 8),
           (const char *)((str->HeapTypeBits & 0xFFFFFFFC) + 8)) == 0;
}
