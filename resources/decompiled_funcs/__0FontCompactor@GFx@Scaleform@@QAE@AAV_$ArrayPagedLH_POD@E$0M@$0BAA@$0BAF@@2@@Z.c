void __thiscall Scaleform::GFx::FontCompactor::FontCompactor(
        Scaleform::GFx::FontCompactor *this,
        Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *data)
{
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::FontCompactor_vtbl *)&Scaleform::GFx::FontCompactor::`vftable';
  this->Encoder.Data = data;
  this->Decoder.Data = data;
  this->ContourHash.pTable = 0;
  this->GlyphHash.pTable = 0;
  this->TmpVertices.Size = 0;
  this->TmpVertices.NumPages = 0;
  this->TmpVertices.MaxPages = 0;
  this->TmpVertices.Pages = 0;
  this->TmpContours.Size = 0;
  this->TmpContours.NumPages = 0;
  this->TmpContours.MaxPages = 0;
  this->TmpContours.Pages = 0;
  this->TmpContour.Size = 0;
  this->TmpContour.NumPages = 0;
  this->TmpContour.MaxPages = 0;
  this->TmpContour.Pages = 0;
  this->GlyphCodes.pTable = 0;
  this->GlyphInfoTable.Size = 0;
  this->GlyphInfoTable.NumPages = 0;
  this->GlyphInfoTable.MaxPages = 0;
  this->GlyphInfoTable.Pages = 0;
  this->KerningTable.Size = 0;
  this->KerningTable.NumPages = 0;
  this->KerningTable.MaxPages = 0;
  this->KerningTable.Pages = 0;
}
