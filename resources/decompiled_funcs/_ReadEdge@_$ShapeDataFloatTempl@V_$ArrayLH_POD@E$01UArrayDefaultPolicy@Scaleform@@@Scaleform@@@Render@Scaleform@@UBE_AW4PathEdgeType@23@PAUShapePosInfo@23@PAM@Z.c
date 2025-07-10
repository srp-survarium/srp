Scaleform::Render::PathEdgeType __thiscall Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadEdge(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::Render::ShapePosInfo *pos,
        float *coord)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // edx
  unsigned __int8 v4; // bl
  unsigned int v5; // esi
  Scaleform::Render::PathEdgeType result; // eax
  int v7; // ebp

  Data = this->Data;
  v4 = Data->Data.Data[pos->Pos];
  v5 = pos->Pos + 1;
  result = Edge_EndPath;
  pos->Pos = v5;
  if ( v4 != 6 )
  {
    v7 = 1;
    *coord = *(float *)&Data->Data.Data[v5];
    pos->Pos += 4;
    coord[1] = *(float *)&Data->Data.Data[pos->Pos];
    pos->Pos += 4;
    if ( (v4 == 4 || v4 == 5)
      && (v7 = 2,
          coord[2] = *(float *)&Data->Data.Data[pos->Pos],
          pos->Pos += 4,
          coord[3] = *(float *)&Data->Data.Data[pos->Pos],
          pos->Pos += 4,
          v4 == 5) )
    {
      coord[4] = *(float *)&Data->Data.Data[pos->Pos];
      pos->Pos += 4;
      result = Edge_CubicTo;
      coord[5] = *(float *)&Data->Data.Data[pos->Pos];
      pos->Pos += 4;
    }
    else
    {
      return v7;
    }
  }
  return result;
}
