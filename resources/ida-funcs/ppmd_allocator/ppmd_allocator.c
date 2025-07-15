ppmd_allocator *__usercall ppmd_allocator::ppmd_allocator@<eax>(ppmd_allocator *this@<ecx>, ppmd_allocator *a2@<eax>)
{
  vostok::memory::base_allocator *m_allocator; // edi
  char *v4; // eax
  unsigned __int8 *v5; // eax
  int v6; // edx
  int v7; // eax
  unsigned int v8; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // ecx
  unsigned __int8 *Units2Indx; // eax
  ppmd_allocator *v15; // [esp+0h] [ebp-10h]
  int v16; // [esp+Ch] [ebp-4h]

  a2->SubAllocatorSize = 0;
  a2->m_allocator = &vostok::memory::g_cook_allocator;
  ppmd_allocator::StopSubAllocator(a2, v15);
  m_allocator = a2->m_allocator;
  v4 = type_info::raw_name(&unsigned char `RTTI Type Descriptor');
  v5 = (unsigned __int8 *)m_allocator->call_malloc(
                            m_allocator,
                            (unsigned int)&loc_100000,
                            v4,
                            "ppmd_allocator::StartSubAllocator",
                            "c:\\survarium.deploy\\sources\\vostok\\core\\sources\\compressor_ppmd_allocator.h",
                            159u);
  a2->HeapStart = v5;
  if ( v5 )
    a2->SubAllocatorSize = (unsigned int)&loc_100000;
  v6 = 4;
  v7 = 1;
  v8 = 4;
  do
  {
    *((_BYTE *)&a2->BList[37].next + v7 + 3) = v7;
    ++v7;
    --v6;
  }
  while ( v6 );
  v9 = v7 + 1;
  do
  {
    a2->Indx2Units[v8++] = v9;
    v9 += 2;
  }
  while ( v8 < 8 );
  v10 = v9 + 1;
  while ( v8 < 0xC )
  {
    a2->Indx2Units[v8++] = v10;
    v10 += 3;
  }
  v11 = v10 + 1;
  while ( v8 < 0x26 )
  {
    a2->Indx2Units[v8++] = v11;
    v11 += 4;
  }
  v12 = 0;
  Units2Indx = a2->Units2Indx;
  v16 = 128;
  do
  {
    v12 += a2->Indx2Units[v12] < (unsigned int)&Units2Indx[-345 - (_DWORD)a2];
    *Units2Indx++ = v12;
    --v16;
  }
  while ( v16 );
  return a2;
}
