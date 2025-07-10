bool __thiscall Scaleform::GFx::AS3::Instances::fl::XML::Matches(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SoundObject *prop_name)
{
  bool v4; // al
  Scaleform::GFx::ASStringNode *Pan; // ebp
  unsigned __int32 v6; // eax
  int Namespace; // eax
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // edx
  int p_Uri; // ecx
  Scaleform::GFx::ASStringNode **v11; // edi
  Scaleform::GFx::AS3::VM *v12; // ebp
  const Scaleform::GFx::AS3::Instances::fl::Namespace *v13; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v14; // ebx
  Scaleform::GFx::AS3::GASRefCountBase *RefCount; // edi
  Scaleform::GFx::AS3::RefCountCollector<328> *pRCC; // edx
  int *v17; // edi
  unsigned int v18; // ecx
  int v19; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  bool result; // [esp+Bh] [ebp-1h]
  Scaleform::GFx::ASString name; // [esp+10h] [ebp+4h]

  v4 = 0;
  result = 0;
  if ( ((int)prop_name->Scaleform::GFx::ASSoundIntf::__vftable & 0x1F) != 0xA )
    return v4;
  Pan = (Scaleform::GFx::ASStringNode *)prop_name->Pan;
  ++Pan->RefCount;
  name.pNode = Pan;
  if ( this->GetName(this)->pNode == Pan
    || Scaleform::GFx::AS3::Multiname::IsAnyType((Scaleform::GFx::AS3::Multiname *)prop_name) )
  {
    v6 = (int)prop_name->Scaleform::RefCountBase<Scaleform::GFx::AS3::SoundObject,323>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable
       & 3;
    if ( v6 <= 1 )
    {
      if ( prop_name->RefCount )
      {
        Namespace = Scaleform::GFx::AS3::Multiname::GetNamespace(prop_name);
        pVM = this->pTraits.pObject->pVM;
        pObject = pVM->DefXMLNamespace.pObject;
        if ( pObject )
          p_Uri = (int)&pObject->Uri;
        else
          p_Uri = (int)&pVM->PublicNamespace.pObject->Uri;
        if ( (*(_BYTE *)(Namespace + 20) & 0xF) == 0
          && (((int)prop_name->Scaleform::RefCountBase<Scaleform::GFx::AS3::SoundObject,323>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable
             & 8) != 0
           || *(_DWORD *)(*(_DWORD *)(Namespace + 28) + 20)) )
        {
          v11 = (Scaleform::GFx::ASStringNode **)(Namespace + 28);
        }
        else
        {
          v11 = (Scaleform::GFx::ASStringNode **)p_Uri;
        }
        if ( *v11 == this->GetNamespace(this)->Uri.pNode )
          result = 1;
      }
      else
      {
        result = 1;
      }
      goto LABEL_34;
    }
    if ( Scaleform::GFx::AS3::Multiname::IsAnyType((Scaleform::GFx::AS3::Multiname *)prop_name) )
    {
      result = 1;
      goto LABEL_34;
    }
    v12 = this->pTraits.pObject->pVM;
    v13 = this->GetNamespace(this);
    if ( ((int)prop_name->Scaleform::RefCountBase<Scaleform::GFx::AS3::SoundObject,323>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable
        & 8) != 0
      || (v14 = v12->DefXMLNamespace.pObject) == 0 )
    {
      v14 = v12->PublicNamespace.pObject;
    }
    if ( Scaleform::GFx::AS3::Multiname::ContainsNamespace(
           (Scaleform::GFx::AS3::Multiname *)prop_name,
           v12->PublicNamespace.pObject) )
    {
      RefCount = (Scaleform::GFx::AS3::GASRefCountBase *)prop_name->RefCount;
      pRCC = RefCount[1]._pRCC;
      v17 = (int *)&RefCount[1];
      v18 = 0;
      if ( pRCC )
      {
        v19 = *v17;
        do
        {
          if ( (*(_BYTE *)(*(_DWORD *)v19 + 20) & 0xF) == 0 )
          {
            pNode = *(Scaleform::GFx::ASStringNode **)(*(_DWORD *)v19 + 28);
            if ( !pNode->Size )
              pNode = v14->Uri.pNode;
            if ( pNode == v13->Uri.pNode )
              goto LABEL_32;
          }
          ++v18;
          v19 += 4;
        }
        while ( v18 < (unsigned int)pRCC );
      }
    }
    else if ( Scaleform::GFx::AS3::Instances::fl::Namespace::operator==(v14, v13) )
    {
LABEL_32:
      result = 1;
    }
    Pan = name.pNode;
  }
LABEL_34:
  if ( Pan->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(Pan);
  return result;
}
