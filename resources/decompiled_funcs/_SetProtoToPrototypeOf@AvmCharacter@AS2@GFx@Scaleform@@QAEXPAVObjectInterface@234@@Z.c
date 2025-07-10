void __thiscall Scaleform::GFx::AS2::AvmCharacter::SetProtoToPrototypeOf(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::ObjectInterface *psrcObj)
{
  Scaleform::GFx::AS2::Environment *(__thiscall *GetASEnvironment)(Scaleform::GFx::AS2::AvmCharacter *); // edx
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v5; // ebx
  Scaleform::GFx::AS2::Object *v6; // eax
  Scaleform::GFx::AS2::Value prototype; // [esp+14h] [ebp-10h] BYREF

  GetASEnvironment = this->GetASEnvironment;
  prototype.T.Type = 0;
  p_StringContext = &GetASEnvironment(this)->StringContext;
  if ( psrcObj->GetMemberRaw(
         psrcObj,
         p_StringContext,
         (const Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[23].pASSupport,
         &prototype) )
  {
    v5 = this->Scaleform::GFx::AS2::ObjectInterface::__vftable;
    v6 = Scaleform::GFx::AS2::Value::ToObject(&prototype, 0);
    v5->Set__proto__(&this->Scaleform::GFx::AS2::ObjectInterface, p_StringContext, v6);
  }
  if ( prototype.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&prototype);
}
