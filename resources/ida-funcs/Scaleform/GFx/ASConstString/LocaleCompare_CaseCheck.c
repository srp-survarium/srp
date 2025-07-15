int __thiscall Scaleform::GFx::ASConstString::LocaleCompare_CaseCheck(
        Scaleform::GFx::ASConstString *this,
        char *pstr,
        unsigned int len,
        bool caseSensitive)
{
  unsigned int v4; // ebx
  unsigned int Size; // esi
  int Length; // eax
  wchar_t *v8; // edi
  wchar_t *v9; // esi
  int v10; // eax
  int v11; // ebx
  _BYTE v13[500]; // [esp+Ch] [ebp-3E8h] BYREF
  _BYTE v14[500]; // [esp+200h] [ebp-1F4h] BYREF

  v4 = len;
  if ( len == -1 )
    v4 = strlen(pstr);
  Size = this->pNode->Size;
  if ( (this->pNode->HashFlags & 0x8000000) == 0 )
  {
    Length = Scaleform::UTF8Util::GetLength((char *)this->pNode->pData, Size);
    if ( Length == Size )
      this->pNode->HashFlags |= 0x8000000u;
    Size = Length;
  }
  if ( Size < 0xFA )
    v8 = (wchar_t *)v13;
  else
    v8 = (wchar_t *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 2 * Size + 2, 0);
  if ( v4 < 0xFA )
    v9 = (wchar_t *)v14;
  else
    v9 = (wchar_t *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 2 * v4 + 2, 0);
  Scaleform::UTF8Util::DecodeString(v8, (char *)this->pNode->pData, this->pNode->Size);
  Scaleform::UTF8Util::DecodeString(v9, pstr, v4);
  if ( caseSensitive )
    v10 = wcscoll(v8, v9);
  else
    v10 = _wcsicoll(v8, v9);
  v11 = v10;
  if ( v8 != (wchar_t *)v13 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
  if ( v9 != (wchar_t *)v14 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
  return v11;
}
