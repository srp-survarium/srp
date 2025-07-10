void __thiscall Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>::Link(
        Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *> *this,
        unsigned int index,
        Scaleform::Render::TreeCacheNode **pnext,
        Scaleform::Render::TreeCacheNode *val)
{
  if ( index < this->DepthAvailable
    || Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>::grow(this, index + 1) )
  {
    *pnext = this->pDepth[index];
    this->pDepth[index] = val;
    if ( this->DepthUsed < index + 1 )
      this->DepthUsed = index + 1;
  }
}
