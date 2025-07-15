int __thiscall Scaleform::GFx::ASString::LocaleCompare_CaseCheck(
        Scaleform::GFx::ASString *this,
        const Scaleform::GFx::ASString *str,
        bool caseSensitive)
{
  char *pData; // edi
  unsigned int Length; // eax

  pData = (char *)str->pNode->pData;
  Length = Scaleform::GFx::ASConstString::GetLength(&str->Scaleform::GFx::ASConstString);
  return Scaleform::GFx::ASConstString::LocaleCompare_CaseCheck(this, pData, Length, caseSensitive);
}
