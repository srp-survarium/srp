vostok::render::lpv_render_surface *__thiscall stlp_std::vector<vostok::render::lpv_render_surface,vostok::render::std_allocator<vostok::render::lpv_render_surface>>::erase(
        vostok::render::lpv_render_surface *__last,
        stlp_std::vector<vostok::render::lpv_render_surface,vostok::render::std_allocator<vostok::render::lpv_render_surface> > *this,
        vostok::render::lpv_render_surface *__first)
{
  vostok::render::lpv_render_surface *v3; // esi
  const stlp_std::random_access_iterator_tag *v5; // [esp+0h] [ebp-14h]
  vostok::render::lpv_render_surface *v6; // [esp+0h] [ebp-14h]
  int *v7; // [esp+4h] [ebp-10h]
  const stlp_std::__false_type *v8; // [esp+4h] [ebp-10h]

  if ( __first != __last )
  {
    v3 = stlp_std::priv::__copy<vostok::render::lpv_render_surface *,vostok::render::lpv_render_surface *,int>(
           __last,
           this->_M_impl._M_finish,
           __first,
           v5,
           v7);
    stlp_std::__destroy_range_aux<vostok::render::lpv_render_surface *,vostok::render::lpv_render_surface>(
      v3,
      this->_M_impl._M_finish,
      v6,
      v8);
    this->_M_impl._M_finish = v3;
  }
  return __first;
}
