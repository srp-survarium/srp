void __thiscall Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  unsigned __int8 *v5; // eax
  int (__thiscall *v6)(const void *, unsigned int, unsigned int *); // edx

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->Realloc(Scaleform::Memory::pGlobalHeap, this->Data, v4);
    }
    else
    {
      v6 = *(int (__thiscall **)(const void *, unsigned int, unsigned int *))(*(_DWORD *)pheapAddr + 40);
      newCapacity = 2;
      v5 = (unsigned __int8 *)v6(pheapAddr, v4, &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  char *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (char *)Scaleform::Memory::pGlobalHeap->Realloc(Scaleform::Memory::pGlobalHeap, this->Data, v4);
    }
    else
    {
      newCapacity = 2;
      v5 = (char *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, v4, &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,327>,Scaleform::ArrayConstPolicy<0,4,1>>::Reserve(
        Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,327>,Scaleform::ArrayConstPolicy<0,4,1> > *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  unsigned __int8 *v5; // eax

  if ( newCapacity >= this->Policy.Capacity )
  {
    if ( newCapacity )
    {
      v4 = 4 * ((newCapacity + 3) >> 2);
      if ( this->Data )
      {
        v5 = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->Realloc(Scaleform::Memory::pGlobalHeap, this->Data, v4);
      }
      else
      {
        newCapacity = 327;
        v5 = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                  Scaleform::Memory::pGlobalHeap,
                                  pheapAddr,
                                  v4,
                                  &newCapacity);
      }
      this->Policy.Capacity = v4;
      this->Data = v5;
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
}


void __thiscall Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,328>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  unsigned __int8 *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->Realloc(Scaleform::Memory::pGlobalHeap, this->Data, v4);
    }
    else
    {
      newCapacity = 328;
      v5 = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                Scaleform::Memory::pGlobalHeap,
                                pheapAddr,
                                v4,
                                &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<unsigned int,Scaleform::AllocatorLH<unsigned int,75>,Scaleform::ArrayConstPolicy<4,4,0>>::Reserve(
        Scaleform::ArrayDataBase<unsigned int,Scaleform::AllocatorLH<unsigned int,75>,Scaleform::ArrayConstPolicy<4,4,0> > *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v3; // eax
  unsigned int v5; // esi
  unsigned int *v6; // eax

  v3 = newCapacity;
  if ( newCapacity < 4 )
    v3 = 4;
  v5 = 4 * ((v3 + 3) >> 2);
  if ( this->Data )
  {
    v6 = (unsigned int *)Scaleform::Memory::pGlobalHeap->Realloc(
                           Scaleform::Memory::pGlobalHeap,
                           this->Data,
                           16 * ((v3 + 3) >> 2));
  }
  else
  {
    newCapacity = 75;
    v6 = (unsigned int *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                           Scaleform::Memory::pGlobalHeap,
                           pheapAddr,
                           16 * ((v3 + 3) >> 2),
                           &newCapacity);
  }
  this->Policy.Capacity = v5;
  this->Data = v6;
}


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


void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::TextureFormat *,Scaleform::AllocatorLH<Scaleform::Render::TextureFormat *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::TextureFormat *,Scaleform::AllocatorLH<Scaleform::Render::TextureFormat *,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  Scaleform::MemoryHeap_vtbl *v4; // edx
  unsigned int v5; // esi
  Scaleform::Render::TextureFormat **v6; // eax
  void *(__thiscall *AllocAutoHeap)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // edx

  if ( newCapacity )
  {
    v4 = Scaleform::Memory::pGlobalHeap->__vftable;
    v5 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v6 = (Scaleform::Render::TextureFormat **)((int (__stdcall *)(Scaleform::Render::TextureFormat **, unsigned int))v4->Realloc)(
                                                  this->Data,
                                                  16 * ((newCapacity + 3) >> 2));
    }
    else
    {
      AllocAutoHeap = v4->AllocAutoHeap;
      newCapacity = 2;
      v6 = (Scaleform::Render::TextureFormat **)((int (__stdcall *)(const void *, unsigned int, unsigned int *))AllocAutoHeap)(
                                                  pheapAddr,
                                                  4 * v5,
                                                  &newCapacity);
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0> > *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v3; // eax
  unsigned int v5; // esi
  Scaleform::GFx::ExecuteTag **v6; // eax

  v3 = newCapacity;
  if ( newCapacity < 0x20 )
    v3 = 32;
  v5 = 16 * ((v3 + 15) >> 4);
  if ( this->Data )
  {
    v6 = (Scaleform::GFx::ExecuteTag **)Scaleform::Memory::pGlobalHeap->Realloc(
                                          Scaleform::Memory::pGlobalHeap,
                                          this->Data,
                                          (v3 + 15) >> 4 << 6);
  }
  else
  {
    newCapacity = 2;
    v6 = (Scaleform::GFx::ExecuteTag **)Scaleform::Memory::pGlobalHeap->Alloc(
                                          Scaleform::Memory::pGlobalHeap,
                                          (v3 + 15) >> 4 << 6,
                                          &newCapacity);
  }
  this->Policy.Capacity = v5;
  this->Data = v6;
}


void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                                                    Scaleform::Memory::pGlobalHeap,
                                                                                    this->Data,
                                                                                    16 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 2;
      v5 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                                    Scaleform::Memory::pGlobalHeap,
                                                                                    pheapAddr,
                                                                                    4 * v4,
                                                                                    &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::AS3::TR::State **v5; // eax
  int (__thiscall *v6)(const void *, unsigned int, unsigned int *); // edx

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::AS3::TR::State **)Scaleform::Memory::pGlobalHeap->Realloc(
                                                Scaleform::Memory::pGlobalHeap,
                                                this->Data,
                                                16 * ((newCapacity + 3) >> 2));
    }
    else
    {
      v6 = *(int (__thiscall **)(const void *, unsigned int, unsigned int *))(*(_DWORD *)pheapAddr + 40);
      newCapacity = 328;
      v5 = (Scaleform::GFx::AS3::TR::State **)v6(pheapAddr, 4 * v4, &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::SwfEvent *,Scaleform::AllocatorLH<Scaleform::GFx::SwfEvent *,260>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::SwfEvent *,Scaleform::AllocatorLH<Scaleform::GFx::SwfEvent *,260>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::SwfEvent **v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::SwfEvent **)Scaleform::Memory::pGlobalHeap->Realloc(
                                          Scaleform::Memory::pGlobalHeap,
                                          this->Data,
                                          16 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 260;
      v5 = (Scaleform::GFx::SwfEvent **)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                          Scaleform::Memory::pGlobalHeap,
                                          pheapAddr,
                                          4 * v4,
                                          &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  int *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (int *)Scaleform::Memory::pGlobalHeap->Realloc(
                    Scaleform::Memory::pGlobalHeap,
                    this->Data,
                    16 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 338;
      v5 = (int *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                    Scaleform::Memory::pGlobalHeap,
                    pheapAddr,
                    4 * v4,
                    &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::AS3::VMAbcFile *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::VMAbcFile *,329>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::VMAbcFile *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::VMAbcFile *,329>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::AS3::VMAbcFile **v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::AS3::VMAbcFile **)Scaleform::Memory::pGlobalHeap->Realloc(
                                                Scaleform::Memory::pGlobalHeap,
                                                this->Data,
                                                16 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 329;
      v5 = (Scaleform::GFx::AS3::VMAbcFile **)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                pheapAddr,
                                                4 * v4,
                                                &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::UserDataState::Data const *,Scaleform::AllocatorLH<Scaleform::Render::UserDataState::Data const *,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::UserDataState::Data const *,Scaleform::AllocatorLH<Scaleform::Render::UserDataState::Data const *,2>,Scaleform::ArrayConstPolicy<0,8,1> > *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  const Scaleform::Render::UserDataState::Data **v5; // eax

  if ( newCapacity >= this->Policy.Capacity )
  {
    if ( newCapacity )
    {
      v4 = 8 * ((newCapacity + 7) >> 3);
      if ( this->Data )
      {
        v5 = (const Scaleform::Render::UserDataState::Data **)Scaleform::Memory::pGlobalHeap->Realloc(
                                                                Scaleform::Memory::pGlobalHeap,
                                                                this->Data,
                                                                32 * ((newCapacity + 7) >> 3));
      }
      else
      {
        newCapacity = 2;
        v5 = (const Scaleform::Render::UserDataState::Data **)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                Scaleform::Memory::pGlobalHeap,
                                                                pheapAddr,
                                                                4 * v4,
                                                                &newCapacity);
      }
      this->Policy.Capacity = v4;
      this->Data = v5;
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
}


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::FontData::AdvanceEntry,Scaleform::AllocatorLH<Scaleform::GFx::FontData::AdvanceEntry,261>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::FontData::AdvanceEntry,Scaleform::AllocatorLH<Scaleform::GFx::FontData::AdvanceEntry,261>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::FontData::AdvanceEntry *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::FontData::AdvanceEntry *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       this->Data,
                                                       48 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 261;
      v5 = (Scaleform::GFx::FontData::AdvanceEntry *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       pheapAddr,
                                                       12 * v4,
                                                       &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::AS2::AsFunctionObject::ArgSpec *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::AS2::AsFunctionObject::ArgSpec *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                               Scaleform::Memory::pGlobalHeap,
                                                               this->Data,
                                                               32 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 323;
      v5 = (Scaleform::GFx::AS2::AsFunctionObject::ArgSpec *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                               Scaleform::Memory::pGlobalHeap,
                                                               pheapAddr,
                                                               8 * v4,
                                                               &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::Button::CharToRec *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::Button::CharToRec *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  this->Data,
                                                  32 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 2;
      v5 = (Scaleform::GFx::Button::CharToRec *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  pheapAddr,
                                                  8 * v4,
                                                  &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::AS3::Value *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::AS3::Value *)Scaleform::Memory::pGlobalHeap->Realloc(
                                           Scaleform::Memory::pGlobalHeap,
                                           this->Data,
                                           (newCapacity + 3) >> 2 << 6);
    }
    else
    {
      newCapacity = 2;
      v5 = (Scaleform::GFx::AS3::Value *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                           Scaleform::Memory::pGlobalHeap,
                                           pheapAddr,
                                           16 * v4,
                                           &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Render::FillStyleType *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::Render::FillStyleType *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 this->Data,
                                                 32 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 259;
      v5 = (Scaleform::Render::FillStyleType *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 8 * v4,
                                                 &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1> > *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  Scaleform::MemoryHeap_vtbl *v4; // edx
  unsigned int v5; // esi
  Scaleform::Render::HAL::FilterStackEntry *v6; // eax
  void *(__thiscall *AllocAutoHeap)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // edx

  if ( newCapacity >= this->Policy.Capacity )
  {
    if ( newCapacity )
    {
      v4 = Scaleform::Memory::pGlobalHeap->__vftable;
      v5 = 8 * ((newCapacity + 7) >> 3);
      if ( this->Data )
      {
        v6 = (Scaleform::Render::HAL::FilterStackEntry *)((int (__stdcall *)(Scaleform::Render::HAL::FilterStackEntry *, unsigned int))v4->Realloc)(
                                                           this->Data,
                                                           (newCapacity + 7) >> 3 << 6);
      }
      else
      {
        AllocAutoHeap = v4->AllocAutoHeap;
        newCapacity = 2;
        v6 = (Scaleform::Render::HAL::FilterStackEntry *)((int (__stdcall *)(const void *, unsigned int, unsigned int *))AllocAutoHeap)(
                                                           pheapAddr,
                                                           8 * v5,
                                                           &newCapacity);
      }
      this->Policy.Capacity = v5;
      this->Data = v6;
    }
    else
    {
      if ( this->Data )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)this->Data);
        this->Data = 0;
      }
      this->Policy.Capacity = 0;
    }
  }
}


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,265>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,265>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::TimelineDef::Frame *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::TimelineDef::Frame *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   this->Data,
                                                   32 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 265;
      v5 = (Scaleform::GFx::TimelineDef::Frame *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   pheapAddr,
                                                   8 * v4,
                                                   &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
  }
  else
  {
    if ( this->Data )
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)this->Data);
      this->Data = 0;
    }
    this->Policy.Capacity = 0;
  }
}


void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::Text::HighlightDesc,Scaleform::AllocatorGH<Scaleform::Render::Text::HighlightDesc,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::Text::HighlightDesc,Scaleform::AllocatorGH<Scaleform::Render::Text::HighlightDesc,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Render::Text::HighlightDesc *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::Render::Text::HighlightDesc *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       this->Data,
                                                       160 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 2;
      v5 = (Scaleform::Render::Text::HighlightDesc *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       40 * v4,
                                                       &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::Text::HighlightDesc,Scaleform::AllocatorLH<Scaleform::Render::Text::HighlightDesc,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::Text::HighlightDesc,Scaleform::AllocatorLH<Scaleform::Render::Text::HighlightDesc,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Render::Text::HighlightDesc *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::Render::Text::HighlightDesc *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       this->Data,
                                                       160 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 2;
      v5 = (Scaleform::Render::Text::HighlightDesc *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       pheapAddr,
                                                       40 * v4,
                                                       &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::AS3::Value *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::AS3::Value *)Scaleform::Memory::pGlobalHeap->Realloc(
                                           Scaleform::Memory::pGlobalHeap,
                                           this->Data,
                                           (newCapacity + 3) >> 2 << 6);
    }
    else
    {
      newCapacity = 2;
      v5 = (Scaleform::GFx::AS3::Value *)Scaleform::Memory::pGlobalHeap->Alloc(
                                           Scaleform::Memory::pGlobalHeap,
                                           16 * v4,
                                           &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::MovieImpl::LevelInfo *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     this->Data,
                                                     32 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 327;
      v5 = (Scaleform::GFx::MovieImpl::LevelInfo *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     pheapAddr,
                                                     8 * v4,
                                                     &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::HAL::MaskStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::MaskStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::HAL::MaskStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::MaskStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1> > *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  Scaleform::MemoryHeap_vtbl *v4; // edx
  unsigned int v5; // esi
  Scaleform::Render::HAL::MaskStackEntry *v6; // eax
  void *(__thiscall *AllocAutoHeap)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // edx

  if ( newCapacity >= this->Policy.Capacity )
  {
    if ( newCapacity )
    {
      v4 = Scaleform::Memory::pGlobalHeap->__vftable;
      v5 = 8 * ((newCapacity + 7) >> 3);
      if ( this->Data )
      {
        v6 = (Scaleform::Render::HAL::MaskStackEntry *)((int (__stdcall *)(Scaleform::Render::HAL::MaskStackEntry *, unsigned int))v4->Realloc)(
                                                         this->Data,
                                                         192 * ((newCapacity + 7) >> 3));
      }
      else
      {
        AllocAutoHeap = v4->AllocAutoHeap;
        newCapacity = 2;
        v6 = (Scaleform::Render::HAL::MaskStackEntry *)((int (__stdcall *)(const void *, unsigned int, unsigned int *))AllocAutoHeap)(
                                                         pheapAddr,
                                                         24 * v5,
                                                         &newCapacity);
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
}


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::MDKillListEntry,Scaleform::AllocatorGH<Scaleform::GFx::MovieImpl::MDKillListEntry,327>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::MDKillListEntry,Scaleform::AllocatorGH<Scaleform::GFx::MovieImpl::MDKillListEntry,327>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::MovieImpl::MDKillListEntry *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::MovieImpl::MDKillListEntry *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           this->Data,
                                                           (newCapacity + 3) >> 2 << 6);
    }
    else
    {
      newCapacity = 327;
      v5 = (Scaleform::GFx::MovieImpl::MDKillListEntry *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           16 * v4,
                                                           &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Slots::Pair,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Slots::Pair,332>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Slots::Pair,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Slots::Pair,332>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::AS3::Slots::Pair *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::AS3::Slots::Pair *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 this->Data,
                                                 112 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 332;
      v5 = (Scaleform::GFx::AS3::Slots::Pair *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 pheapAddr,
                                                 28 * v4,
                                                 &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  tagKERNINGPAIR *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (tagKERNINGPAIR *)Scaleform::Memory::pGlobalHeap->Realloc(
                               Scaleform::Memory::pGlobalHeap,
                               this->Data,
                               32 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 2;
      v5 = (tagKERNINGPAIR *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 8 * v4, &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Tracer::Recalculate,Scaleform::AllocatorDH_POD<Scaleform::GFx::AS3::Tracer::Recalculate,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Tracer::Recalculate,Scaleform::AllocatorDH_POD<Scaleform::GFx::AS3::Tracer::Recalculate,328>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::AS3::Tracer::Recalculate *v5; // eax
  int (__thiscall *v6)(const void *, unsigned int, unsigned int *); // edx

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::AS3::Tracer::Recalculate *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                         Scaleform::Memory::pGlobalHeap,
                                                         this->Data,
                                                         32 * ((newCapacity + 3) >> 2));
    }
    else
    {
      v6 = *(int (__thiscall **)(const void *, unsigned int, unsigned int *))(*(_DWORD *)pheapAddr + 40);
      newCapacity = 328;
      v5 = (Scaleform::GFx::AS3::Tracer::Recalculate *)v6(pheapAddr, 8 * v4, &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1> > *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  Scaleform::MemoryHeap_vtbl *v4; // edx
  unsigned int v5; // esi
  Scaleform::Render::HAL::RenderTargetEntry *v6; // eax
  void *(__thiscall *AllocAutoHeap)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // edx

  if ( newCapacity >= this->Policy.Capacity )
  {
    if ( newCapacity )
    {
      v4 = Scaleform::Memory::pGlobalHeap->__vftable;
      v5 = 8 * ((newCapacity + 7) >> 3);
      if ( this->Data )
      {
        v6 = (Scaleform::Render::HAL::RenderTargetEntry *)((int (__stdcall *)(Scaleform::Render::HAL::RenderTargetEntry *, unsigned int))v4->Realloc)(
                                                            this->Data,
                                                            6016 * ((newCapacity + 7) >> 3));
      }
      else
      {
        AllocAutoHeap = v4->AllocAutoHeap;
        newCapacity = 2;
        v6 = (Scaleform::Render::HAL::RenderTargetEntry *)((int (__stdcall *)(const void *, unsigned int, unsigned int *))AllocAutoHeap)(
                                                            pheapAddr,
                                                            752 * v5,
                                                            &newCapacity);
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
}


void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorGH<Scaleform::Render::StrokeStyleType,259>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorGH<Scaleform::Render::StrokeStyleType,259>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Render::StrokeStyleType *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::Render::StrokeStyleType *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   this->Data,
                                                   112 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 259;
      v5 = (Scaleform::Render::StrokeStyleType *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   28 * v4,
                                                   &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorLH<Scaleform::Render::StrokeStyleType,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorLH<Scaleform::Render::StrokeStyleType,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Render::StrokeStyleType *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::Render::StrokeStyleType *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   this->Data,
                                                   112 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 2;
      v5 = (Scaleform::Render::StrokeStyleType *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   pheapAddr,
                                                   28 * v4,
                                                   &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::TextMeshEntry,Scaleform::AllocatorDH<Scaleform::Render::TextMeshEntry,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::TextMeshEntry,Scaleform::AllocatorDH<Scaleform::Render::TextMeshEntry,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Render::TextMeshEntry *v5; // eax
  int (__thiscall *v6)(const void *, unsigned int, unsigned int *); // edx

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::Render::TextMeshEntry *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 this->Data,
                                                 (newCapacity + 3) >> 2 << 7);
    }
    else
    {
      v6 = *(int (__thiscall **)(const void *, unsigned int, unsigned int *))(*(_DWORD *)pheapAddr + 40);
      newCapacity = 2;
      v5 = (Scaleform::Render::TextMeshEntry *)v6(pheapAddr, 32 * v4, &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::TextMeshLayer,Scaleform::AllocatorDH<Scaleform::Render::TextMeshLayer,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::TextMeshLayer,Scaleform::AllocatorDH<Scaleform::Render::TextMeshLayer,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Render::TextMeshLayer *v5; // eax
  int (__thiscall *v6)(const void *, unsigned int, unsigned int *); // edx

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::Render::TextMeshLayer *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 this->Data,
                                                 144 * ((newCapacity + 3) >> 2));
    }
    else
    {
      v6 = *(int (__thiscall **)(const void *, unsigned int, unsigned int *))(*(_DWORD *)pheapAddr + 40);
      newCapacity = 2;
      v5 = (Scaleform::Render::TextMeshLayer *)v6(pheapAddr, 36 * v4, &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorGH<Scaleform::Render::TextureGlyph,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorGH<Scaleform::Render::TextureGlyph,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Render::TextureGlyph *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::Render::TextureGlyph *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                Scaleform::Memory::pGlobalHeap,
                                                this->Data,
                                                192 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 2;
      v5 = (Scaleform::Render::TextureGlyph *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                Scaleform::Memory::pGlobalHeap,
                                                48 * v4,
                                                &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
  }
  else
  {
    if ( this->Data )
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)this->Data);
      this->Data = 0;
    }
    this->Policy.Capacity = 0;
  }
}


void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorLH<Scaleform::Render::TextureGlyph,261>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorLH<Scaleform::Render::TextureGlyph,261>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Render::TextureGlyph *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::Render::TextureGlyph *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                Scaleform::Memory::pGlobalHeap,
                                                this->Data,
                                                192 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 261;
      v5 = (Scaleform::Render::TextureGlyph *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                pheapAddr,
                                                48 * v4,
                                                &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
  }
  else
  {
    if ( this->Data )
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)this->Data);
      this->Data = 0;
    }
    this->Policy.Capacity = 0;
  }
}


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::Text::CSSToken<wchar_t>,Scaleform::AllocatorGH<Scaleform::GFx::Text::CSSToken<wchar_t>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::Text::CSSToken<wchar_t>,Scaleform::AllocatorGH<Scaleform::GFx::Text::CSSToken<wchar_t>,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::Text::CSSToken<wchar_t> *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::Text::CSSToken<wchar_t> *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        this->Data,
                                                        48 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 2;
      v5 = (Scaleform::GFx::Text::CSSToken<wchar_t> *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        12 * v4,
                                                        &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Pair<double,unsigned long> *v5; // eax
  int (__thiscall *v6)(const void *, unsigned int, unsigned int *); // edx

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::Pair<double,unsigned long> *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      this->Data,
                                                      (newCapacity + 3) >> 2 << 6);
    }
    else
    {
      v6 = *(int (__thiscall **)(const void *, unsigned int, unsigned int *))(*(_DWORD *)pheapAddr + 40);
      newCapacity = 2;
      v5 = (Scaleform::Pair<double,unsigned long> *)v6(pheapAddr, 16 * v4, &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *v5; // eax
  int (__thiscall *v6)(const void *, unsigned int, unsigned int *); // edx

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                                        Scaleform::Memory::pGlobalHeap,
                                                                        this->Data,
                                                                        32 * ((newCapacity + 3) >> 2));
    }
    else
    {
      v6 = *(int (__thiscall **)(const void *, unsigned int, unsigned int *))(*(_DWORD *)pheapAddr + 40);
      newCapacity = 2;
      v5 = (Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *)v6(pheapAddr, 8 * v4, &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>,Scaleform::AllocatorDH<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>,Scaleform::AllocatorDH<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *v5; // eax
  int (__thiscall *v6)(const void *, unsigned int, unsigned int *); // edx

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                                    Scaleform::Memory::pGlobalHeap,
                                                                    this->Data,
                                                                    304 * ((newCapacity + 3) >> 2));
    }
    else
    {
      v6 = *(int (__thiscall **)(const void *, unsigned int, unsigned int *))(*(_DWORD *)pheapAddr + 40);
      newCapacity = 2;
      v5 = (Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *)v6(pheapAddr, 76 * v4, &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::AS2::ArraySortFunctor *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::AS2::ArraySortFunctor *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      this->Data,
                                                      112 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 2;
      v5 = (Scaleform::GFx::AS2::ArraySortFunctor *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      28 * v4,
                                                      &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::ButtonRecord,Scaleform::AllocatorLH<Scaleform::GFx::ButtonRecord,258>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::ButtonRecord,Scaleform::AllocatorLH<Scaleform::GFx::ButtonRecord,258>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::ButtonRecord *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::ButtonRecord *)Scaleform::Memory::pGlobalHeap->Realloc(
                                             Scaleform::Memory::pGlobalHeap,
                                             this->Data,
                                             384 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 258;
      v5 = (Scaleform::GFx::ButtonRecord *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                             Scaleform::Memory::pGlobalHeap,
                                             pheapAddr,
                                             96 * v4,
                                             &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Environment::TryDescr,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Environment::TryDescr,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::AS2::Environment::TryDescr *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::AS2::Environment::TryDescr *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           this->Data,
                                                           48 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 2;
      v5 = (Scaleform::GFx::AS2::Environment::TryDescr *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           pheapAddr,
                                                           12 * v4,
                                                           &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::StaticTextRecord::GlyphEntry,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextRecord::GlyphEntry,258>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::StaticTextRecord::GlyphEntry,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextRecord::GlyphEntry,258>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::StaticTextRecord::GlyphEntry *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::StaticTextRecord::GlyphEntry *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                             Scaleform::Memory::pGlobalHeap,
                                                             this->Data,
                                                             32 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 258;
      v5 = (Scaleform::GFx::StaticTextRecord::GlyphEntry *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                             Scaleform::Memory::pGlobalHeap,
                                                             pheapAddr,
                                                             8 * v4,
                                                             &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1>>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1> > *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Waitable::HandlerStruct *v5; // eax

  if ( newCapacity >= this->Policy.Capacity )
  {
    if ( newCapacity )
    {
      v4 = 16 * ((newCapacity + 15) >> 4);
      if ( this->Data )
      {
        v5 = (Scaleform::Waitable::HandlerStruct *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     this->Data,
                                                     (newCapacity + 15) >> 4 << 7);
      }
      else
      {
        newCapacity = 2;
        v5 = (Scaleform::Waitable::HandlerStruct *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     8 * v4,
                                                     &newCapacity);
      }
      this->Policy.Capacity = v4;
      this->Data = v5;
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
}


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::AS3::Abc::MetadataInfo::Item *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::AS3::Abc::MetadataInfo::Item *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                             Scaleform::Memory::pGlobalHeap,
                                                             this->Data,
                                                             32 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 338;
      v5 = (Scaleform::GFx::AS3::Abc::MetadataInfo::Item *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                             Scaleform::Memory::pGlobalHeap,
                                                             pheapAddr,
                                                             8 * v4,
                                                             &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::Multiname,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::Multiname,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::Multiname,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::Multiname,339>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::AS3::Abc::Multiname *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::AS3::Abc::Multiname *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    this->Data,
                                                    (newCapacity + 3) >> 2 << 6);
    }
    else
    {
      newCapacity = 339;
      v5 = (Scaleform::GFx::AS3::Abc::Multiname *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    pheapAddr,
                                                    16 * v4,
                                                    &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::NamespaceInfo,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::NamespaceInfo,339>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::AS3::Abc::NamespaceInfo *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::AS3::Abc::NamespaceInfo *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        this->Data,
                                                        48 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 339;
      v5 = (Scaleform::GFx::AS3::Abc::NamespaceInfo *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        pheapAddr,
                                                        12 * v4,
                                                        &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::AS3::Instances::fl::Object **v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::AS3::Instances::fl::Object **)Scaleform::Memory::pGlobalHeap->Realloc(
                                                            Scaleform::Memory::pGlobalHeap,
                                                            this->Data,
                                                            16 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 2;
      v5 = (Scaleform::GFx::AS3::Instances::fl::Object **)Scaleform::Memory::pGlobalHeap->Alloc(
                                                            Scaleform::Memory::pGlobalHeap,
                                                            4 * v4,
                                                            &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::AS3::Abc::NamespaceSetInfo *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::AS3::Abc::NamespaceSetInfo *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           this->Data,
                                                           16 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 339;
      v5 = (Scaleform::GFx::AS3::Abc::NamespaceSetInfo *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           pheapAddr,
                                                           4 * v4,
                                                           &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::AS2::Value *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::AS2::Value *)Scaleform::Memory::pGlobalHeap->Realloc(
                                           Scaleform::Memory::pGlobalHeap,
                                           this->Data,
                                           (newCapacity + 3) >> 2 << 6);
    }
    else
    {
      newCapacity = 323;
      v5 = (Scaleform::GFx::AS2::Value *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                           Scaleform::Memory::pGlobalHeap,
                                           pheapAddr,
                                           16 * v4,
                                           &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::AS3::Value *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::AS3::Value *)Scaleform::Memory::pGlobalHeap->Realloc(
                                           Scaleform::Memory::pGlobalHeap,
                                           this->Data,
                                           (newCapacity + 3) >> 2 << 6);
    }
    else
    {
      newCapacity = 331;
      v5 = (Scaleform::GFx::AS3::Value *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                           Scaleform::Memory::pGlobalHeap,
                                           pheapAddr,
                                           16 * v4,
                                           &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  int v3; // ebx
  unsigned int v5; // esi
  unsigned int Size; // eax
  unsigned int v7; // ebp
  Scaleform::GFx::Value *v8; // esi
  unsigned int v9; // ebp
  unsigned int v10; // ebx
  Scaleform::GFx::Value *v11; // esi
  Scaleform::GFx::Value *v12; // eax
  unsigned int s; // [esp+18h] [ebp-Ch]
  Scaleform::GFx::Value *newData; // [esp+1Ch] [ebp-8h]
  int v15; // [esp+20h] [ebp-4h] BYREF

  v3 = 0;
  if ( newCapacity )
  {
    v5 = 4 * ((newCapacity + 3) >> 2);
    newCapacity = v5;
    if ( this->Data )
    {
      v15 = 2;
      newData = (Scaleform::GFx::Value *)Scaleform::Memory::pGlobalHeap->Alloc(
                                           Scaleform::Memory::pGlobalHeap,
                                           24 * v5,
                                           &v15);
      Size = this->Size;
      if ( Size >= v5 )
      {
        s = v5;
        Size = v5;
      }
      else
      {
        s = this->Size;
      }
      if ( Size )
      {
        v7 = Size;
        do
        {
          if ( &newData[v3] )
          {
            Scaleform::GFx::Value::Value(&newData[v3], &this->Data[v3]);
            Size = s;
          }
          v8 = &this->Data[v3];
          if ( (v8->Type & 0x40) != 0 )
          {
            ((void (__stdcall *)(Scaleform::GFx::Value *, int))v8->pObjectInterface->ObjectRelease)(
              v8,
              v8->mValue.IValue);
            Size = s;
            v8->pObjectInterface = 0;
          }
          ++v3;
          --v7;
          v8->Type = VT_Undefined;
        }
        while ( v7 );
        v5 = newCapacity;
      }
      v9 = Size;
      if ( Size < this->Size )
      {
        v10 = Size;
        do
        {
          v11 = &this->Data[v10];
          if ( (v11->Type & 0x40) != 0 )
          {
            ((void (__stdcall *)(Scaleform::GFx::Value *, int))v11->pObjectInterface->ObjectRelease)(
              v11,
              v11->mValue.IValue);
            v11->pObjectInterface = 0;
          }
          ++v9;
          v11->Type = VT_Undefined;
          ++v10;
        }
        while ( v9 < this->Size );
        v5 = newCapacity;
      }
      if ( this->Data )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
      this->Policy.Capacity = v5;
      this->Data = newData;
    }
    else
    {
      newCapacity = 2;
      v12 = (Scaleform::GFx::Value *)Scaleform::Memory::pGlobalHeap->Alloc(
                                       Scaleform::Memory::pGlobalHeap,
                                       24 * v5,
                                       &newCapacity);
      this->Policy.Capacity = v5;
      this->Data = v12;
    }
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::Matrix2x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix2x4<float>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::ExternalFontWinAPI::GlyphType,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::GlyphType,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Render::ExternalFontWinAPI::GlyphType *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::Render::ExternalFontWinAPI::GlyphType *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                                 Scaleform::Memory::pGlobalHeap,
                                                                 this->Data,
                                                                 (newCapacity + 3) >> 2 << 7);
    }
    else
    {
      newCapacity = 2;
      v5 = (Scaleform::Render::ExternalFontWinAPI::GlyphType *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                 Scaleform::Memory::pGlobalHeap,
                                                                 pheapAddr,
                                                                 32 * v4,
                                                                 &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1> > *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Render::Matrix3x4<float> *v5; // eax

  if ( newCapacity >= this->Policy.Capacity )
  {
    if ( newCapacity )
    {
      v4 = 8 * ((newCapacity + 7) >> 3);
      if ( this->Data )
      {
        v5 = (Scaleform::Render::Matrix3x4<float> *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      this->Data,
                                                      384 * ((newCapacity + 7) >> 3));
      }
      else
      {
        newCapacity = 2;
        v5 = (Scaleform::Render::Matrix3x4<float> *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      pheapAddr,
                                                      48 * v4,
                                                      &newCapacity);
      }
      this->Policy.Capacity = v4;
      this->Data = v5;
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
}


void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::Matrix4x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix4x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::Matrix4x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix4x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1> > *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Render::Matrix4x4<float> *v5; // eax

  if ( newCapacity >= this->Policy.Capacity )
  {
    if ( newCapacity )
    {
      v4 = 8 * ((newCapacity + 7) >> 3);
      if ( this->Data )
      {
        v5 = (Scaleform::Render::Matrix4x4<float> *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      this->Data,
                                                      (newCapacity + 7) >> 3 << 9);
      }
      else
      {
        newCapacity = 2;
        v5 = (Scaleform::Render::Matrix4x4<float> *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      pheapAddr,
                                                      v4 << 6,
                                                      &newCapacity);
      }
      this->Policy.Capacity = v4;
      this->Data = v5;
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
}


void __thiscall Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                             Scaleform::Memory::pGlobalHeap,
                                                             this->Data,
                                                             16 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 265;
      v5 = (Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                             Scaleform::Memory::pGlobalHeap,
                                                             4 * v4,
                                                             &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                             Scaleform::Memory::pGlobalHeap,
                                                             this->Data,
                                                             16 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 265;
      v5 = (Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                             Scaleform::Memory::pGlobalHeap,
                                                             pheapAddr,
                                                             4 * v4,
                                                             &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Ptr<Scaleform::GFx::ShapeDataBase> *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::Ptr<Scaleform::GFx::ShapeDataBase> *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                              Scaleform::Memory::pGlobalHeap,
                                                              this->Data,
                                                              16 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 261;
      v5 = (Scaleform::Ptr<Scaleform::GFx::ShapeDataBase> *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                              Scaleform::Memory::pGlobalHeap,
                                                              pheapAddr,
                                                              4 * v4,
                                                              &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  bool *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (bool *)Scaleform::Memory::pGlobalHeap->Realloc(Scaleform::Memory::pGlobalHeap, this->Data, v4);
    }
    else
    {
      newCapacity = 2;
      v5 = (bool *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                     Scaleform::Memory::pGlobalHeap,
                     pheapAddr,
                     v4,
                     &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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


void __thiscall Scaleform::ArrayDataBase<wchar_t,Scaleform::AllocatorLH<wchar_t,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<wchar_t,Scaleform::AllocatorLH<wchar_t,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  wchar_t *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (wchar_t *)Scaleform::Memory::pGlobalHeap->Realloc(
                        Scaleform::Memory::pGlobalHeap,
                        this->Data,
                        8 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 2;
      v5 = (wchar_t *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                        Scaleform::Memory::pGlobalHeap,
                        pheapAddr,
                        2 * v4,
                        &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
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
