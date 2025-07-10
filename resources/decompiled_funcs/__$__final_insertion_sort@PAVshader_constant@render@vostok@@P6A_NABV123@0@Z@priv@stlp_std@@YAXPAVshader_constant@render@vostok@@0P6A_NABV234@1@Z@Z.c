void __usercall stlp_std::priv::__final_insertion_sort<vostok::render::shader_constant *,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        vostok::render::shader_constant *__first@<esi>,
        vostok::render::shader_constant *__last@<eax>,
        vostok::render::shader_constant *a3@<ebx>)
{
  bool (__cdecl *v4)(const vostok::render::shader_constant *, const vostok::render::shader_constant *); // [esp+0h] [ebp-4h]

  if ( __last - __first <= 16 )
  {
    if ( __first != __last )
      stlp_std::priv::__insertion_sort<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        __first,
        __last);
  }
  else
  {
    stlp_std::priv::__insertion_sort<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
      __first,
      __first + 16);
    stlp_std::priv::__unguarded_insertion_sort_aux<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
      __first + 16,
      __last,
      a3,
      v4);
  }
}
