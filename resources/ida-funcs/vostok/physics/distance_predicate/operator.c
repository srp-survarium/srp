BOOL __userpurge vostok::physics::distance_predicate::operator()@<eax>(
        const vostok::physics::closest_ray_result *l@<ecx>,
        const vostok::physics::closest_ray_result *r@<eax>,
        vostok::physics::distance_predicate *this)
{
  float y; // xmm5_4
  float z; // xmm6_4

  y = this->m_from.y;
  z = this->m_from.z;
  return (float)((float)((float)((float)(r->hit_point_world.z - z) * (float)(r->hit_point_world.z - z))
                       + (float)((float)(r->hit_point_world.y - y) * (float)(r->hit_point_world.y - y)))
               + (float)((float)(r->hit_point_world.x - this->m_from.x) * (float)(r->hit_point_world.x - this->m_from.x))) > (float)((float)((float)((float)(l->hit_point_world.z - z) * (float)(l->hit_point_world.z - z)) + (float)((float)(l->hit_point_world.y - y) * (float)(l->hit_point_world.y - y))) + (float)((float)(l->hit_point_world.x - this->m_from.x) * (float)(l->hit_point_world.x - this->m_from.x)));
}
