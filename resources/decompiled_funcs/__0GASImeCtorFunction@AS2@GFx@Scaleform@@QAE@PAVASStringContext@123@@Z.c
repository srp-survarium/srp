void __userpurge Scaleform::GFx::AS2::GASImeCtorFunction::GASImeCtorFunction(
        Scaleform::GFx::AS2::GASImeCtorFunction *this@<ecx>,
        unsigned __int8 *a2@<ebx>,
        Scaleform::GFx::AS2::LocalFrame **psc)
{
  Scaleform::GFx::AS2::LocalFrame **v3; // ebp
  Scaleform::GFx::AS2::ObjectInterface *v5; // edi
  int v6; // eax
  const Scaleform::GFx::AS2::NameNumber *v7; // ecx
  int v8; // eax
  char *Name; // esi
  Scaleform::GFx::AS2::LocalFrame *v10; // ecx
  Scaleform::GFx::ASStringManager *pStringManager; // ecx
  Scaleform::GFx::ASStringNode *v12; // eax
  int v13; // [esp-4h] [ebp-30h]
  Scaleform::GFx::ASStringNode *ConstStringNode; // [esp+10h] [ebp-1Ch] BYREF
  int i; // [esp+14h] [ebp-18h]
  Scaleform::GFx::AS2::GASImeCtorFunction *v16; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value v17; // [esp+1Ch] [ebp-10h] BYREF

  v3 = psc;
  v16 = this;
  Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(
    this,
    (Scaleform::GFx::AS2::ASStringContext *)psc,
    Scaleform::GFx::AS2::ObjectProto::GlobalCtor);
  v5 = &this->Scaleform::GFx::AS2::ObjectInterface;
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::GASImeCtorFunction_vtbl *)&Scaleform::GFx::AS2::GASImeCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::XmlNodeCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  Scaleform::GFx::AS2::AsBroadcaster::Initialize(
    a2,
    v3,
    (Scaleform::GFx::AS2::ASStringContext *)v3,
    &this->Scaleform::GFx::AS2::ObjectInterface);
  Scaleform::GFx::AS2::NameFunction::AddConstMembers(
    a2,
    v3,
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::AS2::ASStringContext *)v3,
    Scaleform::GFx::AS2::GASImeCtorFunction::StaticFunctionTable,
    7u,
    v13);
  v6 = 0;
  i = 0;
  if ( Scaleform::GFx::AS2::GASImeCtorFunction::GASNumberConstTable[0].Name )
  {
    v7 = Scaleform::GFx::AS2::GASImeCtorFunction::GASNumberConstTable;
    do
    {
      v8 = dword_86B1DC[v6];
      Name = (char *)v7->Name;
      v10 = *v3;
      LOBYTE(psc) = 7;
      v17.T.Type = 4;
      v17.NV.Int32Value = v8;
      pStringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager((Scaleform::GFx::AS2::GlobalContext *)v10)->pStringManager;
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(pStringManager, Name, strlen(Name), 0);
      ++ConstStringNode->RefCount;
      v5->SetMemberRaw(
        v5,
        (Scaleform::GFx::AS2::ASStringContext *)v3,
        (const Scaleform::GFx::ASString *)&ConstStringNode,
        &v17,
        (const Scaleform::GFx::AS2::PropFlags *)&psc);
      v12 = ConstStringNode;
      --ConstStringNode->RefCount;
      if ( !v12->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      Scaleform::GFx::AS2::Value::~Value(&v17);
      ++i;
      v6 = 2 * i;
      v7 = &Scaleform::GFx::AS2::GASImeCtorFunction::GASNumberConstTable[i];
    }
    while ( v7->Name );
  }
}
