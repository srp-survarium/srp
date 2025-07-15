void __thiscall Scaleform::Render::Font::calcLowerUpperTop(
        Scaleform::Render::Font *this,
        Scaleform::Render::GlyphCache *log)
{
  unsigned __int8 v3; // al
  char *v4; // edi
  unsigned __int16 v5; // bx
  const char *v6; // ecx
  const char *v7; // eax
  const char *v8; // eax
  unsigned __int8 v9; // al
  char *v10; // edi
  unsigned __int16 v11; // ax
  const char *v12; // [esp-8h] [ebp-28h]
  const char *v13; // [esp-4h] [ebp-24h]
  char v14[8]; // [esp+Ch] [ebp-14h] BYREF
  char v15[12]; // [esp+14h] [ebp-Ch] BYREF

  if ( this->LowerCaseTop )
    goto LABEL_6;
  if ( this->UpperCaseTop )
    goto LABEL_6;
  strcpy(v15, "HEFTUVWXZ");
  strcpy(v14, "zxvwy");
  v3 = aHeft[0];
  v4 = v15;
  if ( !aHeft[0] )
    goto LABEL_6;
  while ( 1 )
  {
    v5 = Scaleform::Render::Font::calcTopBound(this, v3);
    if ( v5 )
      break;
    v3 = *++v4;
    if ( !v3 )
      goto LABEL_6;
  }
  v9 = v14[0];
  v10 = v14;
  if ( !v14[0] )
  {
LABEL_6:
    if ( log )
    {
      v6 = " Italic";
      if ( (this->Flags & 1) == 0 )
        v6 = uri;
      v7 = " Bold";
      if ( (this->Flags & 2) == 0 )
        v7 = uri;
      v8 = (const char *)((int (__thiscall *)(Scaleform::Render::Font *, const char *, const char *))this->GetName)(
                           this,
                           v7,
                           v6);
      Scaleform::Render::GlyphCache::LogWarning(
        log,
        "Font '%s%s%s': No hinting chars (any of 'HEFTUVWXZ' and 'zxvwy'). Auto-Hinting disabled.",
        v8,
        v12,
        v13);
    }
    this->LowerCaseTop = -1;
    this->UpperCaseTop = -1;
  }
  else
  {
    while ( 1 )
    {
      v11 = Scaleform::Render::Font::calcTopBound(this, v9);
      if ( v11 )
        break;
      v9 = *++v10;
      if ( !v9 )
        goto LABEL_6;
    }
    this->UpperCaseTop = v5;
    this->LowerCaseTop = v11;
  }
}
