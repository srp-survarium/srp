void __userpurge ppmd_allocator::SplitBlock(
        ppmd_allocator *this@<eax>,
        unsigned int NewIndx@<ecx>,
        char *pv,
        unsigned int OldIndx)
{
  int v4; // ecx
  unsigned int v5; // edx
  BLK_NODE *v6; // ecx
  int v7; // esi
  unsigned int v8; // edi
  int v9; // esi
  BLK_NODE *v10; // eax

  v4 = this->Indx2Units[NewIndx];
  v5 = this->Indx2Units[OldIndx] - v4;
  v6 = (BLK_NODE *)&pv[12 * v4];
  v7 = this->Indx2Units[v5 + 37];
  if ( this->Indx2Units[v7] != v5 )
  {
    v8 = *((unsigned __int8 *)&this->BList[37].next + v7 + 3);
    v9 = v7 - 1;
    v6->next = this->BList[v9].next;
    this->BList[v9].next = v6;
    v6->Stamp = -1;
    v6[1].Stamp = v8;
    ++this->BList[v9].Stamp;
    v6 = (BLK_NODE *)((char *)v6 + 12 * v8);
    v5 -= v8;
  }
  v10 = &this->BList[this->Indx2Units[v5 + 37]];
  v6->next = v10->next;
  v10->next = v6;
  v6->Stamp = -1;
  v6[1].Stamp = v5;
  ++v10->Stamp;
}
