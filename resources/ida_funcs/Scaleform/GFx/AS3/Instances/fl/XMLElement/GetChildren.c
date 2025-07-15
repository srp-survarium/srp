void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::GetChildren(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::Instances::fl::XMLList *list,
        Scaleform::GFx::AS3::SoundObject *prop_name)
{
  Scaleform::GFx::AS3::SoundObject *v3; // edi
  unsigned int ind; // [esp+8h] [ebp-10h] BYREF
  Scaleform::GFx::AS3::Instances::fl::ChildGet cb; // [esp+Ch] [ebp-Ch] BYREF

  v3 = prop_name;
  if ( Scaleform::GFx::AS3::GetVectorInd(
         (Scaleform::GFx::AS3::CheckResult *)&prop_name,
         (const Scaleform::GFx::AS3::Multiname *)prop_name,
         &ind)->Result )
  {
    if ( ind <= this->Children.Data.Size )
      Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(list, this->Children.Data.Data[ind].pObject);
  }
  else
  {
    cb.List = list;
    cb.Element = this;
    cb.__vftable = (Scaleform::GFx::AS3::Instances::fl::ChildGet_vtbl *)&Scaleform::GFx::AS3::Instances::fl::ChildGet::`vftable';
    Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachChild(this, v3, &cb);
  }
}


void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::GetChildren(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::Instances::fl::XMLList *list,
        Scaleform::GFx::AS3::Instances::fl::XML::Kind k,
        Scaleform::GFx::ASString *name)
{
  unsigned int Size; // ebx
  unsigned int i; // edi
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // esi
  int v8; // eax
  bool all; // [esp+7h] [ebp-1h]

  if ( k )
  {
    if ( !name || !name->pNode->Size || (all = 0, Scaleform::GFx::ASString::operator==(name, "*")) )
      all = 1;
    Size = this->Children.Data.Size;
    for ( i = 0; i < Size; ++i )
    {
      pObject = this->Children.Data.Data[i].pObject;
      v8 = pObject->GetKind(pObject);
      if ( v8 == k && (v8 != 4 || !name || all || pObject->GetName(pObject)->pNode == name->pNode) )
        Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(list, pObject);
    }
  }
  else
  {
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
      &list->List,
      &this->Children);
  }
}
