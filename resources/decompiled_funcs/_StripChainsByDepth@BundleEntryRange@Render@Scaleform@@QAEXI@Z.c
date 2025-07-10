void __thiscall Scaleform::Render::BundleEntryRange::StripChainsByDepth(
        Scaleform::Render::BundleEntryRange *this,
        unsigned int topDepth)
{
  Scaleform::Render::BundleEntry *pFirst; // esi
  Scaleform::Render::Bundle *pObject; // edx
  Scaleform::Render::BundleEntry *v4; // eax
  int p_pChain; // edx
  bool v6; // zf

  pFirst = this->pFirst;
  if ( this->pFirst )
  {
    while ( 1 )
    {
      pObject = pFirst->pBundle.pObject;
      v4 = pFirst;
      if ( pObject )
        pObject->NeedUpdate = 1;
      p_pChain = (int)&pFirst->pChain;
      if ( pFirst->pChain )
      {
        do
        {
          if ( v4->ChainHeight > v4->pSourceNode->Depth - topDepth )
            break;
          v4 = *(Scaleform::Render::BundleEntry **)p_pChain;
          v6 = *(_DWORD *)(*(_DWORD *)p_pChain + 4) == 0;
          p_pChain = *(_DWORD *)p_pChain + 4;
        }
        while ( !v6 );
      }
      v4->pChain = 0;
      v4->ChainHeight = 0;
      if ( pFirst == this->pLast )
        break;
      pFirst = pFirst->pNextPattern;
    }
  }
}
