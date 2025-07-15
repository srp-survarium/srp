Scaleform::GFx::AS3::ClassTraits::UserDefined *__thiscall Scaleform::GFx::AS3::ClassTraits::UserDefined::`scalar deleting destructor'(
        Scaleform::GFx::AS3::ClassTraits::UserDefined *this,
        char a2)
{
  Scaleform::GFx::AS3::ClassTraits::UserDefined::~UserDefined(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
