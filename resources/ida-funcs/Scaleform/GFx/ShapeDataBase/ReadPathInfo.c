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
  Scaleform::GFx::SwfShapeDecoder v10; // [esp+14h] [ebp-14h] BYREF

  if ( (this->Flags & 2) != 0 )
    v4 = 0.050000001;
  else
    v4 = 1.0;
  sfactor = v4;
  Scaleform::GFx::SwfShapeDecoder::SwfShapeDecoder(&v10, pos, this->Paths, sfactor);
  v5 = Shape_NewPath;
  while ( 1 )
  {
    CurBitIndex = v10.Stream.CurBitIndex;
    CurByteIndex = v10.Stream.CurByteIndex;
    if ( ((unsigned __int8)(1 << (7 - LOBYTE(v10.Stream.CurBitIndex))) & v10.Stream.pData[v10.Stream.CurByteIndex]) != 0 )
      break;
    v5 = Scaleform::GFx::SwfShapeDecoder::ReadNonEdgeRec(&v10, v5);
    if ( v5 == Shape_EndShape )
    {
      CurBitIndex = v10.Stream.CurBitIndex;
      CurByteIndex = v10.Stream.CurByteIndex;
      goto LABEL_9;
    }
  }
  *styles = pos->Fill0;
  styles[1] = pos->Fill1;
  styles[2] = pos->Stroke;
  *coord = (double)pos->LastX * pos->Sfactor;
  coord[1] = (double)pos->LastY * pos->Sfactor;
LABEL_9:
  v10.Pos->Pos = CurBitIndex & 7
               | (8 * (v10.Pos->NumStrokeBits & 0xF | (16 * ((16 * CurByteIndex) | v10.Pos->NumFillBits & 0xF))));
  return v5;
}
