void __thiscall Scaleform::GFx::FontData::ReadCodeTable(Scaleform::GFx::FontData *this, Scaleform::GFx::Stream *in)
{
  Scaleform::GFx::Stream *v2; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *pTable; // ecx
  Scaleform::HashIdentityLH<unsigned short,unsigned short,261,Scaleform::IdentityHash<unsigned short> > *p_CodeTable; // edi
  unsigned int Flags; // ecx
  unsigned int Size; // ebx
  unsigned int v8; // ebp
  int v9; // edx
  unsigned int Pos; // eax
  unsigned __int16 v11; // cx
  int v12; // edx
  unsigned int v13; // eax
  unsigned __int16 v14; // dx
  int v15; // [esp+10h] [ebp-Ch] BYREF
  Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeRef key; // [esp+14h] [ebp-8h] BYREF

  v2 = in;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
    in,
    "reading code table at offset %d\n",
    in->Pos + in->FilePos - in->DataSize);
  pTable = this->CodeTable.mHash.pTable;
  p_CodeTable = &this->CodeTable;
  if ( pTable )
    pTable = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *)pTable->EntryCount;
  if ( (5 * this->Glyphs.Data.Size) >> 2 > (unsigned int)pTable )
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeHashF>>::setRawCapacity(
      &this->CodeTable.mHash,
      &this->CodeTable,
      (Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >)((5 * this->Glyphs.Data.Size) >> 2));
  Flags = this->Flags;
  Size = this->Glyphs.Data.Size;
  v8 = 0;
  if ( (Flags & 0x4000) != 0 )
  {
    if ( Size )
    {
      key.pFirst = (const unsigned __int16 *)&v15;
      key.pSecond = (const unsigned __int16 *)&in;
      do
      {
        v9 = v2->DataSize - v2->Pos;
        in = (Scaleform::GFx::Stream *)(unsigned __int16)v8;
        v2->UnusedBits = 0;
        if ( v9 < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(v2, 2);
        Pos = v2->Pos;
        v11 = *(_WORD *)&v2->pBuffer[Pos];
        v2->Pos = Pos + 2;
        v15 = v11;
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeHashF>>::add<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeRef>(
          &p_CodeTable->mHash,
          p_CodeTable,
          &key,
          v11);
        ++v8;
      }
      while ( v8 < Size );
    }
  }
  else if ( Size )
  {
    key.pFirst = (const unsigned __int16 *)&v15;
    key.pSecond = (const unsigned __int16 *)&in;
    do
    {
      v12 = v2->DataSize - v2->Pos;
      in = (Scaleform::GFx::Stream *)(unsigned __int16)v8;
      v2->UnusedBits = 0;
      if ( v12 < 1 )
        Scaleform::GFx::Stream::PopulateBuffer1(v2);
      v13 = v2->Pos;
      v14 = v2->pBuffer[v13];
      v2->Pos = v13 + 1;
      v15 = v14;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeHashF>>::add<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeRef>(
        &p_CodeTable->mHash,
        p_CodeTable,
        &key,
        v14);
      ++v8;
    }
    while ( v8 < Size );
  }
}
