wchar_t *__thiscall Scaleform::Render::Text::Paragraph::TextBuffer::CreatePosition(
        Scaleform::Render::Text::Paragraph::TextBuffer *this,
        Scaleform::Render::Text::Allocator *pallocator,
        unsigned int pos,
        unsigned int length)
{
  unsigned int Size; // eax
  unsigned int v6; // edx
  wchar_t *v7; // eax
  int v8; // eax
  wchar_t *pText; // ecx

  Size = this->Size;
  if ( this->Allocated < Size + length )
  {
    v6 = 2 * (Size + length);
    if ( this->pText )
      v7 = (wchar_t *)((int (__stdcall *)(wchar_t *, unsigned int))Scaleform::Memory::pGlobalHeap->Realloc)(
                        this->pText,
                        v6);
    else
      v7 = (wchar_t *)((int (__stdcall *)(unsigned int, _DWORD))pallocator->pHeap->Alloc)(v6, 0);
    this->pText = v7;
    Size = this->Size;
    this->Allocated = Size + length;
  }
  v8 = Size - pos;
  if ( v8 )
    memmove((unsigned __int8 *)&this->pText[pos + length], (unsigned __int8 *)&this->pText[pos], 2 * v8);
  pText = this->pText;
  this->Size += length;
  return &pText[pos];
}
