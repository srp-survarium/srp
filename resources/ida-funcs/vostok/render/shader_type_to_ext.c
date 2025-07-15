const char *__usercall vostok::render::shader_type_to_ext@<eax>(vostok::render::enum_shader_type st@<eax>)
{
  if ( st == enum_shader_type_vertex )
    return "vs";
  if ( st == enum_shader_type_pixel )
    return "ps";
  return "gs";
}
