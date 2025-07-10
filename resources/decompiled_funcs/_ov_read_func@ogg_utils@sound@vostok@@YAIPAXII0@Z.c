unsigned int __cdecl vostok::sound::ogg_utils::ov_read_func(
        void *ptr,
        unsigned int size,
        unsigned int nmemb,
        vostok::sound::ogg_file_source *datasource)
{
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> value; // [esp+0h] [ebp-A0h] BYREF
  __int64 v6; // [esp+4h] [ebp-9Ch]
  float v7; // [esp+Ch] [ebp-94h]
  __int64 v8; // [esp+10h] [ebp-90h]
  char v9; // [esp+27h] [ebp-79h]
  char v10; // [esp+28h] [ebp-78h]
  char v11; // [esp+29h] [ebp-77h]
  char v12; // [esp+2Ah] [ebp-76h]
  char v13; // [esp+2Bh] [ebp-75h]
  unsigned int v14; // [esp+2Ch] [ebp-74h]
  unsigned int v15; // [esp+30h] [ebp-70h]
  signed int v16; // [esp+34h] [ebp-6Ch]
  int v17; // [esp+38h] [ebp-68h]
  unsigned int pointer; // [esp+54h] [ebp-4Ch]
  char v19; // [esp+58h] [ebp-48h]
  char v20; // [esp+59h] [ebp-47h]
  char v21; // [esp+5Ah] [ebp-46h]
  char v22; // [esp+5Bh] [ebp-45h]
  const unsigned __int8 *m_data; // [esp+5Ch] [ebp-44h]
  unsigned int m_size; // [esp+60h] [ebp-40h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *p_value; // [esp+6Ch] [ebp-34h]
  unsigned int v26; // [esp+70h] [ebp-30h]
  vostok::memory::reader r; // [esp+78h] [ebp-28h] BYREF
  unsigned int bytes_to_read; // [esp+84h] [ebp-1Ch]
  vostok::sound::ogg_file_source *sdata; // [esp+88h] [ebp-18h]
  vostok::resources::pinned_ptr_const<unsigned char> pdata; // [esp+8Ch] [ebp-14h] BYREF
  unsigned int exist_block; // [esp+98h] [ebp-8h]
  unsigned int read_block; // [esp+9Ch] [ebp-4h]

  sdata = datasource;
  p_value = &value;
  *(float *)&value.m_object = 0.0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &value,
    &datasource->resource);
  vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
    &pdata,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)value.m_object);
  m_size = pdata.m_size;
  m_data = pdata.m_data;
  r.m_data = pdata.m_data;
  r.m_pointer = pdata.m_data;
  r.m_size = pdata.m_size;
  v22 = 0;
  pointer = sdata->pointer;
  v21 = 0;
  v20 = 0;
  v19 = 0;
  r.m_pointer = &pdata.m_data[pointer];
  v8 = size;
  v7 = (float)size;
  v6 = (unsigned int)vostok::memory::reader::elapsed(&r);
  *(float *)&value.m_object = (double)v6 / v7;
  v16 = vostok::math::floor(*(float *)&value.m_object);
  v17 = 0;
  exist_block = -(v16 > 0 ? -v16 : 0);
  v14 = nmemb;
  v15 = exist_block;
  read_block = nmemb + (exist_block < nmemb ? exist_block - nmemb : 0);
  bytes_to_read = size * read_block;
  v13 = 0;
  v12 = 0;
  v11 = 0;
  vostok::memory::copy(ptr, size * read_block, r.m_pointer, size * read_block);
  r.m_pointer += bytes_to_read;
  v10 = 0;
  v9 = 0;
  sdata->pointer = r.m_pointer - r.m_data;
  v26 = read_block;
  vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&pdata);
  return v26;
}
