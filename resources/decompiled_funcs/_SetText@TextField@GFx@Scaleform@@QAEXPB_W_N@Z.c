void __thiscall Scaleform::GFx::TextField::SetText(Scaleform::GFx::TextField *this, wchar_t *pnewText, bool reqHtml)
{
  unsigned int Flags; // ecx
  unsigned int v5; // ecx
  unsigned int v6; // ebp
  unsigned int v7; // eax
  char *v8; // edi
  char stackBuff[512]; // [esp+10h] [ebp-200h] BYREF

  Flags = this->Flags;
  if ( reqHtml )
  {
    if ( (Flags & 2) != 0 )
      goto LABEL_7;
    v5 = Flags | 2;
  }
  else
  {
    if ( (Flags & 2) == 0 )
      goto LABEL_7;
    v5 = Flags & 0xFFFFFFFD;
  }
  this->Flags = v5;
LABEL_7:
  v6 = Scaleform::SFwcslen(pnewText);
  v7 = 3 * v6 + 1;
  if ( v7 > 0x200 )
    v8 = (char *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, v7, 0);
  else
    v8 = stackBuff;
  Scaleform::UTF8Util::EncodeString(v8, pnewText, -1);
  Scaleform::GFx::TextField::SetTextValue(this, v8, reqHtml, 1);
  if ( v6 >= 0x200 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
}
