void __thiscall ppmd_allocator::GlueFreeBlocks(ppmd_allocator *this)
{
  unsigned __int8 *LoUnit; // eax
  MEM_BLK *p_s0; // ebx
  BLK_NODE **p_next; // esi
  MEM_BLK *v4; // eax
  BLK_NODE *next; // edx
  unsigned int NU; // edx
  int v7; // edx
  bool v8; // zf
  MEM_BLK *v9; // edx
  BLK_NODE *v10; // ebp
  BLK_NODE *v11; // eax
  unsigned int Stamp; // edx
  unsigned int v13; // esi
  int v14; // edi
  int v15; // ebx
  unsigned int v16; // esi
  unsigned int v17; // ebx
  unsigned int *v18; // edx
  unsigned int v19; // edx
  int v20; // [esp+0h] [ebp-10h]
  MEM_BLK s0; // [esp+4h] [ebp-Ch] BYREF

  LoUnit = this->LoUnit;
  if ( LoUnit != this->HiUnit )
    *LoUnit = 0;
  p_s0 = &s0;
  s0.next = 0;
  p_next = &this->BList[0].next;
  v20 = 38;
  do
  {
    while ( *p_next )
    {
      v4 = (MEM_BLK *)*p_next;
      next = (*p_next)->next;
      *(p_next - 1) = (BLK_NODE *)((char *)*(p_next - 1) - 1);
      *p_next = next;
      NU = v4->NU;
      if ( NU )
      {
        v7 = NU;
        v8 = v4[v7].Stamp == -1;
        v9 = &v4[v7];
        if ( v8 )
        {
          do
          {
            v4->NU += v9->NU;
            v9->NU = 0;
            v9 = &v4[v4->NU];
          }
          while ( v9->Stamp == -1 );
        }
        v4->next = p_s0->next;
        p_s0->next = v4;
        p_s0 = v4;
      }
    }
    p_next += 2;
    --v20;
  }
  while ( v20 );
  v10 = s0.next;
  while ( v10 )
  {
    --s0.Stamp;
    v11 = v10;
    Stamp = v10[1].Stamp;
    v10 = v10->next;
    if ( Stamp )
    {
      if ( Stamp > 0x80 )
      {
        v13 = ((Stamp - 129) >> 7) + 1;
        do
        {
          v11->next = this->BList[37].next;
          this->BList[37].next = v11;
          v11->Stamp = -1;
          v11[1].Stamp = 128;
          ++this->BList[37].Stamp;
          Stamp -= 128;
          v11 += 192;
          --v13;
        }
        while ( v13 );
      }
      v14 = this->Indx2Units[Stamp + 37];
      if ( this->Indx2Units[v14] != Stamp )
      {
        v15 = *((unsigned __int8 *)&this->BList[37].next + v14-- + 3);
        v16 = Stamp - v15;
        v17 = *((_DWORD *)&this->m_allocator + 2 * (Stamp - v15));
        v18 = &v11->Stamp + 3 * (Stamp - v16);
        v18[1] = v17;
        *((_DWORD *)&this->m_allocator + 2 * v16) = v18;
        *v18 = -1;
        v18[2] = v16;
        ++*((_DWORD *)this + 2 * v16 - 1);
      }
      v19 = this->Indx2Units[v14];
      v11->next = this->BList[v14].next;
      this->BList[v14].next = v11;
      v11->Stamp = -1;
      v11[1].Stamp = v19;
      ++this->BList[v14].Stamp;
    }
  }
  this->GlueCount = 0x2000;
}
