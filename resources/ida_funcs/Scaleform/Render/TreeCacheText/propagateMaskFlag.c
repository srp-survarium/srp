void __thiscall Scaleform::Render::TreeCacheText::propagateMaskFlag(
        Scaleform::Render::TreeCacheText *this,
        unsigned int partOfMask)
{
  unsigned int v2; // eax

  v2 = partOfMask | this->Flags & 0xFFBF;
  if ( v2 != this->Flags )
    this->Flags = v2;
}
