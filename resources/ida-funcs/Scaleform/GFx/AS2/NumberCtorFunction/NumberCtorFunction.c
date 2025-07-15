void __userpurge Scaleform::GFx::AS2::NumberCtorFunction::NumberCtorFunction(
        Scaleform::GFx::AS2::NumberCtorFunction *this@<ecx>,
        char *a2@<ebp>,
        Scaleform::GFx::AS2::ASStringContext *psc,
        char a4)
{
  Scaleform::GFx::AS2::ObjectInterface *v5; // esi
  Scaleform::GFx::AS2::Object *Prototype; // eax
  int v7; // eax
  const Scaleform::GFx::AS2::GASNameNumberFunc *v8; // ebx
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  char *Name; // edx
  Scaleform::GFx::ASStringNode *v12; // [esp+10h] [ebp-1Ch]
  _DWORD v13[2]; // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::Value v14; // [esp+1Ch] [ebp-10h] BYREF

  v13[1] = this;
  Scaleform::GFx::AS2::Object::Object(this, psc);
  v5 = &this->Scaleform::GFx::AS2::ObjectInterface;
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::NumberCtorFunction_vtbl *)&Scaleform::GFx::AS2::AmpMarkerCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::TextSnapshotCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->pFunction = Scaleform::GFx::AS2::NumberCtorFunction::GlobalCtor;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc->pContext, ASBuiltin_Function);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    Prototype);
  v7 = 0;
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::NumberCtorFunction_vtbl *)&Scaleform::GFx::AS2::NumberCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::TextSnapshotCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v13[0] = 0;
  if ( GASNumberConstTable[0].Name )
  {
    v8 = GASNumberConstTable;
    do
    {
      *(double *)((char *)&v14.NV.NumberValue + 4) = ((double (__stdcall *)(char *))GASNumberConstTable[v7].Function)(a2);
      pContext = psc->pContext;
      Name = (char *)v8->Name;
      v14.V.BooleanValue = 3;
      v13[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 (Scaleform::GFx::ASStringManager *)pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 Name,
                 strlen(Name),
                 0);
      ++*(_DWORD *)(v13[0] + 12);
      a2 = &a4;
      ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, _DWORD *, $B8BD913BABC9324639AA48504BEFB2FC *))v5->SetMemberRaw)(
        v5,
        psc,
        v13,
        &v14.NV.4);
      if ( !--v12->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      if ( v14.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v14);
      v7 = ++v13[0];
      v8 = &GASNumberConstTable[v13[0]];
    }
    while ( v8->Name );
  }
}
