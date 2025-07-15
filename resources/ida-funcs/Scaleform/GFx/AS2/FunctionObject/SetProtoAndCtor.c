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
  Scaleform::GFx::AS2::FunctionRef result; // [esp+10h] [ebp-Ch] BYREF

  v3 = &this->Scaleform::GFx::AS2::ObjectInterface;
  this->Set__proto__(&this->Scaleform::GFx::AS2::ObjectInterface, psc, pprototype);
  Scaleform::GFx::AS2::ObjectInterface::Get_constructor(&pprototype->Scaleform::GFx::AS2::ObjectInterface, &result, psc);
  Function = result.Function;
  if ( result.Function )
    Scaleform::GFx::AS2::ObjectInterface::Set_constructor(v3, psc, &result);
  Flags = result.Flags;
  if ( (result.Flags & 2) == 0 )
  {
    if ( Function )
    {
      RefCount = Function->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
  }
  if ( (Flags & 1) == 0 )
  {
    pLocalFrame = result.pLocalFrame;
    if ( result.pLocalFrame )
    {
      v8 = result.pLocalFrame->RefCount;
      if ( (v8 & 0x3FFFFFF) != 0 )
      {
        result.pLocalFrame->RefCount = v8 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
}
