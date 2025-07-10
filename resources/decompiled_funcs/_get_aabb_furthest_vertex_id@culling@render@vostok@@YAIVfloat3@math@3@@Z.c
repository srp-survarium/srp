unsigned int __cdecl vostok::render::culling::get_aabb_furthest_vertex_id(vostok::math::float3 dir)
{
  unsigned int result; // eax

  if ( dir.x < 0.0 )
  {
    if ( dir.y < 0.0 )
    {
      return dir.z >= 0.0;
    }
    else
    {
      result = 2;
      if ( dir.z < 0.0 )
        return 3;
    }
  }
  else if ( dir.y < 0.0 )
  {
    result = 5;
    if ( dir.z < 0.0 )
      return 4;
  }
  else
  {
    result = 7;
    if ( dir.z < 0.0 )
      return 6;
  }
  return result;
}
