const vostok::math::float4x4 *__usercall vostok::render::renderer_context::get_view2shadow@<eax>(
        vostok::render::renderer_context *this@<ecx>,
        int a2@<eax>)
{
  const vostok::math::float4x4 *result; // eax

  switch ( (unsigned int)this )
  {
    case 1u:
      result = (const vostok::math::float4x4 *)(a2 + 16580);
      break;
    case 2u:
      result = (const vostok::math::float4x4 *)(a2 + 16644);
      break;
    case 3u:
      result = (const vostok::math::float4x4 *)(a2 + 16708);
      break;
    default:
      result = (const vostok::math::float4x4 *)(a2 + 16516);
      break;
  }
  return result;
}
