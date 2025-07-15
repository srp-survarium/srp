void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::AddInScopeNamespace(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        const Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  Scaleform::GFx::ASStringNode *VStr; // esi
  char v4; // bl
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // ecx
  bool v6; // zf
  unsigned int Size; // ebx
  unsigned int v8; // edi
  unsigned int v9; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *pV; // ebx
  unsigned int v11; // eax
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *p_Namespaces; // edi
  unsigned int v13; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *Data; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v15; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // esi
  const Scaleform::GFx::AS3::Value *Undefined; // eax
  unsigned int v18; // edi
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v19; // ecx
  Scaleform::GFx::AS3::Value *p_Prefix; // esi
  const Scaleform::GFx::AS3::Value *v21; // eax
  unsigned int RefCount; // eax
  const Scaleform::GFx::AS3::Value *x; // [esp+4h] [ebp-10h]
  Scaleform::GFx::ASStringNode *nsCopy; // [esp+8h] [ebp-Ch]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> result; // [esp+10h] [ebp-4h] BYREF
  unsigned int sizea; // [esp+18h] [ebp+4h]

  x = &ns->Prefix;
  if ( (ns->Prefix.Flags & 0x1F) != 0 )
  {
    if ( (ns->Prefix.Flags & 0x1F) == 0xA )
    {
      VStr = ns->Prefix.value.VS._1.VStr;
      v4 = 1;
      ++VStr->RefCount;
      nsCopy = VStr;
      p_EmptyStringNode = VStr;
    }
    else
    {
      p_EmptyStringNode = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
      ++p_EmptyStringNode->RefCount;
      nsCopy = p_EmptyStringNode;
      VStr = p_EmptyStringNode;
      v4 = 2;
    }
    ++nsCopy->RefCount;
    if ( (v4 & 2) != 0 )
    {
      v4 &= ~2u;
      v6 = p_EmptyStringNode->RefCount-- == 1;
      if ( v6 )
        Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
    }
    if ( (v4 & 1) != 0 )
    {
      v6 = VStr->RefCount-- == 1;
      if ( v6 )
        Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
    }
    if ( nsCopy->Size || this->Ns.pObject->Uri.pNode->Size )
    {
      Size = this->Namespaces.Data.Size;
      v8 = -1;
      v9 = 0;
      if ( Size )
      {
        while ( !Scaleform::GFx::AS3::StrictEqual(x, &this->Namespaces.Data.Data[v9].pObject->Prefix) )
        {
          if ( ++v9 >= Size )
            goto LABEL_20;
        }
        v8 = v9;
      }
LABEL_20:
      pV = Scaleform::GFx::AS3::VM::MakeNamespace(this->pTraits.pObject->pVM, &result, NS_Public, &ns->Uri, x)->pV;
      if ( v8 != -1 && this->Namespaces.Data.Data[v8].pObject->Uri.pNode != ns->Uri.pNode )
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Namespaces,
          v8);
      v11 = this->Namespaces.Data.Size;
      p_Namespaces = &this->Namespaces;
      v13 = v11 + 1;
      if ( v11 + 1 >= v11 )
      {
        if ( v13 >= this->Namespaces.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)p_Namespaces,
            p_Namespaces,
            v13 + (v13 >> 2));
      }
      else
      {
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)&p_Namespaces->Data.Data[v11 + 1],
          0xFFFFFFFF);
        if ( v13 < this->Namespaces.Data.Policy.Capacity >> 1 )
          Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)p_Namespaces,
            p_Namespaces,
            v13);
      }
      Data = p_Namespaces->Data.Data;
      this->Namespaces.Data.Size = v13;
      v15 = &Data[v13 - 1];
      if ( v15 )
      {
        v15->pObject = pV;
        if ( pV )
          pV->RefCount = (pV->RefCount + 1) & 0x8FBFFFFF;
      }
      if ( Scaleform::GFx::AS3::StrictEqual(&this->Ns.pObject->Prefix, x) )
      {
        pObject = this->Ns.pObject;
        Undefined = Scaleform::GFx::AS3::Value::GetUndefined();
        Scaleform::GFx::AS3::Value::Assign(&pObject->Prefix, Undefined);
      }
      v18 = 0;
      sizea = this->Attrs.Data.Size;
      if ( sizea )
      {
        do
        {
          v19 = this->Attrs.Data.Data[v18].pObject;
          p_Prefix = &v19->GetCurrNamespace(v19)->Prefix;
          if ( Scaleform::GFx::AS3::StrictEqual(p_Prefix, x) )
          {
            v21 = Scaleform::GFx::AS3::Value::GetUndefined();
            Scaleform::GFx::AS3::Value::Assign(p_Prefix, v21);
          }
          ++v18;
        }
        while ( v18 < sizea );
      }
      if ( pV )
      {
        if ( ((unsigned __int8)pV & 1) == 0 )
        {
          RefCount = pV->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            pV->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
          }
        }
      }
      v6 = nsCopy->RefCount-- == 1;
      if ( v6 )
        Scaleform::GFx::ASStringNode::ReleaseNode(nsCopy);
    }
    else
    {
      v6 = nsCopy->RefCount-- == 1;
      if ( v6 )
        Scaleform::GFx::ASStringNode::ReleaseNode(nsCopy);
    }
  }
}
