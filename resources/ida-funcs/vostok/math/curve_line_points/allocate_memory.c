void __userpurge vostok::math::curve_line_points<float,0>::allocate_memory(
        vostok::math::curve_line_points<float,0> *this@<ecx>,
        unsigned int num@<eax>,
        vostok::math::curve_line_points<float,0> *allocator)
{
  char *v5; // eax
  vostok::math::curve_line_points<float,0> *v6; // ecx

  vostok::math::curve_line_points<float,0>::free_memory(allocator, (int)this);
  this->num_points = num;
  if ( num )
  {
    v5 = type_info::raw_name(&vostok::math::curve_point<float> `RTTI Type Descriptor');
    this->points.pointer = (vostok::math::curve_point<float> *)(*(int (__thiscall **)(vostok::math::curve_line_points<float,0> *, unsigned int, char *, const char *, const char *, int))(LODWORD(allocator->curve_time_min) + 16))(
                                                                 allocator,
                                                                 24 * num,
                                                                 v5,
                                                                 "vostok::math::curve_line_points<float,0>::allocate_memory",
                                                                 "c:\\survarium.deploy\\sources\\vostok\\math_curve_inline.h",
                                                                 313);
    vostok::math::curve_line_points<float,0>::recalculate_ranges(v6, (int)this);
  }
}


void __userpurge vostok::math::curve_line_points<vostok::math::float4_pod,1>::allocate_memory(
        vostok::math::curve_line_points<vostok::math::float4_pod,1> *this@<ecx>,
        unsigned int num@<eax>,
        vostok::math::curve_line_points<vostok::math::float4_pod,1> *allocator)
{
  char *v5; // eax
  vostok::math::curve_line_points<vostok::math::float4_pod,1> *v6; // ecx

  vostok::math::curve_line_points<vostok::math::float4_pod,1>::free_memory(allocator, (int)this);
  this->num_points = num;
  if ( num )
  {
    v5 = type_info::raw_name(&vostok::math::curve_point<vostok::math::float4_pod> `RTTI Type Descriptor');
    this->points.pointer = (vostok::math::curve_point<vostok::math::float4_pod> *)(*(int (__thiscall **)(vostok::math::curve_line_points<vostok::math::float4_pod,1> *, unsigned int, char *, const char *, const char *, int))(LODWORD(allocator->curve_time_min) + 16))(
                                                                                    allocator,
                                                                                    72 * num,
                                                                                    v5,
                                                                                    "vostok::math::curve_line_points<clas"
                                                                                    "s vostok::math::float4_pod,1>::allocate_memory",
                                                                                    "c:\\survarium.deploy\\sources\\vosto"
                                                                                    "k\\math_curve_inline.h",
                                                                                    313);
    vostok::math::curve_line_points<vostok::math::float4_pod,1>::recalculate_ranges(v6, (int)this);
  }
}
