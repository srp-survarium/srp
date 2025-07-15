void __userpurge vostok::particle::color_matrix::allocate_memory(
        vostok::particle::color_matrix *this@<ecx>,
        unsigned int num_rows@<eax>,
        vostok::particle::color_matrix *allocator,
        unsigned int num_columns)
{
  char *v6; // eax

  vostok::particle::color_matrix::free_memory(allocator, this);
  this->m_num_rows = num_rows;
  this->m_num_columns = num_columns;
  v6 = type_info::raw_name(&vostok::particle::color_matrix_point_type `RTTI Type Descriptor');
  this->m_points.pointer = (vostok::particle::color_matrix_point_type *)((int (__thiscall *)(vostok::particle::color_matrix *, unsigned int, char *, const char *, const char *, int))LODWORD(allocator->m_points.pointer->position.x))(
                                                                          allocator,
                                                                          24 * num_columns * num_rows,
                                                                          v6,
                                                                          "vostok::particle::color_matrix::allocate_memory",
                                                                          "c:\\survarium.deploy\\sources\\vostok\\particl"
                                                                          "e\\sources\\color_matrix_inline.h",
                                                                          268);
}
