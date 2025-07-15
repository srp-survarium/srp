void __thiscall Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>(
        Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> *this,
        const Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> *e)
{
  this->NextInChain = e->NextInChain;
  this->HashValue = e->HashValue;
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener::Listener(
    (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *)&this->Value,
    (const Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *)&e->Value);
}


void __thiscall Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>(
        Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> *this,
        const Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> *e)
{
  this->NextInChain = e->NextInChain;
  this->HashValue = e->HashValue;
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>(
    &this->Value,
    &e->Value);
}


void __thiscall Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>(
        Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> *this,
        const Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> *e)
{
  Scaleform::GFx::ASStringNode *pNode; // edx
  const Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // edx

  this->NextInChain = e->NextInChain;
  this->HashValue = e->HashValue;
  pNode = e->Value.First.Name.pNode;
  this->Value.First.Name.pNode = pNode;
  ++pNode->RefCount;
  pObject = e->Value.First.pNs.pObject;
  this->Value.First.pNs.pObject = pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  this->Value.Second = e->Value.Second;
}


void __thiscall Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF>::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF>(
        Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF> *this,
        const Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF> *e)
{
  Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor> *p_Value; // ebx

  this->NextInChain = e->NextInChain;
  p_Value = &this->Value;
  this->HashValue = e->HashValue;
  Scaleform::String::String(&this->Value.First, &e->Value.First);
  Scaleform::String::String(&p_Value->Second, &e->Value.Second);
}


void __thiscall Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF>::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF>(
        Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF> *this,
        const Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF> *e)
{
  Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor> *p_Value; // ebx

  this->NextInChain = e->NextInChain;
  p_Value = &this->Value;
  this->HashValue = e->HashValue;
  Scaleform::String::String(&this->Value.First, &e->Value.First);
  p_Value->Second = e->Value.Second;
}


void __thiscall Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>(
        Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> *this,
        const Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> *e)
{
  this->NextInChain = e->NextInChain;
  this->HashValue = e->HashValue;
  Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>(
    &this->Value,
    &e->Value);
}


void __thiscall Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF>::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF>(
        Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> *this,
        const Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> *e)
{
  Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor> *p_Value; // ebx

  this->NextInChain = e->NextInChain;
  p_Value = &this->Value;
  this->HashValue = e->HashValue;
  Scaleform::StringLH::CopyConstructHelper(&this->Value.First, &e->Value.First);
  p_Value->Second = e->Value.Second;
}


void __thiscall Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF>::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF>(
        Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF> *this,
        const Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF> *e)
{
  Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor> *p_Value; // ebx

  this->NextInChain = e->NextInChain;
  p_Value = &this->Value;
  this->HashValue = e->HashValue;
  Scaleform::StringLH::CopyConstructHelper(&this->Value.First, &e->Value.First);
  p_Value->Second = e->Value.Second;
}


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


void __thiscall Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>(
        Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> *this,
        const Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> *e)
{
  Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor> *p_Value; // ebx
  Scaleform::Render::Text::ImageDesc *pObject; // eax

  this->NextInChain = e->NextInChain;
  p_Value = &this->Value;
  this->HashValue = e->HashValue;
  Scaleform::StringLH::CopyConstructHelper(&this->Value.First, &e->Value.First);
  pObject = e->Value.Second.pObject;
  if ( pObject )
    ++pObject->RefCount;
  p_Value->Second.pObject = e->Value.Second.pObject;
}
