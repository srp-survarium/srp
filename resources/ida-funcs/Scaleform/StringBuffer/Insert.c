void __thiscall Scaleform::StringBuffer::Insert(
        Scaleform::StringBuffer *this,
        const __m128i *substr,
        const char *posAt,
        int len)
{
  unsigned int v4; // eax
  unsigned int Size; // ebx
  const char *ByteIndex; // ebp
  unsigned int v8; // edi
  char *pData; // edx
  unsigned int v10; // eax
  char *v11; // eax
  char *v12; // eax
  unsigned int count; // [esp+1Ch] [ebp+Ch]

  v4 = len;
  Size = this->Size;
  if ( len < 0 )
    v4 = strlen(substr->m128i_i8);
  count = v4;
  if ( this->LengthIsSize )
    ByteIndex = posAt;
  else
    ByteIndex = Scaleform::UTF8Util::GetByteIndex((int)posAt, this->pData, Size);
  v8 = count + Size;
  if ( count + Size >= this->BufferSize )
  {
    pData = this->pData;
    v10 = ~(this->GrowSize - 1) & (this->GrowSize + v8);
    this->BufferSize = v10;
    if ( pData )
      v11 = (char *)Scaleform::Memory::pGlobalHeap->Realloc(Scaleform::Memory::pGlobalHeap, pData, v10);
    else
      v11 = (char *)this->pHeap->Alloc(this->pHeap, v10, 0);
    this->pData = v11;
  }
  memmove(
    (int)&ByteIndex[(unsigned int)this->pData + count],
    (const __m128i *)&ByteIndex[(unsigned int)this->pData],
    Size - (_DWORD)ByteIndex + 1);
  memcpy((int)&ByteIndex[(unsigned int)this->pData], substr, count);
  v12 = this->pData;
  this->Size = v8;
  this->LengthIsSize = 0;
  v12[v8] = 0;
}
