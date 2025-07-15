void __thiscall Scaleform::Render::ShapeDataPackedEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ClosePath(
        Scaleform::Render::ShapeDataPackedEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::Render::ShapePosInfo *pos)
{
  int LastX; // edx
  int StartX; // eax
  int v4; // eax
  int v5; // edi
  int v6; // ebx

  LastX = pos->LastX;
  StartX = pos->StartX;
  if ( LastX != StartX || pos->LastY != pos->StartY )
  {
    v4 = StartX - LastX;
    v5 = pos->StartY - pos->LastY;
    v6 = v4;
    if ( v5 )
    {
      if ( v4 )
      {
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
          &this->Encoder,
          v4,
          v5);
        pos->LastX += v6;
      }
      else
      {
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
          &this->Encoder,
          v5);
        pos->LastX = pos->LastX;
      }
      pos->LastY += v5;
    }
    else
    {
      Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
        &this->Encoder,
        v4);
      pos->LastX += v6;
      pos->LastY = pos->LastY;
    }
  }
}
