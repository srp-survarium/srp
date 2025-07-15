Scaleform::StringLH *__thiscall Scaleform::MemItem::AddChild(
        Scaleform::MemItem *this,
        unsigned int id,
        const __m128i *name)
{
  Scaleform::StringLH *v4; // eax
  Scaleform::StringLH *v5; // esi
  unsigned int Size; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2>,Scaleform::ArrayDefaultPolicy> *p_Children; // edi
  Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr> *v8; // edi
  int v10; // [esp+Ch] [ebp-4h] BYREF

  v10 = 2;
  v4 = (Scaleform::StringLH *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                Scaleform::Memory::pGlobalHeap,
                                this,
                                40,
                                &v10);
  v5 = v4;
  if ( v4 )
  {
    v4->HeapTypeBits = (unsigned int)&Scaleform::RefCountImplCore::`vftable';
    v4[1].HeapTypeBits = 1;
    v4->HeapTypeBits = (unsigned int)&Scaleform::MemItem::`vftable';
    Scaleform::StringLH::StringLH(v4 + 2);
    v5[3].HeapTypeBits = 0;
    LOBYTE(v5[4].pData) = 0;
    BYTE1(v5[4].pData) = 0;
    v5[5].HeapTypeBits = id;
    v5[6].HeapTypeBits = 0;
    v5[7].HeapTypeBits = 0;
    v5[8].HeapTypeBits = 0;
    v5[9].HeapTypeBits = 0;
  }
  else
  {
    v5 = 0;
  }
  Scaleform::String::operator=(v5 + 2, name);
  Size = this->Children.Data.Size;
  p_Children = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Children;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    p_Children,
    p_Children,
    Size + 1);
  v8 = &p_Children->Data[p_Children->Size - 1];
  if ( v8 )
  {
    if ( v5 )
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v5);
    v8->pObject = (Scaleform::GFx::AS3::SocketThreadMgr *)v5;
  }
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v5);
  return v5;
}


Scaleform::StringLH *__thiscall Scaleform::MemItem::AddChild(
        Scaleform::MemItem *this,
        unsigned int id,
        const __m128i *name,
        unsigned int memValue)
{
  Scaleform::StringLH *v5; // eax
  Scaleform::StringLH *v6; // esi
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2>,Scaleform::ArrayDefaultPolicy> *p_Children; // edi
  Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr> *v8; // edi
  int v10; // [esp+Ch] [ebp-4h] BYREF

  v10 = 2;
  v5 = (Scaleform::StringLH *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                Scaleform::Memory::pGlobalHeap,
                                this,
                                40,
                                &v10);
  v6 = v5;
  if ( v5 )
  {
    v5->HeapTypeBits = (unsigned int)&Scaleform::RefCountImplCore::`vftable';
    v5[1].HeapTypeBits = 1;
    v5->HeapTypeBits = (unsigned int)&Scaleform::MemItem::`vftable';
    Scaleform::StringLH::StringLH(v5 + 2);
    v6[3].HeapTypeBits = 0;
    LOBYTE(v6[4].pData) = 0;
    BYTE1(v6[4].pData) = 0;
    v6[5].HeapTypeBits = id;
    v6[6].HeapTypeBits = 0;
    v6[7].HeapTypeBits = 0;
    v6[8].HeapTypeBits = 0;
    v6[9].HeapTypeBits = 0;
  }
  else
  {
    v6 = 0;
  }
  Scaleform::String::operator=(v6 + 2, name);
  p_Children = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Children;
  v6[3].HeapTypeBits = memValue;
  LOBYTE(v6[4].pData) = 1;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    p_Children,
    p_Children,
    p_Children->Size + 1);
  v8 = &p_Children->Data[p_Children->Size - 1];
  if ( v8 )
  {
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6);
    v8->pObject = (Scaleform::GFx::AS3::SocketThreadMgr *)v6;
  }
  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v6);
  return v6;
}
