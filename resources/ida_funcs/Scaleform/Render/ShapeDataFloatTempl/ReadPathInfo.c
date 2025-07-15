Scaleform::Render::ShapePathType __thiscall Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadPathInfo(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        float pos,
        float *coord,
        unsigned int *styles)
{
  Scaleform::Render::ShapePosInfo *v4; // esi
  unsigned int v5; // eax
  Scaleform::Render::ShapePosInfo *Data; // edi
  Scaleform::Render::ShapePathType result; // eax
  char v8; // cl
  unsigned int v9; // eax
  Scaleform::Render::ShapePathType v10; // ebp
  unsigned int *v11; // ebx
  unsigned int UInt30; // eax
  char v13; // cl
  _BYTE *v14; // eax
  char v15; // dl
  char v16; // cl
  float *v17; // ecx
  unsigned int v18; // eax
  unsigned int v19; // edx

  v4 = (Scaleform::Render::ShapePosInfo *)LODWORD(pos);
  v5 = *(_DWORD *)LODWORD(pos);
  Data = (Scaleform::Render::ShapePosInfo *)this->Data;
  if ( *(_DWORD *)LODWORD(pos) >= Data->StartX )
    return 0;
  v8 = *(_BYTE *)(v5 + Data->Pos);
  v9 = v5 + 1;
  v10 = Shape_NewPath;
  pos = *(float *)&Data;
  v4->Pos = v9;
  if ( v8 == 7 )
    return 0;
  if ( !v8 )
  {
    v10 = Shape_NewLayer;
    v4->Pos = v9 + 1;
  }
  v11 = styles;
  v4->Pos += Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadUInt30(
               (Scaleform::Render::PathDataDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&pos,
               v4->Pos,
               styles);
  v4->Pos += Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadUInt30(
               (Scaleform::Render::PathDataDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&pos,
               v4->Pos,
               v11 + 1);
  UInt30 = Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadUInt30(
             (Scaleform::Render::PathDataDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&pos,
             v4->Pos,
             v11 + 2);
  pos = 0.0;
  v4->Pos += UInt30 + 1;
  v13 = *(_BYTE *)(v4->Pos + Data->Pos);
  v14 = (_BYTE *)(Data->Pos + v4->Pos);
  BYTE1(pos) = v14[1];
  v15 = v14[3];
  LOBYTE(pos) = v13;
  v16 = v14[2];
  HIBYTE(pos) = v15;
  BYTE2(pos) = v16;
  v17 = coord;
  *coord = pos;
  v4->Pos += 4;
  v18 = v4->Pos;
  v19 = Data->Pos;
  pos = 0.0;
  pos = *(float *)(v19 + v18);
  result = v10;
  v17[1] = pos;
  v4->Pos += 4;
  return result;
}
