int __thiscall Scaleform::GFx::AS3::Impl::CompareAsString::Compare(
        Scaleform::GFx::AS3::Impl::CompareAsStringInd *this,
        const Scaleform::GFx::ASString *a,
        const Scaleform::GFx::ASString *b)
{
  char *pData; // esi
  unsigned int Length; // eax
  int result; // eax
  char *v7; // esi
  unsigned int v8; // eax
  bool v9; // [esp-4h] [ebp-Ch]
  bool v10; // [esp-4h] [ebp-Ch]

  if ( this->UseLocale )
  {
    if ( this->Desc )
    {
      pData = (char *)a->pNode->pData;
      v9 = !this->CaseInsensitive;
      Length = Scaleform::GFx::ASConstString::GetLength(&a->Scaleform::GFx::ASConstString);
      return Scaleform::GFx::ASConstString::LocaleCompare_CaseCheck(
               &b->Scaleform::GFx::ASConstString,
               pData,
               Length,
               v9);
    }
    else
    {
      v7 = (char *)b->pNode->pData;
      v10 = !this->CaseInsensitive;
      v8 = Scaleform::GFx::ASConstString::GetLength(&b->Scaleform::GFx::ASConstString);
      return Scaleform::GFx::ASConstString::LocaleCompare_CaseCheck(&a->Scaleform::GFx::ASConstString, v7, v8, v10);
    }
  }
  else
  {
    if ( this->CaseInsensitive )
      result = Scaleform::String::CompareNoCase((char *)a->pNode->pData, (char *)b->pNode->pData);
    else
      result = strcmp(a->pNode->pData, b->pNode->pData);
    if ( this->Desc )
      return -result;
  }
  return result;
}
