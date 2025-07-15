vostok::render::effect_descriptor *__usercall vostok::render::make_unique_name@<eax>(
        const vostok::render::surface_effect_parameters *parameters@<esi>,
        vostok::fs_new::virtual_path_string *a2@<ecx>,
        vostok::render::effect_descriptor *descriptor,
        const char *a4)
{
  vostok::fs_new::virtual_path_string::virtual_path_string(a2, (int)descriptor);
  vostok::fs_new::path_string_impl::assignf(
    descriptor,
    (vostok::buffer_string *)LOBYTE(parameters->vertex_input_type),
    (vostok::buffer_string *)"%llu_%lu",
    a4,
    (int)a4 >> 31,
    LOBYTE(parameters->vertex_input_type)
  | ((LOBYTE(parameters->cull_mode) | (((parameters->blend_mode << 8) | LOBYTE(parameters->draw_to_gbuffer)) << 8)) << 8));
  return descriptor;
}
