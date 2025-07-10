void __thiscall Scaleform::GFx::XML::ElementNode::AddAttribute(
        Scaleform::GFx::XML::ElementNode *this,
        Scaleform::GFx::XML::Attribute *xmlAttrib)
{
  if ( this->FirstAttribute )
    this->LastAttribute->Next = xmlAttrib;
  else
    this->FirstAttribute = xmlAttrib;
  this->LastAttribute = xmlAttrib;
}
