void __userpurge vostok::network_core::buffer_writer::serialization_operation_descriptor::serialization_operation_descriptor(
        vostok::network_core::buffer_writer::serialization_operation_descriptor *this@<ecx>,
        int a2@<eax>,
        const char *const type,
        const char *const expression,
        const char *const function,
        const char *const file,
        const int line,
        char value_size,
        const unsigned __int8 player_id)
{
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = this;
  *(_DWORD *)(a2 + 8) = type;
  *(_DWORD *)(a2 + 12) = expression;
  *(_DWORD *)(a2 + 16) = function;
  *(_DWORD *)(a2 + 20) = file;
  *(_DWORD *)(a2 + 24) = line;
  *(_BYTE *)(a2 + 28) = value_size;
}
