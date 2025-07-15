void __thiscall Scaleform::GFx::AS2::MovieClipObject::Set__proto__(
        Scaleform::GFx::AS2::MovieClipObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *protoObj)
{
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v4; // eax
  unsigned int RootIndex; // esi
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v7; // ecx
  int (__thiscall **v8)(void *, char); // [esp+Ch] [ebp-Ch] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // [esp+10h] [ebp-8h]
  Scaleform::GFx::AS2::ASStringContext *v10; // [esp+14h] [ebp-4h]

  Scaleform::GFx::AS2::Object::Set__proto__(this, psc, protoObj);
  if ( protoObj && protoObj->GetObjectType(&protoObj->Scaleform::GFx::AS2::ObjectInterface) != Object_MovieClipObject )
  {
    v4 = (Scaleform::GFx::AS2::MovieClipObject *)((char *)this - 16);
    v8 = &`Scaleform::GFx::AS2::MovieClipObject::Set__proto__'::`5'::MemberVisitor::`vftable';
    if ( this != (Scaleform::GFx::AS2::MovieClipObject *)16 )
      v4->RefCount = (v4->RefCount + 1) & 0x8FFFFFFF;
    RootIndex = this->RootIndex;
    v9 = v4;
    v10 = psc;
    (*(void (__thiscall **)(unsigned int, Scaleform::GFx::AS2::ASStringContext *, int (__thiscall ***)(void *, char), int, _DWORD))(*(_DWORD *)(RootIndex + 16) + 32))(
      RootIndex + 16,
      psc,
      &v8,
      13,
      0);
    if ( v9 )
    {
      RefCount = v9->RefCount;
      v7 = v9;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v9->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
      }
    }
  }
}
