vostok::render::shader_constant *__usercall vostok::render::shader_constant::operator=@<eax>(
        vostok::render::shader_constant *this@<ecx>,
        vostok::render::shader_constant *result@<eax>)
{
  if ( result )
    *result = *this;
  return result;
}
