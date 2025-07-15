unsigned __int8 *__thiscall ppmd_allocator::ExpandUnits(
        ppmd_allocator *this,
        ppmd_allocator *OldPtr,
        BLK_NODE *OldNU,
        unsigned int a4)
{
  unsigned __int8 *result; // eax
  unsigned __int8 *v6; // ecx
  int v7; // edx
  _DWORD *v8; // edi
  unsigned __int8 *v9; // esi
  bool v10; // zf
  BLK_NODE *v11; // ecx
  int v12; // [esp+8h] [ebp-4h]
  int v13; // [esp+18h] [ebp+Ch]

  v12 = OldPtr->Indx2Units[a4 + 37];
  if ( v12 == OldPtr->Units2Indx[a4] )
    return (unsigned __int8 *)OldNU;
  result = ppmd_allocator::AllocUnits(OldPtr, a4 + 1);
  if ( result )
  {
    v13 = a4;
    v6 = result;
    v7 = (char *)OldNU - (char *)result;
    do
    {
      *(_DWORD *)v6 = *(_DWORD *)&v6[v7];
      *((_DWORD *)v6 + 1) = *(_DWORD *)&v6[v7 + 4];
      v9 = &v6[v7 + 8];
      v8 = v6 + 8;
      v6 += 12;
      v10 = v13-- == 1;
      *v8 = *(_DWORD *)v9;
    }
    while ( !v10 );
    v11 = &OldPtr->BList[v12];
    OldNU->next = OldPtr->BList[v12].next;
    v11->next = OldNU;
    OldNU->Stamp = -1;
    OldNU[1].Stamp = a4;
    ++v11->Stamp;
  }
  return result;
}
