unsigned int __usercall vostok::render::stage_lights::index_to_shadow_size@<eax>(
        unsigned int size_index@<eax>,
        vostok::render::stage_lights *this)
{
  if ( !size_index )
    return 1024;
  if ( size_index == 1 )
    return 512;
  return 256;
}
