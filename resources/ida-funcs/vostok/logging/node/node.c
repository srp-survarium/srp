void __userpurge vostok::logging::node::node(
        vostok::logging::node *this@<ecx>,
        int a2@<esi>,
        char *name,
        const vostok::logging::verbosity filter)
{
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  vostok::strings::copy<32>((char (*)[32])(a2 + 16), name);
  *(_DWORD *)(a2 + 48) = 0;
  *(_DWORD *)(a2 + 60) = 0;
  *(_DWORD *)(a2 + 52) = a2 + 48;
  *(_DWORD *)(a2 + 56) = a2 + 48;
  *(_DWORD *)(a2 + 68) = -1;
  *(_DWORD *)(a2 + 64) = filter;
}
