vostok::render::res_texture *__thiscall vostok::render::resource_manager::create_texture(
        vostok::render::resource_manager *this,
        vostok::render::resource_manager *physical_name,
        vostok::resources::query_result_for_cook *parent,
        vostok::resources::query_result_for_cook *mip_level_cut,
        unsigned int use_pool,
        int load_async,
        bool use_converter,
        bool num_last_mips_used,
        unsigned int query_texture,
        bool streamed,
        bool force_query,
        char a12)
{
  const char *v12; // edi
  vostok::resources::query_result_for_cook *v13; // esi
  bool v14; // cf
  bool v15; // zf
  vostok::render::res_texture *result; // eax

  if ( !parent )
    goto LABEL_8;
  v12 = "null";
  v13 = parent;
  this = (vostok::render::resource_manager *)5;
  result = 0;
  v14 = 0;
  v15 = 1;
  do
  {
    if ( !this )
      break;
    v14 = LOBYTE(v13->__vftable) < (unsigned int)*v12;
    v15 = LOBYTE(v13->__vftable) == *v12;
    v13 = (vostok::resources::query_result_for_cook *)((char *)v13 + 1);
    ++v12;
    this = (vostok::render::resource_manager *)((char *)this - 1);
  }
  while ( v15 );
  if ( !v15 )
    result = (vostok::render::res_texture *)(-v14 - (v14 - 1));
  if ( result )
  {
LABEL_8:
    result = (vostok::render::res_texture *)vostok::render::resource_manager::find_texture(
                                              this,
                                              (int)physical_name,
                                              (const char *)parent);
    if ( !result || a12 )
      return vostok::render::resource_manager::load_texture(
               physical_name,
               (char *)parent,
               mip_level_cut,
               use_pool,
               load_async,
               use_converter,
               num_last_mips_used,
               query_texture,
               streamed,
               force_query);
  }
  return result;
}
