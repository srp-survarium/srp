bool __thiscall Scaleform::GFx::TextField::IsUrlTheSame(
        Scaleform::GFx::TextField *this,
        unsigned int mouseIndex,
        const Scaleform::Range *urlRange)
{
  Scaleform::GFx::TextField::CSSHolderBase *pObject; // edi
  bool result; // al
  unsigned int Size; // ebx
  int v6; // edx
  int Index; // ebp
  Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone> *i; // ecx
  signed int v9; // [esp+Ch] [ebp+8h]

  pObject = this->pCSSData.pObject;
  result = 1;
  if ( pObject )
  {
    Size = pObject->UrlZones.Ranges.Data.Size;
    v6 = 0;
    if ( Size )
    {
      Index = urlRange->Index;
      v9 = urlRange->Length + urlRange->Index - 1;
      for ( i = pObject->UrlZones.Ranges.Data.Data;
            v9 < i->Index
         || (signed int)(i->Length + i->Index - 1) < Index
         || pObject->MouseState[mouseIndex].UrlZoneIndex == v6 + 1;
            ++i )
      {
        if ( ++v6 >= Size )
          return 1;
      }
      return 0;
    }
  }
  return result;
}
