char __cdecl vostok::render::reclaim<vostok::render::res_render_output,64>(
        const vostok::render::res_render_output *ptr)
{
  const vostok::render::res_render_output ***v1; // ecx
  const vostok::render::res_render_output **v2; // esi
  const vostok::render::res_render_output **v3; // edi
  const vostok::render::res_render_output **v5; // eax

  v2 = *v1;
  v3 = v1[1];
  while ( 1 )
  {
    if ( v2 == v3 )
      return 0;
    if ( *v2 == ptr )
      break;
    ++v2;
  }
  v5 = v2;
  if ( v2 + 1 != v3 )
  {
    do
    {
      if ( v5 )
        *v5 = v5[1];
      ++v5;
    }
    while ( v5 + 1 != v1[1] );
  }
  v1[1] = &(*v1)[v1[1] - *v1 - 1];
  return 1;
}
