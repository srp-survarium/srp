vostok::physics::primitive_type __usercall vostok::physics::from_bullet_shape_type@<eax>(int type@<eax>)
{
  vostok::physics::primitive_type result; // eax

  switch ( byte_6BC7B8[type] )
  {
    case 0:
      result = primitive_box;
      break;
    case 1:
      result = primitive_sphere;
      break;
    case 2:
      result = primitive_capsule;
      break;
    case 3:
      result = primitive_cylinder;
      break;
  }
  return result;
}
