void __thiscall Scaleform::GFx::XML::DOMStringManager::AllocateStringNodes(Scaleform::GFx::XML::DOMStringManager *this)
{
  Scaleform::GFx::XML::DOMStringManager::StringNodePage *v2; // eax
  int v3; // ecx

  v2 = (Scaleform::GFx::XML::DOMStringManager::StringNodePage *)this->pHeap->Alloc(this->pHeap, 2544, 0);
  if ( v2 )
  {
    v2->pNext = this->pStringNodePages;
    this->pStringNodePages = v2;
    v3 = 127;
    do
    {
      v2->Nodes[0].pData = 0;
      v2->Nodes[0].pManager = (Scaleform::GFx::XML::DOMStringManager *)this->pFreeStringNodes;
      this->pFreeStringNodes = (Scaleform::GFx::XML::DOMStringNode *)v2;
      v2 = (Scaleform::GFx::XML::DOMStringManager::StringNodePage *)((char *)v2 + 20);
      --v3;
    }
    while ( v3 );
  }
}
