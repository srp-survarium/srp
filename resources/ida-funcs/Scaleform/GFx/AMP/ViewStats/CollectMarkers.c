void __thiscall Scaleform::GFx::AMP::ViewStats::CollectMarkers(
        Scaleform::GFx::AMP::ViewStats *this,
        Scaleform::GFx::AMP::MovieProfile *movieProfile)
{
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *pTable; // eax
  Scaleform::StringHashLH<unsigned long,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v4; // edi
  unsigned int v5; // ebx
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v6; // ecx
  Scaleform::StringLH *v7; // eax
  Scaleform::StringLH *v8; // esi
  Scaleform::GFx::Resource *v9; // ebp
  Scaleform::GFx::Resource_vtbl *SizeMask; // ecx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *v11; // edi
  unsigned int Size; // eax
  unsigned int v13; // esi
  Scaleform::RefCountVImpl **v14; // ebp
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *Data; // ecx
  _DWORD *p_pObject; // esi
  unsigned int v17; // eax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v18; // ecx
  Scaleform::GFx::Resource *v19; // [esp+10h] [ebp-18h]
  int v20; // [esp+14h] [ebp-14h]
  int v21; // [esp+18h] [ebp-10h] BYREF
  Scaleform::Lock *p_ViewLock; // [esp+1Ch] [ebp-Ch]
  Scaleform::StringHashLH<unsigned long,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *p_Markers; // [esp+20h] [ebp-8h]

  p_ViewLock = &this->ViewLock;
  EnterCriticalSection(&this->ViewLock.cs);
  pTable = this->Markers.mHash.pTable;
  if ( pTable )
  {
    v5 = 0;
    v6 = pTable + 1;
    do
    {
      if ( v6->EntryCount != -2 )
        break;
      ++v5;
      v6 += 2;
    }
    while ( v5 <= pTable->SizeMask );
    p_Markers = &this->Markers;
    goto LABEL_7;
  }
  v4 = 0;
  p_Markers = 0;
  v5 = 0;
  while ( v4 && v4->mHash.pTable && (signed int)v5 <= (signed int)v4->mHash.pTable->SizeMask )
  {
    v21 = 578;
    v7 = (Scaleform::StringLH *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                  Scaleform::Memory::pGlobalHeap,
                                  movieProfile,
                                  16,
                                  &v21);
    v8 = v7;
    if ( v7 )
    {
      v7->HeapTypeBits = (unsigned int)&Scaleform::RefCountImplCore::`vftable';
      v7[1].HeapTypeBits = 1;
      v7->HeapTypeBits = (unsigned int)&Scaleform::GFx::AMP::Server::SourceFileInfo::`vftable';
      Scaleform::StringLH::StringLH(v7 + 2);
      v9 = (Scaleform::GFx::Resource *)v8;
      v19 = (Scaleform::GFx::Resource *)v8;
    }
    else
    {
      v19 = 0;
      v9 = 0;
    }
    Scaleform::String::operator=(
      (Scaleform::String *)&v9->pLib,
      (const Scaleform::String *)&v4->mHash.pTable[2 * v5 + 2]);
    SizeMask = (Scaleform::GFx::Resource_vtbl *)v4->mHash.pTable[2 * v5 + 2].SizeMask;
    v11 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&movieProfile->Markers;
    v9[1].__vftable = SizeMask;
    Size = movieProfile->Markers.Data.Size;
    v13 = Size + 1;
    if ( Size + 1 >= Size )
    {
      if ( v13 >= movieProfile->Markers.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v11,
          v11,
          v13 + (v13 >> 2));
    }
    else
    {
      v14 = (Scaleform::RefCountVImpl **)&v11->Data[Size - 1];
      v20 = -1;
      do
      {
        if ( *v14 )
          Scaleform::RefCountImpl::Release(*v14);
        --v14;
        --v20;
      }
      while ( v20 );
      if ( v13 < movieProfile->Markers.Data.Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v11,
          v11,
          v13);
      v9 = v19;
    }
    Data = v11->Data;
    movieProfile->Markers.Data.Size = v13;
    p_pObject = &Data[v13 - 1].pObject;
    if ( p_pObject )
    {
      Scaleform::RefCountImpl::AddRef(v9);
      *p_pObject = v9;
    }
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v9);
    v17 = p_Markers->mHash.pTable->SizeMask;
    if ( (int)v5 <= (int)v17 && ++v5 <= v17 )
    {
      v18 = &p_Markers->mHash.pTable[2 * v5 + 1];
      do
      {
        if ( v18->EntryCount != -2 )
          break;
        ++v5;
        v18 += 2;
      }
      while ( v5 <= v17 );
    }
LABEL_7:
    v4 = p_Markers;
  }
  LeaveCriticalSection(&p_ViewLock->cs);
}
