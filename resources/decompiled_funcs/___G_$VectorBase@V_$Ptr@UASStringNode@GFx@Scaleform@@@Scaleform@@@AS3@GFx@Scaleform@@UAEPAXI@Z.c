Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *__thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::`scalar deleting destructor'(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this,
        char a2)
{
  Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::DestructArray(
    this->ValueA.Data.Data,
    this->ValueA.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->ValueA.Data.Data);
  this->__vftable = (Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> >_vtbl *)&Scaleform::GFx::AS3::ArrayBase::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
