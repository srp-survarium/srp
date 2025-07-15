void __thiscall Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>::Clear(
        Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> *this)
{
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value *p_Second; // ecx

  Flags = this->Value.Second.Flags;
  p_Second = &this->Value.Second;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_Second);
      this->NextInChain = -2;
      return;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(p_Second);
  }
  this->NextInChain = -2;
}


void __thiscall Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>::Clear(
        Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> *this)
{
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::~HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>(&this->Value);
  this->NextInChain = -2;
}


void __thiscall Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>::Clear(
        Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> *this)
{
  Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *p_Value; // esi
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value *p_Second; // ecx

  p_Value = &this->Value;
  Flags = this->Value.Second.Flags;
  p_Second = &this->Value.Second;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_Second);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_Second);
  }
  if ( (p_Value->First.Flags & 0x1F) > 9 )
  {
    if ( (p_Value->First.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&p_Value->First);
      this->NextInChain = -2;
      return;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(&p_Value->First);
  }
  this->NextInChain = -2;
}


void __thiscall Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>::Clear(
        Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> *this)
{
  Scaleform::Render::Text::ImageDesc *pObject; // ecx
  volatile LONG *v3; // esi

  pObject = this->Value.Second.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  v3 = (volatile LONG *)(this->Value.First.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  this->NextInChain = -2;
}
