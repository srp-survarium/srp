void __thiscall Scaleform::GFx::AS2::ArrayCtorFunction::ArrayCtorFunction(
        Scaleform::GFx::AS2::ArrayCtorFunction *this,
        Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::ASStringContext *v2; // edi
  Scaleform::GFx::AS2::ObjectInterface *v4; // esi
  Scaleform::GFx::AS2::Object *Prototype; // eax
  int v6; // eax
  const Scaleform::GFx::AS2::NameNumber *v7; // ecx
  char *Name; // edx
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // [esp+10h] [ebp-1Ch] BYREF
  int v12; // [esp+14h] [ebp-18h]
  Scaleform::GFx::AS2::ArrayCtorFunction *v13; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value v14; // [esp+1Ch] [ebp-10h] BYREF

  v2 = psc;
  v13 = this;
  Scaleform::GFx::AS2::Object::Object(this, psc);
  v4 = &this->Scaleform::GFx::AS2::ObjectInterface;
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::ArrayCtorFunction_vtbl *)&Scaleform::GFx::AS2::AmpMarkerCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::TextSnapshotCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->pFunction = Scaleform::GFx::AS2::ArrayCtorFunction::GlobalCtor;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2->pContext, ASBuiltin_Function);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    Prototype);
  v6 = 0;
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::ArrayCtorFunction_vtbl *)&Scaleform::GFx::AS2::ArrayCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::TextSnapshotCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v12 = 0;
  if ( GASArrayConstTable[0].Name )
  {
    v7 = GASArrayConstTable;
    do
    {
      Name = (char *)v7->Name;
      pContext = v2->pContext;
      v14.NV.Int32Value = GASArrayConstTable[v6].Number;
      LOBYTE(psc) = 3;
      v14.T.Type = 4;
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                          (Scaleform::GFx::ASStringManager *)pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                          Name,
                          strlen(Name),
                          0);
      ++ConstStringNode->RefCount;
      v4->SetMemberRaw(
        v4,
        v2,
        (const Scaleform::GFx::ASString *)&ConstStringNode,
        &v14,
        (const Scaleform::GFx::AS2::PropFlags *)&psc);
      v10 = ConstStringNode;
      --ConstStringNode->RefCount;
      if ( !v10->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      if ( v14.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v14);
      v6 = ++v12;
      v7 = &GASArrayConstTable[v12];
    }
    while ( v7->Name );
  }
}
