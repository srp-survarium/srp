_DWORD *__usercall vostok::render::res_render_output::select_refresh@<eax>(
        vostok::render::res_render_output *this@<ecx>,
        _DWORD *result@<eax>)
{
  *result = 0;
  result[1] = 1;
  return result;
}
