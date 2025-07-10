bool __thiscall Scaleform::String::operator!=(Scaleform::String *this, const char *str)
{
  return strcmp((const char *)((this->HeapTypeBits & 0xFFFFFFFC) + 8), str) != 0;
}
