void __thiscall Scaleform::GFx::TextField::TextDocumentListener::View_OnVScroll(
        Scaleform::GFx::TextField::TextDocumentListener *this,
        Scaleform::Render::Text::DocView *view,
        unsigned int newScroll)
{
  unsigned __int8 v3; // al
  int v4; // eax

  v3 = BYTE1(this[-9].__vftable);
  if ( v3 )
  {
    v4 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this[-14] + v3 - 1) + 16))((char *)&this[-14] + 4 * v3 - 4);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 116))(v4);
  }
}
