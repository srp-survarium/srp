Scaleform::GFx::StaticTextCharacter::HighlightDesc *__thiscall Scaleform::GFx::StaticTextCharacter::CreateTextHighlighter(
        Scaleform::GFx::StaticTextCharacter *this)
{
  Scaleform::GFx::MovieImpl *MovieImpl; // eax
  int v3; // eax
  Scaleform::Render::Text::Highlighter *v4; // eax
  Scaleform::GFx::StaticTextCharacter::HighlightDesc *v5; // esi

  if ( this->pHighlight )
    return this->pHighlight;
  MovieImpl = Scaleform::GFx::DisplayObjectBase::FindMovieImpl(this);
  v3 = (int)MovieImpl->GetHeap(MovieImpl);
  v4 = (Scaleform::Render::Text::Highlighter *)(*(int (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v3 + 40))(v3, 28, 0);
  v5 = (Scaleform::GFx::StaticTextCharacter::HighlightDesc *)v4;
  if ( v4 )
  {
    Scaleform::Render::Text::Highlighter::Highlighter(v4);
    this->pHighlight = v5;
    return v5;
  }
  else
  {
    this->pHighlight = 0;
    return 0;
  }
}
