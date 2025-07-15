void __thiscall Scaleform::StringBuffer::operator=(Scaleform::StringBuffer *this, const __m128i *pstr)
{
  const __m128i *v2; // edi
  unsigned int v4; // esi

  v2 = pstr;
  if ( !pstr )
    v2 = (const __m128i *)uri;
  v4 = strlen(v2->m128i_i8);
  Scaleform::StringBuffer::Resize(this, v4);
  memcpy((int)this->pData, v2, v4);
}


void __thiscall Scaleform::StringBuffer::operator+=(Scaleform::StringBuffer *this, const Scaleform::String *src)
{
  Scaleform::StringBuffer::AppendString(
    this,
    (const __m128i *)((src->HeapTypeBits & 0xFFFFFFFC) + 8),
    *(_DWORD *)(src->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
}
