void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM *pVM; // edi
  unsigned int VUInt; // esi
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v6; // ebx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v8; // ecx
  bool v9; // zf
  const char *pData; // eax
  Scaleform::GFx::AS3::XMLSupport *pObject; // ecx
  Scaleform::GFx::AS3::Traits *v12; // eax
  char v13; // cl
  unsigned int Size; // eax
  char v15; // al
  int v16; // ecx
  int Char; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  bool iw; // [esp+Eh] [ebp-5Ah] BYREF
  Scaleform::GFx::ASString str; // [esp+10h] [ebp-58h] BYREF
  unsigned int pos; // [esp+14h] [ebp-54h] BYREF
  Scaleform::GFx::AS3::Instances::fl::XMLList *v22; // [esp+18h] [ebp-50h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> result; // [esp+1Ch] [ebp-4Ch] BYREF
  Scaleform::StringDataPtr s; // [esp+20h] [ebp-48h] BYREF
  Scaleform::StringDataPtr txt; // [esp+28h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::XMLParser parser; // [esp+30h] [ebp-38h] BYREF

  pVM = this->pTraits.pObject->pVM;
  v22 = this;
  if ( argc && (argv->Flags & 0x1F) != 0 && ((argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt) && argc == 1 )
  {
    if ( Scaleform::GFx::AS3::IsXMLObject(argv) )
    {
      VUInt = argv->value.VS._1.VUInt;
      pos = VUInt;
      if ( VUInt )
        *(_DWORD *)(VUInt + 16) = (*(_DWORD *)(VUInt + 16) + 1) & 0x8FBFFFFF;
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> > *)&this->List,
        (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *)&pos);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&pos);
    }
    else
    {
      v6 = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)pVM->XMLSupport_.pObject->GetITraitsXML(pVM->XMLSupport_.pObject);
      str.pNode = &pVM->StringManagerRef->pStringManager->EmptyStringNode;
      ++str.pNode->RefCount;
      v9 = !Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&iw, &str)->Result;
      pNode = str.pNode;
      if ( v9 )
      {
        --str.pNode->RefCount;
        v8 = pNode;
        v9 = pNode->RefCount == 0;
      }
      else
      {
        pData = str.pNode->pData;
        s.Size = str.pNode->Size;
        pObject = pVM->XMLSupport_.pObject;
        s.pStr = pData;
        v12 = pObject->GetITraitsXML(pObject);
        v13 = BYTE2(Scaleform::GFx::AS3::Traits::GetConstructor(v12)[1].__vftable);
        Size = s.Size;
        iw = v13;
        while ( Size )
        {
          v15 = *Scaleform::GFx::ASUtils::SkipWhiteSpace(s.pStr, Size);
          if ( v15 == 59 )
          {
            v16 = s.Size != 0;
            s.pStr += v16;
            Size = s.Size - v16;
            s.Size -= v16;
          }
          else
          {
            if ( v15 == 60 )
            {
              pos = 0;
              Scaleform::GFx::AS3::XMLParser::XMLParser(&parser, v6);
            }
            txt.pStr = 0;
            txt.Size = 0;
            Char = Scaleform::StringDataPtr::FindChar(&s, 60, 0);
            txt.pStr = s.pStr;
            if ( Char == -1 )
              Char = s.Size;
            txt.Size = Char;
            Scaleform::StringDataPtr::TrimLeft(&s, Char);
            if ( iw )
              Scaleform::StringDataPtr::TruncateWhitespace(&txt);
            pos = (unsigned int)Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(v6, &result, v6, &txt, 0)->pV;
            Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
              (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> > *)&v22->List,
              (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *)&pos);
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&pos);
            Size = s.Size;
          }
        }
        v18 = str.pNode;
        --str.pNode->RefCount;
        v8 = v18;
        v9 = v18->RefCount == 0;
      }
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    }
  }
}
