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
