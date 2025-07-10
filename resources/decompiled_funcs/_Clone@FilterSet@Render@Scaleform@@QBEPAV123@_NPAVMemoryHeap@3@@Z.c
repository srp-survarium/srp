Scaleform::Render::FilterSet *__thiscall Scaleform::Render::FilterSet::Clone(
        Scaleform::Render::FilterSet *this,
        bool deepCopy,
        Scaleform::MemoryHeap *heap)
{
  int v3; // ebx
  Scaleform::MemoryHeap *v5; // edi
  Scaleform::Render::FilterSet *v6; // eax
  Scaleform::Render::FilterSet *v7; // esi
  Scaleform::Ptr<Scaleform::Render::Filter> *Data; // ecx
  Scaleform::GFx::Resource *v10; // edi

  v3 = 0;
  if ( !heap )
    heap = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  v5 = heap;
  v6 = (Scaleform::Render::FilterSet *)heap->Alloc(heap, 24, 0);
  v7 = v6;
  if ( !v6 )
    return 0;
  v6->__vftable = (Scaleform::Render::FilterSet_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  v6->RefCount = 1;
  v6->__vftable = (Scaleform::Render::FilterSet_vtbl *)&Scaleform::Render::FilterSet::`vftable';
  v6->Filters.Data.Data = 0;
  v6->Filters.Data.Size = 0;
  v6->Filters.Data.Policy.Capacity = 0;
  v6->Frozen = 0;
  v6->CacheAsBitmap = 0;
  v6->CacheAsBitmap = this->CacheAsBitmap;
  if ( this->Filters.Data.Size )
  {
    while ( 1 )
    {
      Data = this->Filters.Data.Data;
      if ( deepCopy )
      {
        v10 = (Scaleform::GFx::Resource *)Data[v3].pObject->Clone(Data[v3].pObject, v5);
        Scaleform::Render::FilterSet::AddFilter(v7, v10);
        if ( v10 )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v10);
      }
      else
      {
        Scaleform::Render::FilterSet::AddFilter(v7, (Scaleform::GFx::Resource *)Data[v3].pObject);
      }
      if ( ++v3 >= this->Filters.Data.Size )
        break;
      v5 = heap;
    }
  }
  return v7;
}
