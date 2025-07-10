int __thiscall Scaleform::GFx::FontData::GetCharValue(Scaleform::GFx::FontData *this, unsigned int glyphIndex)
{
  Scaleform::HashIdentityLH<unsigned short,unsigned short,261,Scaleform::IdentityHash<unsigned short> > *p_CodeTable; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *pTable; // ecx
  unsigned int v4; // eax
  unsigned int SizeMask; // edx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *v6; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *v7; // esi
  unsigned int EntryCount; // ecx
  unsigned int v9; // edx
  _DWORD *v10; // ecx

  p_CodeTable = &this->CodeTable;
  pTable = this->CodeTable.mHash.pTable;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v4 = 0;
    v6 = pTable + 1;
    do
    {
      if ( v6->EntryCount != -2 )
        break;
      ++v4;
      ++v6;
    }
    while ( v4 <= SizeMask );
    pTable = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *)p_CodeTable;
  }
  else
  {
    v4 = 0;
  }
  v7 = pTable;
  while ( v7 )
  {
    EntryCount = v7->EntryCount;
    if ( !v7->EntryCount )
      break;
    v9 = *(_DWORD *)(EntryCount + 4);
    if ( (int)v4 > (int)v9 )
      break;
    if ( *(unsigned __int16 *)(EntryCount + 8 * v4 + 14) == glyphIndex )
      return *(unsigned __int16 *)(EntryCount + 8 * v4 + 12);
    if ( ++v4 <= v9 )
    {
      v10 = (_DWORD *)(EntryCount + 8 * v4 + 8);
      do
      {
        if ( *v10 != -2 )
          break;
        ++v4;
        v10 += 2;
      }
      while ( v4 <= v9 );
    }
  }
  return -1;
}
