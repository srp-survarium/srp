char __thiscall vostok::collision::terrain_data::get_row_col(
        vostok::collision::terrain_data *this,
        const vostok::math::float3 *position_local,
        int *x,
        int *z)
{
  unsigned int m_vertex_row_size; // eax
  float cell_size; // [esp+0h] [ebp-10h]

  m_vertex_row_size = this->m_vertex_row_size;
  cell_size = this->m_physical_size / (double)(m_vertex_row_size - 1);
  return vostok::collision::get_row_col(x, z, cell_size, m_vertex_row_size, position_local);
}
