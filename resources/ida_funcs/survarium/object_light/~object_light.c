void __thiscall survarium::object_light::~object_light(survarium::object_light *this)
{
  vostok::math::curve_point<vostok::math::float4_pod> *pointer; // eax

  this->__vftable = (survarium::object_light_vtbl *)&survarium::object_light::`vftable';
  if ( this->m_props.m_color_curve.num_points )
  {
    pointer = this->m_props.m_color_curve.points.pointer;
    if ( pointer )
      pt3free(pointer);
    this->m_props.m_color_curve.points.pointer = 0;
    this->m_props.m_color_curve.num_points = 0;
  }
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
