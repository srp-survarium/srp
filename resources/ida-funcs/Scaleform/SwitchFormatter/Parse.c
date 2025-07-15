void __userpurge Scaleform::SwitchFormatter::Parse(
        Scaleform::SwitchFormatter *this@<ecx>,
        int a2@<ebx>,
        const Scaleform::StringDataPtr *str)
{
  unsigned int Size; // edx
  int v4; // edi
  Scaleform::StringDataPtr *NextToken; // eax
  char *pStr; // esi
  unsigned int v7; // ecx
  unsigned int v8; // eax
  unsigned int v9; // edx
  int v10; // eax
  int v11; // esi
  Scaleform::SwitchFormatter *v12; // eax
  char v13; // [esp+7h] [ebp-29h]
  unsigned int v14; // [esp+8h] [ebp-28h] BYREF
  Scaleform::SwitchFormatter *v15; // [esp+Ch] [ebp-24h]
  Scaleform::StringDataPtr v16; // [esp+10h] [ebp-20h] BYREF
  char *v17; // [esp+18h] [ebp-18h] BYREF
  unsigned int v18; // [esp+1Ch] [ebp-14h]
  Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int> >::NodeRef key; // [esp+20h] [ebp-10h] BYREF
  Scaleform::StringDataPtr result; // [esp+28h] [ebp-8h] BYREF

  Size = str->Size;
  v4 = 0;
  v15 = this;
  v16.pStr = str->pStr;
  v16.Size = Size;
  v17 = 0;
  v18 = 0;
  v14 = 0;
  while ( 1 )
  {
    NextToken = Scaleform::StringDataPtr::GetNextToken(&v16, &result, 58);
    pStr = (char *)NextToken->pStr;
    v17 = (char *)NextToken->pStr;
    v7 = NextToken->Size;
    v8 = v7 + 1;
    v18 = v7;
    if ( v16.Size < v7 + 1 )
      v8 = v16.Size;
    v16.pStr += v8;
    v16.Size -= v8;
    if ( v4 )
    {
      key.pFirst = (const int *)&v14;
      key.pSecond = (const Scaleform::StringDataPtr *)&v17;
      v9 = 5381;
      v10 = 4;
      do
      {
        v11 = (unsigned __int8)*(&v13 + v10--);
        v9 = v11 + 65599 * v9;
      }
      while ( v10 );
      Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeHashF,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeAltHashF,Scaleform::AllocatorGH<int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeHashF>>::add<Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeRef>(
        &v15->StringSet.mHash,
        &v15->StringSet,
        &key,
        v9);
      v4 = 0;
      goto LABEL_12;
    }
    if ( !v7 || !pStr )
      goto LABEL_15;
    if ( !isdigit(*pStr) )
      break;
    v14 = atoi(a2, pStr);
    v4 = 1;
LABEL_12:
    if ( !v16.Size )
      return;
  }
  v7 = v18;
  pStr = v17;
LABEL_15:
  v12 = v15;
  v15->DefaultStrValue.pStr = pStr;
  v12->DefaultStrValue.Size = v7;
}
