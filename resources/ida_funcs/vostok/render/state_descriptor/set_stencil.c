void __userpurge vostok::render::state_descriptor::set_stencil(
        vostok::render::state_descriptor *this@<ecx>,
        int a2@<eax>,
        unsigned int enable,
        unsigned __int8 ref,
        unsigned __int8 read_mask,
        unsigned __int8 write_mask)
{
  *(_DWORD *)(a2 + 52) = this;
  *(_BYTE *)(a2 + 56) = ref;
  *(_BYTE *)(a2 + 57) = read_mask;
  *(_DWORD *)(a2 + 356) = enable;
  *(_BYTE *)(a2 + 361) = 1;
}
