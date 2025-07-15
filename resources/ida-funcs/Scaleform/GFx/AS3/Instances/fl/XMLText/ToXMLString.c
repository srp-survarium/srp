void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLText::ToXMLString(
        Scaleform::GFx::AS3::Instances::fl::XMLText *this,
        Scaleform::StringBuffer *buf,
        int ident,
        const Scaleform::GFx::AS3::NamespaceArray *ancestorNamespaces,
        const Scaleform::GFx::AS3::NamespaceArray *usedNotDeclared)
{
  Scaleform::GFx::AS3::Class *Constructor; // eax
  Scaleform::StringBuffer *v7; // edi
  Scaleform::StringBuffer *v8; // esi

  Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(this->pTraits.pObject);
  v7 = buf;
  if ( (int)Constructor[1]._pRCC >= 0 && HIBYTE(Constructor[1].__vftable) && ident > 0 )
    Scaleform::GFx::AS3::Instances::fl::XML::AppendIdent(buf, ident);
  if ( HIBYTE(Scaleform::GFx::AS3::Traits::GetConstructor(this->pTraits.pObject)[1].__vftable) )
  {
    v8 = (Scaleform::StringBuffer *)Scaleform::GFx::ASConstString::TruncateWhitespaceNode(&this->Text);
    ++v8->GrowSize;
    buf = v8;
    Scaleform::GFx::AS3::Instances::fl::XML::EscapeElementValue(v7, (const Scaleform::GFx::ASString *)&buf);
    if ( v8->GrowSize-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v8);
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl::XML::EscapeElementValue(v7, &this->Text);
  }
}
