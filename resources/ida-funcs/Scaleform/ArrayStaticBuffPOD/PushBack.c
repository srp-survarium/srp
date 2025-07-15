void __thiscall Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(
        Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *this,
        unsigned __int8 *val)
{
  unsigned int Size; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  unsigned int v5; // eax
  unsigned __int8 *v6; // eax
  unsigned int Reserved; // ecx
  unsigned __int8 *Data; // edx

  Size = this->Size;
  if ( Size >= 0x400 )
  {
    if ( Size == 1024 )
    {
      pHeap = this->pHeap;
      v5 = 2 * this->Reserved;
      this->Reserved = v5;
      if ( pHeap )
        v6 = (unsigned __int8 *)pHeap->Alloc(pHeap, v5, 0);
      else
        v6 = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                  Scaleform::Memory::pGlobalHeap,
                                  this,
                                  v5,
                                  0);
      this->Data = v6;
      qmemcpy(v6, this->Static, 0x400u);
    }
    else
    {
      Reserved = this->Reserved;
      if ( Size >= Reserved )
      {
        Data = this->Data;
        this->Reserved = 2 * Reserved;
        this->Data = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->Realloc(
                                          Scaleform::Memory::pGlobalHeap,
                                          Data,
                                          2 * Reserved);
      }
    }
    this->Data[this->Size++] = *val;
  }
  else
  {
    this->Static[Size] = *val;
    ++this->Size;
  }
}


void __thiscall Scaleform::ArrayStaticBuffPOD<unsigned short,72,2>::PushBack(
        Scaleform::ArrayStaticBuffPOD<unsigned short,72,2> *this,
        unsigned __int16 *val)
{
  unsigned int Size; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  unsigned int v5; // eax
  unsigned __int16 *v6; // eax
  unsigned int Reserved; // ecx
  unsigned __int16 *Data; // edx
  unsigned int v9; // [esp-Ch] [ebp-10h]

  Size = this->Size;
  if ( Size >= 0x48 )
  {
    if ( Size == 72 )
    {
      pHeap = this->pHeap;
      v5 = 2 * this->Reserved;
      this->Reserved = v5;
      v9 = 2 * v5;
      if ( pHeap )
        v6 = (unsigned __int16 *)pHeap->Alloc(pHeap, v9, 0);
      else
        v6 = (unsigned __int16 *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                   Scaleform::Memory::pGlobalHeap,
                                   this,
                                   v9,
                                   0);
      this->Data = v6;
      qmemcpy(v6, this->Static, 0x90u);
    }
    else
    {
      Reserved = this->Reserved;
      if ( Size >= Reserved )
      {
        Data = this->Data;
        this->Reserved = 2 * Reserved;
        this->Data = (unsigned __int16 *)Scaleform::Memory::pGlobalHeap->Realloc(
                                           Scaleform::Memory::pGlobalHeap,
                                           Data,
                                           4 * Reserved);
      }
    }
    this->Data[this->Size++] = *val;
  }
  else
  {
    this->Static[Size] = *val;
    ++this->Size;
  }
}


void __thiscall Scaleform::ArrayStaticBuffPOD<unsigned int,16,2>::PushBack(
        Scaleform::ArrayStaticBuffPOD<unsigned long,16,2> *this,
        unsigned int *val)
{
  unsigned int Size; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  unsigned int v5; // eax
  unsigned int *v6; // eax
  unsigned int Reserved; // ecx
  unsigned int *Data; // edx
  unsigned int v9; // [esp-Ch] [ebp-10h]

  Size = this->Size;
  if ( Size >= 0x10 )
  {
    if ( Size == 16 )
    {
      pHeap = this->pHeap;
      v5 = 2 * this->Reserved;
      this->Reserved = v5;
      v9 = 4 * v5;
      if ( pHeap )
        v6 = (unsigned int *)pHeap->Alloc(pHeap, v9, 0);
      else
        v6 = (unsigned int *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, v9, 0);
      this->Data = v6;
      qmemcpy(v6, this->Static, 0x40u);
    }
    else
    {
      Reserved = this->Reserved;
      if ( Size >= Reserved )
      {
        Data = this->Data;
        this->Reserved = 2 * Reserved;
        this->Data = (unsigned int *)Scaleform::Memory::pGlobalHeap->Realloc(
                                       Scaleform::Memory::pGlobalHeap,
                                       Data,
                                       8 * Reserved);
      }
    }
    this->Data[this->Size++] = *val;
  }
  else
  {
    this->Static[Size] = *val;
    ++this->Size;
  }
}


void __thiscall Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Font *,32,2>::PushBack(
        Scaleform::ArrayStaticBuffPOD<Scaleform::RefCountImpl *,32,2> *this,
        Scaleform::RefCountImpl **val)
{
  unsigned int Size; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  unsigned int v5; // eax
  Scaleform::RefCountImpl **v6; // eax
  unsigned int Reserved; // ecx
  Scaleform::RefCountImpl **Data; // edx
  unsigned int v9; // [esp-Ch] [ebp-10h]

  Size = this->Size;
  if ( Size >= 0x20 )
  {
    if ( Size == 32 )
    {
      pHeap = this->pHeap;
      v5 = 2 * this->Reserved;
      this->Reserved = v5;
      v9 = 4 * v5;
      if ( pHeap )
        v6 = (Scaleform::RefCountImpl **)pHeap->Alloc(pHeap, v9, 0);
      else
        v6 = (Scaleform::RefCountImpl **)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                           Scaleform::Memory::pGlobalHeap,
                                           this,
                                           v9,
                                           0);
      this->Data = v6;
      qmemcpy(v6, this->Static, 0x80u);
    }
    else
    {
      Reserved = this->Reserved;
      if ( Size >= Reserved )
      {
        Data = this->Data;
        this->Reserved = 2 * Reserved;
        this->Data = (Scaleform::RefCountImpl **)Scaleform::Memory::pGlobalHeap->Realloc(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   Data,
                                                   8 * Reserved);
      }
    }
    this->Data[this->Size++] = *val;
  }
  else
  {
    this->Static[Size] = *val;
    ++this->Size;
  }
}


void __thiscall Scaleform::ArrayStaticBuffPOD<Scaleform::Render::VertexOutput::Fill,16,2>::PushBack(
        Scaleform::ArrayStaticBuffPOD<Scaleform::Render::VertexOutput::Fill,16,2> *this,
        const Scaleform::Render::VertexOutput::Fill *val)
{
  unsigned int Size; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  unsigned int v5; // edx
  Scaleform::Render::VertexOutput::Fill *v6; // eax
  unsigned int Reserved; // ecx
  Scaleform::Render::VertexOutput::Fill *Data; // edx
  unsigned int v9; // ecx

  Size = this->Size;
  if ( Size >= 0x10 )
  {
    if ( Size == 16 )
    {
      pHeap = this->pHeap;
      v5 = 56 * this->Reserved;
      this->Reserved *= 2;
      if ( pHeap )
        v6 = (Scaleform::Render::VertexOutput::Fill *)pHeap->Alloc(pHeap, v5, 0);
      else
        v6 = (Scaleform::Render::VertexOutput::Fill *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        this,
                                                        v5,
                                                        0);
      this->Data = v6;
      qmemcpy((void *)v6, this->Static, 0x1C0u);
    }
    else
    {
      Reserved = this->Reserved;
      if ( Size >= Reserved )
      {
        Data = this->Data;
        v9 = 2 * Reserved;
        this->Reserved = v9;
        this->Data = (Scaleform::Render::VertexOutput::Fill *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                                Scaleform::Memory::pGlobalHeap,
                                                                Data,
                                                                28 * v9);
      }
    }
    qmemcpy((void *)&this->Data[this->Size++], val, sizeof(this->Data[this->Size++]));
  }
  else
  {
    qmemcpy((void *)&this->Static[Size], val, sizeof(this->Static[Size]));
    ++this->Size;
  }
}


void __thiscall Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Math2D::QuadCoord,32,2>::PushBack(
        Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Math2D::QuadCoord,32,2> *this,
        const Scaleform::Render::Math2D::QuadCoord *val)
{
  unsigned int Size; // eax
  Scaleform::Render::Math2D::QuadCoord *v4; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  unsigned int v6; // eax
  Scaleform::Render::Math2D::QuadCoord *v7; // eax
  unsigned int Reserved; // ecx
  Scaleform::Render::Math2D::QuadCoord *Data; // edx
  unsigned int v10; // [esp-Ch] [ebp-10h]

  Size = this->Size;
  if ( Size >= 0x20 )
  {
    if ( Size == 32 )
    {
      pHeap = this->pHeap;
      v6 = 2 * this->Reserved;
      this->Reserved = v6;
      v10 = 16 * v6;
      if ( pHeap )
        v7 = (Scaleform::Render::Math2D::QuadCoord *)pHeap->Alloc(pHeap, v10, 0);
      else
        v7 = (Scaleform::Render::Math2D::QuadCoord *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       this,
                                                       v10,
                                                       0);
      this->Data = v7;
      qmemcpy(v7, this->Static, 0x200u);
    }
    else
    {
      Reserved = this->Reserved;
      if ( Size >= Reserved )
      {
        Data = this->Data;
        this->Reserved = 2 * Reserved;
        this->Data = (Scaleform::Render::Math2D::QuadCoord *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                               Scaleform::Memory::pGlobalHeap,
                                                               Data,
                                                               32 * Reserved);
      }
    }
    v4 = &this->Data[this->Size];
  }
  else
  {
    v4 = &this->Static[Size];
  }
  *v4 = *val;
  ++this->Size;
}


void __thiscall Scaleform::ArrayStaticBuffPOD<Scaleform::Render::ShapeMeshProvider::TmpPathInfoType,32,2>::PushBack(
        Scaleform::ArrayStaticBuffPOD<Scaleform::Render::ShapeMeshProvider::TmpPathInfoType,32,2> *this,
        const Scaleform::Render::ShapeMeshProvider::TmpPathInfoType *val)
{
  unsigned int Size; // eax
  Scaleform::Render::ShapeMeshProvider::TmpPathInfoType *v4; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  unsigned int v6; // eax
  Scaleform::Render::ShapeMeshProvider::TmpPathInfoType *v7; // eax
  unsigned int Reserved; // ecx
  Scaleform::Render::ShapeMeshProvider::TmpPathInfoType *Data; // edx
  unsigned int v10; // [esp-Ch] [ebp-10h]

  Size = this->Size;
  if ( Size >= 0x20 )
  {
    if ( Size == 32 )
    {
      pHeap = this->pHeap;
      v6 = 2 * this->Reserved;
      this->Reserved = v6;
      v10 = 24 * v6;
      if ( pHeap )
        v7 = (Scaleform::Render::ShapeMeshProvider::TmpPathInfoType *)pHeap->Alloc(pHeap, v10, 0);
      else
        v7 = (Scaleform::Render::ShapeMeshProvider::TmpPathInfoType *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                        Scaleform::Memory::pGlobalHeap,
                                                                        this,
                                                                        v10,
                                                                        0);
      this->Data = v7;
      qmemcpy(v7, this->Static, 0x300u);
    }
    else
    {
      Reserved = this->Reserved;
      if ( Size >= Reserved )
      {
        Data = this->Data;
        this->Reserved = 2 * Reserved;
        this->Data = (Scaleform::Render::ShapeMeshProvider::TmpPathInfoType *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                                                Scaleform::Memory::pGlobalHeap,
                                                                                Data,
                                                                                48 * Reserved);
      }
    }
    v4 = &this->Data[this->Size];
  }
  else
  {
    v4 = &this->Static[Size];
  }
  *v4 = *val;
  ++this->Size;
}


void __thiscall Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(
        Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2> *this,
        const Scaleform::Render::Scale9GridTess::TmpVertexType *val)
{
  unsigned int Size; // eax
  Scaleform::Render::Scale9GridTess::TmpVertexType *v4; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  unsigned int v6; // eax
  Scaleform::Render::Scale9GridTess::TmpVertexType *v7; // eax
  unsigned int Reserved; // ecx
  Scaleform::Render::Scale9GridTess::TmpVertexType *Data; // edx
  unsigned int v10; // [esp-Ch] [ebp-10h]

  Size = this->Size;
  if ( Size >= 0x48 )
  {
    if ( Size == 72 )
    {
      pHeap = this->pHeap;
      v6 = 2 * this->Reserved;
      this->Reserved = v6;
      v10 = 12 * v6;
      if ( pHeap )
        v7 = (Scaleform::Render::Scale9GridTess::TmpVertexType *)pHeap->Alloc(pHeap, v10, 0);
      else
        v7 = (Scaleform::Render::Scale9GridTess::TmpVertexType *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                   Scaleform::Memory::pGlobalHeap,
                                                                   this,
                                                                   v10,
                                                                   0);
      this->Data = v7;
      qmemcpy(v7, this->Static, 0x360u);
    }
    else
    {
      Reserved = this->Reserved;
      if ( Size >= Reserved )
      {
        Data = this->Data;
        this->Reserved = 2 * Reserved;
        this->Data = (Scaleform::Render::Scale9GridTess::TmpVertexType *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                                           Scaleform::Memory::pGlobalHeap,
                                                                           Data,
                                                                           24 * Reserved);
      }
    }
    v4 = &this->Data[this->Size];
  }
  else
  {
    v4 = &this->Static[Size];
  }
  *v4 = *val;
  ++this->Size;
}
