int __cdecl vostok::sound::ogg_utils::ov_seek_func(
        vostok::sound::ogg_file_source *datasource,
        __int64 offset_bytes,
        int whence)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v4; // [esp-4h] [ebp-64h] BYREF
  int v5; // [esp+0h] [ebp-60h]
  char v6; // [esp+Bh] [ebp-55h]
  char v7; // [esp+Ch] [ebp-54h]
  char v8; // [esp+Dh] [ebp-53h]
  char v9; // [esp+Eh] [ebp-52h]
  char v10; // [esp+Fh] [ebp-51h]
  unsigned int v11; // [esp+10h] [ebp-50h]
  char v12; // [esp+14h] [ebp-4Ch]
  char v13; // [esp+15h] [ebp-4Bh]
  char v14; // [esp+16h] [ebp-4Ah]
  char v15; // [esp+17h] [ebp-49h]
  char v16; // [esp+18h] [ebp-48h]
  char v17; // [esp+19h] [ebp-47h]
  char v18; // [esp+1Ah] [ebp-46h]
  char v19; // [esp+1Bh] [ebp-45h]
  unsigned int pointer; // [esp+1Ch] [ebp-44h]
  char v21; // [esp+20h] [ebp-40h]
  char v22; // [esp+21h] [ebp-3Fh]
  char v23; // [esp+22h] [ebp-3Eh]
  char v24; // [esp+23h] [ebp-3Dh]
  const unsigned __int8 *m_data; // [esp+24h] [ebp-3Ch]
  unsigned int m_size; // [esp+28h] [ebp-38h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v27; // [esp+34h] [ebp-2Ch]
  volatile int *value; // [esp+38h] [ebp-28h]
  int v29; // [esp+3Ch] [ebp-24h]
  vostok::memory::reader r; // [esp+44h] [ebp-1Ch]
  vostok::sound::ogg_file_source *sdata; // [esp+50h] [ebp-10h]
  vostok::resources::pinned_ptr_const<unsigned char> pdata; // [esp+54h] [ebp-Ch] BYREF

  sdata = datasource;
  v27 = &v4;
  v4.m_object = 0;
  if ( datasource->resource.m_object )
  {
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(v27);
    v27->m_object = (vostok::resources::managed_resource *)sdata->resource;
    if ( v27->m_object )
    {
      value = &v27->m_object->m_reference_count;
      vostok::threading::multi_threading_policy::increment<long volatile>(value);
    }
  }
  vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(&pdata, v4);
  m_size = pdata.m_size;
  m_data = pdata.m_data;
  r.m_data = pdata.m_data;
  r.m_pointer = pdata.m_data;
  r.m_size = pdata.m_size;
  v24 = 0;
  pointer = sdata->pointer;
  v23 = 0;
  v22 = 0;
  v21 = 0;
  r.m_pointer = &pdata.m_data[pointer];
  v5 = whence;
  if ( whence )
  {
    if ( v5 == 1 )
    {
      v16 = 0;
      v15 = 0;
      v14 = 0;
      r.m_pointer += offset_bytes;
    }
    else if ( v5 == 2 )
    {
      v13 = 0;
      v12 = 0;
      v11 = r.m_size;
      v10 = 0;
      v9 = 0;
      v8 = 0;
      r.m_pointer = &r.m_data[r.m_size + offset_bytes];
    }
  }
  else
  {
    v19 = 0;
    v18 = 0;
    v17 = 0;
    r.m_pointer = &r.m_data[offset_bytes];
  }
  v7 = 0;
  v6 = 0;
  sdata->pointer = r.m_pointer - r.m_data;
  v29 = 0;
  vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&pdata);
  return v29;
}
