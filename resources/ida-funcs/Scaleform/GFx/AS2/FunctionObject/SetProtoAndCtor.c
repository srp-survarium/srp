void __thiscall Scaleform::GFx::AS2::FunctionObject::SetProtoAndCtor(
        Scaleform::GFx::AS2::FunctionObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pprototype)
{
  Scaleform::GFx::AS2::ObjectInterface *v3; // esi
  Scaleform::GFx::AS2::FunctionObject *Function; // ebp
  unsigned __int8 Flags; // bl
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v8; // eax
  Scaleform::GFx::AS2::FunctionRef ctor; // [esp+10h] [ebp-Ch] BYREF

  v3 = &this->Scaleform::GFx::AS2::ObjectInterface;
  this->Set__proto__(&this->Scaleform::GFx::AS2::ObjectInterface, psc, pprototype);
  Scaleform::GFx::AS2::ObjectInterface::Get_constructor(&pprototype->Scaleform::GFx::AS2::ObjectInterface, &ctor, psc);
  Function = ctor.Function;
  if ( ctor.Function )
    Scaleform::GFx::AS2::ObjectInterface::Set_constructor(v3, psc, &ctor);
  Flags = ctor.Flags;
  if ( (ctor.Flags & 2) == 0 )
  {
    if ( Function )
    {
      RefCount = Function->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
  }
  if ( (Flags & 1) == 0 )
  {
    pLocalFrame = ctor.pLocalFrame;
    if ( ctor.pLocalFrame )
    {
      v8 = ctor.pLocalFrame->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v8) != 0 )
      {
        ctor.pLocalFrame->RefCount = v8 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
}
