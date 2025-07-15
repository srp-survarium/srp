void __thiscall Scaleform::GFx::ASStringManager::FreeStringNode(
        Scaleform::GFx::ASStringManager *this,
        Scaleform::GFx::ASStringNode *pnode)
{
  Scaleform::GFx::ASStringManager::TextPage::Entry *pData; // eax

  pData = (Scaleform::GFx::ASStringManager::TextPage::Entry *)pnode->pData;
  if ( pnode->pData )
  {
    if ( (pnode->HashFlags & 0x40000000) == 0 )
    {
      if ( pnode->Size < 0xC )
      {
        pData->pNextAlloc = this->pFreeTextBuffers;
        this->pFreeTextBuffers = pData;
        pnode->pData = 0;
        pnode->pLower = this->pFreeStringNodes;
        this->pFreeStringNodes = pnode;
        return;
      }
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)pnode->pData);
    }
    pnode->pData = 0;
  }
  pnode->pLower = this->pFreeStringNodes;
  this->pFreeStringNodes = pnode;
}
