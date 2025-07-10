void __thiscall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this)
{
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *pContainer; // edi
  const Scaleform::MemoryHeap *pHeap; // eax
  unsigned int v3; // esi
  unsigned __int8 *Data; // eax
  unsigned __int8 *v5; // eax

  pContainer = this->pContainer;
  pHeap = pContainer->Data.pHeap;
  v3 = pContainer->Data.Size + 1;
  if ( v3 >= pContainer->Data.Size )
  {
    if ( v3 >= pContainer->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &pContainer->Data,
        pHeap,
        v3 + (v3 >> 2));
  }
  else if ( v3 < pContainer->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &pContainer->Data,
      pHeap,
      pContainer->Data.Size + 1);
  }
  Data = pContainer->Data.Data;
  pContainer->Data.Size = v3;
  v5 = &Data[v3 - 1];
  if ( v5 )
    *v5 = 15;
}
