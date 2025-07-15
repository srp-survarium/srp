char __thiscall Scaleform::GFx::AS2ValueObjectInterface::SetText(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        char *ptext,
        bool reqHtml)
{
  Scaleform::GFx::TextField *v5; // esi
  const char *v7; // eax
  bool v8; // bl
  unsigned int Flags; // ecx
  unsigned int v10; // ecx
  int v11; // [esp+10h] [ebp-18h] BYREF
  int v12; // [esp+14h] [ebp-14h]
  char *v13; // [esp+18h] [ebp-10h]

  v5 = (Scaleform::GFx::TextField *)Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( !v5 )
    return 0;
  if ( v5->GetType(v5) == MouseWheel )
  {
    Flags = v5->Flags;
    if ( reqHtml )
    {
      if ( (v5->Flags & 2) == 0 )
      {
        v10 = Flags | 2;
LABEL_14:
        v5->Flags = v10;
      }
    }
    else if ( (v5->Flags & 2) != 0 )
    {
      v10 = Flags & 0xFFFFFFFD;
      goto LABEL_14;
    }
    Scaleform::GFx::TextField::SetTextValue(v5, ptext, reqHtml, 1);
    return 1;
  }
  v13 = ptext;
  v11 = 0;
  v12 = 6;
  v7 = "htmlText";
  if ( !reqHtml )
    v7 = "text";
  v8 = this->SetMember(this, pdata, v7, (const Scaleform::GFx::Value *)&v11, 1);
  if ( (v12 & 0x40) != 0 )
    (*(void (__thiscall **)(int, int *, char *))(*(_DWORD *)v11 + 8))(v11, &v11, v13);
  return v8;
}


char __thiscall Scaleform::GFx::AS2ValueObjectInterface::SetText(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        wchar_t *ptext,
        bool reqHtml)
{
  Scaleform::GFx::TextField *v5; // edi
  const char *v7; // eax
  bool v8; // bl
  int v9; // [esp+10h] [ebp-18h] BYREF
  int v10; // [esp+14h] [ebp-14h]
  wchar_t *v11; // [esp+18h] [ebp-10h]

  v5 = (Scaleform::GFx::TextField *)Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( !v5 )
    return 0;
  if ( v5->GetType(v5) == MouseWheel )
  {
    Scaleform::GFx::TextField::SetText(v5, ptext, reqHtml);
    return 1;
  }
  else
  {
    v11 = ptext;
    v9 = 0;
    v10 = 7;
    v7 = "htmlText";
    if ( !reqHtml )
      v7 = "text";
    v8 = this->SetMember(this, pdata, v7, (const Scaleform::GFx::Value *)&v9, 1);
    if ( (v10 & 0x40) != 0 )
      (*(void (__thiscall **)(int, int *, wchar_t *))(*(_DWORD *)v9 + 8))(v9, &v9, v11);
    return v8;
  }
}
