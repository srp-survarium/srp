Scaleform::GFx::AMP::GFxSocketImpl *__thiscall Scaleform::GFx::AMP::GFxSocketImpl::`vector deleting destructor'(
        Scaleform::GFx::AMP::GFxSocketImpl *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::AMP::GFxSocketImpl_vtbl *)&Scaleform::GFx::AMP::GFxSocketImpl::`vftable';
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>::Clear(&this->AddressMap.mHash);
  this->__vftable = (Scaleform::GFx::AMP::GFxSocketImpl_vtbl *)&Scaleform::GFx::AMP::SocketInterface::`vftable';
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
