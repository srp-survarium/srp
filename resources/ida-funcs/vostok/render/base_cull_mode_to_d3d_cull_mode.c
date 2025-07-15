int __usercall vostok::render::base_cull_mode_to_d3d_cull_mode@<eax>(vostok::render::enum_cull_mode cull_mode@<eax>)
{
  if ( cull_mode == cull_mode_none )
    return 1;
  if ( cull_mode == cull_mode_front )
    return 2;
  return 3;
}
