void __thiscall Scaleform::GFx::XML::DOMBuilder::StartDocument(Scaleform::GFx::XML::DOMBuilder *this)
{
  Scaleform::GFx::XML::Document *pObject; // eax
  Scaleform::GFx::XML::Document *v3; // edi
  Scaleform::Array<Scaleform::Ptr<Scaleform::GFx::XML::ElementNode>,2,Scaleform::ArrayDefaultPolicy> *p_ParseStack; // esi
  _DWORD *p_pObject; // eax

  pObject = this->pDoc.pObject;
  if ( pObject )
    ++pObject->RefCount;
  v3 = this->pDoc.pObject;
  p_ParseStack = &this->ParseStack;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::XML::ElementNode>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::XML::ElementNode>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->ParseStack.Data,
    &this->ParseStack,
    this->ParseStack.Data.Size + 1);
  p_pObject = &p_ParseStack->Data.Data[this->ParseStack.Data.Size - 1].pObject;
  if ( &p_ParseStack->Data.Data[this->ParseStack.Data.Size] != (Scaleform::Ptr<Scaleform::GFx::XML::ElementNode> *)4 )
  {
    if ( v3 )
      ++v3->RefCount;
    *p_pObject = v3;
  }
  if ( v3 )
    Scaleform::RefCountNTSImpl::Release(v3);
  this->TotalBytesToLoad = this->pLocator->TotalBytesToLoad;
}
