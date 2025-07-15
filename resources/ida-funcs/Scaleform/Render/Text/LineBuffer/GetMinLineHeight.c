int __thiscall Scaleform::Render::Text::LineBuffer::GetMinLineHeight(Scaleform::Render::Text::LineBuffer *this)
{
  unsigned int Size; // ebp
  int v3; // esi
  int v4; // edi
  Scaleform::Render::Text::LineBuffer::Line *v5; // edx
  int Height; // edx

  Size = this->Lines.Data.Size;
  if ( !Size )
    return 0;
  v3 = 0;
  v4 = 0x7FFFFFFF;
  while ( v3 < Size && v3 >= 0 )
  {
    v5 = this->Lines.Data.Data[v3];
    if ( (v5->MemSize & 0x80000000) == 0 )
      Height = v5->Data32.Height;
    else
      Height = v5->Data8.Height;
    if ( Height < v4 )
      v4 = Height;
    ++v3;
  }
  return v4;
}
