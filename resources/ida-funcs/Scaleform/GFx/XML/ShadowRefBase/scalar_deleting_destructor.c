Scaleform::GFx::AS3::Abc::Code *__thiscall Scaleform::GFx::XML::ShadowRefBase::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Abc::Code *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::AS3::Abc::Code_vtbl *)&Scaleform::GFx::AS3::Abc::Code::`vftable';
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
