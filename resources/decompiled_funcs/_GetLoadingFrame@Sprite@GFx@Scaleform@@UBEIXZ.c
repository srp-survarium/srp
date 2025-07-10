unsigned int __thiscall Scaleform::GFx::Sprite::GetLoadingFrame(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::MovieDefRootNode *pRootNode; // eax

  pRootNode = this->pRootNode;
  if ( !pRootNode || pRootNode->ImportFlag )
    return this->pDef.pObject->GetFrameCount(this->pDef.pObject);
  else
    return pRootNode->LoadingFrame;
}
