void __thiscall Scaleform::GFx::AMP::ViewStats::RecordSourceLineTime(
        Scaleform::GFx::AMP::ViewStats *this,
        unsigned __int64 lineTime)
{
  Scaleform::Lock *p_ActiveLock; // edi
  unsigned int ActiveLineNumber; // ebx
  unsigned int ActiveFileId; // ebx
  unsigned int ActiveFileId_high; // ebp
  Scaleform::HashLH<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair>,2,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeHashF> > *p_SourceLineTimingsMap; // esi
  signed int v8; // eax
  const Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> > *v9; // edi
  int v10; // ebx
  signed int v11; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::ConstIterator v12; // [esp+10h] [ebp-20h] BYREF
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::ConstIterator it; // [esp+18h] [ebp-18h] BYREF
  Scaleform::GFx::AMP::ViewStats::FileLinePair key; // [esp+20h] [ebp-10h] BYREF

  p_ActiveLock = &this->ActiveLock;
  EnterCriticalSection(&this->ActiveLock.cs);
  ActiveLineNumber = this->ActiveLineNumber;
  LeaveCriticalSection(&p_ActiveLock->cs);
  key.LineNumber = ActiveLineNumber;
  if ( ActiveLineNumber )
  {
    EnterCriticalSection(&p_ActiveLock->cs);
    ActiveFileId = this->ActiveFileId;
    ActiveFileId_high = HIDWORD(this->ActiveFileId);
    LeaveCriticalSection(&p_ActiveLock->cs);
    p_SourceLineTimingsMap = &this->SourceLineTimingsMap;
    key.FileId = __PAIR64__(ActiveFileId_high, ActiveFileId);
    v8 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::FileLinePair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair>>::NodeHashF>>::findIndexAlt<Scaleform::GFx::AMP::ViewStats::FileLinePair>(
           &p_SourceLineTimingsMap->mHash,
           &key);
    if ( v8 < 0 )
    {
      v9 = 0;
      v10 = 0;
    }
    else
    {
      v9 = (const Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> > *)p_SourceLineTimingsMap;
      v10 = v8;
    }
    v12.Index = v10;
    v12.pHash = v9;
    it.pHash = 0;
    it.Index = 0;
    if ( Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF>>::ConstIterator::operator==(
           &v12,
           &it) )
    {
      it.pHash = 0;
      it.Index = 0;
      v12.pHash = (const Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> > *)&key;
      v12.Index = (int)&it;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::FileLinePair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair>>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair>>::NodeRef>(
        &p_SourceLineTimingsMap->mHash,
        p_SourceLineTimingsMap,
        (const Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeRef *)&v12);
      v11 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::FileLinePair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair>>::NodeHashF>>::findIndexAlt<Scaleform::GFx::AMP::ViewStats::FileLinePair>(
              &p_SourceLineTimingsMap->mHash,
              &key);
      if ( v11 < 0 )
      {
        p_SourceLineTimingsMap = 0;
        v10 = 0;
      }
      else
      {
        v10 = v11;
      }
      v9 = (const Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> > *)p_SourceLineTimingsMap;
    }
    *(_QWORD *)&v9->pTable[4 * v10 + 4] += lineTime;
  }
}
