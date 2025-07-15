void __usercall survarium::create_wire_visual_source(
        vostok::memory::writer *writer@<eax>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        vostok::math::float3 *points,
        unsigned int points_count,
        const char *material_name,
        unsigned int wire_width,
        unsigned int a9,
        unsigned int a10)
{
  unsigned int v10; // ebx
  vostok::memory::writer_base *v12; // ecx
  void (__thiscall *write)(struct vostok::memory::writer *, const void *, unsigned int); // edx
  vostok::memory::writer_base *v14; // ecx
  void (__thiscall *v15)(struct vostok::memory::writer *, const void *, unsigned int); // edx
  float v16; // esi
  unsigned int v17; // esi
  vostok::memory::writer_vtbl *v18; // eax
  __int64 v21; // [esp+0h] [ebp-38h]
  const vostok::math::float4x4 *v22; // [esp+8h] [ebp-30h]
  vostok::render::model_header hdr; // [esp+Ch] [ebp-2Ch] BYREF

  v10 = points_count;
  *(_QWORD *)&hdr.bb.min.x = 0xBF800000BF800000uLL;
  v22 = clear_value;
  hdr.bb.min.z = -1.0;
  LODWORD(v21) = clear_value;
  HIDWORD(v21) = clear_value;
  hdr.platform_id = 0;
  *(_QWORD *)&hdr.bb.max.x = v21;
  LODWORD(hdr.bb.max.z) = clear_value;
  hdr.type = 101;
  vostok::memory::writer_base::open_chunk(writer, 1u);
  ((void (__thiscall *)(vostok::memory::writer *, vostok::render::model_header *, int, int, int, int))writer->write)(
    writer,
    &hdr,
    44,
    a3,
    a4,
    a2);
  vostok::memory::writer_base::close_chunk(v12, writer);
  vostok::memory::writer_base::open_chunk(writer, 2u);
  writer->write(writer, "editor/wire", strlen("editor/wire") + 1);
  write = writer->write;
  a9 = a10;
  write(writer, &a9, 4u);
  vostok::memory::writer_base::close_chunk(v14, writer);
  vostok::memory::writer_base::open_chunk(writer, 3u);
  v15 = writer->write;
  a9 = points_count;
  v15(writer, &a9, 4u);
  if ( points_count )
  {
    v16 = *(float *)&wire_width;
    do
    {
      writer->write(writer, (const void *)LODWORD(v16), 12u);
      LODWORD(v16) += 12;
      --v10;
    }
    while ( v10 );
  }
  v17 = writer->tell(writer);
  writer->seek(writer, *(writer->m_chunk_pos._M_impl._M_finish - 1));
  v18 = writer->__vftable;
  wire_width = v17 - *(writer->m_chunk_pos._M_impl._M_finish - 1) - 4;
  v18->write(writer, &wire_width, 4u);
  writer->seek(writer, v17);
  --writer->m_chunk_pos._M_impl._M_finish;
}
