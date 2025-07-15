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
  Scaleform::GFx::SwfShapeDecoder v10; // [esp+14h] [ebp-28h] BYREF
  Scaleform::GFx::SwfShapeDecoder::Edge v11; // [esp+28h] [ebp-14h] BYREF

  if ( (this->Flags & 2) != 0 )
    v3 = 0.050000001;
  else
    v3 = 1.0;
  sfactor = v3;
  Scaleform::GFx::SwfShapeDecoder::SwfShapeDecoder(&v10, pos, this->Paths, sfactor);
  CurBitIndex = v10.Stream.CurBitIndex;
  CurByteIndex = v10.Stream.CurByteIndex;
  v6 = 0;
  if ( ((unsigned __int8)(1 << (7 - LOBYTE(v10.Stream.CurBitIndex))) & v10.Stream.pData[v10.Stream.CurByteIndex]) != 0 )
  {
    v7 = Scaleform::GFx::SwfShapeDecoder::ReadEdge(&v10, &v11);
    CurBitIndex = v10.Stream.CurBitIndex;
    CurByteIndex = v10.Stream.CurByteIndex;
    v6 = v7;
    if ( v7 == 2 )
    {
      *coord = (double)v11.Cx * pos->Sfactor;
      coord[1] = (double)v11.Cy * pos->Sfactor;
      coord[2] = (double)v11.Ax * pos->Sfactor;
      coord[3] = (double)v11.Ay * pos->Sfactor;
    }
    else
    {
      *coord = (double)v11.Ax * pos->Sfactor;
      coord[1] = (double)v11.Ay * pos->Sfactor;
    }
  }
  v10.Pos->Pos = CurBitIndex & 7
               | (8 * (v10.Pos->NumStrokeBits & 0xF | (16 * ((16 * CurByteIndex) | v10.Pos->NumFillBits & 0xF))));
  return v6;
}
