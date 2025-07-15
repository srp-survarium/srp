void __userpurge Scaleform::GFx::AS2::SharedObject::Flush_::_4_::DataWriter::Visit(
        Scaleform::GFx::AS2::SharedObject::Flush::__l4::DataWriter *this@<ecx>,
        int a2@<edi>,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        unsigned __int8 flags)
{
  long double v; // st7
  const Scaleform::GFx::AS3::Instances::fl::Namespace *CurrNamespace; // eax
  Scaleform::GFx::ASStringNode *v8; // edi
  bool v9; // zf
  const __m128i *v10; // eax
  int v11; // eax
  Scaleform::GFx::SharedObjectVisitor_vtbl *v12; // edx
  Scaleform::GFx::AS2::Environment *pEnv; // edx
  void (__thiscall *v14)(volatile int *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::SharedObject::Flush::__l4::DataWriter *, _DWORD); // eax
  void (*PopArray)(void); // eax
  Scaleform::GFx::AS2::Environment *v16; // edx
  void (__thiscall *v17)(volatile int *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::SharedObject::Flush::__l4::DataWriter *, _DWORD); // eax
  void *v18; // esi
  Scaleform::String v19; // [esp+10h] [ebp-1A0h] BYREF
  Scaleform::String v20; // [esp+14h] [ebp-19Ch] BYREF
  Scaleform::String v21; // [esp+18h] [ebp-198h] BYREF
  Scaleform::String v22; // [esp+1Ch] [ebp-194h] BYREF
  Scaleform::String v23; // [esp+20h] [ebp-190h] BYREF
  Scaleform::GFx::ASStringNode *v24; // [esp+24h] [ebp-18Ch] BYREF
  Scaleform::DoubleFormatter v25; // [esp+28h] [ebp-188h] BYREF

  Scaleform::String::String(&v20, (const __m128i *)name->pNode->pData, name->pNode->Size);
  switch ( val->T.Type )
  {
    case 0u:
      Scaleform::String::String(&v23, (const __m128i *)uri);
      this->pWriter->AddProperty(this->pWriter, &v20, &v23, VT_Undefined);
      Scaleform::String::~String(&v23);
      break;
    case 1u:
      Scaleform::String::String(&v22, (const __m128i *)uri);
      this->pWriter->AddProperty(this->pWriter, &v20, &v22, VT_Null);
      Scaleform::String::~String(&v22);
      break;
    case 2u:
      v9 = !Scaleform::GFx::AS2::Value::ToBool(val, a2, this->pEnv);
      v10 = (const __m128i *)"true";
      if ( v9 )
        v10 = (const __m128i *)"false";
      Scaleform::String::String(&v21, v10);
      this->pWriter->AddProperty(this->pWriter, &v20, &v21, VT_Boolean);
      Scaleform::String::~String(&v21);
      break;
    case 3u:
    case 4u:
      v = Scaleform::GFx::AS2::Value::ToNumber(val, this->pEnv);
      Scaleform::DoubleFormatter::DoubleFormatter(&v25, v);
      Scaleform::DoubleFormatter::Convert(&v25);
      CurrNamespace = Scaleform::GFx::AS3::Instances::fl::XMLElement::GetCurrNamespace((Scaleform::GFx::AS3::Instances::fl::XMLAttr *)&v25);
      Scaleform::String::String(&v19, &v25.Scaleform::String::InitStruct, (unsigned int)CurrNamespace);
      this->pWriter->AddProperty(this->pWriter, &v20, &v19, VT_Number);
      Scaleform::String::~String(&v19);
      v25.Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
      Scaleform::Formatter::~Formatter(&v25);
      break;
    case 5u:
      Scaleform::GFx::AS2::Value::ToStringImpl(val, (Scaleform::GFx::ASString *)&v24, this->pEnv, -1, 0);
      v8 = v24;
      Scaleform::String::String(&v19, (const __m128i *)v24->pData);
      v9 = v8->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
      this->pWriter->AddProperty(this->pWriter, &v20, &v19, VT_String);
      Scaleform::String::~String(&v19);
      break;
    case 6u:
      v19.pData = (Scaleform::String::DataDesc *)Scaleform::GFx::AS2::Value::ToObject(val, this->pEnv);
      if ( !Scaleform::Hash<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Object *,2>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF>>>::Get(
              (Scaleform::Hash<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeHashF> > > *)&this->VisitedObjects,
              (Scaleform::GFx::AS3::Instances::fl::Object *const *)&v19) )
      {
        Scaleform::Hash<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>>::NodeHashF>>>::Add(
          (Scaleform::Hash<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeHashF> > > *)&this->VisitedObjects,
          (Scaleform::GFx::AS3::Instances::fl::Object *const *)&v19,
          (Scaleform::GFx::AS3::Instances::fl::Object *const *)&v19);
        v11 = (*(int (__thiscall **)(volatile int *, int))(v19.pData[1].RefCount + 8))(&v19.pData[1].RefCount, a2);
        v12 = this->pWriter->__vftable;
        if ( v11 == 7 )
        {
          ((void (__stdcall *)(Scaleform::String *, Scaleform::String::DataDesc *, Scaleform::String::DataDesc *))v12->PushArray)(
            &v22,
            v19.pData,
            v20.pData);
          pEnv = this->pEnv;
          v14 = *(void (__thiscall **)(volatile int *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::SharedObject::Flush::__l4::DataWriter *, _DWORD))(v23.pData[1].RefCount + 32);
          v20.pData = 0;
          v14(&v23.pData[1].RefCount, &pEnv->StringContext, this, 0);
          PopArray = (void (*)(void))this->pWriter->PopArray;
        }
        else
        {
          ((void (__stdcall *)(Scaleform::String *, Scaleform::String::DataDesc *, Scaleform::String::DataDesc *))v12->PushObject)(
            &v22,
            v19.pData,
            v20.pData);
          v16 = this->pEnv;
          v17 = *(void (__thiscall **)(volatile int *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::SharedObject::Flush::__l4::DataWriter *, _DWORD))(v23.pData[1].RefCount + 32);
          v20.pData = 0;
          v17(&v23.pData[1].RefCount, &v16->StringContext, this, 0);
          PopArray = (void (*)(void))this->pWriter->PopObject;
        }
        PopArray();
      }
      break;
    default:
      break;
  }
  v18 = (void *)(v20.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v20.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v18);
}
