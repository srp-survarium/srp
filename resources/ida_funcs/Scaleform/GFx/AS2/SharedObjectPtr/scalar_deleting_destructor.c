Scaleform::GFx::AS2::SharedObjectPtr *__thiscall Scaleform::GFx::AS2::SharedObjectPtr::`scalar deleting destructor'(
        Scaleform::GFx::AS2::SharedObjectPtr *this,
        char a2)
{
  Scaleform::GFx::AS2::SharedObject *pObject; // ecx
  unsigned int RefCount; // eax

  this->__vftable = (Scaleform::GFx::AS2::SharedObjectPtr_vtbl *)&Scaleform::GFx::AS2::SharedObjectPtr::`vftable';
  pObject = this->pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
