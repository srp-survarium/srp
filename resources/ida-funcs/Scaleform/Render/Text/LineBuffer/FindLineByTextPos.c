Scaleform::Render::Text::LineBuffer::Iterator *__thiscall Scaleform::Render::Text::LineBuffer::FindLineByTextPos(
        Scaleform::Render::Text::LineBuffer *this,
        Scaleform::Render::Text::LineBuffer::Iterator *result,
        unsigned int textPos)
{
  unsigned int Size; // eax
  unsigned int v5; // eax
  unsigned int v6; // edi
  Scaleform::Render::Text::LineBuffer::Line *v7; // ecx
  unsigned int v8; // edx
  unsigned int TextLength; // ecx
  Scaleform::Render::Text::LineBuffer::Iterator *v10; // eax
  unsigned __int8 Flags; // cl

  Size = this->Lines.Data.Size;
  if ( !Size )
    goto LABEL_13;
  v5 = Scaleform::Alg::LowerBoundSliced<Scaleform::ArrayLH<Scaleform::Render::Text::LineBuffer::Line *,2,Scaleform::ArrayDefaultPolicy>,unsigned int,int (__cdecl *)(Scaleform::Render::Text::LineBuffer::Line const *,int)>(
         &this->Lines,
         0,
         Size,
         &textPos,
         Scaleform::Render::Text::LineBuffer::LineIndexComparator::Less);
  v6 = v5;
  if ( v5 == this->Lines.Data.Size )
    v6 = v5 - 1;
  v7 = this->Lines.Data.Data[v6];
  v8 = v7->Data32.TextPos;
  if ( (v7->MemSize & 0x80000000) != 0 )
  {
    v8 &= 0xFFFFFFu;
    if ( v8 == 0xFFFFFF )
      v8 = -1;
  }
  if ( textPos >= v8
    && ((v7->MemSize & 0x80000000) == 0
      ? (TextLength = v7->Data32.TextLength)
      : (TextLength = HIBYTE(v7->Data8.TextPosAndLength)),
        textPos <= v8 + TextLength) )
  {
    v10 = result;
    Flags = this->Geom.Flags;
    result->YOffset = 0.0;
    result->CurrentPos = v6;
    result->pLineBuffer = this;
    result->pHighlight = 0;
    result->StaticText = (Flags & 4) != 0;
  }
  else
  {
LABEL_13:
    v10 = result;
    result->YOffset = 0.0;
    result->pLineBuffer = 0;
    result->CurrentPos = 0;
    result->StaticText = 0;
    result->pHighlight = 0;
  }
  return v10;
}
