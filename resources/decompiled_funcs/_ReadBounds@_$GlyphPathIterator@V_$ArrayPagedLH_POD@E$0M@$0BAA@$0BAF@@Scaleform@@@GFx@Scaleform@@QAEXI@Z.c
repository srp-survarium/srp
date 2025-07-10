void __thiscall Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadBounds(
        Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *this,
        int pos)
{
  int v2; // edi
  unsigned int v4; // edi
  unsigned int v5; // edi
  __int16 v6; // ax
  unsigned int v7; // eax
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
         &pos)
     + v2;
  this->XMin = pos;
  this->Pos = v4;
  v5 = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadSInt15(
         &this->Data,
         v4,
         &pos)
     + v4;
  v6 = pos;
  this->Pos = v5;
  this->YMin = v6;
  v7 = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadSInt15(
         &this->Data,
         v5,
         &pos);
  v8 = pos;
  v9 = v7 + v5;
  this->Pos = v9;
  this->XMax = v8;
  v10 = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadSInt15(
          &this->Data,
          v9,
          &pos);
  v11 = pos;
  this->Pos = v9 + v10;
  this->YMax = v11;
}
