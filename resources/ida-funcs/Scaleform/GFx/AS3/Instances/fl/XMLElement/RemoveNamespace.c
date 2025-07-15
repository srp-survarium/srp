Scaleform::GFx::AS3::Instances::fl::XMLElement *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::RemoveNamespace(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        const Scaleform::GFx::AS3::Value *ns)
{
  const Scaleform::GFx::AS3::Value *v2; // ebp
  Scaleform::GFx::AS3::Instances::fl::Namespace *VInt; // ebx
  Scaleform::GFx::AS3::Value::V1U v4; // eax
  Scaleform::GFx::AS3::VM *pVM; // edi
  const Scaleform::GFx::AS3::Value *Undefined; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *pV; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::GFx::AS3::Instances::fl::Namespace *v10; // eax
  int v11; // edi
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *pObject; // ecx
  int v13; // eax
  unsigned int v14; // edi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v15; // eax
  unsigned int i; // edi
  Scaleform::GFx::AS3::Instances::fl::XML *v17; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASString uri; // [esp+10h] [ebp-8h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> result; // [esp+14h] [ebp-4h] BYREF

  v2 = ns;
  VInt = 0;
  v4 = ns->value.VS._1;
  if ( (ns->Flags & 0x1F) == 0xB )
  {
    if ( v4.VInt )
    {
      *(_DWORD *)(v4.VInt + 16) = (*(_DWORD *)(v4.VInt + 16) + 1) & 0x8FBFFFFF;
      VInt = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v4.VInt;
    }
  }
  else
  {
    uri.pNode = ns->value.VS._1.VStr;
    ++*(_DWORD *)(v4.VInt + 12);
    pVM = this->pTraits.pObject->pVM;
    Undefined = Scaleform::GFx::AS3::Value::GetUndefined();
    pV = Scaleform::GFx::AS3::VM::MakeNamespace(pVM, &result, NS_Private, &uri, Undefined)->pV;
    if ( pV )
      VInt = pV;
    pNode = uri.pNode;
    --uri.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  v10 = this->GetNamespace(this);
  if ( v10->Uri.pNode != VInt->Uri.pNode || ((*((_BYTE *)VInt + 20) ^ *((_BYTE *)v10 + 20)) & 0xF) != 0 )
  {
    v11 = 0;
    if ( this->Attrs.Data.Size )
    {
      while ( 1 )
      {
        pObject = this->Attrs.Data.Data[v11].pObject;
        v13 = (int)pObject->GetNamespace(pObject);
        if ( *(Scaleform::GFx::ASStringNode **)(v13 + 28) == VInt->Uri.pNode
          && ((*((_BYTE *)VInt + 20) ^ *(_BYTE *)(v13 + 20)) & 0xF) == 0 )
        {
          break;
        }
        if ( ++v11 >= this->Attrs.Data.Size )
          goto LABEL_14;
      }
    }
    else
    {
LABEL_14:
      v14 = 0;
      if ( this->Namespaces.Data.Size )
      {
        while ( 1 )
        {
          v15 = this->Namespaces.Data.Data[v14].pObject;
          if ( v15->Uri.pNode == VInt->Uri.pNode
            && ((VInt->Prefix.Flags & 0x1F) == 0 || Scaleform::GFx::AS3::StrictEqual(&VInt->Prefix, &v15->Prefix)) )
          {
            break;
          }
          if ( ++v14 >= this->Namespaces.Data.Size )
            goto LABEL_21;
        }
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Namespaces,
          v14);
LABEL_21:
        v2 = ns;
      }
      for ( i = 0; i < this->Children.Data.Size; ++i )
      {
        v17 = this->Children.Data.Data[i].pObject;
        v17->RemoveNamespace(v17, v2);
      }
    }
  }
  if ( ((unsigned __int8)VInt & 1) == 0 )
  {
    RefCount = VInt->RefCount;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      VInt->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VInt);
    }
  }
  return this;
}
