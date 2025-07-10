void __thiscall Scaleform::Render::TreeCacheNode::propagateMaskFlag(
        Scaleform::Render::TreeCacheNode *this,
        __int16 partOfMask)
{
  this->Flags = partOfMask | this->Flags & 0xFFBF;
}
