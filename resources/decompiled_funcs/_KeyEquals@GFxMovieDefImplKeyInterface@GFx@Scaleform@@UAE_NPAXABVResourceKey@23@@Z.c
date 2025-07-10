bool __thiscall Scaleform::GFx::GFxMovieDefImplKeyInterface::KeyEquals(
        Scaleform::GFx::GFxMovieDefImplKeyInterface *this,
        void *hdata,
        const Scaleform::GFx::ResourceKey *other)
{
  void *hKeyData; // eax

  if ( this != other->pKeyInterface )
    return 0;
  hKeyData = other->hKeyData;
  return *((_DWORD *)hdata + 2) == *((_DWORD *)hKeyData + 2)
      && Scaleform::GFx::MovieDefBindStates::operator==(
           *((Scaleform::GFx::MovieDefBindStates **)hdata + 3),
           *((Scaleform::GFx::MovieDefBindStates **)hKeyData + 3));
}
