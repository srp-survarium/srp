void __userpurge Scaleform::ArrayDataBase<ID3D11View *,Scaleform::AllocatorLH<ID3D11View *,75>,Scaleform::ArrayConstPolicy<8,8,0>>::Reserve(
        Scaleform::ArrayDataBase<ID3D11Resource *,Scaleform::AllocatorLH<ID3D11Resource *,75>,Scaleform::ArrayConstPolicy<8,8,0> > *this@<edi>,
        unsigned int newCapacity@<eax>,
        int a3@<ecx>,
        const void *pheapAddr)
{
  Scaleform::MemoryHeap_vtbl *v4; // edx
  unsigned int v5; // esi
  ID3D11Resource **v6; // eax
  void *(__thiscall *AllocAutoHeap)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // edx
  int v8; // [esp+0h] [ebp-4h] BYREF

  v8 = a3;
  if ( newCapacity < 8 )
    newCapacity = 8;
  v4 = Scaleform::Memory::pGlobalHeap->__vftable;
  v5 = 8 * ((newCapacity + 7) >> 3);
  if ( this->Data )
  {
    v6 = (ID3D11Resource **)((int (__stdcall *)(ID3D11Resource **, unsigned int))v4->Realloc)(
                              this->Data,
                              32 * ((newCapacity + 7) >> 3));
  }
  else
  {
    AllocAutoHeap = v4->AllocAutoHeap;
    v8 = 75;
    v6 = (ID3D11Resource **)((int (__stdcall *)(const void *, unsigned int, int *))AllocAutoHeap)(
                              pheapAddr,
                              32 * ((newCapacity + 7) >> 3),
                              &v8);
  }
  this->Policy.Capacity = v5;
  this->Data = v6;
}
