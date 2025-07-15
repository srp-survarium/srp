char __userpurge Scaleform::Render::D3D1x::MeshBufferSet::Alloc@<al>(
        Scaleform::Render::D3D1x::MeshBufferSet *this@<esi>,
        unsigned int size@<eax>,
        Scaleform::Render::D3D1x::MeshBuffer **pbuffer,
        unsigned int *poffset)
{
  unsigned int v4; // eax

  v4 = Scaleform::AllocAddr::Alloc(&this->Allocator, (size + 15) >> 4);
  if ( v4 == -1 )
    return 0;
  *pbuffer = this->Buffers.Data.Data[HIBYTE(v4)];
  *poffset = 16 * ((unsigned int)&s_ui_commands_allocator.m_buffer[2035359] & v4);
  return 1;
}
