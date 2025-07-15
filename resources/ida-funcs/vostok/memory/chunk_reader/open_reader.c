vostok::memory::reader *__usercall vostok::memory::chunk_reader::open_reader@<eax>(
        vostok::memory::chunk_reader *this@<ecx>,
        int a2@<eax>,
        _DWORD *a3@<edi>)
{
  int v4; // eax
  int v5; // ecx
  vostok::memory::chunk_reader::chunk_type *v7; // [esp+0h] [ebp-8h]
  vostok::memory::chunk_reader::chunk_type type; // [esp+4h] [ebp-4h] BYREF

  v4 = vostok::memory::chunk_reader::chunk_size(this, a2, &type, v7);
  v5 = *(_DWORD *)(a2 + 8);
  a3[2] = v4;
  *a3 = v5;
  a3[1] = v5;
  return (vostok::memory::reader *)a3;
}
