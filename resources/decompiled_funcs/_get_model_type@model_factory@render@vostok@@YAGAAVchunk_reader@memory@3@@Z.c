unsigned __int16 __usercall vostok::render::model_factory::get_model_type@<ax>(
        vostok::memory::chunk_reader *chunk@<eax>)
{
  vostok::memory::chunk_reader::chunk_type *v3; // [esp+0h] [ebp-34h]
  unsigned int chunk_id; // [esp+4h] [ebp-30h] BYREF
  vostok::render::model_header header; // [esp+8h] [ebp-2Ch] BYREF

  vostok::memory::chunk_reader::chunk_size(
    (vostok::memory::chunk_reader *)1,
    (int)chunk,
    (vostok::memory::chunk_reader::chunk_type *)&chunk_id,
    v3);
  memcpy(&header.platform_id, (unsigned __int8 *)chunk->m_reader.m_pointer, sizeof(header));
  return header.type;
}
