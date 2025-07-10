void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLComment::ToXMLString(
        Scaleform::GFx::AS3::Instances::fl::XMLComment *this,
        Scaleform::StringBuffer *buf,
        int ident,
        const Scaleform::GFx::AS3::NamespaceArray *ancestorNamespaces,
        const Scaleform::GFx::AS3::NamespaceArray *usedNotDeclared)
{
  Scaleform::GFx::AS3::Class *Constructor; // eax

  Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(this->pTraits.pObject);
  if ( (int)Constructor[1]._pRCC >= 0 && HIBYTE(Constructor[1].__vftable) && ident > 0 )
    Scaleform::GFx::AS3::Instances::fl::XML::AppendIdent(buf, ident);
  Scaleform::StringBuffer::AppendString(buf, "<!--", 4u);
  Scaleform::StringBuffer::AppendString(buf, (char *)this->Text.pNode->pData, this->Text.pNode->Size);
  Scaleform::StringBuffer::AppendString(buf, "-->", 3u);
}
