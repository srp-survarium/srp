Scaleform::GFx::AS2::MovieClipObject::Set__proto__::__l5::MemberVisitor *__thiscall `Scaleform::GFx::AS2::GlobalContext::Init'::`4'::MemberVisitor::`scalar deleting destructor'(
        Scaleform::GFx::AS2::MovieClipObject::Set__proto__::__l5::MemberVisitor *this,
        char a2)
{
  Scaleform::GFx::AS2::MovieClipObject *pObject; // ecx
  unsigned int RefCount; // eax

  pObject = this->obj.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->__vftable = (Scaleform::GFx::AS2::MovieClipObject::Set__proto__::__l5::MemberVisitor_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
