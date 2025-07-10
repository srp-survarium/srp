void __userpurge Scaleform::ArrayDataBase<Scaleform::Render::D3D1x::MeshBuffer *,Scaleform::AllocatorLH<Scaleform::Render::D3D1x::MeshBuffer *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::D3D1x::MeshBuffer *,Scaleform::AllocatorLH<Scaleform::Render::D3D1x::MeshBuffer *,2>,Scaleform::ArrayDefaultPolicy> *this@<edi>,
        unsigned int newCapacity@<eax>,
        int a3@<ecx>,
        const void *pheapAddr)
{
  Scaleform::MemoryHeap_vtbl *v4; // edx
  unsigned int v5; // esi
  Scaleform::Render::D3D1x::MeshBuffer **v6; // eax
  void *(__thiscall *AllocAutoHeap)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // edx
  int v8; // [esp+0h] [ebp-4h] BYREF

  v8 = a3;
  if ( newCapacity )
  {
    v4 = Scaleform::Memory::pGlobalHeap->__vftable;
    v5 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v6 = (Scaleform::Render::D3D1x::MeshBuffer **)((int (__stdcall *)(Scaleform::Render::D3D1x::MeshBuffer **, unsigned int))v4->Realloc)(
                                                      this->Data,
                                                      16 * ((newCapacity + 3) >> 2));
    }
    else
    {
      AllocAutoHeap = v4->AllocAutoHeap;
      v8 = 2;
      v6 = (Scaleform::Render::D3D1x::MeshBuffer **)((int (__stdcall *)(const void *, unsigned int, int *))AllocAutoHeap)(
                                                      pheapAddr,
                                                      16 * ((newCapacity + 3) >> 2),
                                                      &v8);
    }
    this->Policy.Capacity = v5;
    this->Data = v6;
  }
  else
  {
    if ( this->Data )
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
      this->Data = 0;
    }
    this->Policy.Capacity = 0;
  }
}
