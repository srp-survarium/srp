void __thiscall Scaleform::GFx::MovieImpl::SetKeyboardListener(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::MovieImpl *l)
{
  Scaleform::GFx::ASMovieRootBase *KeyboardStates; // esi
  int v3; // edi

  KeyboardStates = (Scaleform::GFx::ASMovieRootBase *)this->KeyboardStates;
  v3 = 6;
  do
  {
    Scaleform::GFx::ASMovieRootBase::SetMovie(KeyboardStates, l);
    KeyboardStates += 83;
    --v3;
  }
  while ( v3 );
}
