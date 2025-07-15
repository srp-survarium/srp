void __thiscall Scaleform::GFx::XML::ElementNode::ClearAttributes(Scaleform::GFx::XML::ElementNode *this)
{
  Scaleform::GFx::XML::Attribute *FirstAttribute; // esi
  Scaleform::GFx::XML::Attribute *Next; // edi

  FirstAttribute = this->FirstAttribute;
  if ( FirstAttribute )
  {
    do
    {
      Next = FirstAttribute->Next;
      Scaleform::GFx::XML::DOMString::~DOMString(&FirstAttribute->Value);
      Scaleform::GFx::XML::DOMString::~DOMString(&FirstAttribute->Name);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, FirstAttribute);
      FirstAttribute = Next;
    }
    while ( Next );
  }
  this->LastAttribute = 0;
  this->FirstAttribute = 0;
}
