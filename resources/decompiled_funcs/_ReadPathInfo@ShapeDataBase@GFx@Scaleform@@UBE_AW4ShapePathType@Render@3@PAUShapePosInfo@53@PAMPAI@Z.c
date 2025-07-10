Scaleform::Render::ShapePathType __thiscall Scaleform::GFx::ShapeDataBase::ReadPathInfo(
        Scaleform::GFx::ShapeDataBase *this,
        Scaleform::Render::ShapePosInfo *pos,
        float *coord,
        unsigned int *styles)
{
  double v4; // st7
  Scaleform::Render::ShapePathType v5; // ebp
  char CurBitIndex; // dl
  unsigned int CurByteIndex; // esi
  float sfactor; // [esp+10h] [ebp-18h]
  Scaleform::GFx::SwfShapeDecoder decoder; // [esp+14h] [ebp-14h] BYREF

  if ( (this->Flags & 2) != 0 )
    v4 = 0.050000001;
  else
    v4 = 1.0;
  sfactor = v4;
  Scaleform::GFx::SwfShapeDecoder::SwfShapeDecoder(&decoder, pos, this->Paths, sfactor);
  v5 = Shape_NewPath;
  while ( 1 )
  {
    CurBitIndex = decoder.Stream.CurBitIndex;
    CurByteIndex = decoder.Stream.CurByteIndex;
    if ( ((unsigned __int8)(1 << (7 - LOBYTE(decoder.Stream.CurBitIndex)))
        & decoder.Stream.pData[decoder.Stream.CurByteIndex]) != 0 )
      break;
    v5 = Scaleform::GFx::SwfShapeDecoder::ReadNonEdgeRec(&decoder, v5);
    if ( v5 == Shape_EndShape )
    {
      CurBitIndex = decoder.Stream.CurBitIndex;
      CurByteIndex = decoder.Stream.CurByteIndex;
      goto LABEL_9;
    }
  }
  *styles = pos->Fill0;
  styles[1] = pos->Fill1;
  styles[2] = pos->Stroke;
  *coord = (double)pos->LastX * pos->Sfactor;
  coord[1] = (double)pos->LastY * pos->Sfactor;
LABEL_9:
  decoder.Pos->Pos = CurBitIndex & 7
                   | (8
                    * (decoder.Pos->NumStrokeBits & 0xF | (16 * ((16 * CurByteIndex) | decoder.Pos->NumFillBits & 0xF))));
  return v5;
}
