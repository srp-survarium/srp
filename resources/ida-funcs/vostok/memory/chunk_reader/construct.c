void __usercall vostok::memory::chunk_reader::construct(vostok::memory::chunk_reader *this@<ecx>, int a2@<eax>)
{
  int v2; // ecx
  vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader> *v3; // ecx

  v2 = *(_DWORD *)(a2 + 28);
  if ( v2 )
  {
    v3 = (vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader> *)(v2 - 1);
    if ( v3 )
      vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader>::construct(v3);
    else
      vostok::memory::array_chunk_reader<vostok::memory::chunk_reader>::construct(0);
  }
  else
  {
    *(_DWORD *)(a2 + 20) = 0;
  }
}
