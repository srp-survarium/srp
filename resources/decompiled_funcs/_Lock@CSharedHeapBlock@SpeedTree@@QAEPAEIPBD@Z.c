unsigned __int8 *__thiscall SpeedTree::CSharedHeapBlock::Lock(
        SpeedTree::CSharedHeapBlock *this,
        unsigned int a2,
        char *buf)
{
  void **v5; // [esp+34h] [ebp-118h] BYREF
  int v6; // [esp+13Ch] [ebp-10h]
  int v7; // [esp+148h] [ebp-4h]

  v6 = 0;
  if ( *((_BYTE *)this + 272) )
  {
    SpeedTree::CCore::SetError("CSharedHeapBlock::Lock(), overlapping tmp buffer requests; likely CCore::UnlockTmpBuffer was not called");
  }
  else
  {
    *((_BYTE *)this + 272) = 1;
    v5 = &SpeedTree::CBasicFixedString<1024>::`vftable';
    SpeedTree::CBasicFixedString<1024>::operator=((unsigned __int8 *)buf);
    v7 = 0;
    SpeedTree::CBasicFixedString<1024>::operator=(&v5);
    v7 = -1;
    v5 = &SpeedTree::CBasicFixedString<1024>::`vftable';
    if ( a2 > *((_DWORD *)this + 1) )
    {
      SpeedTree::st_delete_array<unsigned char>(this);
      *((_DWORD *)this + 1) = a2;
      *(_DWORD *)this = SpeedTree::st_new_array<unsigned char>(*((_DWORD *)this + 1), "CSharedHeapBlock");
    }
    return *(unsigned __int8 **)this;
  }
  return (unsigned __int8 *)v6;
}
