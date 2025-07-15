Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_object *__thiscall Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_object::`scalar deleting destructor'(
        Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_object *this,
        char a2)
{
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_object::~Vector_object(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
