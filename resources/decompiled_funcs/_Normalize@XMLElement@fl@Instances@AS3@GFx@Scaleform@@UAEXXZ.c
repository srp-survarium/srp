void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::Normalize(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this)
{
  unsigned int Size; // ebp
  unsigned int v2; // esi
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *p_Children; // edi
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *pObject; // ebx
  Scaleform::GFx::AS3::Instances::fl::XMLText *txt; // [esp+8h] [ebp-8h]
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *i; // [esp+Ch] [ebp-4h]

  Size = this->Children.Data.Size;
  v2 = 0;
  txt = 0;
  if ( Size )
  {
    p_Children = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Children;
    for ( i = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Children;
          ;
          p_Children = i )
    {
      pObject = p_Children->Data.Data[v2].pObject;
      if ( pObject->GetKind(pObject) == kText )
      {
        if ( txt )
        {
          if ( pObject->Text.pNode->Size )
            Scaleform::GFx::ASString::Append(&txt->Text, (Scaleform::GFx::ASStringNode *)&pObject->Text);
          Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
            p_Children,
            v2--);
          --Size;
        }
        else if ( !pObject->Text.pNode->Size || Scaleform::GFx::AS3::Instances::fl::IsWhiteSpaceString(&pObject->Text) )
        {
          Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
            i,
            v2--);
          --Size;
        }
        else
        {
          txt = (Scaleform::GFx::AS3::Instances::fl::XMLText *)pObject;
        }
      }
      else
      {
        txt = 0;
      }
      if ( ++v2 >= Size )
        break;
    }
  }
}
