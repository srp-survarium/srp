void __thiscall Scaleform::Render::TreeCacheShapeLayer::propagateMaskFlag(
        Scaleform::Render::TreeCacheShapeLayer *this,
        unsigned int partOfMask)
{
  unsigned int v2; // eax

  v2 = partOfMask | this->Flags & 0xFFBF;
  if ( v2 != this->Flags )
  {
    this->Flags = v2;
    Scaleform::Render::TreeCacheShapeLayer::updateSortKey(this);
  }
}
