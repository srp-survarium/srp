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
  int tmp[5]; // [esp+Ch] [ebp-14h] BYREF

  v3 = pos->Pos;
  pos->Pos = v3
           + Scaleform::Render::PathDataDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadEdge(
               &this->Decoder,
               pos->Pos,
               tmp);
  switch ( tmp[0] )
  {
    case 0:
      pos->LastX += tmp[1];
      *coord = (double)pos->LastX * this->OneOverMultiplier;
      coord[1] = (double)pos->LastY * this->OneOverMultiplier;
      result = Edge_LineTo;
      break;
    case 1:
      v6 = tmp[1];
      LastX = (double)pos->LastX;
      goto LABEL_4;
    case 2:
      pos->LastX += tmp[1];
      v6 = tmp[2];
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
      tmp[1] += v8;
      tmp[2] += LastY;
      v10 = v8 + tmp[3];
      v11 = LastY + tmp[4];
      *coord = (double)tmp[1] * this->OneOverMultiplier;
      tmp[3] = v10;
      tmp[4] = v11;
      coord[1] = (double)tmp[2] * this->OneOverMultiplier;
      coord[2] = (double)tmp[3] * this->OneOverMultiplier;
      coord[3] = (double)tmp[4] * this->OneOverMultiplier;
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
