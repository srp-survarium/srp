void __thiscall Scaleform::SwitchFormatter::Parse(
        Scaleform::SwitchFormatter *this,
        const Scaleform::StringDataPtr *str)
{
  unsigned int Size; // edx
  int v3; // edi
  Scaleform::StringDataPtr *NextToken; // eax
  const char *pStr; // esi
  unsigned int v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // edx
  int v9; // eax
  int v10; // esi
  Scaleform::SwitchFormatter *v11; // eax
  char v12; // [esp+7h] [ebp-29h]
  int valueNumber; // [esp+8h] [ebp-28h] BYREF
  Scaleform::SwitchFormatter *v14; // [esp+Ch] [ebp-24h]
  Scaleform::StringDataPtr tmpStr; // [esp+10h] [ebp-20h] BYREF
  Scaleform::StringDataPtr curStr; // [esp+18h] [ebp-18h] BYREF
  Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int> >::NodeRef key; // [esp+20h] [ebp-10h] BYREF
  Scaleform::StringDataPtr result; // [esp+28h] [ebp-8h] BYREF

  Size = str->Size;
  v3 = 0;
  v14 = this;
  tmpStr.pStr = str->pStr;
  tmpStr.Size = Size;
  curStr.pStr = 0;
  curStr.Size = 0;
  valueNumber = 0;
  while ( 1 )
  {
    NextToken = Scaleform::StringDataPtr::GetNextToken(&tmpStr, &result, 58);
    pStr = NextToken->pStr;
    curStr.pStr = NextToken->pStr;
    v6 = NextToken->Size;
    v7 = v6 + 1;
    curStr.Size = v6;
    if ( tmpStr.Size < v6 + 1 )
      v7 = tmpStr.Size;
    tmpStr.pStr += v7;
    tmpStr.Size -= v7;
    if ( v3 )
    {
      key.pFirst = &valueNumber;
      key.pSecond = &curStr;
      v8 = 5381;
      v9 = 4;
      do
      {
        v10 = (unsigned __int8)*(&v12 + v9--);
        v8 = v10 + 65599 * v8;
      }
      while ( v9 );
      Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeHashF,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeAltHashF,Scaleform::AllocatorGH<int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeHashF>>::add<Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeRef>(
        &v14->StringSet.mHash,
        &v14->StringSet,
        &key,
        v8);
      v3 = 0;
      goto LABEL_12;
    }
    if ( !v6 || !pStr )
      goto LABEL_15;
    if ( !isdigit(*pStr) )
      break;
    valueNumber = atoi(pStr);
    v3 = 1;
LABEL_12:
    if ( !tmpStr.Size )
      return;
  }
  v6 = curStr.Size;
  pStr = curStr.pStr;
LABEL_15:
  v11 = v14;
  v14->DefaultStrValue.pStr = pStr;
  v11->DefaultStrValue.Size = v6;
}
