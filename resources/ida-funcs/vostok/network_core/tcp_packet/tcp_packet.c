void __usercall vostok::network_core::tcp_packet::tcp_packet(
        vostok::network_core::tcp_packet *this@<ecx>,
        int a2@<esi>)
{
  *(_DWORD *)a2 = this;
  *(_DWORD *)(a2 + 4) = (*(int (__thiscall **)(vostok::network_core::tcp_packet *, int, const char *, const char *, const char *, int))&this->m_buffer.m_allocator->m_use_memory_monitor)(
                          this,
                          1024,
                          "network_core::mutable_buffer",
                          "vostok::network_core::mutable_buffer::mutable_buffer",
                          "c:\\survarium.deploy\\sources\\vostok/network_core/mutable_buffer_inline.h",
                          23);
  *(_DWORD *)(a2 + 8) = 1024;
  *(_DWORD *)(a2 + 12) = 3;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  *(_BYTE *)(a2 + 32) = -1;
  *(_DWORD *)(a2 + 36) = a2;
}
