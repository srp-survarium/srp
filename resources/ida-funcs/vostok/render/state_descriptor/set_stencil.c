void __userpurge vostok::render::state_descriptor::set_stencil(
        vostok::render::state_descriptor *this@<ecx>,
        int a2@<esi>,
        int enable,
        unsigned int ref,
        unsigned __int8 read_mask,
        unsigned __int8 write_mask)
{
  bool is_set; // al

  is_set = vostok::command_line::key::is_set((vostok::command_line::key *)this, (int)&s_opt2);
  *(_BYTE *)(a2 + 361) = 1;
  *(_DWORD *)(a2 + 52) = !is_set ? enable : 0;
  *(_BYTE *)(a2 + 56) = read_mask;
  *(_BYTE *)(a2 + 57) = write_mask;
  *(_DWORD *)(a2 + 356) = ref;
}
