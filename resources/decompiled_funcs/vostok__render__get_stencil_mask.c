unsigned int __usercall vostok::render::get_stencil_mask@<eax>(vostok::render::enum_vertex_input_type vit@<eax>)
{
  unsigned int result; // eax

  switch ( vit )
  {
    case skeletal_4_bones_mesh_vertex_input_type:
    case skeletal_3_bones_mesh_vertex_input_type:
    case skeletal_2_bones_mesh_vertex_input_type:
    case skeletal_1_bones_mesh_vertex_input_type:
      result = 133;
      break;
    case particle_vertex_input_type:
    case particle_subuv_vertex_input_type:
    case particle_beamtrail_vertex_input_type:
      result = 134;
      break;
    default:
      result = 130;
      break;
  }
  return result;
}
