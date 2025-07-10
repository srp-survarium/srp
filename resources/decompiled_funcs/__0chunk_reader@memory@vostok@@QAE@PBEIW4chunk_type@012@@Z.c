void __userpurge vostok::memory::chunk_reader::chunk_reader(
        vostok::memory::chunk_reader *this@<ecx>,
        _DWORD *a2@<eax>,
        const unsigned __int8 *data,
        unsigned int size,
        vostok::memory::chunk_reader::chunk_type type)
{
  a2[1] = this;
  a2[2] = this;
  a2[3] = data;
  a2[4] = 0;
  a2[6] = 0;
  a2[7] = 0;
  a2[5] = 0;
}
