void __thiscall Scaleform::StringBuffer::Insert(
        Scaleform::StringBuffer *this,
        char *substr,
        unsigned int posAt,
        int len)
{
  unsigned int v4; // eax
  unsigned int Size; // ebx
  int ByteIndex; // ebp
  unsigned int v8; // edi
  char *pData; // edx
  unsigned int v10; // eax
  char *v11; // eax
  char *v12; // eax
  unsigned int insertSize; // [esp+1Ch] [ebp+Ch]

  v4 = len;
  Size = this->Size;
  if ( len < 0 )
    v4 = strlen(substr);
  insertSize = v4;
  if ( this->LengthIsSize )
    ByteIndex = posAt;
  else
    ByteIndex = Scaleform::UTF8Util::GetByteIndex(posAt, this->pData, Size);
  v8 = insertSize + Size;
  if ( insertSize + Size >= this->BufferSize )
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
    (unsigned __int8 *)&this->pData[ByteIndex + insertSize],
    (unsigned __int8 *)&this->pData[ByteIndex],
    Size - ByteIndex + 1);
  memcpy((unsigned __int8 *)&this->pData[ByteIndex], (unsigned __int8 *)substr, insertSize);
  v12 = this->pData;
  this->Size = v8;
  this->LengthIsSize = 0;
  v12[v8] = 0;
}
