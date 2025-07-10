void __thiscall Scaleform::GFx::ASStringManager::AllocateStringNodes(Scaleform::GFx::ASStringManager *this)
{
  Scaleform::GFx::ASStringManager::StringNodePage *v2; // eax
  int v3; // ecx

  v2 = (Scaleform::GFx::ASStringManager::StringNodePage *)this->pHeap->Alloc(this->pHeap, 3052, 0);
  if ( v2 )
  {
    v2->pNext = this->pStringNodePages;
    this->pStringNodePages = v2;
    v3 = 127;
    do
    {
      v2->Nodes[0].pData = 0;
      v2->Nodes[0].pManager = this;
      v2->Nodes[0].pLower = this->pFreeStringNodes;
      this->pFreeStringNodes = (Scaleform::GFx::ASStringNode *)v2;
      v2 = (Scaleform::GFx::ASStringManager::StringNodePage *)((char *)v2 + 24);
      --v3;
    }
    while ( v3 );
  }
}
