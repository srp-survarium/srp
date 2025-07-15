Scaleform::GFx::XML::Document *__thiscall Scaleform::GFx::XML::Document::`scalar deleting destructor'(
        Scaleform::GFx::XML::Document *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::XML::Document_vtbl *)&Scaleform::GFx::XML::Document::`vftable';
  Scaleform::GFx::XML::DOMString::~DOMString(&this->Encoding);
  Scaleform::GFx::XML::DOMString::~DOMString(&this->XMLVersion);
  Scaleform::GFx::XML::ElementNode::~ElementNode(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
