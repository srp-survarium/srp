Scaleform::GFx::AS2::RefCountCollector<323>::Root *__thiscall Scaleform::GFx::AS2::RefCountBaseGC<323>::`scalar deleting destructor'(
        Scaleform::GFx::AS2::RefCountCollector<323>::Root *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::AS2::RefCountCollector<323>::Root_vtbl *)&Scaleform::GFx::AS2::RefCountBaseGC<323>::`vftable';
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
