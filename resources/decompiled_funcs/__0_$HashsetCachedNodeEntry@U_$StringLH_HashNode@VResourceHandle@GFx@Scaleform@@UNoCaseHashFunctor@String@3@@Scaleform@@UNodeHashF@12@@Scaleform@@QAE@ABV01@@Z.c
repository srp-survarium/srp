void __thiscall Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF>::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF>(
        Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> *this,
        const Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> *e)
{
  Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor> *p_Value; // esi
  Scaleform::GFx::ResourceHandle::HandleType HType; // eax
  Scaleform::GFx::Resource *pResource; // ecx

  this->NextInChain = e->NextInChain;
  p_Value = &this->Value;
  this->HashValue = e->HashValue;
  Scaleform::StringLH::CopyConstructHelper(&this->Value.First, &e->Value.First);
  HType = e->Value.Second.HType;
  p_Value->Second.HType = HType;
  pResource = e->Value.Second.pResource;
  p_Value->Second.BindIndex = (unsigned int)pResource;
  if ( HType == RH_Pointer )
  {
    if ( pResource )
      Scaleform::RefCountImpl::AddRef(pResource);
  }
}
