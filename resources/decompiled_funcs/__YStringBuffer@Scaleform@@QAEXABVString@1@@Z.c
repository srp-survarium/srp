void __thiscall Scaleform::StringBuffer::operator+=(Scaleform::StringBuffer *this, const Scaleform::String *src)
{
  Scaleform::StringBuffer::AppendString(
    this,
    (char *)((src->HeapTypeBits & 0xFFFFFFFC) + 8),
    *(_DWORD *)(src->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
}
