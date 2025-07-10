void __thiscall Scaleform::GFx::TextField::TextDocumentListener::View_OnMaxScrollChanged(
        Scaleform::GFx::TextField::TextDocumentListener *this,
        Scaleform::Render::Text::DocView *view)
{
  unsigned __int8 v2; // al
  int v3; // eax

  v2 = BYTE1(this[-9].__vftable);
  if ( v2 )
  {
    v3 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this[-14] + v2 - 1) + 16))((char *)&this[-14] + 4 * v2 - 4);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 116))(v3);
  }
}
