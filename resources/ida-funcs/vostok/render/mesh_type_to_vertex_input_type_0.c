vostok::render::enum_vertex_input_type __usercall vostok::render::mesh_type_to_vertex_input_type_0@<eax>(
        vostok::render::mesh_type_enum type@<eax>)
{
  vostok::render::enum_vertex_input_type result; // eax

  switch ( byte_650B34[type] )
  {
    case 0:
      result = static_mesh_vertex_input_type;
      break;
    case 1:
      result = static_mesh_vertex_colored_input_type;
      break;
    case 2:
      result = skeletal_1_bones_mesh_vertex_input_type;
      break;
    case 3:
      result = skeletal_2_bones_mesh_vertex_input_type;
      break;
    case 4:
      result = skeletal_3_bones_mesh_vertex_input_type;
      break;
    case 5:
      result = skeletal_4_bones_mesh_vertex_input_type;
      break;
    case 6:
      result = wires_vertex_input_type;
      break;
    case 7:
      result = grassmesh_vertex_input_type;
      break;
  }
  return result;
}
