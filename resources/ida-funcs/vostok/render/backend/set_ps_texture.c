void __userpurge vostok::render::backend::set_ps_texture(
        vostok::render::backend *this@<ecx>,
        int a2@<esi>,
        char *name,
        vostok::render::res_texture *texture)
{
  if ( vostok::render::textures_handler<1>::set_overwrite(
         (vostok::render::textures_handler<1> *)this,
         a2 + 3740,
         name,
         texture) )
  {
    *(_BYTE *)(a2 + 109) = 1;
  }
}
