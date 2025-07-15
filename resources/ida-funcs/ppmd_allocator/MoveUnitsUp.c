unsigned __int8 *__userpurge ppmd_allocator::MoveUnitsUp@<eax>(
        ppmd_allocator *this@<edx>,
        unsigned __int8 *OldPtr@<eax>,
        unsigned int NU)
{
  char *v3; // ecx
  unsigned __int8 *v4; // ebx
  int v5; // edi
  unsigned __int8 *v6; // edi
  bool v7; // zf
  unsigned __int8 *v8; // esi
  unsigned __int8 *UnitsStart; // edi
  int v10; // esi
  int v11; // [esp+8h] [ebp-Ch]
  unsigned int v12; // [esp+Ch] [ebp-8h]
  unsigned __int8 *v13; // [esp+10h] [ebp-4h]
  unsigned __int8 *v14; // [esp+1Ch] [ebp+8h]

  v11 = this->Indx2Units[NU + 37];
  if ( OldPtr <= this->UnitsStart + 0x4000 )
  {
    v3 = (char *)this + 8 * this->Indx2Units[NU + 37];
    if ( (unsigned int)OldPtr <= *((_DWORD *)v3 + 2) )
    {
      v4 = (unsigned __int8 *)*((_DWORD *)v3 + 2);
      v5 = *((_DWORD *)v4 + 1);
      --*((_DWORD *)v3 + 1);
      v13 = (unsigned __int8 *)(OldPtr - v4);
      *((_DWORD *)v3 + 2) = v5;
      v12 = NU;
      v14 = v4;
      do
      {
        v6 = v14;
        v14 += 12;
        v7 = v12-- == 1;
        *(_DWORD *)v6 = *(_DWORD *)&v13[(_DWORD)v6];
        v8 = &v13[(_DWORD)v6 + 4];
        v6 += 4;
        *(_DWORD *)v6 = *(_DWORD *)v8;
        *((_DWORD *)v6 + 1) = *((_DWORD *)v8 + 1);
      }
      while ( !v7 );
      UnitsStart = this->UnitsStart;
      v10 = this->Indx2Units[v11];
      if ( OldPtr == UnitsStart )
      {
        this->UnitsStart = &UnitsStart[12 * v10];
      }
      else
      {
        *((_DWORD *)OldPtr + 1) = *((_DWORD *)v3 + 2);
        *((_DWORD *)v3 + 2) = OldPtr;
        *(_DWORD *)OldPtr = -1;
        *((_DWORD *)OldPtr + 2) = v10;
        ++*((_DWORD *)v3 + 1);
      }
      return v4;
    }
  }
  return OldPtr;
}
