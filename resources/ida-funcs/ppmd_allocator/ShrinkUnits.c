char *__userpurge ppmd_allocator::ShrinkUnits@<eax>(
        ppmd_allocator *this@<eax>,
        unsigned int OldNU@<ecx>,
        char *OldPtr,
        unsigned int NewNU)
{
  unsigned int v4; // ecx
  unsigned int v6; // esi
  char *v7; // edx
  int v8; // esi
  int v9; // edi
  char *v10; // edx
  _DWORD *v11; // edi
  bool v12; // zf
  _DWORD *v13; // esi
  int v14; // edx
  BLK_NODE *v15; // ecx
  char *result; // eax
  char *v17; // [esp+8h] [ebp-4h]
  unsigned int v18; // [esp+14h] [ebp+8h]
  _DWORD *v19; // [esp+18h] [ebp+Ch]

  v4 = this->Indx2Units[OldNU + 37];
  v6 = this->Indx2Units[NewNU + 37];
  if ( v4 == v6 )
    return OldPtr;
  v7 = (char *)this + 8 * v6;
  if ( !*((_DWORD *)v7 + 2) )
  {
    ppmd_allocator::SplitBlock(this, v6, OldPtr, v4);
    return OldPtr;
  }
  v8 = *((_DWORD *)v7 + 2);
  v9 = *(_DWORD *)(v8 + 4);
  --*((_DWORD *)v7 + 1);
  *((_DWORD *)v7 + 2) = v9;
  v18 = NewNU;
  v17 = (char *)v8;
  v19 = (_DWORD *)v8;
  v10 = &OldPtr[-v8];
  do
  {
    v11 = v19;
    v19 += 3;
    v12 = v18-- == 1;
    *v11 = *(_DWORD *)((char *)v11 + (_DWORD)v10);
    v13 = (_DWORD *)((char *)v11++ + (_DWORD)v10 + 4);
    *v11 = *v13;
    v11[1] = v13[1];
  }
  while ( !v12 );
  v14 = this->Indx2Units[v4];
  v15 = &this->BList[v4];
  *((_DWORD *)OldPtr + 1) = v15->next;
  result = v17;
  v15->next = (BLK_NODE *)OldPtr;
  *(_DWORD *)OldPtr = -1;
  *((_DWORD *)OldPtr + 2) = v14;
  ++v15->Stamp;
  return result;
}
