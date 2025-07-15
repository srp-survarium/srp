double __usercall vostok::collision::sphere_geometry_instance::get_surface_area@<st0>(
        vostok::collision::sphere_geometry_instance *this@<ecx>,
        float a2@<xmm0>)
{
  vostok::collision::sphere_geometry_instance::radius(this);
  return a2 * a2 * 12.566371;
}
