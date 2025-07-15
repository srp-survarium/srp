void __thiscall Scaleform::GFx::TextField::SetText(Scaleform::GFx::TextField *this, wchar_t *pnewText, char reqHtml)
{
  unsigned int Flags; // ecx
  unsigned int v5; // ecx
  unsigned int v6; // ebp
  unsigned int v7; // eax
  __m128i *p_pbuff; // edi
  char pbuff; // [esp+10h] [ebp-200h] BYREF

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
    p_pbuff = (__m128i *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, v7, 0);
  else
    p_pbuff = (__m128i *)&pbuff;
  Scaleform::UTF8Util::EncodeString(p_pbuff->m128i_i8, pnewText, -1);
  Scaleform::GFx::TextField::SetTextValue(this, p_pbuff, reqHtml, 1);
  if ( v6 >= 0x200 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_pbuff);
}
