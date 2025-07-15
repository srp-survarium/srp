int __thiscall Scaleform::GFx::ShapeDataBase::ReadEdge(
        Scaleform::GFx::ShapeDataBase *this,
        Scaleform::Render::ShapePosInfo *pos,
        float *coord)
{
  double v3; // st7
  char CurBitIndex; // dl
  unsigned int CurByteIndex; // edi
  int v6; // ebp
  int v7; // eax
  float sfactor; // [esp+10h] [ebp-2Ch]
  Scaleform::GFx::SwfShapeDecoder decoder; // [esp+14h] [ebp-28h] BYREF
  Scaleform::GFx::SwfShapeDecoder::Edge edge; // [esp+28h] [ebp-14h] BYREF

  if ( (this->Flags & 2) != 0 )
    v3 = 0.050000001;
  else
    v3 = 1.0;
  sfactor = v3;
  Scaleform::GFx::SwfShapeDecoder::SwfShapeDecoder(&decoder, pos, this->Paths, sfactor);
  CurBitIndex = decoder.Stream.CurBitIndex;
  CurByteIndex = decoder.Stream.CurByteIndex;
  v6 = 0;
  if ( ((unsigned __int8)(1 << (7 - LOBYTE(decoder.Stream.CurBitIndex)))
      & decoder.Stream.pData[decoder.Stream.CurByteIndex]) != 0 )
  {
    v7 = Scaleform::GFx::SwfShapeDecoder::ReadEdge(&decoder, &edge);
    CurBitIndex = decoder.Stream.CurBitIndex;
    CurByteIndex = decoder.Stream.CurByteIndex;
    v6 = v7;
    if ( v7 == 2 )
    {
      *coord = (double)edge.Cx * pos->Sfactor;
      coord[1] = (double)edge.Cy * pos->Sfactor;
      coord[2] = (double)edge.Ax * pos->Sfactor;
      coord[3] = (double)edge.Ay * pos->Sfactor;
    }
    else
    {
      *coord = (double)edge.Ax * pos->Sfactor;
      coord[1] = (double)edge.Ay * pos->Sfactor;
    }
  }
  decoder.Pos->Pos = CurBitIndex & 7
                   | (8
                    * (decoder.Pos->NumStrokeBits & 0xF | (16 * ((16 * CurByteIndex) | decoder.Pos->NumFillBits & 0xF))));
  return v6;
}
