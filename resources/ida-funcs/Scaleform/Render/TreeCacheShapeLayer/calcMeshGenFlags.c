unsigned int __thiscall Scaleform::Render::TreeCacheShapeLayer::calcMeshGenFlags(
        Scaleform::Render::TreeCacheShapeLayer *this)
{
  unsigned __int16 Flags; // cx
  unsigned int result; // eax

  Flags = this->Flags;
  if ( (Flags & 0x40) != 0 )
    result = 2;
  else
    result = (Flags & 0xC) == 4;
  if ( (Flags & 0x80u) != 0 )
    result |= 8u;
  return result;
}
