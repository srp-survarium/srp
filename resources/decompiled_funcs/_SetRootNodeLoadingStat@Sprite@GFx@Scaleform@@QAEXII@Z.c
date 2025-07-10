void __thiscall Scaleform::GFx::Sprite::SetRootNodeLoadingStat(
        Scaleform::GFx::Sprite *this,
        unsigned int bytesLoaded,
        unsigned int loadingFrame)
{
  if ( this->pRootNode )
  {
    this->pRootNode->BytesLoaded = bytesLoaded;
    this->pRootNode->LoadingFrame = this->pRootNode->ImportFlag ? 0 : loadingFrame;
  }
}
