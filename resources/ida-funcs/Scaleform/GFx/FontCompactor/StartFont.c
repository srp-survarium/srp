void __thiscall Scaleform::GFx::FontCompactor::StartFont(
        Scaleform::GFx::FontCompactor *this,
        char *name,
        __int16 flags,
        __int16 nominalSize,
        __int16 ascent,
        __int16 descent,
        __int16 leading)
{
  char i; // bl
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *Data; // esi
  unsigned int v10; // ebp
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v11; // ebx
  Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *p_Encoder; // esi
  unsigned int v13; // ebp
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v14; // edx

  for ( i = *name; i; ++name )
  {
    Data = this->Encoder.Data;
    v10 = Data->Size >> 12;
    if ( v10 >= Data->NumPages )
      Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
        Data,
        Data->Size >> 12);
    Data->Pages[v10][Data->Size++ & 0xFFF] = i;
    i = name[1];
  }
  v11 = this->Encoder.Data;
  p_Encoder = &this->Encoder;
  v13 = v11->Size >> 12;
  if ( v13 >= v11->NumPages )
    Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
      v11,
      v11->Size >> 12);
  v11->Pages[v13][v11->Size++ & 0xFFF] = 0;
  this->FontMetricsPos = p_Encoder->Data->Size;
  Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt16fixlen(
    &this->Encoder,
    flags);
  Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt16fixlen(
    &this->Encoder,
    nominalSize);
  Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt16fixlen(
    &this->Encoder,
    ascent);
  Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt16fixlen(
    &this->Encoder,
    descent);
  Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt16fixlen(
    &this->Encoder,
    leading);
  v14 = p_Encoder->Data;
  this->FontNumGlyphs = 0;
  this->FontTotalGlyphBytes = 0;
  this->FontStartGlyphs = v14->Size;
  Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt32fixlen(
    &this->Encoder,
    0);
  Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt32fixlen(
    &this->Encoder,
    0);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeHashF> > *)&this->GlyphCodes);
  this->GlyphInfoTable.Size = 0;
  this->KerningTable.Size = 0;
}
