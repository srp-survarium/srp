Scaleform::GFx::AS3::RefCountBaseGC<328> *__thiscall Scaleform::GFx::AS3::RefCountCollector<328>::ListRootNode::`scalar deleting destructor'(
        Scaleform::GFx::AS3::RefCountBaseGC<328> *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::AS3::RefCountBaseGC<328>_vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable';
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)this);
  return this;
}
