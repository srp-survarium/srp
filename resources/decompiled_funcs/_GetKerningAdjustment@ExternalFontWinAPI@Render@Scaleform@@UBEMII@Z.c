double __thiscall Scaleform::Render::ExternalFontWinAPI::GetKerningAdjustment(
        Scaleform::Render::ExternalFontWinAPI *this,
        float lastCode,
        __int16 thisCode)
{
  Scaleform::HashLH<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>,2,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeHashF> > *p_KerningPairs; // esi
  int v4; // eax
  int v5; // eax

  p_KerningPairs = &this->KerningPairs;
  HIWORD(lastCode) = thisCode;
  v4 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>,Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontData::KerningPair,261>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>,Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>::NodeHashF>>::findIndexAlt<Scaleform::GFx::FontData::KerningPair>(
         &this->KerningPairs.mHash,
         (const Scaleform::Render::ExternalFontWinAPI::KerningPairType *)&lastCode);
  if ( v4 < 0 )
    return 0.0;
  v5 = (int)&p_KerningPairs->mHash.pTable[2 * v4 + 2];
  if ( !v5 )
    return 0.0;
  return *(float *)(v5 + 4);
}
