void __thiscall Scaleform::StatsUpdate::FileVisitor::UpdateMovieHeap(
        Scaleform::StatsUpdate::FileVisitor *this,
        Scaleform::MemoryHeap *heap,
        Scaleform::StatBag *fileStatBag)
{
  unsigned int i; // esi
  Scaleform::MemoryHeap::HeapVisitor visitor; // [esp+8h] [ebp-21Ch] BYREF
  Scaleform::MemoryHeap **v6; // [esp+Ch] [ebp-218h]
  unsigned int v7; // [esp+10h] [ebp-214h]
  int v8; // [esp+14h] [ebp-210h]
  Scaleform::StatBag other; // [esp+18h] [ebp-20Ch] BYREF

  if ( (heap->Info.Desc.Flags & 0x1000) == 0 )
  {
    Scaleform::StatBag::StatBag(&other, 0, 0x2000u);
    heap->GetStats(heap, &other);
    Scaleform::StatBag::CombineStatBags(
      fileStatBag,
      &other,
      (bool (__thiscall *)(Scaleform::StatBag *, unsigned int, Scaleform::Stat *))Scaleform::StatBag::Add);
    visitor.__vftable = (Scaleform::MemoryHeap::HeapVisitor_vtbl *)&Scaleform::StatsUpdate::HolderVisitor::`vftable';
    v6 = 0;
    v7 = 0;
    v8 = 0;
    Scaleform::MemoryHeap::VisitChildHeaps(heap, &visitor);
    for ( i = 0; i < v7; ++i )
      Scaleform::StatsUpdate::FileVisitor::UpdateMovieHeap(this, v6[i], fileStatBag);
    if ( v6 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
    visitor.__vftable = (Scaleform::MemoryHeap::HeapVisitor_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
    Scaleform::StatBag::~StatBag(&other);
  }
}
