Scaleform::GFx::AS3::Abc::File *__thiscall Scaleform::GFx::AS3::Abc::File::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Abc::File *this,
        char a2)
{
  Scaleform::GFx::AS3::Abc::File::~File(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)this);
  return this;
}
