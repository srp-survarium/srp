Scaleform::SwitchFormatter *__thiscall Scaleform::SwitchFormatter::`scalar deleting destructor'(
        Scaleform::SwitchFormatter *this,
        char a2)
{
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeHashF,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeAltHashF,Scaleform::AllocatorGH<int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeHashF,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeAltHashF,Scaleform::AllocatorGH<int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::AllocatorGH<Scaleform::GFx::FontCompactor::ContourKeyType,261>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType> > *)&this->StringSet);
  this->__vftable = (Scaleform::SwitchFormatter_vtbl *)&Scaleform::FmtResource::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
