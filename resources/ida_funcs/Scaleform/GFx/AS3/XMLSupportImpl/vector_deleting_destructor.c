Scaleform::GFx::AS3::XMLSupportImpl *__thiscall Scaleform::GFx::AS3::XMLSupportImpl::`vector deleting destructor'(
        Scaleform::GFx::AS3::XMLSupportImpl *this,
        char a2)
{
  Scaleform::GFx::AS3::XMLSupportImpl::~XMLSupportImpl(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
