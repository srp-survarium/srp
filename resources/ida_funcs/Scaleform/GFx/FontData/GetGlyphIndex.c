int __thiscall Scaleform::GFx::FontData::GetGlyphIndex(Scaleform::GFx::FontData *this, unsigned __int16 code)
{
  Scaleform::HashIdentityLH<unsigned short,unsigned short,261,Scaleform::IdentityHash<unsigned short> > *p_CodeTable; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> > v3; // esi
  signed int Index; // eax
  int p_SizeMask; // eax

  p_CodeTable = &this->CodeTable;
  v3.pTable = p_CodeTable->mHash.pTable;
  if ( p_CodeTable->mHash.pTable
    && (Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeHashF>>::findIndexCore<unsigned short>(
                  &p_CodeTable->mHash,
                  &code,
                  code & v3.pTable->SizeMask),
        Index >= 0)
    && (p_SizeMask = (int)&v3.pTable[Index + 1].SizeMask) != 0 )
  {
    return *(unsigned __int16 *)(p_SizeMask + 2);
  }
  else
  {
    return -1;
  }
}
