void __thiscall Scaleform::GFx::AMP::GFxSocketImpl::GetName(
        Scaleform::GFx::AMP::GFxSocketImpl *this,
        unsigned int *port,
        unsigned int *address,
        char *name,
        DWORD nameSize)
{
  unsigned int *v6; // esi
  signed int Index; // eax
  int v8; // esi
  void *v9; // esi
  struct hostent *v10; // eax
  char **h_addr_list; // edx
  int v12; // ecx
  char **v13; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::Iterator it; // [esp+10h] [ebp-434h] BYREF
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::ConstIterator v15; // [esp+18h] [ebp-42Ch] BYREF
  char servInfo[32]; // [esp+20h] [ebp-424h] BYREF
  char hostName[1028]; // [esp+40h] [ebp-404h] BYREF

  *port = ntohs(this->SocketAddress.sin_port);
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
      it.pHash = 0;
    }
    else
    {
      it.pHash = &this->AddressMap.mHash;
      v8 = Index;
    }
    it.Index = v8;
    v15.pHash = 0;
    v15.Index = 0;
    if ( Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor>>::ConstIterator::operator==(
           &it,
           &v15) )
    {
      if ( getnameinfo((const SOCKADDR *)&this->SocketAddress, 16, name, nameSize, servInfo, 0x20u, 1) )
        *name = 0;
      Scaleform::String::String((Scaleform::String *)&it, name);
      Scaleform::Hash<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>>::Add(
        &this->AddressMap,
        address,
        (const Scaleform::String *)&it);
      v9 = (void *)((int)it.pHash & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)(((int)it.pHash & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
    }
    else
    {
      strcpy_s(name, nameSize, (const char *)((it.pHash->pTable[2 * v8 + 2].SizeMask & 0xFFFFFFFC) + 8));
    }
    v6 = address;
  }
  if ( !this->LocalHostAddress && !gethostname(hostName, 1025) )
  {
    v10 = gethostbyname(hostName);
    if ( v10 )
    {
      h_addr_list = v10->h_addr_list;
      v12 = 0;
      if ( *h_addr_list )
      {
        v13 = v10->h_addr_list;
        while ( *(_DWORD *)*v13 != this->SocketAddress.sin_addr.S_un.S_addr )
        {
          v13 = &h_addr_list[++v12];
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
