void __usercall raii_buffer::~raii_buffer(raii_buffer *this@<ecx>, int a2@<eax>)
{
  HANDLE ProcessHeap; // eax
  void *v3; // [esp-4h] [ebp-4h]

  if ( *(_BYTE *)(a2 + 4) )
  {
    v3 = *(void **)a2;
    ProcessHeap = GetProcessHeap();
    HeapFree(ProcessHeap, 0, v3);
  }
}
