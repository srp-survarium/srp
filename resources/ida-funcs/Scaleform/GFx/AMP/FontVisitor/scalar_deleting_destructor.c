Scaleform::GFx::AMP::FontVisitor *__thiscall Scaleform::GFx::AMP::FontVisitor::`scalar deleting destructor'(
        Scaleform::GFx::AMP::FontVisitor *this,
        char a2)
{
  Scaleform::ConstructorMov<Scaleform::String>::DestructArray(this->Fonts.Data.Data, this->Fonts.Data.Size);
  if ( this->Fonts.Data.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Fonts.Data.Data);
  this->__vftable = (Scaleform::GFx::AMP::FontVisitor_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
