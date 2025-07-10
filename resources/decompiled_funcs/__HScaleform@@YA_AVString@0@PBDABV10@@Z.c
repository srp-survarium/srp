Scaleform::String *__cdecl Scaleform::operator+(Scaleform::String *result, char *l, const Scaleform::String *r)
{
  Scaleform::String::String(result, l, (char *)((r->HeapTypeBits & 0xFFFFFFFC) + 8), 0);
  return result;
}
