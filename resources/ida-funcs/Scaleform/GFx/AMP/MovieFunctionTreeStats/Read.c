void __thiscall Scaleform::GFx::AMP::MovieFunctionTreeStats::Read(
        Scaleform::GFx::AMP::MovieFunctionTreeStats *this,
        Scaleform::File *str,
        unsigned int version)
{
  Scaleform::GFx::AMP::MovieFunctionTreeStats *v4; // edi
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem>,2,Scaleform::ArrayDefaultPolicy> *p_FunctionRoots; // ebp
  int v7; // eax
  Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem> *v8; // ecx
  Scaleform::GFx::AMP::FuncTreeItem *v9; // eax
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem> *v11; // edi
  int (__thiscall *v12)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *p_FunctionInfo; // ebp
  int (__thiscall *v14)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::StringLH *v15; // eax
  Scaleform::StringLH *v16; // edi
  int (__thiscall *v17)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v18)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned int v19; // ecx
  int (__thiscall *v20)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v21)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::RefCountVImpl *v23; // [esp+3Ch] [ebp-44h] BYREF
  Scaleform::GFx::AMP::FuncTreeItem *v24; // [esp+40h] [ebp-40h]
  Scaleform::File *v25; // [esp+44h] [ebp-3Ch] BYREF
  unsigned int v26; // [esp+48h] [ebp-38h] BYREF
  unsigned int v27; // [esp+4Ch] [ebp-34h] BYREF
  unsigned int v28; // [esp+50h] [ebp-30h] BYREF
  Scaleform::RefCountVImpl *Size; // [esp+54h] [ebp-2Ch] BYREF
  int v30; // [esp+58h] [ebp-28h] BYREF
  int v31; // [esp+5Ch] [ebp-24h] BYREF
  int v32; // [esp+60h] [ebp-20h] BYREF
  int v33; // [esp+64h] [ebp-1Ch]
  unsigned int v34; // [esp+68h] [ebp-18h] BYREF
  unsigned int v35; // [esp+6Ch] [ebp-14h]
  _DWORD v36[2]; // [esp+70h] [ebp-10h] BYREF
  Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [esp+78h] [ebp-8h] BYREF
  Scaleform::RefCountVImpl *file; // [esp+84h] [ebp+4h]
  unsigned int filea; // [esp+84h] [ebp+4h]
  Scaleform::File *fileb; // [esp+84h] [ebp+4h]

  v4 = this;
  Scaleform::GFx::AMP::readString(str, &this->ViewName);
  Read = str->Read;
  v23 = 0;
  Read(str, (unsigned __int8 *)&v23, 4);
  p_FunctionRoots = &v4->FunctionRoots;
  Size = (Scaleform::RefCountVImpl *)v4->FunctionRoots.Data.Size;
  file = v23;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2>,Scaleform::ArrayDefaultPolicy> *)&v4->FunctionRoots,
    &v4->FunctionRoots,
    (unsigned int)v23);
  if ( file > Size )
  {
    v7 = (char *)file - (char *)Size;
    v8 = &p_FunctionRoots->Data.Data[(_DWORD)Size];
    if ( file != Size )
    {
      do
      {
        if ( v8 )
          v8->pObject = 0;
        ++v8;
        --v7;
      }
      while ( v7 );
    }
  }
  filea = 0;
  if ( v4->FunctionRoots.Data.Size )
  {
    do
    {
      v30 = 2;
      v9 = (Scaleform::GFx::AMP::FuncTreeItem *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  v4,
                                                  48,
                                                  &v30);
      if ( v9 )
      {
        v9->__vftable = (Scaleform::GFx::AMP::FuncTreeItem_vtbl *)&Scaleform::RefCountImplCore::`vftable';
        v9->RefCount = 1;
        v9->__vftable = (Scaleform::GFx::AMP::FuncTreeItem_vtbl *)&Scaleform::GFx::AMP::FuncTreeItem::`vftable';
        v9->Children.Data.Data = 0;
        v9->Children.Data.Size = 0;
        v9->Children.Data.Policy.Capacity = 0;
        v24 = v9;
      }
      else
      {
        v24 = 0;
      }
      pObject = (Scaleform::RefCountVImpl *)p_FunctionRoots->Data.Data[filea].pObject;
      v11 = &p_FunctionRoots->Data.Data[filea];
      if ( pObject )
        Scaleform::RefCountImpl::Release(pObject);
      v11->pObject = v24;
      Scaleform::GFx::AMP::FuncTreeItem::Read(p_FunctionRoots->Data.Data[filea++].pObject, str, version);
      v4 = this;
    }
    while ( filea < this->FunctionRoots.Data.Size );
  }
  v12 = str->Read;
  v25 = 0;
  v12(str, (unsigned __int8 *)&v25, 4);
  if ( v25 )
  {
    p_FunctionInfo = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v4->FunctionInfo;
    fileb = v25;
    while ( 1 )
    {
      v14 = str->Read;
      v32 = 0;
      v33 = 0;
      v14(str, (unsigned __int8 *)&v32, 8);
      v36[0] = v32;
      v36[1] = v33;
      v31 = 578;
      v15 = (Scaleform::StringLH *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                     Scaleform::Memory::pGlobalHeap,
                                     v4,
                                     32,
                                     &v31);
      v16 = v15;
      if ( v15 )
      {
        v15->HeapTypeBits = (unsigned int)&Scaleform::RefCountImplCore::`vftable';
        v15[1].HeapTypeBits = 1;
        v15->HeapTypeBits = (unsigned int)&Scaleform::GFx::AMP::Server::SourceFileInfo::`vftable';
        Scaleform::StringLH::StringLH(v15 + 2);
      }
      else
      {
        v16 = 0;
      }
      Scaleform::GFx::AMP::readString(str, v16 + 2);
      v17 = str->Read;
      v26 = 0;
      v17(str, (unsigned __int8 *)&v26, 4);
      v16[3].HeapTypeBits = v26;
      v18 = str->Read;
      v34 = 0;
      v35 = 0;
      v18(str, (unsigned __int8 *)&v34, 8);
      v19 = v35;
      v16[4].HeapTypeBits = v34;
      v16[5].HeapTypeBits = v19;
      v20 = str->Read;
      v27 = 0;
      v20(str, (unsigned __int8 *)&v27, 4);
      v16[6].HeapTypeBits = v27;
      v21 = str->Read;
      v28 = 0;
      v21(str, (unsigned __int8 *)&v28, 4);
      v16[7].HeapTypeBits = v28;
      key.pFirst = (const unsigned __int64 *)v36;
      Size = (Scaleform::RefCountVImpl *)v16;
      key.pSecond = (const Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes> *)&Size;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
        p_FunctionInfo,
        p_FunctionInfo,
        &key);
      if ( Size )
        Scaleform::RefCountImpl::Release(Size);
      fileb = (Scaleform::File *)((char *)fileb - 1);
      if ( !fileb )
        break;
      v4 = this;
    }
  }
}
