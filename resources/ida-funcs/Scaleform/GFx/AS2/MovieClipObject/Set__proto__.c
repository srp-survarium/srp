void __thiscall Scaleform::GFx::AS2::MovieClipObject::Set__proto__(
        Scaleform::GFx::AS2::MovieClipObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *protoObj)
{
  Scaleform::GFx::AS2::MovieClipObject *v4; // eax
  unsigned int RootIndex; // esi
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::MovieClipObject *pObject; // ecx
  Scaleform::GFx::AS2::MovieClipObject::Set__proto__::__l5::MemberVisitor visitor; // [esp+Ch] [ebp-Ch] BYREF

  Scaleform::GFx::AS2::Object::Set__proto__(this, psc, protoObj);
  if ( protoObj && protoObj->GetObjectType(&protoObj->Scaleform::GFx::AS2::ObjectInterface) != Object_MovieClipObject )
  {
    v4 = (Scaleform::GFx::AS2::MovieClipObject *)((char *)this - 16);
    visitor.__vftable = (Scaleform::GFx::AS2::MovieClipObject::Set__proto__::__l5::MemberVisitor_vtbl *)&`Scaleform::GFx::AS2::MovieClipObject::Set__proto__'::`5'::MemberVisitor::`vftable';
    if ( this != (Scaleform::GFx::AS2::MovieClipObject *)16 )
      v4->RefCount = (v4->RefCount + 1) & 0x8FFFFFFF;
    RootIndex = this->RootIndex;
    visitor.obj.pObject = v4;
    visitor.pStringContext = psc;
    (*(void (__thiscall **)(unsigned int, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::MovieClipObject::Set__proto__::__l5::MemberVisitor *, int, _DWORD))(*(_DWORD *)(RootIndex + 16) + 32))(
      RootIndex + 16,
      psc,
      &visitor,
      13,
      0);
    if ( visitor.obj.pObject )
    {
      RefCount = visitor.obj.pObject->RefCount;
      pObject = visitor.obj.pObject;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        visitor.obj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
      }
    }
  }
}
