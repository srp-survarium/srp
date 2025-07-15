Scaleform::Render::PathEdgeType __thiscall Scaleform::Render::ShapeDataPackedDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadEdge(
        Scaleform::Render::ShapeDataPackedDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::Render::ShapePosInfo *pos,
        float *coord)
{
  unsigned int v3; // ebx
  Scaleform::Render::PathEdgeType result; // eax
  int v6; // ecx
  double LastX; // st7
  int v8; // edx
  int LastY; // eax
  int v10; // ecx
  int v11; // edx
  int data; // [esp+Ch] [ebp-14h] BYREF
  int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  int v15; // [esp+18h] [ebp-8h]
  int v16; // [esp+1Ch] [ebp-4h]

  v3 = pos->Pos;
  pos->Pos = v3
           + Scaleform::Render::PathDataDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadEdge(
               &this->Decoder,
               pos->Pos,
               &data);
  switch ( data )
  {
    case 0:
      pos->LastX += v13;
      *coord = (double)pos->LastX * this->OneOverMultiplier;
      coord[1] = (double)pos->LastY * this->OneOverMultiplier;
      result = Edge_LineTo;
      break;
    case 1:
      v6 = v13;
      LastX = (double)pos->LastX;
      goto LABEL_4;
    case 2:
      pos->LastX += v13;
      v6 = v14;
      LastX = (double)pos->LastX;
LABEL_4:
      pos->LastY += v6;
      *coord = LastX * this->OneOverMultiplier;
      result = Edge_LineTo;
      coord[1] = (double)pos->LastY * this->OneOverMultiplier;
      break;
    case 3:
      v8 = pos->LastX;
      LastY = pos->LastY;
      v13 += v8;
      v14 += LastY;
      v10 = v8 + v15;
      v11 = LastY + v16;
      *coord = (double)v13 * this->OneOverMultiplier;
      v15 = v10;
      v16 = v11;
      coord[1] = (double)v14 * this->OneOverMultiplier;
      coord[2] = (double)v15 * this->OneOverMultiplier;
      coord[3] = (double)v16 * this->OneOverMultiplier;
      pos->LastX = v10;
      pos->LastY = v11;
      result = Edge_QuadTo;
      break;
    default:
      result = Edge_EndPath;
      break;
  }
  return result;
}
