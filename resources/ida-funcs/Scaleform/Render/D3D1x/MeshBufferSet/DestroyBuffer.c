void __userpurge Scaleform::Render::D3D1x::MeshBufferSet::DestroyBuffer(
        Scaleform::Render::D3D1x::MeshBufferSet *this@<edi>,
        Scaleform::Render::D3D1x::MeshBuffer *pbuffer@<esi>,
        bool deleteBuffer)
{
  Scaleform::AllocAddr::RemoveSegment(&this->Allocator, pbuffer->Index << 24, (pbuffer->Size + 15) >> 4);
  this->TotalSize -= pbuffer->Size;
  this->Buffers.Data.Data[pbuffer->Index] = 0;
  if ( deleteBuffer )
    ((void (__thiscall *)(Scaleform::Render::D3D1x::MeshBuffer *, int))pbuffer->~Scaleform::Render::D3D1x::MeshBuffer)(
      pbuffer,
      1);
}
