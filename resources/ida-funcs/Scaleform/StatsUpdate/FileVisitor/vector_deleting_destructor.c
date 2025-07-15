Scaleform::StatsUpdate::FileVisitor *__thiscall Scaleform::StatsUpdate::FileVisitor::`vector deleting destructor'(
        Scaleform::StatsUpdate::FileVisitor *this,
        char a2)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::StatsUpdate::FileStats,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Clear(&this->FileStatsMap.mHash);
  this->__vftable = (Scaleform::StatsUpdate::FileVisitor_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
