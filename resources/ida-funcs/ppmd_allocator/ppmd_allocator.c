ppmd_allocator *__usercall ppmd_allocator::ppmd_allocator@<eax>(ppmd_allocator *this@<ecx>, ppmd_allocator *a2@<eax>)
{
  int v3; // edx
  int v4; // ecx
  unsigned int v5; // eax
  int v6; // ecx
  int i; // ecx
  int j; // ecx
  int v9; // eax
  unsigned __int8 *Units2Indx; // ecx
  int v11; // edi
  ppmd_allocator *v13; // [esp+0h] [ebp-10h]
  unsigned int v14; // [esp+4h] [ebp-Ch]

  a2->m_allocator = &vostok::memory::g_cook_allocator;
  a2->SubAllocatorSize = 0;
  ppmd_allocator::StartSubAllocator(v13, v14);
  v3 = 4;
  v4 = 1;
  v5 = 4;
  do
  {
    *((_BYTE *)&a2->BList[37].next + v4 + 3) = v4;
    ++v4;
    --v3;
  }
  while ( v3 );
  v6 = v4 + 1;
  do
  {
    a2->Indx2Units[v5++] = v6;
    v6 += 2;
  }
  while ( v5 < 8 );
  for ( i = v6 + 1; v5 < 0xC; i += 3 )
    a2->Indx2Units[v5++] = i;
  for ( j = i + 1; v5 < 0x26; j += 4 )
    a2->Indx2Units[v5++] = j;
  v9 = 0;
  Units2Indx = a2->Units2Indx;
  v11 = 128;
  do
  {
    v9 += a2->Indx2Units[v9] < (unsigned int)&Units2Indx[-345 - (_DWORD)a2];
    *Units2Indx++ = v9;
    --v11;
  }
  while ( v11 );
  return a2;
}
