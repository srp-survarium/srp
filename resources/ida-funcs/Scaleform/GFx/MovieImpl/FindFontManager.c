Scaleform::GFx::FontManager *__thiscall Scaleform::GFx::MovieImpl::FindFontManager(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::MovieDefImpl *pdefImpl)
{
  Scaleform::GFx::MovieDefRootNode *pNext; // eax
  Scaleform::List<Scaleform::GFx::MovieDefRootNode,Scaleform::GFx::MovieDefRootNode> *p_RootMovieDefNodes; // edx
  int v4; // ecx

  pNext = this->RootMovieDefNodes.Root.pNext;
  p_RootMovieDefNodes = &this->RootMovieDefNodes;
  while ( 1 )
  {
    v4 = p_RootMovieDefNodes ? (int)&p_RootMovieDefNodes[-1].Root.4 : 0;
    if ( pNext == (Scaleform::GFx::MovieDefRootNode *)v4 )
      break;
    if ( pNext->pDefImpl == pdefImpl && pNext->pFontManager.pObject )
      return pNext->pFontManager.pObject;
    pNext = pNext->pNext;
  }
  return 0;
}
