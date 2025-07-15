void __thiscall Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadBounds(
        Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *this,
        unsigned int pos)
{
  unsigned int v2; // edi
  unsigned int v4; // edi
  unsigned int v5; // edi
  __int16 v6; // ax
  unsigned int SInt15; // eax
  __int16 v8; // dx
  unsigned int v9; // edi
  unsigned int v10; // eax
  __int16 v11; // cx
  unsigned int v12; // [esp-8h] [ebp-10h]

  v2 = pos;
  v12 = pos;
  this->Pos = pos;
  v4 = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadSInt15(
         &this->Data,
         v12,
         (int *)&pos)
     + v2;
  this->XMin = pos;
  this->Pos = v4;
  v5 = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadSInt15(
         &this->Data,
         v4,
         (int *)&pos)
     + v4;
  v6 = pos;
  this->Pos = v5;
  this->YMin = v6;
  SInt15 = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadSInt15(
             &this->Data,
             v5,
             (int *)&pos);
  v8 = pos;
  v9 = SInt15 + v5;
  this->Pos = v9;
  this->XMax = v8;
  v10 = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadSInt15(
          &this->Data,
          v9,
          (int *)&pos);
  v11 = pos;
  this->Pos = v9 + v10;
  this->YMax = v11;
}


void __thiscall Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::ReadBounds(
        Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261> > *this,
        unsigned int pos)
{
  const Scaleform::ArrayUnsafeLH_POD<unsigned char,261> *Data; // edi
  unsigned __int8 *v3; // edx
  int v4; // eax
  int v5; // edx
  int v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // edx
  int v10; // eax
  unsigned int v11; // esi
  unsigned __int8 *v12; // edx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  unsigned int v16; // esi
  int v17; // eax
  int v18; // edx
  unsigned int v19; // esi

  Data = this->Data.Data;
  this->Pos = pos;
  v3 = &Data->Data[pos];
  v4 = (char)*v3;
  if ( (v4 & 1) != 0 )
  {
    v5 = (v4 >> 1) & 0x7F | ((char)v3[1] << 7);
    v6 = 2;
  }
  else
  {
    LOWORD(v5) = v4 >> 1;
    v6 = 1;
  }
  v7 = v6 + pos;
  this->XMin = v5;
  this->Pos = v6 + pos;
  v8 = (char)Data->Data[v6 + pos];
  if ( (v8 & 1) != 0 )
  {
    v9 = (v8 >> 1) & 0x7F | ((char)Data->Data[v7 + 1] << 7);
    v10 = 2;
  }
  else
  {
    LOWORD(v9) = v8 >> 1;
    v10 = 1;
  }
  v11 = v10 + v7;
  this->YMin = v9;
  this->Pos = v11;
  v12 = &Data->Data[v11];
  v13 = (char)*v12;
  if ( (v13 & 1) != 0 )
  {
    v14 = (v13 >> 1) & 0x7F | ((char)v12[1] << 7);
    v15 = 2;
  }
  else
  {
    LOWORD(v14) = v13 >> 1;
    v15 = 1;
  }
  v16 = v15 + v11;
  this->XMax = v14;
  this->Pos = v16;
  v17 = (char)Data->Data[v16];
  if ( (v17 & 1) != 0 )
  {
    v18 = (v17 >> 1) & 0x7F | ((char)Data->Data[v16 + 1] << 7);
    v19 = v16 + 2;
  }
  else
  {
    v18 = v17 >> 1;
    v19 = v16 + 1;
  }
  this->Pos = v19;
  this->YMax = v18;
}
