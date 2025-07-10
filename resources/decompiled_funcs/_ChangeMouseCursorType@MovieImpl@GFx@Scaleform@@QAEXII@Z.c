void __thiscall Scaleform::GFx::MovieImpl::ChangeMouseCursorType(
        Scaleform::GFx::MovieImpl *this,
        unsigned int mouseIdx,
        unsigned int newCursorType)
{
  char *v3; // esi
  int v4; // eax

  v3 = (char *)this + 56 * mouseIdx;
  if ( *((_DWORD *)v3 + 1158) != newCursorType )
    this->pASMovieRoot.pObject->ChangeMouseCursorType(this->pASMovieRoot.pObject, mouseIdx, newCursorType);
  v4 = *((_DWORD *)v3 + 1157);
  if ( v4 == -1 )
    *((_DWORD *)v3 + 1158) = newCursorType;
  else
    *((_DWORD *)v3 + 1158) = v4;
}
