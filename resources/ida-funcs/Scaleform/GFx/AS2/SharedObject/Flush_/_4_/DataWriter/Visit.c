void __userpurge Scaleform::GFx::AS2::SharedObject::Flush_::_4_::DataWriter::Visit(
        Scaleform::GFx::AS2::SharedObject::Flush::__l4::DataWriter *this@<ecx>,
        int a2@<edi>,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        unsigned __int8 flags)
{
  long double v; // st7
  const Scaleform::GFx::AS3::Instances::fl::Namespace *CurrNamespace; // eax
  Scaleform::GFx::ASStringNode *pNode; // edi
  bool v9; // zf
  char *v10; // eax
  int v11; // eax
  Scaleform::GFx::SharedObjectVisitor_vtbl *v12; // edx
  Scaleform::GFx::AS2::Environment *pEnv; // edx
  void (__thiscall *v14)(volatile int *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::SharedObject::Flush::__l4::DataWriter *, _DWORD); // eax
  void (*PopArray)(void); // eax
  Scaleform::GFx::AS2::Environment *v16; // edx
  void (__thiscall *v17)(volatile int *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::SharedObject::Flush::__l4::DataWriter *, _DWORD); // eax
  void *v18; // esi
  Scaleform::GFx::AS2::Object *pobj; // [esp+10h] [ebp-1A0h] BYREF
  Scaleform::String propname; // [esp+14h] [ebp-19Ch] BYREF
  Scaleform::String v21; // [esp+18h] [ebp-198h] BYREF
  Scaleform::String v22; // [esp+1Ch] [ebp-194h] BYREF
  Scaleform::String v23; // [esp+20h] [ebp-190h] BYREF
  Scaleform::GFx::ASString result; // [esp+24h] [ebp-18Ch] BYREF
  Scaleform::DoubleFormatter f; // [esp+28h] [ebp-188h] BYREF

  Scaleform::String::String(&propname, (char *)name->pNode->pData, name->pNode->Size);
  switch ( val->T.Type )
  {
    case 0u:
      Scaleform::String::String(&v23, (char *)&buf);
      this->pWriter->AddProperty(this->pWriter, &propname, &v23, VT_Undefined);
      Scaleform::String::~String(&v23);
      break;
    case 1u:
      Scaleform::String::String(&v22, (char *)&buf);
      this->pWriter->AddProperty(this->pWriter, &propname, &v22, VT_Null);
      Scaleform::String::~String(&v22);
      break;
    case 2u:
      v9 = Scaleform::GFx::AS2::Value::ToBool(val, this->pEnv) == 0;
      v10 = (char *)&stru_95AF78.m_key_bindings[4].m_keyboard[1];
      if ( v9 )
        v10 = (char *)&stru_95AF78.m_key_bindings[6];
      Scaleform::String::String(&v21, v10);
      this->pWriter->AddProperty(this->pWriter, &propname, &v21, VT_Boolean);
      Scaleform::String::~String(&v21);
      break;
    case 3u:
    case 4u:
      v = Scaleform::GFx::AS2::Value::ToNumber(val, this->pEnv);
      Scaleform::DoubleFormatter::DoubleFormatter(&f, v);
      Scaleform::DoubleFormatter::Convert(&f);
      CurrNamespace = Scaleform::GFx::AS3::Instances::fl::XMLElement::GetCurrNamespace((Scaleform::GFx::AS3::Instances::fl::XMLAttr *)&f);
      Scaleform::String::String(
        (Scaleform::String *)&pobj,
        &f.Scaleform::String::InitStruct,
        (unsigned int)CurrNamespace);
      this->pWriter->AddProperty(this->pWriter, &propname, (const Scaleform::String *)&pobj, VT_Number);
      Scaleform::String::~String((Scaleform::String *)&pobj);
      f.Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
      Scaleform::Formatter::~Formatter(&f);
      break;
    case 5u:
      Scaleform::GFx::AS2::Value::ToStringImpl(val, &result, this->pEnv, -1, 0);
      pNode = result.pNode;
      Scaleform::String::String((Scaleform::String *)&pobj, (char *)result.pNode->pData);
      v9 = pNode->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      this->pWriter->AddProperty(this->pWriter, &propname, (const Scaleform::String *)&pobj, VT_String);
      Scaleform::String::~String((Scaleform::String *)&pobj);
      break;
    case 6u:
      pobj = Scaleform::GFx::AS2::Value::ToObject(val, this->pEnv);
      if ( !Scaleform::Hash<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Object *,2>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF>>>::Get(
              (Scaleform::Hash<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeHashF> > > *)&this->VisitedObjects,
              (Scaleform::GFx::AS3::Instances::fl::Object *const *)&pobj) )
      {
        Scaleform::Hash<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>>::NodeHashF>>>::Add(
          (Scaleform::Hash<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeHashF> > > *)&this->VisitedObjects,
          (Scaleform::GFx::AS3::Instances::fl::Object *const *)&pobj,
          (Scaleform::GFx::AS3::Instances::fl::Object *const *)&pobj);
        v11 = ((int (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, int))pobj->GetObjectType)(
                &pobj->Scaleform::GFx::AS2::ObjectInterface,
                a2);
        v12 = this->pWriter->__vftable;
        if ( v11 == 7 )
        {
          ((void (__stdcall *)(Scaleform::String *, Scaleform::GFx::AS2::Object *, Scaleform::String::DataDesc *))v12->PushArray)(
            &v22,
            pobj,
            propname.pData);
          pEnv = this->pEnv;
          v14 = *(void (__thiscall **)(volatile int *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::SharedObject::Flush::__l4::DataWriter *, _DWORD))(v23.pData[1].RefCount + 32);
          propname.pData = 0;
          v14(&v23.pData[1].RefCount, &pEnv->StringContext, this, 0);
          PopArray = (void (*)(void))this->pWriter->PopArray;
        }
        else
        {
          ((void (__stdcall *)(Scaleform::String *, Scaleform::GFx::AS2::Object *, Scaleform::String::DataDesc *))v12->PushObject)(
            &v22,
            pobj,
            propname.pData);
          v16 = this->pEnv;
          v17 = *(void (__thiscall **)(volatile int *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::SharedObject::Flush::__l4::DataWriter *, _DWORD))(v23.pData[1].RefCount + 32);
          propname.pData = 0;
          v17(&v23.pData[1].RefCount, &v16->StringContext, this, 0);
          PopArray = (void (*)(void))this->pWriter->PopObject;
        }
        PopArray();
      }
      break;
    default:
      break;
  }
  v18 = (void *)(propname.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((propname.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v18);
}
