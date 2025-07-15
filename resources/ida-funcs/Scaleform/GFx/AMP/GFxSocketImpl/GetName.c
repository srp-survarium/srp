void __thiscall Scaleform::GFx::AMP::GFxSocketImpl::GetName(
        Scaleform::GFx::AMP::GFxSocketImpl *this,
        unsigned int *port,
        unsigned int *address,
        __m128i *name,
        DWORD nameSize)
{
  unsigned int *v6; // esi
  int Index; // eax
  int v8; // esi
  void *v9; // esi
  int v10; // eax
  _DWORD *v11; // edx
  int v12; // ecx
  _DWORD *v13; // eax
  int v14; // [esp+0h] [ebp-444h]
  int v15; // [esp+0h] [ebp-444h]
  int v16; // [esp+4h] [ebp-440h]
  int v17; // [esp+4h] [ebp-440h]
  int v18; // [esp+8h] [ebp-43Ch]
  int v19; // [esp+8h] [ebp-43Ch]
  int v20; // [esp+Ch] [ebp-438h]
  int v21; // [esp+Ch] [ebp-438h]
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::ConstIterator v22; // [esp+10h] [ebp-434h] BYREF
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::ConstIterator it; // [esp+18h] [ebp-42Ch] BYREF
  char pServiceBuffer[32]; // [esp+20h] [ebp-424h] BYREF
  char namea[1028]; // [esp+40h] [ebp-404h] BYREF

  *port = ((unsigned __int16 (__stdcall *)(_DWORD, int, int, int, int))(&off_8E3A98 + 6))(
            this->SocketAddress.sin_port,
            v14,
            v16,
            v18,
            v20);
  v6 = address;
  *address = ntohl(this->SocketAddress.sin_addr.S_un.S_addr);
  if ( name )
  {
    Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>::findIndexAlt<unsigned long>(
              (Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> > *)&this->AddressMap,
              address);
    v8 = 0;
    if ( Index < 0 )
    {
      v22.pHash = 0;
    }
    else
    {
      v22.pHash = &this->AddressMap.mHash;
      v8 = Index;
    }
    v22.Index = v8;
    it.pHash = 0;
    it.Index = 0;
    if ( Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF>>::ConstIterator::operator==(
           &v22,
           &it) )
    {
      if ( getnameinfo((const SOCKADDR *)&this->SocketAddress, 16, name->m128i_i8, nameSize, pServiceBuffer, 0x20u, 1) )
        name->m128i_i8[0] = 0;
      Scaleform::String::String((Scaleform::String *)&v22, name);
      Scaleform::Hash<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>>::Add(
        &this->AddressMap,
        address,
        (const Scaleform::String *)&v22);
      v9 = (void *)((int)v22.pHash & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)(((int)v22.pHash & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
    }
    else
    {
      strcpy_s(
        (int)&this->AddressMap,
        name->m128i_i8,
        nameSize,
        (const char *)((v22.pHash->pTable[2 * v8 + 2].SizeMask & 0xFFFFFFFC) + 8));
    }
    v6 = address;
  }
  if ( !this->LocalHostAddress && !gethostname(namea, 1025) )
  {
    v10 = ((int (__stdcall *)(char *, int, int, int, int))(&off_8E3A98 + 5))(namea, v15, v17, v19, v21);
    if ( v10 )
    {
      v11 = *(_DWORD **)(v10 + 12);
      v12 = 0;
      if ( *v11 )
      {
        v13 = *(_DWORD **)(v10 + 12);
        while ( *(_DWORD *)*v13 != this->SocketAddress.sin_addr.S_un.S_addr )
        {
          v13 = &v11[++v12];
          if ( !*v13 )
            goto LABEL_21;
        }
        this->LocalHostAddress = *v6;
      }
    }
  }
LABEL_21:
  if ( this->LocalHostAddress == *v6 )
    *v6 = 2130706433;
}
