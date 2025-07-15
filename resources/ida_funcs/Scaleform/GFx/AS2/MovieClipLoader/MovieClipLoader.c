void __userpurge Scaleform::GFx::AS2::MovieClipLoader::MovieClipLoader(
        Scaleform::GFx::AS2::MovieClipLoader *this@<ecx>,
        Scaleform::GFx::AS2::LocalFrame **a2@<ebp>,
        Scaleform::GFx::AS2::Environment *penv)
{
  unsigned __int8 *p_StringContext; // ebx
  Scaleform::GFx::AS2::Object *Prototype; // eax
  int v6; // [esp+0h] [ebp-Ch]
  int v7; // [esp+4h] [ebp-8h]

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::MovieClipLoader_vtbl *)&Scaleform::GFx::AS2::MovieClipLoader::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::MovieClipLoader::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->ProgressInfo.mHash.pTable = 0;
  p_StringContext = (unsigned __int8 *)&penv->StringContext;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_MovieClipLoader);
  this->Set__proto__(&this->Scaleform::GFx::AS2::ObjectInterface, &penv->StringContext, Prototype);
  if ( this != (Scaleform::GFx::AS2::MovieClipLoader *)-16 )
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      p_StringContext,
      a2,
      &this->Scaleform::GFx::AS2::ObjectInterface,
      (Scaleform::GFx::AS2::ASStringContext *)p_StringContext,
      GAS_AsBcFunctionTable,
      1u,
      v6);
  Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance(
    (int)this,
    (int)&this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::AS2::ASStringContext *)p_StringContext,
    &this->Scaleform::GFx::AS2::ObjectInterface,
    v6,
    v7);
}
