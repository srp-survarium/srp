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
