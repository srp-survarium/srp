char __userpurge vostok::render::hw_buffer_pool_chunk::allocate_range@<al>(
        vostok::render::hw_buffer_pool_chunk *this@<eax>,
        vostok::render::hw_buffer_pool_range *out_range@<edi>,
        vostok::render::hw_buffer_pool_chunk *a3@<ecx>,
        unsigned __int8 *initial_data,
        unsigned int num_bytes,
        const unsigned int stride,
        ID3D11Buffer *hw_temp_buffer,
        bool do_allocation)
{
  int *p_begin_offset; // ecx
  unsigned int v10; // eax
  vostok::buffer_vector<vostok::render::hw_buffer_pool_range> *v11; // ecx
  vostok::render::hw_buffer_pool_range *v12; // eax
  unsigned int v14; // eax
  vostok::threading::simple_lock *v15; // ecx
  vostok::threading::simple_lock *p_m_lock; // esi
  int v18; // [esp-4h] [ebp-360h]
  vostok::fixed_vector<vostok::render::hw_buffer_pool_range,64> out_array; // [esp+8h] [ebp-354h] BYREF
  char v20; // [esp+314h] [ebp-48h] BYREF
  _BYTE v21[24]; // [esp+31Ch] [ebp-40h] BYREF
  _BYTE v22[24]; // [esp+334h] [ebp-28h] BYREF
  unsigned int v23; // [esp+34Ch] [ebp-10h]
  unsigned int v24; // [esp+350h] [ebp-Ch]
  int *v25; // [esp+354h] [ebp-8h]

  out_array.m_begin = (vostok::render::hw_buffer_pool_range *)out_array.m_buffer;
  out_array.m_end = (vostok::render::hw_buffer_pool_range *)out_array.m_buffer;
  out_array.m_max_end = (vostok::render::hw_buffer_pool_range *)&v20;
  if ( !vostok::render::hw_buffer_pool_chunk::gather_free_ranges(
          a3,
          &this->allocations.m_begin,
          (vostok::render::hw_buffer_pool_range *)&out_array) )
    return 0;
  v23 = num_bytes / stride;
  if ( out_array.m_begin == out_array.m_end )
    return 0;
  p_begin_offset = &out_array.m_begin->begin_offset;
  v25 = &out_array.m_begin->begin_offset;
  while ( 1 )
  {
    v10 = *p_begin_offset;
    v11 = (vostok::buffer_vector<vostok::render::hw_buffer_pool_range> *)(p_begin_offset[1] - *p_begin_offset + 1);
    v24 = v10 / stride + 1;
    if ( v24 + v23 < (unsigned int)v11 / stride && (unsigned int)v11 + stride * v24 >= num_bytes + stride * v24 )
      break;
    p_begin_offset = v25 + 3;
    v12 = (vostok::render::hw_buffer_pool_range *)(v25 + 2);
    v25 += 3;
    if ( v12 == out_array.m_end )
      return 0;
  }
  if ( do_allocation )
  {
    v14 = stride * v24;
    out_range->begin_offset = stride * v24;
    out_range->owner = this;
    out_range->end_offset = v14 + num_bytes - 1;
    vostok::buffer_vector<vostok::render::hw_buffer_pool_range>::push_back(
      v11,
      (const vostok::render::hw_buffer_pool_range *)this,
      out_range);
    vostok::threading::simple_lock::lock(v15, (int)&this->m_pool->m_lock);
    ((void (__stdcall *)(ID3D11Buffer *, _BYTE *, int))hw_temp_buffer->GetDesc)(hw_temp_buffer, v21, v18);
    this->m_hw_buffer->GetDesc(this->m_hw_buffer, (D3D11_BUFFER_DESC *)v22);
    memcpy(&this->m_cpu_write_copy[out_range->begin_offset], initial_data, num_bytes);
    _InterlockedExchange(&this->m_changed, 1);
    p_m_lock = &this->m_pool->m_lock;
    if ( p_m_lock->m_lock-- == 1 )
      _InterlockedExchange(&p_m_lock->m_thread_id, 0);
  }
  else
  {
    this->m_sorting_leaved_bytes_in_range = (unsigned int)v11 - num_bytes;
  }
  return 1;
}
