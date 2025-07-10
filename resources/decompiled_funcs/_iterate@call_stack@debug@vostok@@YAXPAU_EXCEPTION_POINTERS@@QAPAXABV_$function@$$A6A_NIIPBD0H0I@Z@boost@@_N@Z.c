void __usercall vostok::debug::call_stack::iterate(
        vostok::memory::base_allocator *a1@<ecx>,
        unsigned int a2@<ebx>,
        _EXCEPTION_POINTERS *pointers,
        void **call_stack,
        vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *callback,
        bool invert_order)
{
  __int64 v6; // rax
  int v7; // ecx
  __int64 v8; // rax
  int v9; // ecx
  HANDLE v10; // eax
  HANDLE CurrentThread; // eax
  void *v12; // [esp+0h] [ebp-2018h]
  unsigned __int64 v13; // [esp+4h] [ebp-2014h]
  unsigned int j; // [esp+8h] [ebp-2010h]
  const char *v15; // [esp+Ch] [ebp-200Ch]
  unsigned int i; // [esp+Ch] [ebp-200Ch]
  unsigned __int64 ranOffsets[2]; // [esp+10h] [ebp-2008h] BYREF
  unsigned int num_call_stack_lines; // [esp+2014h] [ebp-4h]

  initialize(a1, v12, v13, v15);
  if ( pointers || !s_pfnCaptureStackBackTrace )
  {
    CurrentThread = GetCurrentThread();
    GetStackTrace(a2, CurrentThread, pointers, callback, invert_order);
  }
  else
  {
    num_call_stack_lines = 0;
    if ( call_stack )
    {
      for ( i = 0; i < 0x200; ++i )
      {
        v6 = (int)call_stack[i];
        v7 = 2 * i;
        LODWORD(ranOffsets[v7]) = v6;
        HIDWORD(ranOffsets[v7]) = HIDWORD(v6);
        v8 = (int)call_stack[i];
        v9 = 2 * i;
        LODWORD(ranOffsets[v9 + 1]) = v8;
        HIDWORD(ranOffsets[v9 + 1]) = HIDWORD(v8);
        if ( !call_stack[i] )
        {
          num_call_stack_lines = i;
          break;
        }
      }
    }
    else
    {
      v10 = GetCurrentThread();
      GetStackTraceFast(v10, (unsigned __int64 (*)[2])ranOffsets);
      num_call_stack_lines = 0;
      for ( j = 0;
            j < 0x200
         && (HIDWORD(ranOffsets[2 * j]) | LODWORD(ranOffsets[2 * j])
          || HIDWORD(ranOffsets[2 * j + 1]) | LODWORD(ranOffsets[2 * j + 1]));
            ++j )
      {
        ++num_call_stack_lines;
      }
    }
    WriteStackTrace(a2, (unsigned __int64 (*)[2])ranOffsets, num_call_stack_lines, callback, invert_order);
  }
}
