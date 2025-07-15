void __thiscall Scaleform::StatsUpdate::HolderVisitor::Visit(
        Scaleform::StatsUpdate::HolderVisitor *this,
        Scaleform::MemoryHeap *pParent,
        Scaleform::GFx::AS3::Instances::fl::Object *heap)
{
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *p_Heaps; // edi
  unsigned int v4; // esi
  Scaleform::GFx::AS3::Instances::fl::Object **Data; // edx

  p_Heaps = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&this->Heaps;
  v4 = this->Heaps.Data.Size + 1;
  if ( v4 >= this->Heaps.Data.Size )
  {
    if ( v4 >= this->Heaps.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_Heaps,
        p_Heaps,
        v4 + (v4 >> 2));
  }
  else if ( v4 < this->Heaps.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_Heaps,
      p_Heaps,
      this->Heaps.Data.Size + 1);
  }
  Data = p_Heaps->Data;
  p_Heaps->Size = v4;
  if ( &Data[v4] != (Scaleform::GFx::AS3::Instances::fl::Object **)4 )
    Data[v4 - 1] = heap;
}
