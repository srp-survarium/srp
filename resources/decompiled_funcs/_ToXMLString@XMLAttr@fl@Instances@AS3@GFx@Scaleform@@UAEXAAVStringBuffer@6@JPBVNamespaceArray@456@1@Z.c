void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLAttr::ToXMLString(
        Scaleform::GFx::AS3::Instances::fl::XMLAttr *this,
        Scaleform::StringBuffer *buf,
        int ident,
        const Scaleform::GFx::AS3::NamespaceArray *ancestorNamespaces,
        const Scaleform::GFx::AS3::NamespaceArray *usedNotDeclared)
{
  Scaleform::GFx::AS3::Instances::fl::XML::EscapeAttributeValue(buf, &this->Data);
}
