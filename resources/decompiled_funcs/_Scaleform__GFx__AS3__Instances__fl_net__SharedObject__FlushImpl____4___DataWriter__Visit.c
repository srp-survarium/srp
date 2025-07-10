void __thiscall Scaleform::GFx::AS3::Instances::fl_net::SharedObject::FlushImpl_::_4_::DataWriter::Visit(
        Scaleform::GFx::AS3::Instances::fl_net::SharedObject::FlushImpl::__l4::DataWriter *this,
        const Scaleform::String *name,
        const Scaleform::GFx::AS3::Value *val)
{
  const Scaleform::GFx::AS3::Instances::fl::Namespace *CurrNamespace; // eax
  unsigned int Size; // eax
  Scaleform::GFx::ASStringNode *VStr; // edi
  char *v8; // eax
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::Instances::fl_net::SharedObject::FlushImpl::__l4::DataWriter *v10; // ecx
  Scaleform::GFx::AS3::Instances::fl::Object *pobj; // [esp+Ch] [ebp-1E8h] BYREF
  Scaleform::String v12; // [esp+10h] [ebp-1E4h] BYREF
  Scaleform::String v13; // [esp+14h] [ebp-1E0h] BYREF
  Scaleform::String v14; // [esp+18h] [ebp-1DCh] BYREF
  Scaleform::LongFormatter v15; // [esp+1Ch] [ebp-1D8h] BYREF
  Scaleform::DoubleFormatter f; // [esp+6Ch] [ebp-188h] BYREF

  switch ( val->Flags & 0x1F )
  {
    case 0u:
      Scaleform::String::String(&v14, (char *)&buf);
      this->pWriter->AddProperty(this->pWriter, name, &v14, VT_Undefined);
      Scaleform::String::~String(&v14);
      break;
    case 1u:
      v8 = (char *)&stru_95AF78.m_key_bindings[4].m_keyboard[1];
      if ( !val->value.VS._1.VBool )
        v8 = (char *)&stru_95AF78.m_key_bindings[6];
      Scaleform::String::String(&v12, v8);
      this->pWriter->AddProperty(this->pWriter, name, &v12, VT_Boolean);
      Scaleform::String::~String(&v12);
      break;
    case 2u:
    case 3u:
      Scaleform::LongFormatter::LongFormatter(&v15, val->value.VS._1.VInt);
      Scaleform::LongFormatter::Convert(&v15);
      Size = Scaleform::LongFormatter::GetSize(&v15);
      Scaleform::String::String((Scaleform::String *)&pobj, &v15.Scaleform::String::InitStruct, Size);
      this->pWriter->AddProperty(this->pWriter, name, (const Scaleform::String *)&pobj, VT_Int);
      Scaleform::String::~String((Scaleform::String *)&pobj);
      v15.Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
      Scaleform::Formatter::~Formatter(&v15);
      break;
    case 4u:
      Scaleform::DoubleFormatter::DoubleFormatter(&f, val->value.VNumber);
      Scaleform::DoubleFormatter::Convert(&f);
      CurrNamespace = Scaleform::GFx::AS3::Instances::fl::XMLElement::GetCurrNamespace((Scaleform::GFx::AS3::Instances::fl::XMLAttr *)&f);
      Scaleform::String::String(
        (Scaleform::String *)&pobj,
        &f.Scaleform::String::InitStruct,
        (unsigned int)CurrNamespace);
      this->pWriter->AddProperty(this->pWriter, name, (const Scaleform::String *)&pobj, VT_Number);
      Scaleform::String::~String((Scaleform::String *)&pobj);
      f.Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
      Scaleform::Formatter::~Formatter(&f);
      break;
    case 0xAu:
      VStr = val->value.VS._1.VStr;
      ++VStr->RefCount;
      Scaleform::String::String((Scaleform::String *)&pobj, (char *)VStr->pData);
      if ( VStr->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
      this->pWriter->AddProperty(this->pWriter, name, (const Scaleform::String *)&pobj, VT_String);
      Scaleform::String::~String((Scaleform::String *)&pobj);
      break;
    case 0xCu:
      if ( val->value.VS._1.VInt )
      {
        pobj = val->value.VS._1.VFunct;
        if ( !Scaleform::Hash<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Object *,2>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF>>>::Get(
                &this->VisitedObjects,
                &pobj) )
        {
          Scaleform::Hash<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *>>::NodeHashF>>>::Add(
            &this->VisitedObjects,
            &pobj,
            &pobj);
          pObject = pobj->pTraits.pObject;
          if ( pObject->TraitsType != Traits_Array || (pObject->Flags & 0x20) != 0 )
          {
            this->pWriter->PushObject(this->pWriter, name);
            Scaleform::GFx::AS3::Instances::fl_net::SharedObject::FlushImpl_::_4_::DataWriter::VisitMembers(
              v10,
              this,
              pobj);
            this->pWriter->PopObject(this->pWriter);
          }
          else
          {
            this->pWriter->PushArray(this->pWriter, name);
            Scaleform::GFx::AS3::Instances::fl_net::SharedObject::FlushImpl_::_4_::DataWriter::VisitMembers(
              (Scaleform::GFx::AS3::Instances::fl_net::SharedObject::FlushImpl::__l4::DataWriter *)pobj,
              this,
              pobj);
            this->pWriter->PopArray(this->pWriter);
          }
        }
      }
      else
      {
        Scaleform::String::String(&v13, (char *)&buf);
        this->pWriter->AddProperty(this->pWriter, name, &v13, VT_Null);
        Scaleform::String::~String(&v13);
      }
      break;
    default:
      return;
  }
}
