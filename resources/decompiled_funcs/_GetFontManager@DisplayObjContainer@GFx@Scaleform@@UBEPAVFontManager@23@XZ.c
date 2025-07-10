Scaleform::GFx::FontManager *__thiscall Scaleform::GFx::DisplayObjContainer::GetFontManager(
        Scaleform::GFx::DisplayObjContainer *this)
{
  Scaleform::GFx::MovieDefRootNode *pRootNode; // ecx
  Scaleform::GFx::InteractiveObject *pParent; // ecx

  pRootNode = this->pRootNode;
  if ( pRootNode )
    return pRootNode->pFontManager.pObject;
  pParent = this->pParent;
  if ( pParent )
    return pParent->GetFontManager(pParent);
  else
    return this->pASRoot->pMovieImpl->RootMovieDefNodes.Root.pNext->pFontManager.pObject;
}
