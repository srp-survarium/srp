Scaleform::Render::Text::LineBuffer::Iterator *__thiscall Scaleform::Render::Text::LineBuffer::FindLineAtYOffset(
        Scaleform::Render::Text::LineBuffer *this,
        Scaleform::Render::Text::LineBuffer::Iterator *result,
        float yoff)
{
  unsigned int Size; // eax
  unsigned int v5; // eax
  unsigned int v6; // edi
  double v7; // st7
  Scaleform::Render::Text::LineBuffer::Line *v8; // ecx
  unsigned int Height; // ebx
  int Leading; // eax
  Scaleform::Render::Text::LineBuffer::Iterator *v11; // eax
  unsigned __int8 Flags; // cl

  Size = this->Lines.Data.Size;
  if ( !Size )
    goto LABEL_13;
  v5 = Scaleform::Alg::LowerBoundSliced<Scaleform::ArrayLH<Scaleform::Render::Text::LineBuffer::Line *,2,Scaleform::ArrayDefaultPolicy>,float,int (__cdecl *)(Scaleform::Render::Text::LineBuffer::Line const *,float)>(
         &this->Lines,
         0,
         Size,
         &yoff,
         Scaleform::Render::Text::LineBuffer::LineYOffsetComparator::Less);
  v6 = v5;
  if ( v5 == this->Lines.Data.Size )
    v6 = v5 - 1;
  v7 = yoff;
  v8 = this->Lines.Data.Data[v6];
  if ( (double)v8->Data32.OffsetY <= yoff
    && ((v8->MemSize & 0x80000000) == 0 ? (Height = v8->Data32.Height) : (Height = v8->Data8.Height),
        (v8->MemSize & 0x80000000) == 0 ? (Leading = v8->Data32.Leading) : (Leading = v8->Data8.Leading),
        LODWORD(yoff) = v8->Data32.OffsetY + Height + Leading,
        (double)SLODWORD(yoff) > v7) )
  {
    v11 = result;
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
    v11 = result;
    result->YOffset = 0.0;
    result->pLineBuffer = 0;
    result->pHighlight = 0;
    result->CurrentPos = 0;
    result->StaticText = 0;
  }
  return v11;
}
