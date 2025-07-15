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


void __thiscall Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,2>,Scaleform::ArrayConstPolicy<0,4,1>>::Reserve(
        Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,2>,Scaleform::ArrayConstPolicy<0,4,1> > *this,
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
        newCapacity = 2;
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
        void *pheapAddr)
{
  unsigned int v3; // esi
  ID3D11Resource **v4; // eax

  if ( newCapacity < 8 )
    newCapacity = 8;
  v3 = 8 * ((newCapacity + 7) >> 3);
  if ( this->Data )
    v4 = (ID3D11Resource **)Scaleform::Memory::pGlobalHeap->Realloc(
                              Scaleform::Memory::pGlobalHeap,
                              this->Data,
                              32 * ((newCapacity + 7) >> 3));
  else
    v4 = (ID3D11Resource **)Scaleform::AllocatorBaseLH<75>::Alloc(pheapAddr, 32 * ((newCapacity + 7) >> 3));
  this->Policy.Capacity = v3;
  this->Data = v4;
}


void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::TextureFormat *,Scaleform::AllocatorLH<Scaleform::Render::TextureFormat *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::TextureFormat *,Scaleform::AllocatorLH<Scaleform::Render::TextureFormat *,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  Scaleform::Render::TextureFormat **v4; // eax

  if ( newCapacity )
  {
    if ( this->Data )
      v4 = (Scaleform::Render::TextureFormat **)Scaleform::Memory::pGlobalHeap->Realloc(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  this->Data,
                                                  16 * ((newCapacity + 3) >> 2));
    else
      v4 = (Scaleform::Render::TextureFormat **)Scaleform::AllocatorBaseLH<2>::Alloc(
                                                  pheapAddr,
                                                  16 * ((newCapacity + 3) >> 2));
    this->Policy.Capacity = 4 * ((newCapacity + 3) >> 2);
    this->Data = v4;
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
                                                 (newCapacity + 3) >> 2 << 7);
    }
    else
    {
      newCapacity = 332;
      v5 = (Scaleform::GFx::AS3::Slots::Pair *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
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


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,331>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,331>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::ASString *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::ASString *)Scaleform::Memory::pGlobalHeap->Realloc(
                                         Scaleform::Memory::pGlobalHeap,
                                         this->Data,
                                         16 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 331;
      v5 = (Scaleform::GFx::ASString *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
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
  unsigned int v13; // [esp+18h] [ebp-Ch]
  Scaleform::GFx::Value *v14; // [esp+1Ch] [ebp-8h]
  int v15; // [esp+20h] [ebp-4h] BYREF

  v3 = 0;
  if ( newCapacity )
  {
    v5 = 4 * ((newCapacity + 3) >> 2);
    newCapacity = v5;
    if ( this->Data )
    {
      v15 = 2;
      v14 = (Scaleform::GFx::Value *)Scaleform::Memory::pGlobalHeap->Alloc(
                                       Scaleform::Memory::pGlobalHeap,
                                       24 * v5,
                                       &v15);
      Size = this->Size;
      if ( Size >= v5 )
      {
        v13 = v5;
        Size = v5;
      }
      else
      {
        v13 = this->Size;
      }
      if ( Size )
      {
        v7 = Size;
        do
        {
          if ( &v14[v3] )
          {
            Scaleform::GFx::Value::Value(&v14[v3], &this->Data[v3]);
            Size = v13;
          }
          v8 = &this->Data[v3];
          if ( (v8->Type & 0x40) != 0 )
          {
            ((void (__stdcall *)(Scaleform::GFx::Value *, int))v8->pObjectInterface->ObjectRelease)(
              v8,
              v8->mValue.IValue);
            Size = v13;
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
      this->Data = v14;
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
