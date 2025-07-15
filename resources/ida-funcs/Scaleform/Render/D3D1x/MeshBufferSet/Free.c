unsigned int __userpurge Scaleform::Render::D3D1x::MeshBufferSet::Free@<eax>(
        Scaleform::Render::D3D1x::MeshBuffer *pbuffer@<eax>,
        unsigned int offset@<ecx>,
        Scaleform::Render::D3D1x::MeshBufferSet *this,
        unsigned int size)
{
  return 16 * Scaleform::AllocAddr::Free(&this->Allocator, (offset >> 4) | (pbuffer->Index << 24), (size + 15) >> 4);
}
