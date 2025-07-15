void __thiscall vostok::network_core::buffer_writer::w_string(
        vostok::network_core::buffer_writer *this,
        char *string,
        int a3)
{
  vostok::network_core::buffer_writer *v3; // ecx
  vostok::network_core::buffer_writer *v4; // [esp+0h] [ebp-4h] BYREF

  v4 = this;
  LOBYTE(v4) = strlen((const char *)a3);
  vostok::network_core::buffer_writer::w(
    (vostok::network_core::buffer_writer *)(a3 + 1),
    string,
    (unsigned __int8 *)&v4,
    1u);
  vostok::network_core::buffer_writer::w(v3, string, (unsigned __int8 *)a3, (unsigned __int8)v4);
}
