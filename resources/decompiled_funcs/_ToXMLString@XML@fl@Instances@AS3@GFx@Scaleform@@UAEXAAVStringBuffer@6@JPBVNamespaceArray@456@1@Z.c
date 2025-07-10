void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::ToXMLString(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::StringBuffer *buf,
        int ident,
        const Scaleform::GFx::AS3::NamespaceArray *ancestorNamespaces,
        const Scaleform::GFx::AS3::NamespaceArray *usedNotDeclared)
{
  Scaleform::StringBuffer::AppendString(buf, (char *)this->Text.pNode->pData, this->Text.pNode->Size);
}
