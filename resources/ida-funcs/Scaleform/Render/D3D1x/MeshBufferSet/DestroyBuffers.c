void __userpurge Scaleform::Render::D3D1x::MeshBufferSet::DestroyBuffers(
        Scaleform::Render::D3D1x::MeshBufferSet *this@<ecx>,
        Scaleform::Render::D3D1x::MeshBufferSet *a2@<eax>,
        Scaleform::Render::MeshBuffer::AllocType type)
{
  unsigned int i; // ebx
  Scaleform::Render::D3D1x::MeshBuffer **v5; // eax

  for ( i = 0; i < a2->Buffers.Data.Size; ++i )
  {
    v5 = &a2->Buffers.Data.Data[i];
    if ( *v5 && (type == AT_None || (*v5)->Type == type) )
      Scaleform::Render::D3D1x::MeshBufferSet::DestroyBuffer(a2, *v5, 1);
  }
}
