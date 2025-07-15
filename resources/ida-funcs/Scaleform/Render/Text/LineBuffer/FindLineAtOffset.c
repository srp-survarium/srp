Scaleform::Render::Text::LineBuffer::Iterator *__thiscall Scaleform::Render::Text::LineBuffer::FindLineAtOffset(
        Scaleform::Render::Text::LineBuffer *this,
        Scaleform::Render::Text::LineBuffer::Iterator *result,
        const Scaleform::Render::Point<float> *p)
{
  unsigned int Size; // eax
  float *p_y; // ebx
  unsigned int v6; // ebp
  Scaleform::Render::Text::LineBuffer::Line **Data; // eax
  Scaleform::Render::Text::LineBuffer::Line *v8; // ecx
  int OffsetY; // esi
  bool v10; // dl
  int v11; // edi
  int v12; // eax
  int OffsetX; // esi
  int v14; // ecx
  Scaleform::Render::Text::LineBuffer::Iterator *v15; // eax
  char v16; // dl
  Scaleform::Render::Text::LineBuffer::Line **v17; // [esp+10h] [ebp-14h]
  int v18; // [esp+18h] [ebp-Ch]
  unsigned int v19; // [esp+1Ch] [ebp-8h]

  Size = this->Lines.Data.Size;
  if ( Size )
  {
    p_y = &p->y;
    v6 = Scaleform::Alg::LowerBoundSliced<Scaleform::ArrayLH<Scaleform::Render::Text::LineBuffer::Line *,2,Scaleform::ArrayDefaultPolicy>,float,int (__cdecl *)(Scaleform::Render::Text::LineBuffer::Line const *,float)>(
           &this->Lines,
           0,
           Size,
           &p->y,
           Scaleform::Render::Text::LineBuffer::LineYOffsetComparator::Less);
    v19 = this->Lines.Data.Size;
    if ( v6 == v19 )
      --v6;
    Data = this->Lines.Data.Data;
    v8 = this->Lines.Data.Data[v6];
    OffsetY = v8->Data32.OffsetY;
    v18 = OffsetY;
    v10 = (v8->MemSize & 0x80000000) != 0;
    v17 = &Data[v6];
    while ( (double)OffsetY <= *p_y )
    {
      v11 = v10 ? v8->Data8.Height : v8->Data32.Height;
      v12 = v10 ? v8->Data8.Leading : v8->Data32.Leading;
      if ( (double)(OffsetY + v11 + v12) <= *p_y )
        break;
      OffsetX = v8->Data32.OffsetX;
      if ( (double)OffsetX <= p->x )
      {
        v14 = v10 ? v8->Data8.Width : v8->Data32.Width;
        if ( (double)(OffsetX + v14) > p->x )
        {
          v15 = result;
          result->YOffset = 0.0;
          v16 = this->Geom.Flags >> 2;
          result->CurrentPos = v6;
          result->pHighlight = 0;
          result->StaticText = v16 & 1;
          result->pLineBuffer = this;
          return v15;
        }
      }
      ++v17;
      if ( ++v6 != v19 )
      {
        v8 = *v17;
        OffsetY = (*v17)->Data32.OffsetY;
        v10 = ((*v17)->MemSize & 0x80000000) != 0;
        if ( OffsetY == v18 )
          continue;
      }
      break;
    }
  }
  v15 = result;
  result->YOffset = 0.0;
  result->pHighlight = 0;
  result->CurrentPos = 0;
  result->StaticText = 0;
  result->pLineBuffer = 0;
  return v15;
}
