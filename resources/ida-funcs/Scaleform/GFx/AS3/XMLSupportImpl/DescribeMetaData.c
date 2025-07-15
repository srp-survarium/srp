void __thiscall Scaleform::GFx::AS3::XMLSupportImpl::DescribeMetaData(
        Scaleform::GFx::AS3::XMLSupportImpl *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Instances::fl::XMLElement *xml,
        const Scaleform::GFx::AS3::VMAbcFile *file,
        const Scaleform::GFx::AS3::Abc::TraitInfo *ti)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v5; // eax
  unsigned int Size; // ebp
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // esi
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // edi
  Scaleform::GFx::AS3::Abc::MetadataInfo *v9; // eax
  __m128i *pStr; // ebp
  unsigned int v11; // ebx
  Scaleform::GFx::AS3::CheckResult *(__thiscall *AppendChild)(struct Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::AS3::CheckResult *, const Scaleform::GFx::AS3::Value *); // edx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  bool v15; // bl
  Scaleform::GFx::AS3::WeakProxy *v16; // eax
  Scaleform::GFx::AS3::Abc::MetadataInfo::Item *v17; // ebp
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::GFx::ASStringNode *v19; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v21; // eax
  Scaleform::GFx::ASStringNode *v22; // eax
  Scaleform::GFx::ASStringNode *v23; // eax
  Scaleform::GFx::ASStringNode *v24; // eax
  Scaleform::GFx::ASStringNode *v25; // ecx
  bool v26; // zf
  Scaleform::GFx::ASStringNode *v27; // eax
  Scaleform::GFx::ASStringNode *v28; // eax
  Scaleform::GFx::ASStringNode *v29; // eax
  Scaleform::GFx::ASStringNode *v30; // eax
  Scaleform::GFx::ASStringNode *v31; // eax
  bool v32; // [esp+Dh] [ebp-77h]
  char v33; // [esp+Eh] [ebp-76h] BYREF
  char v34; // [esp+Fh] [ebp-75h] BYREF
  Scaleform::GFx::ASString _value; // [esp+10h] [ebp-74h] BYREF
  Scaleform::GFx::ASString _key; // [esp+14h] [ebp-70h] BYREF
  Scaleform::GFx::ASString _arg; // [esp+18h] [ebp-6Ch] BYREF
  Scaleform::GFx::ASString _metadata; // [esp+1Ch] [ebp-68h] BYREF
  Scaleform::GFx::ASString _name; // [esp+20h] [ebp-64h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> metadata; // [esp+24h] [ebp-60h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> arg; // [esp+28h] [ebp-5Ch] BYREF
  unsigned int j; // [esp+2Ch] [ebp-58h]
  unsigned int k; // [esp+30h] [ebp-54h]
  Scaleform::GFx::ASString v; // [esp+34h] [ebp-50h] BYREF
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *xml_itr; // [esp+38h] [ebp-4Ch]
  const Scaleform::GFx::AS3::Abc::MetadataInfo *mdi; // [esp+3Ch] [ebp-48h]
  Scaleform::GFx::ASString v47; // [esp+40h] [ebp-44h] BYREF
  const Scaleform::GFx::AS3::Abc::ConstPool *cp; // [esp+44h] [ebp-40h]
  Scaleform::GFx::ASString v49; // [esp+48h] [ebp-3Ch] BYREF
  unsigned int isize; // [esp+4Ch] [ebp-38h]
  unsigned int msize; // [esp+50h] [ebp-34h]
  Scaleform::StringDataPtr result; // [esp+54h] [ebp-30h] BYREF
  Scaleform::StringDataPtr v53; // [esp+5Ch] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Value v54; // [esp+64h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value v55; // [esp+74h] [ebp-10h] BYREF

  if ( (ti->kind & 0x40) != 0 )
  {
    v5 = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)this->GetITraitsXML(this);
    Size = ti->meta_info.info.Data.Size;
    xml_itr = v5;
    pObject = vm->PublicNamespace.pObject;
    StringManagerRef = vm->StringManagerRef;
    msize = Size;
    if ( Size )
    {
      _name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      StringManagerRef->pStringManager,
                      "name",
                      4u,
                      0);
      ++_name.pNode->RefCount;
      _metadata.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                          StringManagerRef->pStringManager,
                          "metadata",
                          8u,
                          0);
      ++_metadata.pNode->RefCount;
      _arg.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                     StringManagerRef->pStringManager,
                     "arg",
                     3u,
                     0);
      ++_arg.pNode->RefCount;
      _key.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                     StringManagerRef->pStringManager,
                     "key",
                     3u,
                     0);
      ++_key.pNode->RefCount;
      _value.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                       StringManagerRef->pStringManager,
                       "value",
                       5u,
                       0);
      ++_value.pNode->RefCount;
      cp = &file->File.pObject->Const_Pool;
      k = 0;
      while ( 1 )
      {
        v9 = file->File.pObject->Metadata.Info.Data.Data[ti->meta_info.info.Data.Data[k]];
        pStr = (__m128i *)v9->Name.pStr;
        v11 = v9->Name.Size;
        mdi = v9;
        Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
          xml_itr,
          &metadata,
          xml_itr,
          pObject,
          &_metadata,
          0);
        AppendChild = xml->AppendChild;
        *(_QWORD *)&v54.value.VNumber = __PAIR64__(v53.Size, (unsigned int)metadata.pV);
        v54.Bonus.pWeakProxy = 0;
        v54.Flags = 12;
        v32 = !AppendChild(xml, (Scaleform::GFx::AS3::CheckResult *)&v33, &v54)->Result;
        if ( (v54.Flags & 0x1F) > 9 )
        {
          if ( (v54.Flags & 0x200) != 0 )
          {
            pWeakProxy = v54.Bonus.pWeakProxy;
            --v54.Bonus.pWeakProxy->RefCount;
            if ( !pWeakProxy->RefCount )
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
            memset(&v54.Bonus, 0, 12);
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v54);
          }
        }
        if ( v32 )
        {
LABEL_28:
          pNode = _value.pNode;
          --_value.pNode->RefCount;
          if ( !pNode->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
          v21 = _key.pNode;
          --_key.pNode->RefCount;
          if ( !v21->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v21);
          v22 = _arg.pNode;
          --_arg.pNode->RefCount;
          if ( !v22->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v22);
          v23 = _metadata.pNode;
          --_metadata.pNode->RefCount;
          if ( !v23->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v23);
          v24 = _name.pNode;
          --_name.pNode->RefCount;
          v25 = v24;
          v26 = v24->RefCount == 0;
          goto LABEL_37;
        }
        v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManagerRef->pStringManager, pStr, v11);
        ++v.pNode->RefCount;
        Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(metadata.pV, pObject, &_name, &v);
        v14 = v.pNode;
        --v.pNode->RefCount;
        if ( !v14->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v14);
        isize = mdi->Items.Data.Size;
        j = 0;
        if ( isize )
          break;
LABEL_27:
        if ( ++k >= msize )
          goto LABEL_28;
      }
      while ( 1 )
      {
        Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(xml_itr, &arg, xml_itr, pObject, &_arg, 0);
        *(_QWORD *)&v55.value.VNumber = __PAIR64__(v53.Size, (unsigned int)arg.pV);
        v55.Bonus.pWeakProxy = 0;
        v55.Flags = 12;
        v15 = !metadata.pV->AppendChild(metadata.pV, &v34, &v55)->Result;
        if ( (v55.Flags & 0x1F) > 9 )
        {
          if ( (v55.Flags & 0x200) != 0 )
          {
            v16 = v55.Bonus.pWeakProxy;
            --v55.Bonus.pWeakProxy->RefCount;
            if ( !v16->RefCount )
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v16);
            memset(&v55.Bonus, 0, 12);
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v55);
          }
        }
        if ( v15 )
          break;
        v17 = &mdi->Items.Data.Data[j];
        if ( v17->KeyInd > 0 )
        {
          Scaleform::GFx::AS3::Abc::StringView::ToStringDataPtr(&cp->ConstStr.Data.Data[v17->KeyInd], &result);
          v47.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                        StringManagerRef->pStringManager,
                        (__m128i *)result.pStr,
                        result.Size);
          ++v47.pNode->RefCount;
          Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(arg.pV, pObject, &_key, &v47);
          v18 = v47.pNode;
          --v47.pNode->RefCount;
          if ( !v18->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v18);
        }
        Scaleform::GFx::AS3::Abc::StringView::ToStringDataPtr(&cp->ConstStr.Data.Data[v17->ValueInd], &v53);
        v49.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                      StringManagerRef->pStringManager,
                      (__m128i *)v53.pStr,
                      v53.Size);
        ++v49.pNode->RefCount;
        Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(arg.pV, pObject, &_value, &v49);
        v19 = v49.pNode;
        --v49.pNode->RefCount;
        if ( !v19->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v19);
        if ( ++j >= isize )
          goto LABEL_27;
      }
      v27 = _value.pNode;
      --_value.pNode->RefCount;
      if ( !v27->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v27);
      v28 = _key.pNode;
      --_key.pNode->RefCount;
      if ( !v28->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v28);
      v29 = _arg.pNode;
      --_arg.pNode->RefCount;
      if ( !v29->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v29);
      v30 = _metadata.pNode;
      --_metadata.pNode->RefCount;
      if ( !v30->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v30);
      v31 = _name.pNode;
      --_name.pNode->RefCount;
      v25 = v31;
      v26 = v31->RefCount == 0;
LABEL_37:
      if ( v26 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v25);
    }
  }
}
