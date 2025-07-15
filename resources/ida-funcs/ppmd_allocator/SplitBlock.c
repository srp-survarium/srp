void __userpurge ppmd_allocator::SplitBlock(
        ppmd_allocator *this@<eax>,
        unsigned int NewIndx@<ecx>,
        char *pv,
        unsigned int OldIndx)
{
  int v4; // ecx
  int v5; // edx
  char *v6; // ecx
  int v7; // esi
  int v8; // edi
  BLK_NODE *v9; // esi
  BLK_NODE *v10; // eax

  v4 = this->Indx2Units[NewIndx];
  v5 = this->Indx2Units[OldIndx] - v4;
  v6 = &pv[12 * v4];
  v7 = this->Indx2Units[v5 + 37];
  if ( this->Indx2Units[v7] != v5 )
  {
    v8 = *((unsigned __int8 *)&this->BList[37].next + v7 + 3);
    v9 = &this->BList[v7 - 1];
    *((_DWORD *)v6 + 1) = v9->next;
    v9->next = (BLK_NODE *)v6;
    *(_DWORD *)v6 = -1;
    *((_DWORD *)v6 + 2) = v8;
    ++v9->Stamp;
    v6 += 12 * v8;
    v5 -= v8;
  }
  v10 = &this->BList[this->Indx2Units[v5 + 37]];
  *((_DWORD *)v6 + 1) = v10->next;
  v10->next = (BLK_NODE *)v6;
  *(_DWORD *)v6 = -1;
  *((_DWORD *)v6 + 2) = v5;
  ++v10->Stamp;
}
