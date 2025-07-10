Scaleform::GFx::XML::ElementNode *__thiscall Scaleform::GFx::XML::Document::Clone(
        Scaleform::GFx::XML::Document *this,
        BOOL deep)
{
  Scaleform::GFx::XML::ElementNode *v3; // eax
  Scaleform::GFx::XML::ElementNode *v4; // edi

  Scaleform::GFx::XML::ObjectManager::CreateDocument(this->MemoryManager.pObject);
  v4 = v3;
  Scaleform::GFx::XML::ElementNode::CloneHelper(this, v3, deep);
  Scaleform::GFx::XML::DOMString::AssignNode((Scaleform::GFx::XML::DOMString *)&v4[1].RefCount, this->Encoding.pNode);
  LOBYTE(v4[1].MemoryManager.pObject) = this->Standalone;
  Scaleform::GFx::XML::DOMString::AssignNode((Scaleform::GFx::XML::DOMString *)&v4[1], this->XMLVersion.pNode);
  v4->Type = this->Type;
  return v4;
}
