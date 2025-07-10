void __thiscall Scaleform::GFx::XML::DOMStringManager::FreeStringNode(
        Scaleform::GFx::XML::DOMStringManager *this,
        Scaleform::GFx::XML::DOMStringNode *pnode)
{
  Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *pData; // eax

  pData = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)pnode->pData;
  if ( pnode->pData )
  {
    if ( pnode->Size < 0xC )
    {
      pData->pNextAlloc = this->pFreeTextBuffers;
      this->pFreeTextBuffers = pData;
      pnode->pData = 0;
      pnode->pManager = (Scaleform::GFx::XML::DOMStringManager *)this->pFreeStringNodes;
      this->pFreeStringNodes = pnode;
      return;
    }
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)pnode->pData);
    pnode->pData = 0;
  }
  pnode->pManager = (Scaleform::GFx::XML::DOMStringManager *)this->pFreeStringNodes;
  this->pFreeStringNodes = pnode;
}
