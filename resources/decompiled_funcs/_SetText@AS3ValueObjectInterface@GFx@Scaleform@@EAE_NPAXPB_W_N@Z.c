char __thiscall Scaleform::GFx::AS3ValueObjectInterface::SetText(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata,
        wchar_t *ptext,
        bool reqHtml)
{
  int v4; // eax
  Scaleform::GFx::TextField *v7; // edi
  const char *v8; // eax
  bool v9; // bl
  int v10; // [esp+10h] [ebp-18h] BYREF
  int v11; // [esp+14h] [ebp-14h]
  wchar_t *v12; // [esp+18h] [ebp-10h]

  v4 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v4 + 60) - 17) >= 0xC || (*(_DWORD *)(v4 + 56) & 0x20) != 0 )
    return 0;
  v7 = (Scaleform::GFx::TextField *)pdata[12];
  if ( v7->GetType(v7) == MouseWheel )
  {
    Scaleform::GFx::TextField::SetText(v7, ptext, reqHtml);
    return 1;
  }
  else
  {
    v12 = ptext;
    v10 = 0;
    v11 = 7;
    v8 = "htmlText";
    if ( !reqHtml )
      v8 = "text";
    v9 = this->SetMember(this, pdata, v8, (const Scaleform::GFx::Value *)&v10, 1);
    if ( (v11 & 0x40) != 0 )
      (*(void (__thiscall **)(int, int *, wchar_t *))(*(_DWORD *)v10 + 8))(v10, &v10, v12);
    return v9;
  }
}
